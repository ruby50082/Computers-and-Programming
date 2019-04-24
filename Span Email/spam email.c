#include<stdio.h>
#include<string.h>
#define MAX_LEN 200
#define MAX_ROW 100

const double threshold=0.980132450331127;

int main(int argc, char **argv)
{
	int k,m,p,i,j,q=0,index=0;
	int print=0,judge=0;
	double weight[100];
	FILE *key,*email;
	char content [MAX_ROW][MAX_LEN];
	char keyword [MAX_ROW][MAX_LEN];
	
	for(m=1;m<argc;m++){									//找Keyword
		if(strcmp(*(argv+m),"-oc")==0)			print=1;
		if(strcmp(*(argv+m),"-spam")==0)		judge=1;                     
		if(strcmp(*(argv+m),"-k")==0){
			key = fopen(*(argv+(m+1)),"r");
			if(key == NULL)	printf("Error opening file\n");
			else{
				while(1){
					fscanf(key,"%lf",&weight[index]);		//index= keyword數量
					if(weight[index] == -999)	break;
					fscanf(key,"%s",&keyword[index]);
					index++;
				}		
			}
			fclose(key);
		}
	}
	
	for(m=1;m<argc;m++){
		if( *(*(argv+m))=='-' && *(*(argv+m)+1)=='e'){
			int mail_num=0,z;
			for(z=2;z<strlen(*(argv+m)) ;z++)	mail_num=mail_num*10+ *(*(argv+m)+z)-'0';
			
			for(z=1;z<=mail_num;z++){
				double num[100]={0},total=0;
				email = fopen(*(argv+(m+z)),"r");
				if(email == NULL)	printf("Error opening file\n");
				else{
					while( fgets (content[q],MAX_LEN-1,email) != NULL ){
						int begin=0, row_len=strlen(content[q]);      //strlen 表字串長度 
						for(i=0;i<row_len;i++){
							if(content[q][i]<'A'||content[q][i]>'z'||(content[q][i]>'Z'&&content[q][i]<'a')){		 
								int end=i-1,len=end-begin+1;          //len 內容字串有幾個字元 
								char cmp[len+1];
								for(j=0;j<len;j++){                   //找到非字母的字元後 往前擷取那一段放到字元陣列 
									cmp[j]=content[q][begin];
									begin++;
								}
								total++;
								for(k=0;k<index;k++){  				 //與Keyword比較            
									int key_len=strlen(keyword[k]), flag=0,z;
									if(key_len!=len)	continue;			
									for(z=0;z<len;z++){
										if(cmp[z]!=keyword[k][z] && cmp[z]+'a'-'A'!=keyword[k][z]){   // 逐一子母比對 
											flag=1;
											break;
										}
									} 
									if(flag==0)	num[k]++;
								}
								
								for(j=i+1;j<row_len;j++){             //找下一個起始點 
									if((content[q][j]>='A'&&content[q][j]<='Z')||(content[q][j]>='a'&&content[q][j]<='z')){
										begin=j;
										break;
									}
								}i=begin;
							}
						}
						q++;
					}
					fclose(email);
				}
				double swe=0;
				for(i=0;i<index;i++)		swe+=weight[i]*num[i]/total;
				//printf("%.15lf\n",swe);
				if(print==1&&judge==1){
					for(i=0;i<index;i++)	printf("%s %.0lf\n",keyword[i],num[i]);
					if(swe>threshold)		printf("This is a spam email.\n");
					else					printf("This is a normal email.\n");
				}
				else if(print==1)	for(i=0;i<index;i++)	printf("%s %.0lf\n",keyword[i],num[i]);
				else if(judge==1){
					if(swe>threshold)		printf("This is a spam email.\n");
					else					printf("This is a normal email.\n");
				}
				printf("\n\n\n");
			}
		}
	}
	return 0;
}
