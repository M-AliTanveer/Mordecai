#ifndef WINDOWS_H
#define WINDOWS_H
#include <windows.h>
#endif
extern CONSOLE_SCREEN_BUFFER_INFO cn; //global structure variable. CONSOLE_SCREEN_BUFFER_INFO saves different data about console screen like length, size etc.
extern INPUT_RECORD mouse[2]; extern DWORD records; //INPUT_RECORD is a structure that holds attributes of different input types.
extern int count,sum;
#ifndef struc 
#define struc 
struct student{
	char name[400];
	int roll_no;
	int pf[7];
	int irs[7];							
	int ap[7];							
	int cal[7];
	int eng[7];
	char  pf_att[6][20];
	char  irs_att[6][20];
	char  ap_att[6][20];
	char  cal_att[6][20];
	char  eng_att[6][20];	
};
#endif
