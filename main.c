//Prototypes All the way up here to make sure no warnings occur for linking
void pos(int,int);
void studentside(void);
void teacherside(void);

//using definitions to not repeat long commands here
#define cls system("cls")
#define getconsole GetConsoleScreenBufferInfo
#define getstd GetStdHandle(STD_OUTPUT_HANDLE) 
#define getstd1 GetStdHandle(STD_INPUT_HANDLE)
#define mouseev mouse[i].Event.MouseEvent

//inclusion of deafult and user generated headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "vars.h"
#include "ali.c"
#include "momina.c"
#include "fawad.c"

CONSOLE_SCREEN_BUFFER_INFO cn; //global structure variable. CONSOLE_SCREEN_BUFFER_INFO saves different data about console screen like length, size etc.
INPUT_RECORD mouse[2]; DWORD records; //INPUT_RECORD is a structure that holds attributes of different input types.
int count;
int sum=0;
int count1[20];

int main()
{
	system("mode 120,30"); 										//Sets Console size by calling a system command. Sets console dimensions to 120 x 30
	SetConsoleTitle("MORDECAI - A \"REGULAR\" Student Portal"); //Sets Console Title.
	static DWORD conmode; 										//DWORD is a 32 bit unsigned integer
	static COORD place; 										//COORD is a structure basically saves coordinates in .X and .Y elements. 
	static int i,o;
	if(count==0)
	{GetConsoleMode(getstd,&conmode);							 //saves the state of console just started. a console has different properties which are specificcally saved here for later use.
	getconsole(getstd, &cn); 									//saves data about the console's screen and buffer' relation to CONSOLE_SCREEN_BUFFER_INFO variable 
	SetConsoleMode(getstd1,ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); //changes console properties to those specified.
	SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY); //changes properties of text printed on console. Here we use it to change color
	pos(0,cn.srWindow.Top+9);									//a function made to move cursor position to specified x and y coordinates
	printf("\t\t888b     d888  .d88888b.  8888888b.  8888888b.  8888888888 .d8888b.        d8888 8888888\n");
	printf("\t\t8888b   d8888 d88P   Y88b 888   Y88b 888   Y88b 888       d88P  Y88b      d88888   888 \n");  
	printf("\t\t88888b.d88888 888     888 888    888 888    888 888       888    888     d88P888   888  \n"); 
	printf("\t\t888Y88888P888 888     888 888   d88P 888    888 8888888  888            d88P 888   888  \n"); 
	printf("\t\t888 Y888P 888 888     888 8888888P'' 888    888 888      888           d88P  888   888 \n");  
	printf("\t\t888  Y8P  888 888     888 888 T88b   888    888 888       888    888  d88P   888   888  \n"); 
	printf("\t\t888       888 Y88b. .d88P 888  T88b  888  .d88P 888       Y88b  d88P d8888888888   888  \n");
	printf("\t\t888       888 ''Y88888P'' 888   T88b 8888888P'' 8888888888 'Y8888P' d88P     888 8888888 \n");	
	printf("\n");
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	printf("\n\n\n\n Loading- - - 3");
	sleep(1); 												//delays program execution by 1 second
	printf(" - - - 2");
	sleep(1);
	printf(" - - - 1");
	sleep(1);
	printf(" - - - Done");
	}
	cls;
	pos(0,2); 
	SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); //changes properties of text printed on console. Here we use it to change color
	printf("                                       &&&&&\n");                 
    printf("           &&&&&&&&&&&&&&&&&&&&&&     &&&&&&&\n");               
    printf("           &&                   &&    &&&&&&&\n");                
    printf("           &&        &&         &&     &&&&&\n");                 
    printf("           &&           &       &&  ,&&&   &&&,\n");              
    printf("           &&              &    & &&&&&&& &&&&&&&\n");            
    printf("           &&                &&&(&&&&&&&&&&&&&&&&&\n");           
    printf("           &&                 &&&&&& &&&&&&&&& &&&\n");           
    printf("           &&                   .&&& &&&&&&&&& &&&\n");           
    printf("           &&                   &&   &&&&&&&&& &&&\n");           
    printf("           &&&&&&&&&&&&&&&&&&&&&&   &&&&&&&&& &&&\n");           
    printf("                                     &&&&&&&&& && \n");           
    printf("                                     &&&& &&&&\n");               
    printf("                                     &&&& &&&& \n");              
    printf("                                     &&&& &&&&\n");               
    printf("                                     &&&& &&&&\n");               
    printf("                                     &&&& &&&&\n");               
    printf("                                     &&&& &&&&\n");               
    printf("                                     &&&& &&&&\n");                
	pos(7,23); 
	printf("Double Click Here To Acesss the Teacher Portal");
	SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY); 
	o=(cn.srWindow.Right-cn.srWindow.Left)/2+7;
	pos(o,3-1);
    printf("                    #@@@@@#\n");                pos(o,4-1);
    printf("               @@@@@@@@@@@@@@@@@\n");           pos(o,5-1);  
    printf("           @@@@@@@@@@@@@@@@@@@@@@@@@ \n");      pos(o,6-1);  
    printf("              @@@@@@@@@@@@@@@@@@@  | \n");      pos(o,7-1);
    printf("               @@@@@@@@@@@@@@@@#   |   \n");    pos(o,8-1);
    printf("               @@             @@  <|> \n");     pos(o,8);
    printf("               @@             @       \n");     pos(o,9);
    printf("                @&           @@          \n");  pos(o,10);
    printf("                @@          @@         \n");    pos(o,11);
    printf("                 @@       @@          \n");     pos(o,12);
    printf("                   @@@@@@@@           \n");     pos(o,13);
    printf("                   |      |          \n");      pos(o,14);
    printf("                @@@@@    @@@@@@        \n");    pos(o,15);
    printf("            @@@@@@@@@@@ @@@@@@@@@@@   \n");     pos(o,16);
    printf("           @@@@@@@@@@@@ @@@@@@@@@@@@    \n");   pos(o,17);
    printf("          @@@@@@@@@@@@@ @@@@@@@@@@@@@   \n");   pos(o,18);
    printf("         @@@@@@@@@@@@@   @@@@@@@@@@@@@  \n");   pos(o,19);
    printf("         @@@@@@@@@@@@@   @@@@@@@@@@@@@   \n");  pos(o,20);
    printf("        @@@@@@@@@@@@@@   @@@@@@@@@@@@@@  \n");	pos(o,21);
    pos(o+1,23);
    printf("Double Click Here To Acesss the Student Portal"); 
    SetConsoleTextAttribute(getstd,cn.wAttributes);
    for(i=cn.srWindow.Top;i<=cn.srWindow.Bottom-5;i++)
	{
		pos((cn.srWindow.Right+2)/2,i);
		printf("|");
	}
	pos(0,cn.srWindow.Bottom-4);
	for(i=cn.srWindow.Left;i<=cn.srWindow.Right;i++)
	{
		printf("-");
	}
	pos(cn.srWindow.Right/2-17,cn.srWindow.Bottom-3);
	printf("Double click here to Close the Program\n\t\t\tDeveloped collectively by Syeda Momina, Fawad J Fateh and Muhammad Ali");
	pos(cn.srWindow.Left,cn.srWindow.Bottom);
	SetConsoleMode(getstd1,ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); 		//changes console properties to those specified.
	for(;;)
	{
		ReadConsoleInput(getstd1,mouse,2,&records); 							//reads input given direcly to console through different input methods
		for (i=0;i<records;i++)
		{if(mouse[i].EventType==MOUSE_EVENT) 									//Here we will only catch the input from mouse
			{if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X<cn.srWindow.Right/2)&&(mouseev.dwMousePosition.Y<cn.srWindow.Bottom-4))  //checks if mouse input is double click and then checks if the double click  
			teacherside();																																													//position matches the required one
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X>cn.srWindow.Right/2)&&(mouseev.dwMousePosition.Y<cn.srWindow.Bottom-4))
			studentside();
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.Y>cn.srWindow.Bottom-4))
			goto end;}
		}
	}
	
	
	
	
	
	
	
	
	end:
	pos(cn.srWindow.Left,cn.srWindow.Bottom);
	ExitProcess(0); 									// Closes Program and Stops the Process
}

