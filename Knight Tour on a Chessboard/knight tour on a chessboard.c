#include<stdio.h>

int a[8][2]={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
int map[9][9]={0};
int num=2,flag=0;

void find (int x,int y);

int main(void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	map[x][y]=1;
	find(x,y);
	
	return 0;
 } 
 
 void find (int x,int y){
 	int i,j,xx,yy;
 	for(i=0;i<8;i++){
 		xx=x+a[i][0];
 		yy=y+a[i][1];
 		if(xx>8 || xx<1 || yy>8 || yy<1)	continue;
 		if(map[xx][yy]!=0)	continue;
 		map[xx][yy]=num++;
 		
 		if(num>64 && flag==0){
 			flag=1;
 			for(i=1;i<=8;i++){
	 			for(j=1;j<=8;j++){
	 				printf("%3d",map[i][j]);
				}
				 printf("\n");
			}
			 return;
		}
		if(num>64)	return;	
 		
		find(xx,yy);
 		map[xx][yy]=0;
 		num--;
	}
	return ;
 }
