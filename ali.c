#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "vars.h"
#define cls system("cls")
int summ(int *po,int n,int sum)
{
	if(n>=6)
	{
		return po[n];
	}
	else
	sum=po[n]+summ(po,n+1,sum);
	return sum;
}
void notifier(int teach)
{
	cls;
	struct student s[20];
	char notif1[100], notif2[100];
	int ha=0,ha1=0,*mem;
	mem=calloc(4,sizeof(int));
	FILE *f,*f1,*f2;
	f=fopen("master.dat", "rb+");
	fread(&s,sizeof(s),1,f);
	fclose(f);
	char codes[5][5]={
	"PF",
	"IRS",
	"AP",
	"CAL",
	"ENG"};
	f1=fopen("notifatten.txt","r");
	if(f1!=NULL)
	ha++;
	fscanf(f1,"%d %d %[^\t]s",&mem[0],&mem[1],notif1); //su, stu
	fclose(f1);
	f2=fopen("notifmark.txt","r");
	if(f2!=NULL)
	ha1++;
	fscanf(f2,"%d %d %[^\t]s",&mem[2],&mem[3],notif2); //su1, stu1
	fclose(f2);
	if(ha+ha1==0 || (strcmpi(codes[teach],codes[mem[0]])!=0 && strcmpi(codes[teach],codes[mem[3]])!=0) )
	{
		printf("\n\nNo Notifications Sent by Your Students!\nEverything is in Order!");
	}
	else
	{
		if(ha>0 && strcmp(codes[teach],codes[mem[0]])==0)
		{
			printf("\n\nNotification for Incorrect Attendance:\n\nSent by %s. Roll number %d\n\nMessage:\n%s", s[mem[1]].name,s[mem[1]].roll_no, notif1);
		}
		if(ha1>0 && strcmp(codes[teach],codes[mem[2]])==0)
		{
			printf("\n\nNotification for Incorrect Marks:\n\nSent by %s. Roll number %d\n\nMessage:\n%s", s[mem[3]].name,s[mem[3]].roll_no, notif2);
		}
		else
		printf("none\n");
	}
	
	
}

void attendance_student(int stud)
{
	cls;
	char codes[5][5]={
	"PF",
	"IRS",
	"AP",
	"CAL",
	"ENG"};
	int i,j=0,k,l,subj; float tot=0,pres=0,abs=0;
	FILE *f;
	int day,month,state;
	char code[5];
	struct student s[20];
	f=fopen("master.dat", "rb+");
	fread(s,sizeof(s),1,f);
	rewind(f);
	fclose(f);
	char *ptr,*pt;
	pt=&s[stud].pf_att[0][0];
	for(l=0;l<5;l++)
	{pres=0;
	abs=0;
	tot=0;
		for(k=0;k<6;k++)
		{
			for(i=0;i<20;i++,pt++)
			{
				if(*pt=='A')
				{abs++;
				tot++;}
				else if(*pt=='P')
				{pres++;
				tot++;}
				else
				tot++;
			}
		}
		if(l==0)
		{
		pos(cn.srWindow.Right/2-17,cn.srWindow.Top);
		SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY); 
		printf("Attendance Percentages of All Subjects:");
		pos(cn.srWindow.Right/2-17,cn.srWindow.Top+1);
		printf("---------------------------------------");
		SetConsoleTextAttribute(getstd,cn.wAttributes);}
		printf("\nTotal Classes Taken of %-3s are %0.0f out of %0.0f.\nPresent Percentage: %0.2f%%\n\n",codes[l],pres,abs+pres,(pres*100/(pres+abs)));
	}
		SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY); 
		printf("\b\b\n------------------------------------------------------------------------------------------------------------------------\n\n");
		SetConsoleTextAttribute(getstd,cn.wAttributes);
	printf("What Subject Would you like to view the Detailed Attendance of?\nEnter Subject Code: ");
	scanf("%s", code);
	for(i=0;i<5;i++)
	{		
		if(strcmpi(code,codes[i])==0)
		{
			subj=i;
			break;
		}
	}
	mont:
	printf("\nWhat month would you like to View the Attendance of?\n(1 to 6. 1 for August, 6 for January): ");
	scanf("%d", &month);
	if(month<1 || month>6)
	{
		printf("\nIncorrect Input! Please Try again\n");
		goto mont;
	}
	printf("\nLoading Attendance of Subject %s of Month %d", codes[subj],month);
	sleep(1);
	cls;
	switch(subj)
	{
		case 0:
			{ptr=&s[stud].pf_att[month][0];
			break;}
		case 1:
			{ptr=&(s[stud].irs_att[month][0]);
			break;}
		case 2:
			{ptr=&(s[stud].ap_att[month][0]);
			break;}
		case 3:
			{ptr=&(s[stud].cal_att[month][0]);
			break;}
		case 4:
			{ptr=&(s[stud].eng_att[month][0]);
			break;}	
	}
	printf("Your Attendance of %s of Month %d: \n", codes[subj],month);
	printf("\t_______________________________________");
	SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
	printf("\n\t|%-8s | %-11s | %-11s |\n","Lecture#","Date", "Attendance");
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	printf("\t|-------------------------------------|\n");
	for(i=0;i<20;i++,j++)
	{
		if(j%5==0)
		j=j+2;
		if(*ptr!='A' && *ptr!='P')
		{
			printf("\t|%-8d | %2d/%2d/%s  | %-11s |\n",  i,j,month+7,month<6?("2019"):("2020"),"Not Updated");
		}
		else
		{printf("\t|%-8d | %2d/%2d/%s  | %-11c |\n",  i,j,month+7,month<6?("2019"):("2020"),*ptr);}
		ptr++;
	}
	printf("\t---------------------------------------\n");
	int no;
	char noi[500]; FILE *wq;
	printf("\n\nDid you find Any Errors and would like to notify the teacher?\n(1 for Yes / 2 For No) ");
	scanf("%d", &no);
	if(no==1)
	{
		printf("\n\nPlease Enter the errors for the teacher below: Inclusion of Date will aid the teacher!\nPress Enter for new line.Press Tab then Enter to send notification\n");
		scanf("%[^\t]s", noi);
		wq=fopen("notifatten.txt","w");
		fprintf(wq,"%d %d %s",subj,stud,noi);
		fclose(wq);
		printf("\nNotification sent!");
	}
}

