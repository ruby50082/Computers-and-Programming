#include <stdio.h>
int F(int n)
{
 	if(n<=2) return 1;
	else return F(n-1)+F(n-2);
}

int main(void)
{
	int i,j,m,n,w_money,c_money;
	
	scanf("%d",&m);		//m=幾筆資料 
	for(i=0;i<m;i++){
		c_money=0;
		w_money=0;
		scanf("%d",&n);	//n=幾天 
		for(j=1;j<=n;j++){
			c_money=c_money+F(j);
		}
		w_money=12000*n;
		if(w_money > c_money)	printf("w\n");
		else if(w_money < c_money)	printf("c\n");
		else printf("e\n");
	}
	
	return 0;
}
