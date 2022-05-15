/* Your Name & E-mail: Nathan Ng nng012@ucr.edu
* Discussion Section: 21
* Assignment: Custom Project
* Exercise Description: 
*   "Bop It!" the Game. 
*   Perform correct actions to gain points. The game ends
*   when an incorrect action is performed, or no action 
*   is performed at all.
*   
*   Bop It - IR Remote (1-9)
*   Block It - Photoresistor
*   Pull It - Joystick
*   
*   The active buzzer will go off when the game ends, and
*   the total number of points will be displayed.
*   
*   The reset button can be pressed at any time to reset
*   the game.
*   
* I acknowledge all content contained herein, excluding 
*   template or example code, is my own original work. 
*   
* Complexity 1 and 2: https://youtu.be/WMTQU9JH2fw
* Complexity 3: https://youtu.be/PI6QpEZ8H-k
* Other Notes: https://youtu.be/-UWUvp4Ug3A
*/

#include <IRremote.h>
#include <LiquidCrystal.h>

int rand_num, bop_num, t;
int points;
bool bop, block, pull, other, flag;

//IRReceiver
const int receiver = 6; 
IRrecv irrecv(receiver); 
decode_results results;  

//LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int contrast = 60;

//Joystick Module
int VRx = A0;
int VRy = A1;
int SW = 10;
int xVal, yVal, mapX, mapY;

//Photoresistor
int lightValue, maxLight;

//Active Buzzer
int buzzerPin = 7;

//Reset Button
int resetPin = 8;
int buttonState = 0;

typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
} task;

const unsigned long tasksPeriodGCD = 20;
const unsigned short tasksNum = 7;
task tasks[tasksNum];

enum GameStates {G_Init, G_s0, G_s1, G_s2, G_s3, G_s4, G_s5, G_s6, G_s7};
int TickFct_Game(int state);

enum RemoteStates {R_Init, R_s0};
int TickFct_Remote(int state);

enum PhotoresistorStates {P_Init, P_s0};
int TickFct_Photoresistor(int state);

enum PhotoresistorCheckStates {PC_Init, PC_s0};
int TickFct_PhotoresistorCheck(int state);

enum JoystickStates {J_Init, J_s0};
int TickFct_Joystick(int state);

enum JoystickCheckStates {JC_Init, JC_s0};
int TickFct_JoystickCheck(int state);

enum ResetButtonStates {B_Init, B_s0, B_s1};
int TickFct_ResetButton(int state);

void setup()
{
  //IRReceiver      
  irrecv.enableIRIn();   
  irrecv.blink13(true); 

  //LCD
  /*analogWrite(7, 80);*/
  lcd.begin(16, 2);

  //Joystick
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT);

  //Active Buzzer
  pinMode(buzzerPin, OUTPUT);

  //Reset Button
  pinMode(resetPin, INPUT);
  
  Serial.begin(9600);

  unsigned char i = 0;
  tasks[i].state = G_Init;
  tasks[i].period = 100;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_Game;
  i++;
  tasks[i].state = R_Init;
  tasks[i].period = 20;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_Remote;
  i++;
  tasks[i].state = P_Init;
  tasks[i].period = 20;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_Photoresistor;
  i++;
  tasks[i].state = PC_Init;
  tasks[i].period = 20;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_PhotoresistorCheck;
  i++;
  tasks[i].state = J_Init;
  tasks[i].period = 20;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_Joystick;
  i++;
  tasks[i].state = JC_Init;
  tasks[i].period = 20;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_JoystickCheck;
  i++;
  tasks[i].state = B_Init;
  tasks[i].period = 20;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_ResetButton;
}

