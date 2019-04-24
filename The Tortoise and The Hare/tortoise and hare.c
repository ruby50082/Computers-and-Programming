#include<stdio.h>
#include<windows.h>
#include<time.h>

int main(void){
	int i,j,t_sit=1,h_sit=1,index,set=0,set2=0,flag=0;
	int a[61];
	srand(time(NULL));
	
	while(1){
		printf("BANG!!! AND THEY'RE OFF!!!!!\n");
		for(i=1;i<=25;i++)	printf("%3d",i);
		printf("\n");
		for(i=1;i<=60;i++){
			int terr = rand()%10;
			if(terr>=0 && terr<=1)	a[i]=1;		//river
			if(terr>=2 && terr<=3)	a[i]=2;		//forest
			if(terr>=4 && terr<=9)	a[i]=3;		//slope
		}
		for(i=1;i<=25;i++){
			if(a[i]==1)	printf("  R");
			if(a[i]==2)	printf("  F");
			if(a[i]==3)	printf("  S");
		}
		printf("\n");
		printf("  T\n");
		printf("  H\n");
		
		system("pause"); 
		system("cls");
		 
		
		while(1){
			
			int t_move = rand()%10;
			int h_move = rand()%10;	
			
			if(a[t_sit]==1){
				printf("Tortoise Fast plod\n");
				t_sit+=3;
				if(t_sit>60)	t_sit=60;
			}
			else{
				if(t_move>=0 && t_move<=4){				//烏龜走路方式 
					printf("Tortoise Fast plod\n");
					t_sit+=3;
					if(t_sit>60)	t_sit=60;}
				if(t_move>=5 && t_move<=6){
					printf("Tortoise Slip\n");
					t_sit-=6;
					if(t_sit<1)	t_sit=1;}
				if(t_move>=7 && t_move<=9){
					printf("Tortoise Slow plod\n");
					t_sit+=1;
					if(t_sit>60)	t_sit=60;}
			}

			if(a[h_sit]==2 && flag==0){					//兔子走路方式
				printf("Hare Sleep\n");
				h_sit=h_sit;
				
				flag=1;
				set=0;
			}
			else if(set==2){
				printf("Hare Sleep\n");
				h_sit=h_sit;
				flag=0;
				set=0;
			}
			else if(t_sit==h_sit){
				printf("Hurt!!!\n");
				h_sit=h_sit;
				flag=0;
				set=0;
			}
			else{
				flag=0;
				if(h_move>=0 && h_move<=1){				 
					printf("Hare Sleep\n");
					set=0;
					h_sit=h_sit;}
				if(h_move>=2 && h_move<=3){
					printf("Hare Big hop\n");
					h_sit+=9;
					set=0;
					if(h_sit>60)	h_sit=60;}
				if(h_move==4){
					printf("Hare Big Slip\n");
					h_sit-=12;
					set=0;
					if(h_sit<1)	h_sit=1;}
				if(h_move>=5 && h_move<=7){
					printf("Hare Small hop\n");
					h_sit+=1;
					set++;
					if(h_sit>60)	h_sit=60;}
				if(h_move>=8 && h_move<=9){
					printf("Hare Small Slip\n");
					h_sit-=2;
					set=0;
					if(h_sit<1)	h_sit=1;}	
			}
			
			if(t_sit==h_sit){							//各種功能 
				printf("\nOUCH!!!\n\n");
			}
			if(h_sit==60 && t_sit==60){
				printf("\nIt's a tie.\n\n");
			}
			else if(h_sit==60){
				printf("\nHare wins. Yuch.\n\n");
			}
			else if(t_sit==60){
				printf("\nTORTOISE WINS!!! YAY!!!\n\n");
			}
			if(t_sit<=25 && h_sit<=25){					//龜兔都在25格以內 
				for(i=1;i<=25;i++){
					printf("%3d",i);
				}
				printf("\n");
				for(i=1;i<=25;i++){
					if(a[i]==1)	printf("  R");
					if(a[i]==2)	printf("  F");
					if(a[i]==3)	printf("  S");
				}
				printf("\n");
				for(i=1;i<=25;i++){
					if(t_sit==i){
						for(j=1;j<=(3*i-3);j++)	printf(" ");
						printf("  T\n");
					}
				}
				for(i=1;i<=25;i++){
					if(h_sit==i){
						for(j=1;j<=(3*i-3);j++)	printf(" ");
						printf("  H\n");
					}
				}
			} 
			else{										//龜兔至少一者超過第25格 
				if(h_sit-t_sit>=0 && h_sit-t_sit<25){
					if(t_sit+24<=60){
						for(i=t_sit;i<t_sit+25;i++)	printf("%3d",i);
						printf("\n");
						for(i=t_sit;i<t_sit+25;i++){
							if(a[i]==1)	printf("  R");
							if(a[i]==2)	printf("  F");
							if(a[i]==3)	printf("  S");
						}
					}
					else{
						for(i=t_sit;i<=60;i++)	printf("%3d",i);
						printf("\n");
						for(i=t_sit;i<=60;i++){
							if(a[i]==1)	printf("  R");
							if(a[i]==2)	printf("  F");
							if(a[i]==3)	printf("  S");
						}
					}
					printf("\n");
					printf("  T\n");
					for(i=26;i<=60;i++){
						if(h_sit==i){
							for(j=1;j<=(3*h_sit-3*t_sit);j++)	printf(" ");
							printf("  H\n");
						}
					}
				}
				else if(h_sit-t_sit>=25 && h_sit-t_sit<50){
					for(i=t_sit;i<t_sit+25;i++)	printf("%3d",i);
					printf("\n");
					for(i=t_sit;i<t_sit+25;i++){
						if(a[i]==1)	printf("  R");
						if(a[i]==2)	printf("  F");
						if(a[i]==3)	printf("  S");
					}
					printf("\n");
					printf("  T\n");
					if(t_sit+49<=60){
						for(i=t_sit+25;i<t_sit+50;i++)	printf("%3d",i);
						printf("\n");
						for(i=t_sit+25;i<t_sit+50;i++){
							if(a[i]==1)	printf("  R");
							if(a[i]==2)	printf("  F");
							if(a[i]==3)	printf("  S");
						}
					}
					else{
						for(i=t_sit+25;i<=60;i++)	printf("%3d",i);
						printf("\n");
						for(i=t_sit+25;i<=60;i++){
							if(a[i]==1)	printf("  R");
							if(a[i]==2)	printf("  F");
							if(a[i]==3)	printf("  S");
						}
					}
					printf("\n");
					for(i=26;i<=60;i++){
						if(h_sit==i){
							for(j=1;j<=(3*h_sit-3*t_sit-3*25);j++)	printf(" ");
							printf("  H\n");
						}
					}
				}
				else if(h_sit-t_sit>=50 && h_sit-t_sit<=60){
					for(i=t_sit;i<t_sit+25;i++)	printf("%3d",i);
					printf("\n");
					for(i=t_sit;i<t_sit+25;i++){
						if(a[i]==1)	printf("  R");
						if(a[i]==2)	printf("  F");
						if(a[i]==3)	printf("  S");
					}
					printf("\n");
					printf("  T\n");
					for(i=t_sit+25;i<t_sit+50;i++)	printf("%3d",i);
					printf("\n");
					for(i=t_sit+25;i<t_sit+50;i++){
						if(a[i]==1)	printf("  R");
						if(a[i]==2)	printf("  F");
						if(a[i]==3)	printf("  S");
					}
					printf("\n");
					for(i=t_sit+50;i<=60;i++)	printf("%3d",i);
					printf("\n");
					for(i=t_sit+50;i<=60;i++){
						if(a[i]==1)	printf("  R");
						if(a[i]==2)	printf("  F");
						if(a[i]==3)	printf("  S");
					}
					printf("\n");
					for(i=26;i<=60;i++){
						if(h_sit==i){
							for(j=1;j<=(3*h_sit-3*t_sit-3*50);j++)	printf(" ");
							printf("  H\n");
						}
					}
				}
				else if(t_sit-h_sit>0 && t_sit-h_sit<25){
						if(h_sit+24<=60){
							for(i=h_sit;i<h_sit+25;i++)	printf("%3d",i);
							printf("\n");
							for(i=h_sit;i<h_sit+25;i++){
								if(a[i]==1)	printf("  R");
								if(a[i]==2)	printf("  F");
								if(a[i]==3)	printf("  S");
							}
						}
						else{
							for(i=h_sit;i<=60;i++)	printf("%3d",i);
							printf("\n");
							for(i=h_sit;i<=60;i++){
								if(a[i]==1)	printf("  R");
								if(a[i]==2)	printf("  F");
								if(a[i]==3)	printf("  S");
							}
						}
					printf("\n");
					printf("  H\n");
					for(i=26;i<=60;i++){
						if(t_sit==i){
							for(j=1;j<=(3*t_sit-3*h_sit);j++)	printf(" ");
							printf("  T\n");
						}
					}
				}
				else if(t_sit-h_sit>=25 && t_sit-h_sit<50){
					for(i=h_sit;i<h_sit+25;i++)	printf("%3d",i);
					printf("\n");
					for(i=h_sit;i<h_sit+25;i++){
						if(a[i]==1)	printf("  R");
						if(a[i]==2)	printf("  F");
						if(a[i]==3)	printf("  S");
					}
					printf("\n");
					printf("  H\n");
					if(h_sit+49<=60){
						for(i=h_sit+25;i<h_sit+50;i++)	printf("%3d",i);
						printf("\n");
						for(i=h_sit+25;i<h_sit+50;i++){
							if(a[i]==1)	printf("  R");
							if(a[i]==2)	printf("  F");
							if(a[i]==3)	printf("  S");
						}
					}
					else{
						for(i=h_sit+25;i<=60;i++)	printf("%3d",i);
						printf("\n");
						for(i=h_sit+25;i<=60;i++){
							if(a[i]==1)	printf("  R");
							if(a[i]==2)	printf("  F");
							if(a[i]==3)	printf("  S");
						}
					}
					printf("\n");
					for(i=26;i<=60;i++){
						if(t_sit==i){
							for(j=1;j<=(3*t_sit-3*h_sit-3*25);j++)	printf(" ");
							printf("  T\n");
						}
					}
				}
				else if(t_sit-h_sit>=50 && t_sit-h_sit<=60){
					for(i=h_sit;i<h_sit+25;i++)	printf("%3d",i);
					printf("\n");
					for(i=h_sit;i<h_sit+25;i++){
						if(a[i]==1)	printf("  R");
						if(a[i]==2)	printf("  F");
						if(a[i]==3)	printf("  S");
					}
					printf("\n");
					printf("  H\n");
					for(i=h_sit+25;i<h_sit+50;i++)	printf("%3d",i);
					printf("\n");
					for(i=h_sit+25;i<h_sit+50;i++){
						if(a[i]==1)	printf("  R");
						if(a[i]==2)	printf("  F");
						if(a[i]==3)	printf("  S");
					}
					printf("\n");
					for(i=h_sit+50;i<=60;i++)	printf("%3d",i);
					printf("\n");
					for(i=h_sit+50;i<=60;i++){
						if(a[i]==1)	printf("  R");
						if(a[i]==2)	printf("  F");
						if(a[i]==3)	printf("  S");
					}
					printf("\n");
					for(i=26;i<=60;i++){
						if(t_sit==i){
							for(j=1;j<=(3*t_sit-3*h_sit-3*50);j++)	printf(" ");
							printf("  T\n");
						}
					}
				}
			}
			if(h_sit==60 || t_sit==60)	break;		
		
			system("pause");
			system("cls");

		}
		if(h_sit==60 || t_sit==60)	break;
	}
}
