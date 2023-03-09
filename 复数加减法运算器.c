#include <stdio.h>

struct complex{
int re; // real part（实部）
int im; // imaginary part（虚部）
};

int main(){
struct complex add(struct complex a, struct complex b);
struct complex minus(struct complex a, struct complex b);
struct complex x, y, z;
// 输入实数x的实部和虚部
scanf("%d,%d", &x.re, &x.im);
// 输入实数y的实部和虚部
scanf("%d,%d", &y.re, &y.im);
// 计算并输出复数加法和
z = add(x, y); 
printf("%d+%di\n",z.re, z.im);
// 计算并输出复数减法差
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


