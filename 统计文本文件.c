#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
int statisticsFromFile(int *num, char *fileName, char *mode);
/*
 * ��������num����������Ԫ�أ�
 * ��1��Ԫ�ر�ʾ��ĸ������
 * ��2��Ԫ�ر�ʾ���ָ�����
 * ��3��Ԫ�ر�ʾ�����ַ�����
 */
int num[3]={0,0,0};
char fileName[] = "ex802.txt";
/*��ȡ�ļ�������ͳ���ַ�����*/
statisticsFromFile(num, fileName, "r");
/*�����ʾ�����ַ�����*/
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
