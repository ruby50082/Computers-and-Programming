#include<stdio.h>
#include<stdlib.h> 
#include<windows.h>

int main(void)
{
	HANDLE hOut; 
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int month,year,i,j,k,week,before;
	char c;
	int a[3000]={0};
	for(i=0;i<3000;i+=4){
			if( (i%4==0 && i%100!=0) || i%400==0 ){
				a[i]=1;	
			} 
	}
	
	int day=0;
	int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE ); 
	printf("Please input the month and year of the calendar you want to print.\n");
	printf("Month: ");
	scanf("%d",&month);
	printf("\nYear: ");
	scanf("%d",&year);
	
	printf("\n\n");
	printf("%2d/%4d\n",month,year);
	SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_INTENSITY); 
	printf("   Sun");
	SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE ); 
	printf("   Mon   Tue   Wed   Thu   Fri");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_INTENSITY); 
	printf("   Sat\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE ); 
	
	if(a[year]==1)	days[2]=29;
	else			days[2]=28;	
	if(year<2016){
		for(i=year+1;i<2016;i++){
			day=day%7+365+a[i];	
		}
		for(j=month;j<=12;j++){
			day=day%7+days[j];
		}
		
		week=5-(day%7);
		if(week==-1) week=6;
		for(k=0;k<week;k++){
			if(month==1) days[month-1]=31;
			before=days[month-1]-week+k+1;			
			SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY); 	
			if(k==0){
				SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY );
			}
			printf("%6d",before);
			
		}
		for(k=1;k<=days[month];k++){
			if((k+week)%7 == 1 ||(k+week)%7 == 0){
				SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY );
			}
			else{
				SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
			}
			printf("%6d",k); 
			if((k+week)%7 == 0) printf("\n");
		}
		if( (days[month]+week) %7 != 0){
			for(k=1; k <= ( 7-( (days[month]+week)%7 ) ) ;k++){
				if(k==( 7-( (days[month]+week)%7 ))){
					SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY );
				}
				else{
						SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY); 
				}
					printf("%6d",k);
					
			}
		}
		SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE ); 			
	}
	else{
		for(i=2016;i<year;i++){
			day=day%7+365+a[i];
		}
		for(j=1;j<month;j++){
			day=day%7+days[j];
		}
		
		week=((day%7)+5)%7;
		for(k=0;k<week;k++){
			if(month==1) days[month-1]=31;
			before=days[month-1]-week+k+1;
			SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY); 	
			if(k==0){
				SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY );
			}
			printf("%6d",before);
		}
		for(k=1;k<=days[month];k++){
			printf("%6d",k);
			if((k+week)%7 == 6 ||(k+week)%7 == 0){
				SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY );
			}
			else{
				SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
			}
			if((k+week)%7==0) printf("\n");
		}
		if((days[month]+week)%7 != 0 ){
			for(k=1;k<=(7-((days[month]+week)%7));k++){
				if(k==( 7-( (days[month]+week)%7 ))){
					SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY );
				}
				else{
						SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY); 
				}
				printf("%6d",k);	
			}
		}
		SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE ); 	
	}

		
}

		
