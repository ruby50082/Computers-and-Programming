#include<stdio.h>

int main(void)
{
	int i,m,n,amount,a,b,c,d;
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&n);
		a=n/50;
		b=(n-(a*50))/10;
		c=(n-(a*50)-(b*10))/5;
		d=n-(a*50)-(b*10)-(c*5);
		amount =a+b+c+d;
		printf("You have to pay %d dollars.\n",amount);
		printf("%d fifty-dollar coin(s),%d ten-dollar coin(s),%d five-dollar coin(s),and %d one-dollar(s).\n",a,b,c,d);	
	}
	return 0;
}
