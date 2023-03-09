#include<stdio.h>
int main(){
	int n,i=1;
	float sum=0,tmp1=1,tmp2=2,tmp3=0;
	scanf("%d",&n);
	for(i;i<=n;i++){
		sum+=tmp2/tmp1;
		tmp3=tmp2;
		tmp2+=tmp1;
		tmp1=tmp3;
	}
	printf("%.2f",sum);
	return 0;
} 