void attendance_teacher(int teach)
{
	cls;
	int i,j,k;
	FILE *f;
	int day,month,state;
	struct student s[20];
	char *ptr;
	pos(cn.srWindow.Right/3+7,cn.srWindow.Bottom/2-5);
	SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
	printf("Attendance Updation\n------------------------------------------------------------------------------------------------------------------------\n");
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	mont:
	printf("\nPlease Input what month you would like to update the attendance of\n(1 to 6. 1 for August, 6 for January): ");
	scanf("%d", &month);
	if(month<1 || month>7)
	{
		printf("\nIncorrect Input! Please Try again\n");
		goto mont;
	}
	da:
	printf("\nPlease Input what date you would like to update the attendance of(1 to 20): ");
	scanf("%d", &day);
	if(day<1 || day>20)
	{
		printf("\nIncorrect Input! Please Try again\n");
		goto da;
	}
	printf("\nLoading Attendance of Day %d of Month %d", day,month);
	sleep(1);
	cls;
	printf("\nFor Your Ease of Use, Would you like to set the default attendance state to Present or leave it to Absent?\n(1 for P / 2 for A) ");
	scanf("%d", &state);
	f=fopen("master.dat", "rb+");
	fread(s,sizeof(s),1,f);
	rewind(f);
	
	switch(teach)
	{
		case 0:
			{ptr=&s[0].pf_att[month][day];
			break;}
		case 1:
			{ptr=&(s[0].irs_att[month][day]);
			break;}
		case 2:
			{ptr=&(s[0].ap_att[month][day]);
			break;}
		case 3:
			{ptr=&(s[0].cal_att[month][day]);
			break;}
		case 4:
			{ptr=&(s[0].eng_att[month][day]);
			break;}
			
	}
	for(i=0;i<20;i++)
	{
//		printf("before: %c of %s\n", *ptr, s[i].name);
		*ptr = state==1?('P'):('A'); 
//		printf("after: %c of %s\n", *ptr, s[i].name);
		ptr=ptr+sizeof(s[0]);
	}
	printf("\nStart Entering Attendance of Each. A is for Absent and P is Present\nYou can press enter to keep it set at default mode\n\n");
	ptr=ptr-20*sizeof(s[0]);
	for(i=0;i<20;i++)
	{
		printf("%-15s : ", i==18?("Gen. Aladeen"):(s[i].name));
		fflush(stdin); 
		*ptr = getchar(); 
		if(*ptr=='a')
		*ptr='A';
		else if(*ptr=='p')
		*ptr='P';
		else if(*ptr!='A' && *ptr!='P')
		*ptr = state==1?('P'):('A');
		ptr=ptr+sizeof(s[0]);
	}
	ptr=ptr-20*sizeof(s[0]);
	cls;
	printf("New Attendance for all students: \n");
	printf("\t_______________________________________");
	SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
	printf("\n\t|%-5s | %-15s | %-10s |\n","Roll#","Name", "Attendance");
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	printf("\t|-------------------------------------|\n");
	for(i=0;i<20;i++)
	{
		printf("\t|%-5d | %-15s | %-10c |\n",  s[i].roll_no,i==18?("Gen. Aladeen"):(s[i].name),*ptr);
		ptr=ptr+sizeof(s[0]);
	}
	printf("\t---------------------------------------");
	ptr=ptr-20*sizeof(s[0]);
	fwrite(s,sizeof(s),1,f);
	fclose(f);	
}

