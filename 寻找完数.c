#include<stdio.h>
int main(){
	int m,n,a,i,j,k,l=0,o;
	int result[9999];
	scanf("%d,%d",&m,&n);
	if(m>0&&n>0&&m<=9999&&n<=9999){
		if(m>n){
			a=m;
			m=n;
			n=a;
		}
		for(i=m;i<=n;i++){
			k=0;
			for(j=1;j<=i-1;j++){
				if(i%j==0)
					k+=j;
				}
			if(k==i){
				result[l]=i;
				l++;
				}
			}
		for(l=l-1;o<l;o++)
			printf("%d,",result[o]);
		printf("%d",result[l]);
		}
	else
		printf("error");
	return 0;
}
