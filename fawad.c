#include<string.h>
#define cls system("cls")
#include<stdlib.h>
#include<stdio.h>
#include "vars.h"

int marks_updater(struct student *ptr,char *label)
{
	cls;
	int choice,j,yh,which;
	char sub[5][4]={"PF",
					"IRS",
					"AP",
					"CAL",
					"ENG",};
	int x,i;
	// if both strings are the same, strcmp returns 0
	for(i=0;i<5;i++)
	{
	if(strcmp(label,sub[i])==0)//here we comapre the original subject name we recieved from the main as *label in the function and comparing it with the array ofsubject strings to find a match
	{
		yh=i;
	}
	}
	switch(yh)
	{
		case 0:
		{
			printf("\nWhat would you like to input the Marks of? \n(1 for Quizzes / 2 for Sessionals / 3 for Finals) ");
			scanf("%d", &choice);
			cls;
			switch(choice)
			{
				case 1:
				{	
					printf("\n\nWhich quizz would you like to enter the marks of?\n(1-4) ");
					scanf("%d", &which);
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Quiz %d", which);
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=which-1;j<which;j++)
					{
						printf("Enter marks of quizz %d for %s: ", j+1, ptr->name);
						scanf("%d", &ptr->pf[j]);
					}
					ptr++;
				    }
				    break;
				}
				case 2:
				{
					printf("\n\nWhich Sessional would you like to enter the marks of?\n(1-2) ");
					scanf("%d", &which);
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Sessional %d", which);
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=which+3;j<which+4;j++)
					{
						printf("Enter marks of Sessional %d for %s: ", j-3, ptr->name);
						scanf("%d", &ptr->pf[j]);
					}
					ptr++;
				    }
				    break;
				}
				case 3:
				{
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Finals");
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=6;j<7;j++)
					{
						printf("Enter marks of Finals for %s: ", ptr->name);
						scanf("%d", &ptr->pf[j]);
					}
					ptr++;
				    }
				    break;
				}	
			}
			break;
		}
		case 1:
		{
			printf("\nWhat would you like to input the Marks of? \n(1 for Quizzes / 2 for Sessionals / 3 for Finals)");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1:
				{	
					printf("\n\nWhich quizz would you like to enter the marks of?\n(1-4) ");
					scanf("%d", &which);
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Quiz %d", which);
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=which-1;j<which;j++)
					{
						printf("Enter marks of quizz %d for %s: ", j+1, ptr->name);
						scanf("%d", &ptr->irs[j]);
					}
					ptr++;
				    }
				    break;
				}
				case 2:
				{
					printf("\n\nWhich Sessional would you like to enter the marks of?\n(1-2) ");
					scanf("%d", &which);
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Sessional %d", which);
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=which+3;j<which+4;j++)
					{
						printf("Enter marks of Sessional %d for %s: ", j-3, ptr->name);
						scanf("%d", &ptr->irs[j]);
					}
					ptr++;
				    }
				    break;
				}
				case 3:
				{
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Finals");
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=6;j<7;j++)
					{
						printf("Enter marks of Finals for %s: ", ptr->name);
						scanf("%d", &ptr->irs[j]);
					}
					ptr++;
				    }
				    break;
				}	
			}
			break;
		}
		case 2:
		{
			printf("\nWhat would you like to input the Marks of? \n(1 for Quizzes / 2 for Sessionals / 3 for Finals)");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1:
				{	
					printf("\n\nWhich quizz would you like to enter the marks of?\n(1-4) ");
					scanf("%d", &which);
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Quiz %d", which);
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=which-1;j<which;j++)
					{
						printf("Enter marks of quizz %d for %s: ", j+1, ptr->name);
						scanf("%d", &ptr->ap[j]);
					}
					ptr++;
				    }
				    break;
				}
				case 2:
				{
					printf("\n\nWhich Sessional would you like to enter the marks of?\n(1-2) ");
					scanf("%d", &which);
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Sessional %d", which);
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=which+3;j<which+4;j++)
					{
						printf("Enter marks of Sessional %d for %s: ", j-3, ptr->name);
						scanf("%d", &ptr->ap[j]);
					}
					ptr++;
				    }
				    break;
				}
				case 3:
				{
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Finals");
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=6;j<7;j++)
					{
						printf("Enter marks of Finals for %s: ", ptr->name);
						scanf("%d", &ptr->ap[j]);
					}
					ptr++;
				    }
				    break;
				}	
			}
			break;
		}
		case 3:
		{
			printf("\nWhat would you like to input the Marks of? \n(1 for Quizzes / 2 for Sessionals / 3 for Finals)");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1:
				{	
					printf("\n\nWhich quizz would you like to enter the marks of?\n(1-4) ");
					scanf("%d", &which);
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Quiz %d", which);
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=which-1;j<which;j++)
					{
						printf("Enter marks of quizz %d for %s: ", j+1, ptr->name);
						scanf("%d", &ptr->cal[j]);
					}
					ptr++;
				    }
				    break;
				}
				case 2:
				{
					printf("\n\nWhich Sessional would you like to enter the marks of?\n(1-2) ");
					scanf("%d", &which);
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Sessional %d", which);
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=which+3;j<which+4;j++)
					{
						printf("Enter marks of Sessional %d for %s: ", j-3, ptr->name);
						scanf("%d", &ptr->cal[j]);
					}
					ptr++;
				    }
				    break;
				}
				case 3:
				{
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Finals");
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=6;j<7;j++)
					{
						printf("Enter marks of Finals for %s: ", ptr->name);
						scanf("%d", &ptr->cal[j]);
					}
					ptr++;
				    }
				    break;
				}	
			}
			break;
		}
		case 4:
		{
			printf("\nWhat would you like to input the Marks of? \n(1 for Quizzes / 2 for Sessionals / 3 for Finals)");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1:
				{	
					printf("\n\nWhich quizz would you like to enter the marks of?\n(1-4) ");
					scanf("%d", &which);
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Quiz %d", which);
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=which-1;j<which;j++)
					{
						printf("Enter marks of quizz %d for %s: ", j+1, ptr->name);
						scanf("%d", &ptr->eng[j]);
					}
					ptr++;
				    }
				    break;
				}
				case 2:
				{
					printf("\n\nWhich Sessional would you like to enter the marks of?\n(1-2) ");
					scanf("%d", &which);
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Sessional %d", which);
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=which+3;j<which+4;j++)
					{
						printf("Enter marks of Sessional %d for %s: ", j-3, ptr->name);
						scanf("%d", &ptr->eng[j]);
					}
					ptr++;
				    }
				    break;
				}
				case 3:
				{
					cls;
					pos(cn.srWindow.Right/2-19,cn.srWindow.Top+8);
					SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
					printf("Entering marks of Finals");
					printf("\n------------------------------------------------------------------------------------------------------------------------\n");
					SetConsoleTextAttribute(getstd,cn.wAttributes);
					for(x=0;x<20;x++)
					{
					for(j=6;j<7;j++)
					{
						printf("Enter marks of Finals for %s: ", ptr->name);
						scanf("%d", &ptr->eng[j]);
					}
					ptr++;
				    }
				    break;
				}	
			}
			break;
		}
	}
		
}

