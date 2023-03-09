#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
int statisticsFromFile(int *num, char *fileName, char *mode);
/*
 * 定义数组num，包含三个元素：
 * 第1个元素表示字母个数；
 * 第2个元素表示数字个数；
 * 第3个元素表示其他字符个数
 */
int num[3]={0,0,0};
char fileName[] = "ex802.txt";
/*读取文件并分类统计字符个数*/
statisticsFromFile(num, fileName, "r");
/*输出显示各类字符个数*/
printf("letter:%d\n",num[0]);
printf("number:%d\n",num[1]);
printf("other:%d",num[2]);
return 0;
}

int statisticsFromFile(int *num, char *fileName, char *mode){
	FILE *fp;
	int i,j;
	char temp[100];
	fp=fopen(fileName,mode); 
	for(i=0;i<100;i++){
		fscanf(fp,"%c",&temp[i]);
		if(temp[i]=='\0')
			break;
	}
	fclose(fp);
	j=i-1;
	for(i=0;i<=j;i++){
		if((temp[i]>='a'&&temp[i]<='z')||(temp[i]>='A'&&temp[i]<='Z')){
   			num[0]++;
		}
		else if(temp[i]>='0'&&temp[i]<='9'){
   			num[1]++;
		}
		else
   			num[2]++;
	}
}