void checkBop() {
  switch(results.value) {
   case 0xFF30CF: if (bop_num == 1) { bop = true; } else other = true; /*Serial.println("1");*/ break;
   case 0xFF18E7: if (bop_num == 2) { bop = true; } else other = true; /*Serial.println("2");*/ break;
   case 0xFF7A85: if (bop_num == 3) { bop = true; } else other = true; /*Serial.println("3");*/ break;
   case 0xFF10EF: if (bop_num == 4) { bop = true; } else other = true; /*Serial.println("4");*/ break;
   case 0xFF38C7: if (bop_num == 5) { bop = true; } else other = true; /*Serial.println("5");*/ break;
   case 0xFF5AA5: if (bop_num == 6) { bop = true; } else other = true; /*Serial.println("6");*/ break;
   case 0xFF42BD: if (bop_num == 7) { bop = true; } else other = true; /*Serial.println("7");*/ break;
   case 0xFF4AB5: if (bop_num == 8) { bop = true; } else other = true; /*Serial.println("8");*/ break;
   case 0xFF52AD: if (bop_num == 9) { bop = true; } else other = true; /*Serial.println("9");*/ break;
   default: other  = true; Serial.print("Other: Bop"); break;
  }
  delay(100);
}

//void checkBlock() {
//  if (lightValue < (maxLight / 2)) {
//    if (rand_num == 2 && flag) {
//      block = true;
//      flag = false;
//      Serial.println("Block it!");
//    }
//    else if (rand_num != -1) {
//      other = true;
//      Serial.println("Other: Block");
//    }
//  }
//}

//void checkPull() {
//  if (!(-20 <= mapX && mapX <= 20 && -20 <= mapY && mapY <= 20)) {
//    if (rand_num == 3 && flag) {
//      while (!(-20 <= mapX && mapX <= 20 && -20 <= mapY && mapY <= 20)) {
//       xVal = analogRead(A0);
//       yVal = analogRead(A1);
//       mapX = map(xVal, 0, 1023, -512, 512);
//       mapY = map(yVal, 0, 1023, -512, 512);
//      }
//      pull = true;
//      flag = false;
//      Serial.println("Pull it!");
//    }
//    else if (rand_num != -1) {
//      other = true;
//      Serial.println("Other: Pull");
//    }
//  }
//}
   
void loop() { 
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
    if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period) {
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = millis(); // Last time this task was ran
    }
  }
  delay(100);
}

int TickFct_Game(int state) {
  switch(state) {
    case G_Init:
      lcd.clear();
      lcd.setCursor(0, 0);
      t = 0;
      flag = false;
      other = false;
      bop = false;
      block = false;
      pull = false;
      points = 0;
      bop_num = -1;
      rand_num = -1;
      state = G_s0;

    case G_s0:
      rand_num = random(1, 4);
      if (rand_num == 1) {      //Bop It
        bop_num = random(1, 10);
        lcd.print("Bop It! ");
        lcd.print(bop_num);
        t = 0;
        state = G_s1;
      }
      else if (rand_num == 2) {  //Block It
        lcd.print("Block It!");
        t = 0;
        state = G_s2;
      }
      else if (rand_num == 3) {   //Pull It
        lcd.print("Pull It!");
        t = 0;
        state = G_s3;
      }
      break;

    case G_s1:
      if (t <= 25 && bop) { 
        bop = false;
        other = false;
        bop_num = -1;
        points++;
        state = G_s4;
      }
      else if (t > 25 || other) {
        other = false;
        state = G_s5;
      }
      t++;
      Serial.print("Bop - ");
      Serial.println(t);
      break;

    case G_s2:
      if (t < 25 && block) {
        block = false;
        flag = false;
        other = false;
        points++;
        t = 0;
        state = G_s4;
      }
      else if (t >= 25 || other) {
        other = false;
        state = G_s5;
      }
      t++;
      Serial.print("Block - ");
      Serial.println(t);
      break;
      
    case G_s3:
      if (t <= 25 && pull) {
        pull = false;
        flag = false;
        other = false;
        points++;
        t = 0;
        state = G_s4;
      }
      else if (t > 25 || other) {
        other = false;
        state = G_s5;
      }
      t++;
      Serial.print("Pull - ");
      Serial.println(t);
      break;

    case G_s4:
      rand_num = -1;
      lcd.clear();
      lcd.setCursor(0, 0);
      if (t > 5)
        state = G_s0;
      t++;
      break;

    case G_s5:
      lcd.clear();
      lcd.print("Total Points: ");
      lcd.setCursor(0, 1);
      lcd.print(points);
      t = 0;
      state = G_s6;
      break;

    case G_s6:
      if (t <= 5) {
        if (t % 2 == 0) 
          digitalWrite(buzzerPin, HIGH);
        else
          digitalWrite(buzzerPin, LOW);
      }
      else
        state = G_s7;
      t++;
      break;
      
    case G_s7:
      break;

    default:
      state = G_Init;
  }

  return state;
}

