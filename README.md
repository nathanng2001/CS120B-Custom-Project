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

Bop It will be single player. The actions will consist of “Bop It,” “Block It,” and “Pull It.” The “Bop It” action will be the remote control buttons (1-9), “Block It” the photoresistor, and “Pull It” the joystick module. The LCD screen will display the action to be done. The initial score will be 0, and will increment by 1 for each correct action done within the time limit, 2 seconds. The game ends when an incorrect action is performed or the player did not perform any action in the time limit. The active buzzer will turn on when the game is over. Pressing the button will reset the game. 

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
## Class Diagram
 > <!--Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). -->

 > The main class will create a game object from the game class, which will handle the turn based aspect of the game. The game class will have access to compstrat, ship, and factory classes. The compstrat class will be used to generate moves for the CPU, choosing a strategy better suited for different points in the game. The factory class will create the ship objects for both the player and the CPU, and the ship class will be used in conjunction with the game class to handle hit detection, misses, ship health, and ship coordinates on the boards. 
 
 > CS100 UML_Overview![CS100 UML_Overview](https://user-images.githubusercontent.com/39098603/131289412-22e85e28-1e5d-4827-9cb9-dc0080d9ecb5.png)

 > CS100 Game![CS100 Game](https://user-images.githubusercontent.com/39098603/131289479-f968355f-2e97-4019-becb-07729c149113.png)

 > CS100 CompStrat![CS100 CompStrat](https://user-images.githubusercontent.com/39098603/131289513-596545cf-1099-4726-b39f-ec146b434cdf.png)

 > CS100 Ship/Factory![CS100 Ship:Factory](https://user-images.githubusercontent.com/39098603/131289754-41f8cab3-56b1-4694-84a8-03a45da0ed49.png)

 > <!--## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.-->

 > <!--## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. -->
 
 ## Screenshots
 > <!--Screenshots of the input/output after running your application-->
 > CS100 Input![CS100 Input](https://user-images.githubusercontent.com/39098603/131290296-fad61bfb-e65a-46e7-b89c-c773af85e7c7.png)

 > CS100 Sample_Board![CS100 Sample_Board](https://user-images.githubusercontent.com/39098603/131290591-8f3b67a0-c269-4482-aa20-08705a60029b.png)

 > CS100 Sample_Game![CS100 Sample_Game](https://user-images.githubusercontent.com/39098603/131290939-04ba732e-03e7-4330-acd3-934321d7032e.png)

 > CS100 Sample_Output![CS100 Sample_Output](https://user-images.githubusercontent.com/39098603/131290953-f3d1ac59-c675-4995-bb05-4444cde9e8bc.png)

 ## Installation/Usage
 > <!--Instructions on installing and running your application-->
 > Create a local directory on your local machine, and clone the Battleship directory.
 > ```sh
 > git clone <https://github.com/cs100/final-project-brookenathanshankar.git>
 > ```
 > To play, first compile the files
 > ```sh
 > g++ main.cpp game.cpp compstrat.cpp -o main
 > ```
 > Then run `./main` to play
 > 
 ## Testing
 > <!--How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.-->
 > Our project was tested through our units tests files via CMake. We tested primarily for out of bounds, and invalid/incorrect user input.
