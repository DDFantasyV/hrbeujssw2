#include <stdio.h>
#include <string.h>

typedef struct teacher{
int id; // 职工号
char name[100]; // 姓名
int salary; // 工资
}teacher;

const int NUM = 5; 

int main(){
void input(teacher *t, int n);
void output(teacher *t, int n);
void sort(teacher *t, int n);
teacher t[NUM]; //教师数组
teacher *pt = t;
input(pt, NUM); //为教师数组元素赋值
printf("Before sorting:\n");
output(pt, NUM); //排序前输出
sort(pt, NUM); //按工资排序
printf("After sorting:\n");
output(pt, NUM); //排序后输出
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
