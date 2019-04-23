#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define swap(a,b){int t=a;a=b;b=t;}

void increase_sort(int x[],int n);
void decrease_sort(int x[],int n);

int main(void)
{
	srand(time(NULL));
	
	int x,y,num,total,i,target,check;
	char c,filename[10];
	FILE *in,*out;
	
	printf("Please select the way to read a set of integers.\n");
	printf("1: random numbers; 2: read integers from a text file.\n");
	scanf("%d",&x);

	if(x==1){
		printf("How many number of integers do you want to input?\n");
		scanf("%d",&num);
		int a[num];
		for(i=0;i<num;i++){
			a[i]=rand()%10000;
		}
		while(1){
			getchar();
			printf("Specify the operation you want to do.\n");
			printf("i: print integers in increasing order;\n");
			printf("d: print integers in decreasing order.\n");
			printf("b: perform a binary search.\n");
			printf("q: Quit the program.\n");
			scanf("%c",&c);
			if(c=='q')	break;
			else if(c=='i'){
				check=1;
				increase_sort(a,num);
				for(i=0;i<num;i++)	printf("%d ",a[i]);
				printf("\n");
			}	
			else if(c=='d'){
				check=2;
				decrease_sort(a,num);
				for(i=0;i<num;i++)	printf("%d ",a[i]);
				printf("\n");
			}
			else if(c=='b'){
				printf("Input an integer for search:");
				scanf("%d",&target);
				int left=0,right=num-1;
				if(check==1){
					while(left<=right){
						int m=(left+right)/2;
						if(target==a[m]){
							printf("The number %d is in array[%d]\n",target,m);
							break;
						} 
						if(target>a[m]) left=m+1;
						if(target<a[m]) right=m;
					}
				}
				if(check==2){
					while(left<=right){
						int m=(left+right)/2;
						if(target==a[m]){
							printf("The number %d is in array[%d]\n",target,m);
							break;
						} 
						if(target>a[m]) right=m;
						if(target<a[m]) left=m+1;
					}
				}				
				if(left>right)	printf("The number %d is not in the integer list.\n",target);
			}
			else	printf("Input error!\n");
		}
	}
	else if(x==2){
		printf("Please specify the filename you want to open and read.\n");
		scanf("%s",&filename);
		if(strcmp(filename,"Set0")==0){
			if((in =fopen("Set0.txt","r")) == NULL){
				printf("Input file does not exist!\n");
				return 0;}
		}
		if(strcmp(filename,"Set1")==0){
			if((in =fopen("Set1.txt","r")) == NULL){
				printf("Input file does not exist!\n");
				return 0;}
		}
		if(strcmp(filename,"Set2")==0){
			if((in =fopen("Set2.txt","r")) == NULL){
				printf("Input file does not exist!\n");
				return 0;}
		}
		if(strcmp(filename,"Set3")==0){
			if((in =fopen("Set3.txt","r")) == NULL){
				printf("Input file does not exist!\n");
				return 0;}
		}
		if(strcmp(filename,"Set4")==0){
			if((in =fopen("Set4.txt","r")) == NULL){
				printf("Input file does not exist!\n");
				return 0;}
		}
		if(strcmp(filename,"Set5")==0){
			if((in =fopen("Set5.txt","r")) == NULL){
				printf("Input file does not exist!\n");
				return 0;}
		}
		fscanf(in,"%d",&total);
		int b[total];
		for(i=0;i<total;i++)	fscanf(in,"%d",&b[i]);
		
		printf("All integers in file %s have been read.\n",filename);
		if((out=fopen("output.txt","w"))==NULL){
			printf("does not exist\n");
			return 0;
		}
		while(1){
			getchar();
			printf("Specify the operation you want to do.\n");
			printf("i: print integers in increasing order;\n");
			printf("d: print integers in decreasing order.\n");
			printf("b: perform a binary search.\n");
			printf("q: Quit the program.\n");
			scanf("%c",&c);
			if(c=='q')	break;
			else if(c=='i'){
				increase_sort(b,total);
				check=1;
				for(i=0;i<total;i++)	fprintf(out,"%d ",b[i]);
				fprintf(out,"\n");
			}	
			else if(c=='d'){
				decrease_sort(b,total);
				check=2;
				for(i=0;i<total;i++)	fprintf(out,"%d ",b[i]);
				fprintf(out,"\n");
			}	
			else if(c=='b'){
				printf("Input an integer for search:");
				scanf("%d",&target);
				int left=0,right=total-1;
				if(check==1){
					while(left<=right){
						int m=(left+right)/2;
						if(target==b[m]){
							printf("The number %d is in array[%d]\n",target,m);
							break;
						} 
						if(target>b[m]) left=m+1;
						if(target<b[m]) right=m;
					}
				}
				if(check==2){
					while(left<=right){
						int m=(left+right)/2;
						if(target==b[m]){
							printf("The number %d is in array[%d]\n",target,m);
							break;
						} 
						if(target>b[m]) right=m;
						if(target<b[m]) left=m+1;
					}
				}				
				if(left>right)	printf("The number %d is not in the integer list.\n",target);
			}
			else	printf("Input error!\n");
		}	
 	}
}
void increase_sort(int x[],int n){
	int i,j;
	for(i=n-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(x[j]>x[j+1]) swap(x[j],x[j+1]);
		}	
	}
}
void decrease_sort(int x[],int n){
	int i,j;
	for(i=0;i<=n-1;i++){
		for(j=n-1;j>i;j--){
			if(x[j-1]<x[j]) swap(x[j-1],x[j]);
		}	
	}
}
