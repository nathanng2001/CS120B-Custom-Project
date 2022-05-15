 > <!-- > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). -->
 > 
# Bop It
 > <!--Your author list below should include links to all members GitHub (remove existing author).-->
 
 > Authors: [Nathan Ng](https://github.com/nathanng2001)
 
 > <!--You will be forming a group of **THREE** students and working on an interesting project. A list of proposed project ideas that have been successful in previous quarters is given in the project specifications link on iLearn. You can select an idea from the list, start thinking about the features you will implement, what design patterns can help you implement them, and why. If you want to propose your own original idea, you will have to contact an instructor to discuss the project and obtain written permission before you submit your project proposal. Your project needs to implement two design patterns.The project work should be divided almost equally among team members and each member is expected to work on at least one design pattern (more than one partner may work on a pattern) and some of its test cases. You can of course help each other, but it needs to be clear who will be responsible for which patterns and for which features.-->
 
 > <!-- ## Expectations
 > * Incorporate **at least two** distinct design patterns. You need to include at least *one* design pattern that we will teach this session:
 >   * Composite, Strategy, Abstract Factory, Visitor, or Decorator
 > * All design patterns need to be linked together (it can't be two distinct projects)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. -->

## Project Description
 > <!--Your project description should summarize the project you are proposing. Be sure to include-->
 > <!--* Why is it important or interesting to you?-->
 > Bop It is a handheld game where players perform a series of actions based on audio output. The original game had three actions. “Bop it” is associated with a button, “twist it,” a lever, and “pull it” a handle. Each action performed in a set amount of time earns a point, and the aim of the game is to score as many points as possible. 

> Bop It will be single player. The actions will consist of “Bop It,” “Block It,” and “Pull It.” The “Bop It” action will be the remote control buttons (1-9), “Block It” the photoresistor, and “Pull It” the joystick module. The LCD screen will display the action to be done. The initial score will be 0, and will increment by 1 for each correct action done within the time limit, 2 seconds. The game ends when an incorrect action is performed or the player did not perform any action in the time limit. The active buzzer will turn on when the game is over. Pressing the button will reset the game. 

 > <!--## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA-->
## Wiring Diagram
 > <!--Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). -->

 > CS120B Wiring_Overview![CS120B_Custom_Lab_Wiring_Diagram](https://user-images.githubusercontent.com/39098603/168495806-99d8620a-b18f-4b07-ac8e-d155a2c704c2.png)

 
 ## Screenshots
 > <!--Screenshots of the input/output after running your application-->
 > Task Diagram ![task_diagram](https://user-images.githubusercontent.com/39098603/168495901-d79324dd-a96e-45a6-83cb-fd7ad7465252.png)

> Game State Machine![game_sm](https://user-images.githubusercontent.com/39098603/168496023-7007cc06-9f3e-4c79-a8e7-a78faf6ec212.png)

> Remote State Machine![remote_sm](https://user-images.githubusercontent.com/39098603/168496034-2d23e9be-0537-4974-a0db-c796de9283be.png)

> Photoresistor State Machine![photoresistor_sm](https://user-images.githubusercontent.com/39098603/168496050-d90069c1-d65f-45ab-8c6a-e30957efdfe5.png)

> PhotoresistorCheck State Machine![photoresistorcheck_sm](https://user-images.githubusercontent.com/39098603/168496059-3c6e1d2c-9ec3-4e5a-ac4e-f419377140e1.png)

> Joystick State Machine![joystick_sm](https://user-images.githubusercontent.com/39098603/168496110-e1fabf2f-4ef0-4118-87f1-4b19e2be618e.png)

> JoystickCheck State Machine![joystickcheck_sm](https://user-images.githubusercontent.com/39098603/168496118-fcc9ddab-d5eb-4cd0-b10f-8a2671326fe2.png)

> ResetButton State Machine![resetbutton_sm](https://user-images.githubusercontent.com/39098603/168496127-baaa3b1a-9fd0-4e59-abf1-556278725e33.png)
