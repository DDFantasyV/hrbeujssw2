#include <stdio.h>

int main(void){
void assign(int *array, int length);
int max(int *array, int length);
int a[5];
assign(a, 5);
printf("max=%d",max(a, 5));
return 0;
}

void assign(int *array,int length){
	int i;
	for(i=0;i<length;i++){
		scanf("%d",array);
		array++;
	}
}
 
int max(int *array,int length){
	int temp,i;
	for(i=0;i<length;i++){
		if(*array>=temp)
			temp=*array;
		array++;
	}
	return temp;
}
