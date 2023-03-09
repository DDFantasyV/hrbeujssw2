#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

/*������*/
int main(void){
	/*��������*/
	void input(int *p, int n);
	void output(int *p, int n);
	void move(int *p, int length, int m);

	/*�������ݽṹ*/
	int a[LENGTH], m;//m��ʾ����Ԫ��ѭ���ƶ���λ�ø���
	int *p = a;
	input(p, LENGTH);
	scanf("%d", &m);
	/*����move�������������Ԫ�ص�ѭ���ƶ�*/
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
		/*����ѭ���ƶ�*/
		moveToRight(p, length, m);
		}
	else if(m == 0){
		/*���ƶ�*/
			; //����䣬ʲô������
		}
	else{
		/*����ѭ���ƶ�*/
		moveToLeft(p, length, m);
	}
}
