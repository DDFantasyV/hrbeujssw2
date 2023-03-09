#include<stdio.h>
int n,a[21][21];

void Square(){
    int m=n-1,k=0,i;
    int total=0;
    while(total<n*n){
        for(i=m;i>=k;i--){
		 	a[k][i]=total+1;
			total+=1;
		} 
        for(i=k+1;i<=m;i++){
		 	a[i][k]=total+1;
			total+=1;
		} 
        for(i=k+1;i<=m;i++){
		 	a[m][i]=total+1;
			total+=1;
		}
        for(i=m-1;i>=k+1;i--){
			a[i][m]=total+1;
			total+=1;
		}
        m--;
        k++;
    }
}

 void Output(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
			printf("%3d ",a[i][j]);
    printf("\n");
    }
}
 int main(){
    scanf("%d",&n);
    Square();
    Output();
return 0;
}
