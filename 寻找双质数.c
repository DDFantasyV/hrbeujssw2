#include<stdio.h>
int main(){
	int m,n;
	scanf("%d,%d",&m,&n);
	
	int zs[2000];
	int i,j,k=0;
	i=m;
	for(i;i<=n;i++){
		for(j=2;j<=i;j++){
			if(i%j==0) 
				break;		
		}
		if(i==j){
			zs[k]=i;
			k++;
		}
	}
	
	int tmp;
	tmp=k-1;
	k=0;
	for(k;k<=tmp;k++){
		if(zs[k+1]-zs[k]==2)
			printf("%d,%d\n",zs[k],zs[k+1]);
	}
	
	return 0;
} 
