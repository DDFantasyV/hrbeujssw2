#include<stdio.h> 
int main(){
	int a = 0,b = 0,i = 0,j = 0,k = 0,l = 0;
    scanf("%d,%d",&a,&b);
    i = a + b;
    j = a - b;
    k = a * b;
    l = a / b;
	printf("a+b=%d\n",i);
	printf("a-b=%d\n",j);
	printf("a*b=%d\n",k);
	printf("a/b=%d",l);
	return 0;
}
