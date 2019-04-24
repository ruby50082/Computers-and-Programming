#include<stdio.h>
#include<stdlib.h>

int n,qn,q,z=0,k=0,i,j;
int x[500],y[500];
int total=0,odd_total=0,greater_total=0;
FILE *in; 

struct Line{
	int x1,y1;
	int x2,y2;
	int change; 
}L[500],ver[250],temp;

struct Rectangle{
	int bottom,left;
	int area;
}rec[250],ttemp;

struct Cut{        //�\�θ�11-1���@�� 
	int y1,y2;
}cut[250];

void build_rec(){  //���Ϊ���� 
	for(i=1;i<z;i++){
		if(ver[i].change==1)	continue;    //change�O1��ܦ��������V�V�U 
		cut[0].y2=ver[i].y2;
		cut[0].y1=ver[i].y1;
		int c_max=1,c;
		for(j=i-1;j>=0;j--){                 //���i���䥪�䪺 
			temp=ver[j];
			for(c=0;c<c_max;c++){
				if(cut[c].y1==-1 && cut[c].y2==-1)	continue;	// -1��ܳQ�R��	
				if(temp.y1>=cut[c].y2 || temp.y2<=cut[c].y1)	continue; //�ư��u�����I���Ʃιs�涰 
				if(temp.y1<=cut[c].y1 && temp.y2>=cut[c].y2){
					rec[k].bottom = cut[c].y1;
					rec[k].left = temp.x1;
					rec[k].area = (cut[c].y2-cut[c].y1)*(ver[i].x1-temp.x1);
					k++;
					cut[c].y1 = cut[c].y2 = -1;
				}
				else if(temp.y1<=cut[c].y1){
					rec[k].bottom = cut[c].y1;
					rec[k].left = temp.x1;
					rec[k].area = (temp.y2-cut[c].y1)*(ver[i].x1-temp.x1);
					cut[c].y1 = temp.y2;
					k++;
				}
				else if(temp.y2>=cut[c].y2){
					rec[k].bottom = temp.y1;
					rec[k].left = temp.x1;
					rec[k].area = (cut[c].y2-temp.y1)*(ver[i].x1-temp.x1);
					cut[c].y2 = temp.y1;
					k++;
				}
				else if(temp.y1>=cut[c].y1 && temp.y2<=cut[c].y2){    //�I����q������  
					rec[k].bottom = temp.y1;
					rec[k].left = temp.x1;
					rec[k].area = (temp.y2-temp.y1)*(ver[i].x1-temp.x1);
					cut[c_max].y1 = temp.y2;     //�s�W�u�q 
					cut[c_max].y2 = cut[c].y2;
					cut[c].y2 = temp.y1;
					k++; c_max++;
					break;
				}
			}
		}
	}
}

void sort_rec(){     //�����αƧ� 
	for(i=0;i<k;i++)for(j=k-1;j>i;j--){
		if(rec[j].bottom == rec[j-1].bottom && rec[j].left < rec[j-1].left){
			ttemp=rec[j];
			rec[j]=rec[j-1];
			rec[j-1]=ttemp;
		}
		else if(rec[j].bottom < rec[j-1].bottom){
			ttemp=rec[j];
			rec[j]=rec[j-1];
			rec[j-1]=ttemp;
		}
	}
}

void sort_line(){    //�﫫������Ƨ� 
	for(i=0;i<z;i++)for(j=z-1;j>i;j--){
		if(ver[j].x1 < ver[j-1].x1){
			temp=ver[j];
			ver[j]=ver[j-1];
			ver[j-1]=temp;
		}
	}
}

void init(){     //��J���I  �إ��� �ç�X���������x�s�bver�}�C 
	fscanf(in,"%d",&n);
	for(i=0;i<n;i++)		 fscanf(in,"%d%d",&x[i],&y[i]);
	for(i=0;i<n-1;i++){
		L[i].x1=x[i]; 		 L[i].y1=y[i];
		L[i].x2=x[i+1]; 	 L[i].y2=y[i+1];
		if(L[i].x1==L[i].x2) ver[z++]=L[i];
	}
	L[n-1].x1=x[n-1]; 		 L[n-1].y1=y[n-1];
	L[n-1].x2=x[0]; 		 L[n-1].y2=y[0];
	if(L[n-1].x1==L[n-1].x2) ver[z++]=L[n-1];
	
	for(i=0;i<z;i++){        //�P�_�����䬰�V�W�ΦV�U 
		ver[i].change=0;
		if(ver[i].y2<ver[i].y1){
			int t=ver[i].y2;
			ver[i].y2=ver[i].y1;
			ver[i].y1=t;
			ver[i].change=1;
		}
	}
}

int main(){
	in=fopen("polygon5.txt","r");
	init();
	sort_line();
	build_rec();
	sort_rec();

	for(i=0;i<k;i+=2)	odd_total+=rec[i].area;     //��s�����_�ƪ�����έ��n�M 
	for(i=0;i<k;i++)	total+=rec[i].area;
	for(i=0;i<k;i++){
		if(rec[i].area*k >= total)	greater_total+=rec[i].area; //��j�󵥩󥭧����n������έ��n�M 
	}
	printf("%d\n",k);
	printf("%d\n",odd_total);
	printf("%d\n",greater_total);
	while(fscanf(in,"%d",&qn)!=EOF){    // qn����`�@�߰ݴX�Ӫ���� 
		if(qn==-1)	break;
		int ans=0;
		for(i=0;i<qn;i++){
			fscanf(in,"%d",&q);         //�p��߰ݪ�����έ��n�M  q���s�� 
			ans+=rec[q-1].area;
		}
		printf("%d\n",ans);
	}
	fclose(in);	
	return 0;
}
