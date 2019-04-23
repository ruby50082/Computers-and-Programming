#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main(void)
{
	int ans[10],pos[10];
	int i,j,num,y;
	char str[100],c,x,ch;
	
	time_t now;
	time(&now);
	printf("Now time is %s\n",asctime(localtime(&now)));

	
	while(1){
		srand(time(NULL));
		int count=0,total=0;
		for(i=0;i<=9;i++)	ans[i]=-1;      // pos[n]=0  represent n is not in the answer
		while(count<4){
			num=rand()%10;
			if(ans[num]!=-1)
				continue;
			ans[num]=count++;		
		}
		
		printf("\nPlease input a 4-digit integer. Four digits must be four different numbers.\n");
		while(1){
			int flag=0,a=0,b=0;
			printf("Your 4-digit number: ");
			for(i=0;;i++){
				scanf("%c",&str[i]);
				if(str[i]=='\n'){
					break;
				}
			}
			if(str[0]<'0' || str[0]>'9'){
				printf("Your input does not begin with a numerical character\n");
				printf("Press Enter to continue!\n");
				scanf("%c",&ch);
				continue;
			}
			for(i=1;i<100;i++){
				if(str[i]=='\n')	break;
				if(str[i]<'0' || str[i]>'9'){
					printf("Your input has non-numerical characters.\n");
					printf("You have to input a 4-digit number.\n");
					printf("Press Enter to continue!\n");
					scanf("%c",&ch);
					flag=1;
					break;
				}
			}
			if(flag==1)	continue;
			if( strlen(str)>5 || strlen(str)<=4 ){
				printf("You have to input a 4-digit number.\n");
				printf("Press Enter to continue!\n");
				scanf("%c",&ch);
				continue;
			}
			printf("Your input number is ");
			
			for(i=0;i<4;i++){
				printf("%c",str[i]);
			}
			printf(".");	
			
			for(i=0;i<=9;i++)	pos[i]=-1;		
			for(i=0;i<4;i++){					
				if(pos[ str[i]-'0']!=-1){
					printf("Digits of the input number are the same. Retry again!\n");
					printf("Press Enter to continue!\n");
					scanf("%c",&ch);
					flag=1;
					break;
				}
				pos[ str[i]-'0'] = i;
				if(ans[ str[i]-'0']==i) a++;
				else if(ans[ str[i]-'0']!=-1) b++;
			}
			if(flag==1)	continue;
			total++;
			if(a==4){
				printf("\nCongratulations! After %d trials, you got the right number!\n",total);
				printf("Do you want to play again? (y/n)");
				scanf("%c%c",&c,&ch);
				break;
			}
			else{
				printf("    You got %dA%dB.\n",a,b);
				continue;
			}
		}
		if(c=='n')	break;		
	}
}

	