void challan(int stud)
{
	cls;
	int i;
	FILE *f,*f2;
	struct student s[20];
	f=fopen("master.dat","rb+");
	fread(&s,sizeof(s),1,f);
	rewind(f);
	fclose(f);
	SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY); 
	printf("-------------------------------------------------------------------------------------------------------\n");
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	printf("|\t\t\t\"National University of Compters and Emerging Sceinces\"\n");
	printf("|\t\t\t\t\t'Fee Challan'\n|");
	printf("\n|\tName: %s\t\t\tRoll Number: %d\n|", s[stud].name, s[stud].roll_no);
	printf("\n|\tTuition Fees:  Rs 120,000\n|\tPoint Charges: Rs 20,000\n|\tMiscellanous:  Rs 4,532\n|\t--------------------------\n|\tTotal Fees:    Rs 144,532\n|");
	printf("\n|\n|\tPrinting Date: 2nd December 2019\t\t\t\tDue Date: 10th January 2019\n|");
	printf("\n|\tPay this Challan to the Nearest branch of Faysal Bank\n|");
	printf("\n|\t\t*This is a computer generated Receipt and requires no signature of any kind*\n");
	SetConsoleTextAttribute(getstd,FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("-------------------------------------------------------------------------------------------------------\n");
	for(i=cn.srWindow.Top+1;i<cn.srWindow.Top+18;i++)
	{
		pos(cn.srWindow.Left+102,i);
		printf("|");
	}
	SetConsoleTextAttribute(getstd,cn.wAttributes);
	f2=fopen("challan.txt","wb+");
	printf("\n\nA similar challan has been saved in the Working Directory in a file named Challan for ease of use of the user!");
	fprintf(f2,"-------------------------------------------------------------------------------------------------------\n");
	fprintf(f2,"|\t\t\t\"National University of Compters and Emerging Sceinces\"\n");
	fprintf(f2,"|\t\t\t\t\t'Fee Challan'\n|");
	fprintf(f2,"\n|\tName: %s\t\t\tRoll Number: %d\n|", s[stud].name, s[stud].roll_no);
	fprintf(f2,"\n|\tTuition Fees:  Rs 120,000\n|\tPoint Charges: Rs 20,000\n|\tMiscellanous:  Rs 4,532\n|\t--------------------------\n|\tTotal Fees:    Rs 144,532\n|");
	fprintf(f2,"\n|\n|\tPrinting Date: 2nd December 2019\t\t\t\tDue Date: 10th January 2019\n|");
	fprintf(f2,"\n|\tPay this Challan to the Nearest branch of Faysal Bank\n|");
	fprintf(f2,"\n|\t\t*This is a computer generated Receipt and requires no signature of any kind*\n");
	fprintf(f2,"-------------------------------------------------------------------------------------------------------\n");
	fclose(f2);
}
void best_worst(int teach)
{
	char codes[5][5]={
	"PF",
	"IRS",
	"AP",
	"CAL",
	"ENG"};
	struct student s[20],*ptr;
	int i,j,k,l,large,small,smalloc,largeloc,smalli,largei;
	FILE *f;
	f=fopen("master.dat", "rb");
	if(f==NULL)
	{
		printf("null\n");
	}
	fread(&s, sizeof(s), 1,f);
	rewind(f);
	fclose(f);
	cls;
	ptr=s;
	
	switch(teach)
	{
		case 0:
		{
			large=summ(s[0].pf,0,sum=0); small=summ(s[0].pf,0,sum=0);
			pos(cn.srWindow.Right/3-15,cn.srWindow.Bottom/2-5);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Mark Sheet of %s\n------------------------------------------------------------------------------------------------------------------------\n\n", codes[teach]);
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			printf("\t_______________________________________");
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("\n\t|%-5s | %-15s | %-11s |\n","Roll#","Name", "Total Marks");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			printf("\t|--------------------------------------|\n");
			for(i=0;i<20;i++)
			{
				printf("\t|%-5d | %-15s | %-11d |\n",  s[i].roll_no,i==18?("Gen. Aladeen"):(s[i].name),summ(s[i].pf,0,sum=0));
				if(large<=summ(s[i].pf,0,sum=0))
				{
					large=summ(s[i].pf,0,sum=0);
					largeloc=ptr->roll_no;
				}
				if(small>=summ(s[i].pf,0,sum=0))
				{
					small=summ(s[i].pf,0,sum=0);
					smalloc=ptr->roll_no;
				}
				ptr++;
			}
			printf("\t---------------------------------------\n\n");
			for(i=0;i<20;i++)
			{
				if(s[i].roll_no==largeloc)
				largei=i;
				if(s[i].roll_no==smalloc)
				smalli=i;
			}
			printf("large: %d\tsmall: %d", largei,smalli);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-5);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Best Performer of Your Class");
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-4);
			printf("----------------------------");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-3);
			printf("%d %s Marks: %d\n\n", s[largei].roll_no, s[largei].name, summ(s[largei].pf,0,sum=0));
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Worst Performer of Your Class");
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2+1);
			printf("-----------------------------");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2+2);
			printf("%d %s Marks: %d\n\n", s[smalli].roll_no, s[smalli].name, summ(s[smalli].pf,0,sum=0));
			pos(cn.srWindow.Left,cn.srWindow.Bottom);
			break;
		}
		case 1:
		{
			large=summ(s[0].irs,0,sum=0); small=summ(s[0].irs,0,sum=0);
			pos(cn.srWindow.Right/3-15,cn.srWindow.Bottom/2-5);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Mark Sheet of %s\n------------------------------------------------------------------------------------------------------------------------\n\n\n", codes[teach]);
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			printf("\t_______________________________________");
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("\n\t|%-5s | %-15s | %-11s|\n","Roll#","Name", " Total Marks");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			printf("\t|--------------------------------------|\n");
			for(i=0;i<20;i++)
			{
				printf("\t|%-5d | %-15s | %-11d |\n",  s[i].roll_no,i==18?("Gen. Aladeen"):(s[i].name),summ(s[i].irs,0,sum));
				if(large<=summ(s[i].irs,0,sum))
				{
					large=summ(s[i].irs,0,sum);
					largeloc=ptr->roll_no;
				}
				if(small>=summ(s[i].irs,0,sum))
				{
					small=summ(s[i].irs,0,sum);
					smalloc=ptr->roll_no;
				}
				ptr++;
			}
			printf("\t---------------------------------------");
			for(i=0;i<20;i++)
			{
				if(s[i].roll_no==largeloc)
				largei=i;
				if(s[i].roll_no==smalloc)
				smalli=i;
			}
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-5);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Best Performer of Your Class");
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-4);
			printf("----------------------------");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-3);
			printf("%d %s Marks: %d\n\n", s[largei].roll_no, s[largei].name, summ(s[largei].irs,0,sum));
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Worst Performer of Your Class");
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2+1);
			printf("-----------------------------");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2+2);
			printf("%d %s Marks: %d\n\n", s[smalli].roll_no, s[smalli].name, summ(s[smalli].irs,0,sum));
			pos(cn.srWindow.Left,cn.srWindow.Bottom);
			break;
		}
		case 2:
		{
			large=summ(s[0].ap,0,sum=0); small=summ(s[0].ap,0,sum=0);
			pos(cn.srWindow.Right/3-15,cn.srWindow.Bottom/2-5);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Mark Sheet of %s\n------------------------------------------------------------------------------------------------------------------------\n\n\n", codes[teach]);
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			printf("\t_______________________________________");
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("\n\t|%-5s | %-15s | %-11s|\n","Roll#","Name", " Total Marks");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			printf("\t|--------------------------------------|\n");
			for(i=0;i<20;i++)
			{
				printf("\t|%-5d | %-15s | %-11d |\n",  s[i].roll_no,i==18?("Gen. Aladeen"):(s[i].name),summ(s[i].ap,0,sum));
				if(large<=summ(s[i].ap,0,sum))
				{
					large=summ(s[i].ap,0,sum);
					largeloc=ptr->roll_no;
				}
				if(small>=summ(s[i].ap,0,sum))
				{
					small=summ(s[i].ap,0,sum);
					smalloc=ptr->roll_no;
				}
				ptr++;
			}
			printf("\t---------------------------------------");
			for(i=0;i<20;i++)
			{
				if(s[i].roll_no==largeloc)
				largei=i;
				if(s[i].roll_no==smalloc)
				smalli=i;
			}
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-5);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Best Performer of Your Class");
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-4);
			printf("----------------------------");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-3);
			printf("%d %s Marks: %d\n\n", s[largei].roll_no, s[largei].name, summ(s[largei].ap,0,sum));
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Worst Performer of Your Class");
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2+1);
			printf("-----------------------------");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2+2);
			printf("%d %s Marks: %d\n\n", s[smalli].roll_no, s[smalli].name, summ(s[smalli].ap,0,sum));
			pos(cn.srWindow.Left,cn.srWindow.Bottom);
			break;
		}
		case 3:
		{
			large=summ(s[0].cal,0,sum=0); small=summ(s[0].cal,0,sum=0);
			pos(cn.srWindow.Right/3-15,cn.srWindow.Bottom/2-5);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Mark Sheet of %s\n------------------------------------------------------------------------------------------------------------------------\n\n\n", codes[teach]);
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			printf("\t_______________________________________");
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("\n\t|%-5s | %-15s | %-11s|\n","Roll#","Name", " Total Marks");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			printf("\t|--------------------------------------|\n");
			for(i=0;i<20;i++)
			{
				printf("\t|%-5d | %-15s | %-11d |\n",  s[i].roll_no,i==18?("Gen. Aladeen"):(s[i].name),summ(s[i].cal,0,sum));
				if(large<=summ(s[i].cal,0,sum))
				{
					large=summ(s[i].cal,0,sum);
					largeloc=ptr->roll_no;
				}
				if(small>=summ(s[i].cal,0,sum))
				{
					small=summ(s[i].cal,0,sum);
					smalloc=ptr->roll_no;
				}
				ptr++;
			}
			printf("\t---------------------------------------");
			for(i=0;i<20;i++)
			{
				if(s[i].roll_no==largeloc)
				largei=i;
				if(s[i].roll_no==smalloc)
				smalli=i;
			}
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-5);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Best Performer of Your Class");
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-4);
			printf("----------------------------");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-3);
			printf("%d %s Marks: %d\n\n", s[largei].roll_no, s[largei].name, summ(s[largei].cal,0,sum));
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Worst Performer of Your Class");
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2+1);
			printf("-----------------------------");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2+2);
			printf("%d %s Marks: %d\n\n", s[smalli].roll_no, s[smalli].name, summ(s[smalli].cal,0,sum));
			pos(cn.srWindow.Left,cn.srWindow.Bottom);
			break;
		}
		case 4:
		{
			large=summ(s[0].eng,0,sum=0); small=summ(s[0].eng,0,sum=0);
			pos(cn.srWindow.Right/3-15,cn.srWindow.Bottom/2-5);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Mark Sheet of %s\n------------------------------------------------------------------------------------------------------------------------\n\n\n", codes[teach]);
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			printf("\t_______________________________________");
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("\n\t|%-5s | %-15s | %-11s|\n","Roll#","Name", " Total Marks");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			printf("\t|--------------------------------------|\n");
			for(i=0;i<20;i++)
			{
				printf("\t|%-5d | %-15s | %-11d |\n",  s[i].roll_no,i==18?("Gen. Aladeen"):(s[i].name),summ(s[i].eng,0,sum));
				if(large<=summ(s[i].eng,0,sum))
				{
					large=summ(s[i].eng,0,sum);
					largeloc=ptr->roll_no;
				}
				if(small>=summ(s[i].eng,0,sum))
				{
					small=summ(s[i].eng,0,sum);
					smalloc=ptr->roll_no;
				}
				ptr++;
			}
			printf("\t---------------------------------------");
			for(i=0;i<20;i++)
			{
				if(s[i].roll_no==largeloc)
				largei=i;
				if(s[i].roll_no==smalloc)
				smalli=i;
			}
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-5);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Best Performer of Your Class");
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-4);
			printf("----------------------------");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2-3);
			printf("%d %s Marks: %d\n\n", s[largei].roll_no, s[largei].name, summ(s[largei].eng,0,sum));
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2);
			SetConsoleTextAttribute(getstd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); 
			printf("Worst Performer of Your Class");
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2+1);
			printf("-----------------------------");
			SetConsoleTextAttribute(getstd,cn.wAttributes);
			pos(cn.srWindow.Right/2+5,cn.srWindow.Bottom/2+2);
			printf("%d %s Marks: %d\n\n", s[smalli].roll_no, s[smalli].name, summ(s[smalli].eng,0,sum));
			pos(cn.srWindow.Left,cn.srWindow.Bottom);
			break;
		}
	
	}
}
