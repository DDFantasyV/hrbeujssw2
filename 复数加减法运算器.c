#include <stdio.h>

struct complex{
int re; // real part��ʵ����
int im; // imaginary part���鲿��
};

int main(){
struct complex add(struct complex a, struct complex b);
struct complex minus(struct complex a, struct complex b);
struct complex x, y, z;
// ����ʵ��x��ʵ�����鲿
scanf("%d,%d", &x.re, &x.im);
// ����ʵ��y��ʵ�����鲿
scanf("%d,%d", &y.re, &y.im);
// ���㲢��������ӷ���
z = add(x, y); 
printf("%d+%di\n",z.re, z.im);
// ���㲢�������������
z = minus(x, y);
printf("%d+%di",z.re, z.im);
return 0;
}



struct complex add(struct complex a, struct complex b){
	struct complex c;
	c.re=a.re+b.re;
	c.im=a.im+b.im;
	return c; 
}

struct complex minus(struct complex a, struct complex b){
	struct complex c;
	c.re=a.re-b.re;
	c.im=a.im-b.im;
	return c; 
}


