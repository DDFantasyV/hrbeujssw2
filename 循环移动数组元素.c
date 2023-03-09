#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

/*主函数*/
int main(void){
	/*声明函数*/
	void input(int *p, int n);
	void output(int *p, int n);
	void move(int *p, int length, int m);

	/*定义数据结构*/
	int a[LENGTH], m;//m表示数组元素循环移动的位置个数
	int *p = a;
	input(p, LENGTH);
	scanf("%d", &m);
	/*调用move函数，完成数组元素的循环移动*/
	move(p, LENGTH, m);
	output(p, LENGTH);
	return 0;
}

void input(int *p, int n){
	int i; 
	for(i=0;i<n; i++)
	scanf("%d,",&p[i]);	
}

void output(int *p, int n){
	int i;
	for(i=0;i<n;i++)
	printf("%d ",p[i]);
}

void moveToRight(int *p, int length, int m){
	int *q = (int *)malloc(sizeof(int)*length);
	int i;
	for(i=0;i<length;i++)
	{
		q[(i+m)%length]=p[i];
	}
	for(i=0;i<length;i++)
		p[i] = q[i];
}

void moveToLeft(int *p, int length, int m){
	int *q = (int *)malloc(sizeof(int)*length);
	int i; 
	for(i=0;i<length;i++)
	{
		q[(i+m+length)%length]=p[i];
	}
	for(i=0;i<length;i++)
		p[i]=q[i];
}

void move(int *p, int length, int m){
	if(m > 0){
		/*向右循环移动*/
		moveToRight(p, length, m);
		}
	else if(m == 0){
		/*不移动*/
			; //空语句，什么都不做
		}
	else{
		/*向左循环移动*/
		moveToLeft(p, length, m);
	}
}
