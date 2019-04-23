#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i,j,column,row,first_x,first_y,second_x,second_y,amount;
	char a[6];
	FILE *in,*out;
	
	printf("Please input the filename you want to open.\n");
	scanf("%s",a);
	getchar();
	if(strcmp(a,"route1")==0)
		in = fopen("route1.txt","r");
	if(strcmp(a,"route2")==0)
		in = fopen("route2.txt","r");
	if(strcmp(a,"route3")==0)
		in = fopen("route3.txt","r");
		
	out = fopen("path.txt","w");
	fscanf(in,"%d%d",&column,&row);
	fscanf(in,"%d%d",&first_x,&first_y);
	fscanf(in,"%d%d",&second_x,&second_y);
	fscanf(in,"%d",&amount);
	
	int maze[row+2][column+2];		//初始化 
	for(i=0;i<(row+2);i++){
		for(j=0;j<(column+2);j++){
			maze[i][j]=0;		// 0 = 普通路 
		}
	}
	for(i=0;i<(row+2);i++){
		maze[i][0]=-1;
		maze[i][column+1]=-1;	// -1 = 障礙 
	}
	for(j=0;j<(column+2);j++){
		maze[0][j]=-1;
		maze[row+1][j]=-1;
	}
	
	for(i=0;i<amount;i++){
		int obstacle_x,obstacle_y;
		fscanf(in,"%d%d",&obstacle_x,&obstacle_y);
		maze[obstacle_y+1][obstacle_x+1]=-1;
	}
	
	maze[first_y+1][first_x+1]=1;
	int num=1,bingo=0;
	while(1){
		for(i=1;i<(row+1);i++){
			for(j=1;j<(column+1);j++){
				if(maze[i][j]==num){
					if(i+1==second_y+1 && j == second_x+1)	bingo=1;
					if(i-1==second_y+1 && j == second_x+1)	bingo=1;
					if(i==second_y+1 && j+1 == second_x+1)	bingo=1;
					if(i==second_y+1 && j-1 == second_x+1)	bingo=1;
					
					if(maze[i+1][j]==0)	maze[i+1][j]=num+1;
					if(maze[i-1][j]==0)	maze[i-1][j]=num+1;
					if(maze[i][j+1]==0)	maze[i][j+1]=num+1;
					if(maze[i][j-1]==0)	maze[i][j-1]=num+1;
				}
				if(bingo==1)	break;
			}
			if(bingo==1)	break;
		}
		num++;
		if(bingo==1)	break;
	}
	fprintf(out,"%d\n",num-1);
	int y=second_y+1,x=second_x+1;
	for(i=num;i>1;i--){
		if(maze[y+1][x]==num-1){
			fprintf(out,"0 ");
			y++;
			num--;
			continue;
		}
		if(maze[y-1][x]==num-1){
			fprintf(out,"1 ");
			y--;
			num--;
			continue;
		}
		if(maze[y][x-1]==num-1){
			fprintf(out,"2 ");
			x--;
			num--;
			continue;
		}
		if(maze[y][x+1]==num-1){
			fprintf(out,"3 ");
			x++;
			num--;
		}
	}
	fprintf(out,"\n");
	return 0;
}
