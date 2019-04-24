#include<stdio.h>
#include<stdlib.h>
#define max 180001

typedef struct{
	int id,x,y1,y2;
}Line;
Line line[max],temp;

typedef struct{
	int y1[max];
	int y2[max];
}Cut;
Cut cut;
int cmp[max];
int right_line[max];

int main()
{
	int i,j,index=0,k,p;
	char filename[30];
	FILE *in,*out;
	
	printf("Please input the filename you want to open:\n");
	scanf("%s",filename);
	in = fopen(filename,"r");
	out = fopen("vLine.out.txt","w");
	
	while(fscanf(in,"%d%d%d%d",&line[index].id,&line[index].x,&line[index].y1,&line[index].y2)!=EOF){
		index++;
	}
	fclose(in);
	
	for(i=0;i<index;i++) for(j=index-1;j>i;j--){       //bubble_sort
		if(line[j].x<line[j-1].x){
			temp=line[j];  line[j]=line[j-1];   line[j-1]=temp;
		}
		if(line[j].x==line[j-1].x){
			if(line[j].y1<line[j-1].y1){
				temp=line[j]; line[j]=line[j-1]; line[j-1]=temp;
			}
		}
	}	
	for(i=0;i<index;i++)	cmp[line[i].id]=i;    //記錄id 對應到的 i值 
	
	for(p=1;p<=index;p++){				// p 是id                       
		fprintf(out,"%d ",p);
		i=cmp[p];
		cut.y1[0]=line[i].y1;
		cut.y2[0]=line[i].y2;
		int k_max=1,num=0,q,tt;
		for(j=i+1;j<index;j++){
			int flag=0;                   //flag 記錄是否輸出過 
			for(k=0; k<k_max; k++){
				if(cut.y1[k]==-1 && cut.y2[k]==-1)	continue;    //  -1表已被刪除 
				if(cut.y1[k]>=line[j].y2 || cut.y2[k]<=line[j].y1)	continue;  //排除只有頂點重複或零交集 
				
				if(flag==0)	right_line[num++] = line[j].id;
				flag=1;
				if(cut.y1[k]>=line[j].y1 && cut.y2[k]<=line[j].y2){	
					cut.y1[k] = cut.y2[k] = -1;   
				}
				else if(cut.y2[k]<=line[j].y2 && cut.y2[k]>=line[j].y1 && cut.y1[k]<=line[j].y1){
					cut.y2[k] = line[j].y1;
				}
				else if(cut.y1[k]<=line[j].y2 && cut.y1[k]>=line[j].y1 && cut.y2[k]>=line[j].y2){
					cut.y1[k] = line[j].y2;
				}
				else if(cut.y1[k]<=line[j].y1 && cut.y2[k]>=line[j].y2){  //截成兩段的情形 
					cut.y1[k_max] = line[j].y2;     //新增線段 
					cut.y2[k_max] = cut.y2[k];
					cut.y2[k] = line[j].y1;
					k_max++;
					break;			
				}
			}
		}
		for(j=0;j<num;j++) for(q=num-1;q>j;q--){
			if(right_line[q]<right_line[q-1]){
			tt=right_line[q]; right_line[q]=right_line[q-1]; right_line[q-1]=tt; }
		}
		for(j=0;j<num;j++)	fprintf(out,"%d ",right_line[j]);	
		fprintf(out,"\n");
	}
	fclose(out);
	return 0;	
}
// vLineSet1.txt
