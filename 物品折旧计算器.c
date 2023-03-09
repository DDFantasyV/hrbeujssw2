#include<stdio.h>
int main(){
	float a,b,c,d,ans1,ans2;
	scanf("%f,%f,%f,%f",&a,&b,&c,&d);
	ans1 = ( a - b ) / c;
	ans2 = a - ans1 * d;
	printf("%.2f,%.2f",ans1,ans2);
	return 0;
} 
