#include<stdio.h>
int main(){
	int a,b,c=0,i;
	scanf("%d",&a);
	for(i=2;i<=a;i++){
		b=a%i;
		while(b==0){
			a=a/i;
			b=a%i;
			c++;
		}
		if(c>=2){
			printf("%d ",i);
		}
		c=0;
	}	
	return 0;
}
