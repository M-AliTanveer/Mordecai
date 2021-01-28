#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "vars.h"
#define cls system("cls")

void student_leave(int stud, int *count1)
{
	cls;
	struct student s[20];
	FILE *f;
	f=fopen("master.dat", "rb+");
	fread(&s,sizeof(s),1,f);
	fclose(f);
	int i;
	char codes[5][5]={
	"PF",
	"IRS",
	"AP",
	"CAL",
	"ENG"};
	
	char subjcode[5];
	int course,choie;

	FILE *lptr;
	char date1[20];
	char date2[20];
	char application[500];
	
	lptr=fopen("application.txt", "w+");
	if(lptr==NULL)
	{
		puts("File cannot be opened");
		exit(1);
	}
	if(count1[stud]>1)
	{
		printf("Status Update for your leave Applied Earlier:\nIt has been %s", count1[stud]==2?("Accepted"):("Rejected"));
	}
	printf("\n\n\t\t\t\t\t\tApplying for Leave\n");
	printf("Would You like to Apply for Leave?\n(1 for Yes / Other Number for No)  ");
	scanf("%d",&choie);
	if(choie==1)
	{
	printf("\nWhich course do you want to apply leave for?\n(PF,IRS,AP,CAL,ENG,) ");
	scanf("%s", subjcode);
	for(i=0;i<5;i++)
	{
		int compare;
		compare=strcmpi(subjcode,codes[i]);
		if(compare==0)

		{
			course=i;
			break;
		}
	}	
	printf("\nFrom which date you want a leave?\n(Format: DD/MM/YYYY) ");
	scanf("%s", &date1);
//	fwrite(&date1,sizeof(date1),1,lptr);
	
	printf("\nTo which date? \n(Format: DD/MM/YYYY) ");
	scanf("%s", &date2);
//	fwrite(&date2,sizeof(date2),1,lptr);
	
	printf("\nStart Writing your application: \n");
	
	printf("For adding new line press ENTER key. \nFor ending the Application press TAB key, then ENTER key.\n");
	scanf("%[^\t]s", &application);
	
	printf("\n%d  %s  \nYour Application for %s has been submitted!", s[stud].roll_no, s[stud].name, subjcode);
	
	fprintf(lptr,"%d %d %s %s %s",stud,course,date1,date2,application);

	fclose(lptr);
	count1[stud]=0;
	count1[stud]=count1[stud]+1;
	}
}
void teacher_leave(int teach,int *count1)
{
	cls;
	struct student s[20];
	FILE *f;
	f=fopen("master.dat", "rb+");
	fread(&s,sizeof(s),1,f);
	fclose(f);
	char date1[20];
	char date2[20];
	char application[500];
	int subj, stud,cho,option;
	char codes[5][5]={
	"PF",
	"IRS",
	"AP",
	"CAL",
	"ENG"};
	char subjcode[5];
	FILE *tp;
	
	tp=fopen("application.txt", "r+");
	fscanf(tp,"%d %d %s %s %[^\t]s",&stud,&subj,date1,date2,application);
	if(strcmpi(codes[teach],codes[subj])==0 && count1[stud]<2)
	{
	printf("\n%s with roll number %d has applied for Leave. Would you like to view it?\n(1 for Yes / Other Number for No) ", s[stud].name, s[stud].roll_no);
	scanf("%d", &cho);
	if(cho==1)
	{
	printf("\n\nFrom Date: %s to Date: %s\n\n%s",date1,date2,application);
		
	printf("\n\nDo you want to accept this leave application?\n(1 for Yes / Other Number for No) ");
	scanf("%d", &option);
	
	if(option==1)
	{
		count1[stud]++;
	}
	else
	count1[stud]=count1[stud]+2;
	}
	else
	{
		printf("Going back to Teacher Menu . . .");
		sleep(1);
	}
	}
	else
	printf("\n\nNo Application Submitted!");
}
