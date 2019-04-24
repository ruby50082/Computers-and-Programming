#include<stdio.h>
#include<stdlib.h>
#define max 50000
int main(int argc,char **argv)
{
	int i,left,right,a[max]={0};
	long long int temp=0,total=0;
	FILE *in;
	
	in = fopen(*(argv+1),"r");
	
	while(fscanf(in,"%d%d",&left,&right)!=EOF){
		a[left]++;
		a[right]--;
	}
	for(i=0;i<max;i++){
		temp+=a[i];
		total+=temp*(temp-1)/2;
	}
	
	printf("%lld",total);
	
	return 0;
}