void pos(int x, int y)
{	
	COORD place;
	place.X=cn.srWindow.Left+x;
	place.Y=cn.srWindow.Top+y;
	SetConsoleCursorPosition(getstd, place);   //sets cursor position to that specified
}
void studentside(void)
{
	int i,o=0,stud;
	char n[400]; int roll;
	cls;
	FILE *f;
	struct student s[20];
	f=fopen("master.dat", "rb+");
	fread(&s,sizeof(s),1,f);
	rewind(f);
	check:
	cls;
	pos(cn.srWindow.Right/3-5,cn.srWindow.Bottom/2-5);
	SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY); 
	printf("*Login Credentials Required To Access The Student Portal!*\n------------------------------------------------------------------------------------------------------------------------\n");
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	printf("\nPlease Enter Your Name: ");
	fflush(stdin);
	scanf("%[^\n]s",n);
	printf("\n\nPlease Enter Your Roll Numner: ");
	scanf("%d", &roll);
	for(i=0;i<20;i++)
	{		
		if(strcmpi(n,s[i].name)==0 && roll==s[i].roll_no)
		{
			o++;
			stud=i;
			break;
		}

	}
	if(o==1)
	{printf("\n\nWelcome to The Student Portal Mr.%s\nLoading the Portal!", s[stud].name);
	sleep(2);
	student_menu:
	cls;
	pos(0,cn.srWindow.Bottom/2);
	SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY); 
	for(i=cn.srWindow.Left;i<=cn.srWindow.Right;i++)
	{
		printf("-");
	}
	for(i=cn.srWindow.Top;i<=cn.srWindow.Bottom;i++)
	{
		pos(cn.srWindow.Right/3,i);
		printf("|");
	} 
	for(i=cn.srWindow.Top;i<=cn.srWindow.Bottom;i++)
	{
		pos(2*(cn.srWindow.Right)/3,i);
		printf("|");
	}
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	pos(cn.srWindow.Right/9-3,cn.srWindow.Bottom/4-1);
	printf("Check Your Uploaded\n\t\t\b\bGrades/Marks");
	pos(4*cn.srWindow.Right/9-3,cn.srWindow.Bottom/4-1);
	printf("Check Your Attendance");
	pos(4*cn.srWindow.Right/9-3,cn.srWindow.Bottom/4);
	printf("\b\band Attendance Percentage");
	pos(7*cn.srWindow.Right/9,cn.srWindow.Bottom/4-1);
	printf("View and Save");
	pos(7*cn.srWindow.Right/9,cn.srWindow.Bottom/4);
	printf(" Fee Challan");
	pos(cn.srWindow.Right/9-2,3*cn.srWindow.Bottom/4-1);
	printf("Apply for Leave");
	pos(cn.srWindow.Right/9-2,3*cn.srWindow.Bottom/4);
	printf("  From Classes");
	pos(4*cn.srWindow.Right/9,3*cn.srWindow.Bottom/4-1);
	printf("\b\bPredict subject wise");
	pos(4*cn.srWindow.Right/9,3*cn.srWindow.Bottom/4);
	printf("Marks and Grades");
	pos(7*cn.srWindow.Right/9,3*cn.srWindow.Bottom/4-1);
	printf("Back To Main Menu");
	pos(cn.srWindow.Left,cn.srWindow.Bottom);
	SetConsoleMode(getstd1,ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); //changes console properties to those specified.
	for(;;)
	{
		ReadConsoleInput(getstd1,mouse,2,&records); //reads input given direcly to console
		for (i=0;i<records;i++)
		{if(mouse[i].EventType==MOUSE_EVENT)
			{if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X>2*cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y>cn.srWindow.Bottom/2))
			{count++;
			main();}
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X>2*cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y<cn.srWindow.Bottom/2))
			{challan(stud);
			printf("\n\nPress Any key to go back to Student menu");
			getch();
			goto student_menu;
			}
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X>cn.srWindow.Right/3)&&(mouseev.dwMousePosition.X<2*cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y<cn.srWindow.Bottom/2))
			{
			attendance_student(stud);
			printf("\n\nPress Any key to go back to Student Menu");
			getch();
			goto student_menu;
			}
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X<cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y<cn.srWindow.Bottom/2))
			{
			struct student *pointer;
			pointer = s;
			viewmarks(stud,pointer);
			printf("\n\nPress Any key to go back to Student Menu");
			getch();
			goto student_menu;
				
			}
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X>cn.srWindow.Right/3)&&(mouseev.dwMousePosition.X<2*cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y>cn.srWindow.Bottom/2))
			{
			struct student *pointer;
			pointer = s;
			grade_predictor(stud,pointer);
			printf("\n\nPress Any key to go back to Student Menu");
			getch();
			goto student_menu;
			}
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X<cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y>cn.srWindow.Bottom/2))
			{
			student_leave(stud,count1);
			printf("\n\nPress Any key to go back to Student Menu");
			getch();
			goto student_menu;
			}
			}
		}
	}
	
	}
	else
	{
		printf("\nNo Such User Record was Found! Please Enter Correct Credentials!\nPress Any Key to go Back to Login...\n\n");
		getch();
		goto check;
	}
}
void teacherside(void)
{
	int i,o=0,teach;
	char names[5][400]={
	"Basit Jasani",
	"Muhammad Hassan",
	"Rabia Tabassum",
	"Nadeem Khan",
	"Saba Qadir"};
	char codes[5][5]={
	"PF",
	"IRS",
	"AP",
	"CAL",
	"ENG"};
	char n[400], code[5];
	cls;
	FILE *f;
	struct student s[20];
	f=fopen("master.dat", "rb+");
	fread(&s,sizeof(s),1,f);
	rewind(f);
	fclose(f);
	check:
	cls;
	pos(cn.srWindow.Right/3-5,cn.srWindow.Bottom/2-5);
	SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
	printf("*Login Credentials Required To Access The Teacher Portal!*\n------------------------------------------------------------------------------------------------------------------------\n");
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	printf("\nPlease Enter Your Name: ");
	fflush(stdin);
	scanf("%[^\n]s",n);
	printf("\n\nPlease Enter Your Subject Code: ");
	scanf("%s", code);
	for(i=0;i<5;i++)
	{		
		if(strcmpi(n, names[i])==0 && strcmpi(code,codes[i])==0)
		{
			o++;
			teach=i;
			break;
		}
	}
	if(o==1)
	{printf("\n\nWelcome to The Teacher Portal %s %s\nLoading the Portal!", i==2||i==4?("Ma'am"):("Sir"),names[teach]);
	sleep(2);
	teacher_menu:
	cls;
	pos(0,cn.srWindow.Bottom/2);
	SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
	for(i=cn.srWindow.Left;i<=cn.srWindow.Right;i++)
	{
		printf("-");
	}
	for(i=cn.srWindow.Top;i<=cn.srWindow.Bottom;i++)
	{
		pos(cn.srWindow.Right/3,i);
		printf("|");
	}
	for(i=cn.srWindow.Top;i<=cn.srWindow.Bottom;i++)
	{
		pos(2*(cn.srWindow.Right)/3,i);
		printf("|");
	}
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	pos(cn.srWindow.Right/9,cn.srWindow.Bottom/4-1);
	printf("Upload Marks of\n\t\t\b\bYour Classes");
	pos(4*cn.srWindow.Right/9-3,cn.srWindow.Bottom/4-1);
	printf(" Upload Attendance");
	pos(4*cn.srWindow.Right/9-3,cn.srWindow.Bottom/4);
	printf("  Of your Classes");
	pos(7*cn.srWindow.Right/9,cn.srWindow.Bottom/4-1);
	printf("Notifications from");
	pos(7*cn.srWindow.Right/9,cn.srWindow.Bottom/4);
	printf("Your Students");
	pos(cn.srWindow.Right/9-2,3*cn.srWindow.Bottom/4-1);
	printf("Accept/Reject Leave");
	pos(cn.srWindow.Right/9-2,3*cn.srWindow.Bottom/4);
	printf("\b\b\bApplicatin from Students");
	pos(4*cn.srWindow.Right/9-5,3*cn.srWindow.Bottom/4-1);
	printf("Best and Worst Performers");
	pos(4*cn.srWindow.Right/9,3*cn.srWindow.Bottom/4);
	printf("Of your Class");
	pos(7*cn.srWindow.Right/9,3*cn.srWindow.Bottom/4-1);
	printf("Back To Main Menu");
	SetConsoleMode(getstd1,ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); //changes console properties to those specified.
	pos(cn.srWindow.Left,cn.srWindow.Bottom);

	for(;;)
	{
		ReadConsoleInput(getstd1,mouse,2,&records); //reads input given direcly to console
		for (i=0;i<records;i++)
		{if(mouse[i].EventType==MOUSE_EVENT)
			{if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X>2*cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y>cn.srWindow.Bottom/2))
			{count++;
			main();}
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X>cn.srWindow.Right/3)&&(mouseev.dwMousePosition.X<2*cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y<cn.srWindow.Bottom/2))
			{attendance_teacher(teach);
			printf("\n\nPress Any key to go back to Teacher Menu");
			getch();
			goto teacher_menu;
			}
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X<cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y<cn.srWindow.Bottom/2))
			{
			struct student *pointer;
			pointer = s;
			marks_updater(pointer,codes[teach]);
			f=fopen("master.dat", "rb+");
			fwrite(&s,sizeof(s),1,f);
			rewind(f);
			fclose(f);
			printf("\n\nPress Any key to go back to Teacher Menu");
			getch();
			goto teacher_menu;
			}
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X>cn.srWindow.Right/3)&&(mouseev.dwMousePosition.X<2*cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y>cn.srWindow.Bottom/2))
			{
			best_worst(teach);
			printf("\n\nPress Any key to go back to Teacher Menu");
			getch();
			goto teacher_menu;
			}
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X<cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y>cn.srWindow.Bottom/2))
			{
			teacher_leave(teach,count1);
			printf("\n\nPress Any key to go back to Teacher Menu");
			getch();
			goto teacher_menu;
			}
			else if((mouseev.dwEventFlags==DOUBLE_CLICK)&&(mouseev.dwMousePosition.X>2*cn.srWindow.Right/3)&&(mouseev.dwMousePosition.Y<cn.srWindow.Bottom/2))
			{
			notifier(teach);
			printf("\n\nPress Any key to go back to Teacher Menu");
			getch();
			goto teacher_menu;
			}
			}
		}
	}
	}
	else
	{
		printf("\nNo Such Teacher Record was Found! Please Enter Correct Credentials!\nPress Any Key to go Back to Login...\n\n");
		getch();
		goto check;
	}
	
}