int TickFct_Remote(int state) {
  switch(state) {
    case R_Init:
      //bop = false;
      state = R_s0;
      break;

    case R_s0:
      if (irrecv.decode(&results)) {   
        Serial.println(results.value, HEX);      
        checkBop();
        irrecv.resume();   
      }
      break;

    default:
      state = R_Init;
      break;
  }

  return state;
}

int TickFct_Photoresistor(int state) {
  switch(state) {
    case P_Init:
      //block = false;
      lightValue = 0;
      maxLight = -1;
      state = P_s0;
      break;
      
    case P_s0:
      lightValue = analogRead(A5);
      if (lightValue > maxLight)
        maxLight = lightValue;
      //Serial.println(lightValue);
      //checkBlock();
      break;

    default:
      state = P_Init;
      break;
  }

  return state;
}

int TickFct_PhotoresistorCheck(int state) {
  switch(state) {
    case PC_Init:
      state = PC_s0;
      break;
      
    case PC_s0:
      if (lightValue < (maxLight / 2)) { 
        if (rand_num == 2) {
          flag = true;
        }
        else if (rand_num != -1) {
          other = true;
          Serial.println("Other: Block");
        }
      }

      else if (rand_num == 2 && flag) {
        block = true;
        flag = false;
        Serial.println("Block it!");
      }
      break;

    default:
      state = PC_Init;
      break;
  }

  return state;
}

int TickFct_Joystick(int state) {
  switch(state) {
    case J_Init:
      mapX = 0;
      mapY = 0;
      //pull = false;
      state = J_s0;
      break;

    case J_s0:
      xVal = analogRead(A0);
      yVal = analogRead(A1);
      mapX = map(xVal, 0, 1023, -512, 512);
      mapY = map(yVal, 0, 1023, -512, 512);
//      Serial.println();
//      Serial.print("X: ");
//      Serial.print(mapX);
//      Serial.print(" | Y: ");
//      Serial.print(mapY); 
//      checkPull();
      break;

    default:
      state = J_Init;
      break;
  }

  return state;
}

int TickFct_JoystickCheck(int state) {
  switch(state) {
    case JC_Init:
      state = JC_s0;
      break;

    case JC_s0:
      if (!(-20 <= mapX && mapX <= 20 && -20 <= mapY && mapY <= 20)) {
        if (rand_num == 3) {
          flag = true;
        }
        else if (rand_num != -1) {
          other = true;
          Serial.println("Other: Pull");
        }
      }
      else if (rand_num == 3 && flag) {
          pull = true;
          flag = false;
          Serial.println("Pull it!");
      }
      break;

    default:
      state = JC_Init;
      break;
    
  }

  return state;
}

int TickFct_ResetButton(int state) {
  switch(state) {
    case B_Init:
      state = B_s0;
      break;

    case B_s0:
      buttonState = digitalRead(resetPin);
      if (buttonState == 1) {
          lcd.clear();
          lcd.write("Resetting...");
          t = 0;
          tasks[0].state = tasks[0].TickFct(G_s7);
          state = B_s1;
      }
      //Serial.println(buttonState);
      break;

    case B_s1:
      if (t > 25) {
        tasks[0].state = tasks[0].TickFct(G_Init);
        state = B_s0;
      }
      else {
        Serial.print("Reset - ");
        Serial.println(t);
        t++;
      }
      break;
  }

  return state;
}
