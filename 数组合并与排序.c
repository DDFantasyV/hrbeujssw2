#include<stdio.h>
int main(){
	int a[6],b[6];
	int c[11];
	int i,j,tmp;
	for(i=1;i<=5;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=5;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=5;i++)
		c[i]=a[i];
	for(i=1;i<=5;i++)
		c[i+5]=b[i];
	for(i=1;i<=10;i++){
		if(i!=10)
		printf("%d,",c[i]);
		else
		printf("%d\n",c[i]);
	}
	for(i=1;i<=9;i++){
		for(j=1;j<=9;j++){
			if(c[j]>c[j+1]){
				tmp=c[j];
				c[j]=c[j+1];
				c[j+1]=tmp;
			}
		}
	}
	for(i=1;i<=10;i++){
		if(i!=10)
		printf("%d,",c[i]);
		else
		printf("%d",c[i]);
	}
	return 0;
} 
