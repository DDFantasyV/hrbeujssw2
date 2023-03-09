#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc,char *argv[]){
/*（1）声明函数及变量*/
int writeToFile(char *str, char *fileName, char *mode);
char str[100];
char fileName[] = "ex801.txt";
/*（2）获取键盘输入字串*/
fgets(str, 100, stdin);
//gets(str); //将回车看作字串输入结束标志，字串中可以有空格
//scanf("%s", str); //将空格看作字串输入结束标志，字串中不能有空格
/*（3）将字串写入文件*/
int charNum = writeToFile(str, fileName, "w");
if(charNum < 0){
//printf("write error");//用于调试
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


