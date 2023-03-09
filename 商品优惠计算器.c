#include<stdio.h>
int main(){
	float a;
	scanf("%f",&a);
	if(a<=500)
		printf("%.2f",a);
	else{
		if(a<=1000){
			a=0.9*a;
			printf("%.2f",a);
		}
		else{
			a=0.8*a;
			printf("%.2f",a);
		}
	}
	return 0;
}
