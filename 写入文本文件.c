#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc,char *argv[]){
/*��1����������������*/
int writeToFile(char *str, char *fileName, char *mode);
char str[100];
char fileName[] = "ex801.txt";
/*��2����ȡ���������ִ�*/
fgets(str, 100, stdin);
//gets(str); //���س������ִ����������־���ִ��п����пո�
//scanf("%s", str); //���ո����ִ����������־���ִ��в����пո�
/*��3�����ִ�д���ļ�*/
int charNum = writeToFile(str, fileName, "w");
if(charNum < 0){
//printf("write error");//���ڵ���
return -1;
}
return 0;
}

int writeToFile(char *str, char *fileName, char *mode){
	int i;
	char temp;
	for(i=0;i<100;i++){
		temp=str[i];
		if(str[i]>='a'&&str[i]<='z'){
			str[i]=temp-32;
		}
		else if(str[i]>='A'&&str[i]<='Z'){
			str[i]=temp+32;
		}
		else if(str[i]=='\n')
			break;
	} 
	temp=i;
	FILE *fp;
	fp=fopen("ex801.txt","wb");
	for(i=0;i<temp;i++){
		fprintf(fp,"%c",str[i]);
	}
	fclose(fp);
}


