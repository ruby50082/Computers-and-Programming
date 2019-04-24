#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 1000000

typedef struct 
{
	int left;
	int right;
}Line;
Line line[max];


int main(int argc,char **argv)
{
	long long int i,j,index=0,len=0,t;
	FILE *in;
	clock_t start,finish;
	double duration,duration1,duration2;
	
	in = fopen(*(argv+1),"r");
	start = clock();
		
	while(fscanf(in,"%d%d",&line[index].left,&line[index].right)!=EOF){
		index++;
	}
	
	for(i=0;i<index;i++){
		for(j=i+1;j<index;j++){
			if(line[i].left<=line[j].left && line[i].right>line[j].left && line[i].right<=line[j].right){
				len += line[i].right-line[j].left;
			}
			else if(line[i].left<=line[j].left && line[i].right>=line[j].right){
				len += line[j].right-line[j].left;
			}
			else if(line[j].left<=line[i].left && line[j].right>line[i].left && line[j].right<=line[i].right){
				len += line[j].right-line[i].left;
			}
			else if(line[j].left<=line[i].left && line[j].right>=line[i].right){
				len += line[i].right-line[i].left;
			}
		}
		
	}
	printf("%lld\n",len);
	finish = clock();
	duration = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("T3 %lf seconds\n",duration);
	
	
	start = clock();
	
	for(i=0;i<index;i++){
		for(j=index-1;j>i;j--){
			if(line[j].left<line[j-1].left){
				t=line[j].left; line[j].left=line[j-1].left; line[j-1].left=t;
				t=line[j].right; line[j].right=line[j-1].right; line[j-1].right=t;
			}
		}
	}
	finish = clock();
	duration1 = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("T1 %lf seconds\n",duration1);
	
	start = clock();
	len=0;
	for(i=0;i<index;i++){
		int k=i+1;
		while(k<index && line[i].right>line[k].left){
			len+=line[i].right-line[k].left;
			k++;
		}
	}
	finish = clock();
	duration2 = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("T2 %lf seconds\n",duration2);
	
	if(duration2>duration)	printf("T2>T3\n");
	if(duration2<duration)	printf("T2<T3\n");
	if(duration2==duration)	printf("T2=T3\n");
	
	if(duration1+duration2>duration)	printf("T1+T2>T3\n");
	if(duration1+duration2<duration)	printf("T1+T2<T3\n");
	if(duration1+duration2==duration)	printf("T1+T2=T3\n");
	
	system("pause");
	return 0;
}
