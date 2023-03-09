#include <stdio.h>
#include <string.h>

typedef struct teacher{
int id; // ְ����
char name[100]; // ����
int salary; // ����
}teacher;

const int NUM = 5; 

int main(){
void input(teacher *t, int n);
void output(teacher *t, int n);
void sort(teacher *t, int n);
teacher t[NUM]; //��ʦ����
teacher *pt = t;
input(pt, NUM); //Ϊ��ʦ����Ԫ�ظ�ֵ
printf("Before sorting:\n");
output(pt, NUM); //����ǰ���
sort(pt, NUM); //����������
printf("After sorting:\n");
output(pt, NUM); //��������
return 0;
}

void input(teacher *t, int n){
	int i;
	for(i=0;i<5;i++)
		scanf("%d %s %d",&t[i].id,&t[i].name,&t[i].salary);
}

void output(teacher *t, int n){
	int i;
	for(i=0;i<5;i++)
		printf("%d,%s,%d\n",t[i].id,t[i].name,t[i].salary);
}

void sort(teacher *t, int n){
	int i,j,k;
	for(i=0;i<n;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(t[k].salary>t[j].salary){
				t[6]=t[k];
				t[k]=t[j];
				t[j]=t[6];
			}
		}
	}
}
