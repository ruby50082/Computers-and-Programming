#include<stdio.h>
int main(void)
{
	int i,j,k,m,w_money,c_money,d,n;
	int c[41];
	
	scanf("%d",&m);		// m=幾筆資料 

	for(i=1;i<=m;i++){		// 跑m筆資料 
		w_money=0;
		c_money=0;
		scanf("%d",&n);	// n=幾天 
		w_money=12000*n;
		c[1]=1;
		c[2]=1;
		for(j=3;j<=n;j++){
			c[j]=c[j-1]+c[j-2];
		}
		for(j=1;j<=n;j++){
			c_money+=c[j];
		}
		if(w_money > c_money)	printf("w\n");
		else if(w_money < c_money)	printf("c\n");
		else	printf("e\n");
	}
	return 0;
}