int grade_predictor(int bp ,struct student *is)
{
	cls;
	char subj[400],grade[3];
	int *po;
    printf("\n\nEnter the name of the subject You want to predict the mark of:\n");
	fflush(stdin);
	gets(subj);
	
	char sub[5][4]={"PF",
					"IRS",
					"AP",
					"CAL",
					"ENG"};
	int i,j,b,n=1,z,prediction,counterclose=0,s;
	for(z=0;z<5;z++)
	{
		if(strcmpi(subj,sub[z])==0)
		{ s=z;
			switch(s)			//Sets pointer to point towards array of subject given
			{
			case 0:
				{po=&is[bp].pf[0];
				break;}
			case 1:
				{po=&is[bp].irs[0];
				break;}
			case 2:
				{po=&is[bp].ap[0];
				break;}
			case 3:
				{po=&is[bp].cal[0];
				break;}
			case 4:
				{po=&is[bp].eng[0];
				break;}		
			}
		}
	}
	cls;
	if(strcmpi(subj,sub[s])==0)
	{
	pos(cn.srWindow.Right/2-17,cn.srWindow.Top);
	SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY); 
	printf("Marks and Grade Predictor:");
	pos(cn.srWindow.Right/2-20,cn.srWindow.Top+1);
	printf("---------------------------------------");
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	printf("\n\nYour marks in %s are as follows:\n", subj);
	for(j=0;j<7;j++)
		{
			
			if(j<4)
			{
				if(n==1)
				
				{
				printf("%s Quizz %d = %d ",subj,j+1 ,po[j]);
				n++;}	
				
				else
				printf(" Quizz %d = %d ",j+1, po[j]);
				}
			if(j>=4 && j<6)
			{
				
				printf(" Sessional %d = %d  ",j-3, po[j]);
			}
			if(j==6)
			{
				
				printf(" Final= %d ", po[j]);
			
			}

         }
			if(po[0]!=0 && po[1]!=0 && po[4]!=0)
			{
				printf("\nThe Predictor is gathering Data...");
				sleep(1);
				printf("\nPlease Wait a couple of Seconds...");
				sleep(2);
				printf("\nAlmost Done...");
				sleep(1);
				prediction=100-(15-po[4])-(8-po[0]-po[1]-po[2]-po[3])-(15-po[4]);
				if(prediction>=92)
				strcpy(grade,"A+");
				else if(prediction>=86)
				strcpy(grade,"A");
				else if(prediction>=82)
				strcpy(grade,"A-");
				else if(prediction>=78)
				strcpy(grade,"B+");
				else if(prediction>=74)
				strcpy(grade,"B");
				else if(prediction>=70)
				strcpy(grade,"B-");
				else if(prediction>=64)
				strcpy(grade,"C");
				else if(prediction>=58)
				strcpy(grade,"D");
				else if(prediction>=50)
				strcpy(grade,"E");
				else if(prediction<50)
				strcpy(grade,"F");
				printf("\n\nWe predict that your marks in the finals if same pace is maintained will be :%d\nThat will Get you a grade of %s\n\nGood Luck!",prediction,grade);
			}
			else 
			{
				printf("\n\nERROR!NOT ENOUGHT DATA\n\nPrediction requires marks greater than 0 of at least 2 Quizzes and 1 Sessional");
				counterclose++;
			}
	}
	else
	{
		printf("Incorrect Input! No such Subject Code Exists!");
	}
}
int viewmarks(int bp ,struct student *is)
{ 	//1=roll no. 2=pointer to structure
	cls;
	char sub[5][4]={"PF",
					"IRS",
					"AP",
					"CAL",
					"ENG"};
    int i,j,b,z,s;
    int *po;
    char subj[400];
    printf("\n\nEnter the name of the subject you want to view marks of:\n");
	fflush(stdin);
	gets(subj);
	cls;
	for(z=0;z<5;z++)
	{
		if(strcmpi(subj,sub[z])==0)
		s=z;
	}
			switch(s)
			{
			case 0:
				{po=&is[bp].pf[0];
				break;}
			case 1:
				{po=&is[bp].irs[0];
				break;}
			case 2:
				{po=&is[bp].ap[0];
				break;}
			case 3:
				{po=&is[bp].cal[0];
				break;}
			case 4:
				{po=&is[bp].eng[0];
				break;}		
			}	
		
		if(strcmpi(subj,sub[s])==0)
		{
		int n=1;	int l=1; int m=1; int v=1; int t=1;
		SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
		pos(cn.srWindow.Right/2-15,cn.srWindow.Top+2);
		printf("Marks of %s for %s",sub[s], is[bp].name);
		printf("\n------------------------------------------------------------------------------------------------------------------------\n\n");
		printf("Quizzes\n");
		printf("-------\n");
		SetConsoleTextAttribute(getstd,cn.wAttributes); 
		printf("\tMarks of Quizz 1: %d\n\n\tMarks of Quizz 2: %d\n\n\tMarks of Quizz 3: %d\n\n\tMarks of Quizz 4: %d\n\n", po[0],po[1],po[2],po[3]);
		SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
		printf("Sessionals\n");
		printf("----------\n");
		SetConsoleTextAttribute(getstd,cn.wAttributes); 
		printf("\tMarks of Sessional 1: %d\n\n\tMarks of Sessional 2: %d\n\n", po[4],po[5]);
		SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
		printf("Final Exam\n");
		printf("----------\n");
		SetConsoleTextAttribute(getstd,cn.wAttributes);
		printf("\tMarks of Final Exam: %d\n\n", po[6]);
		SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
		printf("Grand Total\n");
		printf("-----------\n");
		SetConsoleTextAttribute(getstd,cn.wAttributes);
		sum=0;
		printf("\tThe Combined Marks in %s are: %d", sub[s],summ(po,0,sum));
		
		int no;
		char noi[500]; FILE *wq;
		printf("\n\nDid you find Any Errors and would like to notify the teacher?\n(1 for Yes / 2 For No) ");
		scanf("%d", &no);
		if(no==1)
		{
			printf("\n\nPlease Enter the errors for the teacher below: Inclusion of Date will aid the teacher!\nPress Enter for new line.Press Tab then Enter to send notification\n");
			scanf("%[^\t]s", noi);
			wq=fopen("notifmark.txt","w");
			fprintf(wq,"%d %d %s",s,bp,noi);
			fclose(wq);
			printf("\nNotification sent!");
		}
		}
		else
		{
			printf("Incorrect Input! No such Subject Code Exists!");
		}
}
