## Mordecai

Mordecai is a clone of My University's Student Portal, only better!
This Project was made in first semseter in University for my *Programming Fundamentals* course. Developed by Myself, @Fawad-Javed-Fateh and Syeda Momina. 

*Why Clone the University Portal?* We decided to make a clone of our University Portal not only because we like a challenge, but because we believe that our university's student portal lacked some crucial features that must be implemented to make the communication between student and teacher easier!

The project consists of two different portions. 
- A Student Side
- A teacher Side

#### 1. The Student Side
The Student side consists of features such as Viewing your Marks per Subject, Viewing your atendance per Subject and and viewing your aggregated attendance %.
**Apllying for Leave**, where the student can ask a certain teacher for some day's leave, and **Student Notifier**, where the student coluld notify the teacher for mistakes in marking, were new features that were implemented by us. The student can also print out his fee challan and get it as a formatted txt file. 
#### 2. The Teacher Side
The Teacher Side consisted of the counter-parts of the Student Side's features. The Teachers can upload the marks for each student, set the attendance and view the notifications sent by the students. The teachers also have a salary tab for viewing their salary and related details. 


I personally am not a big fan of the console and how it is by default set to take input only by the keyboard. In this project, I worked with Windows API functions to implement clicking in the Console. The Program displays tasteful colored Ascii Art to differentiate the teacher and student side. Majority of the input is taken with the mouse.

I limited the program to only accept Double Clicks of the mouse. Winows.h was used for the Windows API functions and any compiler specific libraries were discouraged. 

We made use of structures to save all the info about teachers and students and the structures were written in a .dat file in binary form to prevent data loss after the program was closed. 


#### How to Execute:
1. Import all the .c files and the vars.h and master.dat file in the same folder
2. Simply compile and run the primary .c file named main.c. It is the file that incorporates the work of all the project partners and allows for mouse clicking.

**Made with love and hardwork. Please Dont copy without permission.**
