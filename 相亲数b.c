#include<stdio.h>
int main(){
	int a,b,c,a1,b1,e=0,f=0,i;
	scanf("%d %d",&a,&b);
	a1=a;
	b1=b;
	printf("%d,",a);
	for(i=2;i<=a;i++){
		c=a%i;
		if(c==0){
			a1=a/i;
			if(a1==1)
				printf("%d",a1);
			else
				printf("%d+",a1);
			e+=a1;
		}
	}
	printf("=%d\n",e);
	
	printf("%d,",b);
	for(i=2;i<=b;i++){
		c=b%i;
		if(c==0){
			b1=b/i;
			if(b1==1)
				printf("%d",b1);
			else
				printf("%d+",b1);
			f+=b1;
		}
	}
	printf("=%d\n",f);
	if(a==f&&b==e)
		printf("1");
	else
		printf("0");
	return 0;
} 
