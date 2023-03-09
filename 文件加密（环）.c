#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
typedef struct node *Nodep;
Nodep head = NULL , p , t , q ;

char s[100];		//源 
char tmp[100];		//去重 
char enc[100];		//加密 
int i , j , k , f , time ;
char temp , ch ;

void WriteFile();								//写入 
void DelRepeated();								//去重
void Upcat();									//升序追加
void CircleEncryption();						//环加密
void Output(FILE *fp1,FILE *fp2);				//输出
void ReadFile(FILE *fpread);					//读取 

int main() {
	gets(s);									//明码 
	WriteFile();								//待加密内容 
	FILE *fp1 = fopen("in.txt","r");
	FILE *fp2 = fopen("out.txt","w");
	DelRepeated();								//去重 
	Upcat();									//升序追加
	CircleEncryption();							//环加密
	Output(fp1,fp2);							//输出
	FILE *fpread = fopen("out.txt","rt");
	ReadFile(fpread);							//已加密内容 
	return 0;
}


void WriteFile(){
	FILE *fp;
	char a;
	fp = fopen("in.txt","w");
	for(a = getchar();a != EOF;a = getchar())
		fputc(a , fp);
	fclose(fp);
}


void DelRepeated(){
	int n = strlen(s);
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			if(s[j] == s[i]) {
				s[j] = '0';			//重复设为0
			}
		}
	}
	j = 0;
	for(i = 0; i < n; i++) {
		if(s[i] != '0') {			//重复不输出
			tmp[j] = s[i];
			j++;
		}
	}
}


void Upcat(){
	memset(s,0,sizeof(s));
	k = 0;
	for(i = 97; i <= 122; i++){
		f = 0;
		for(j = 0; j < strlen(tmp); j++){		//判断去重数组里面有没有该字母 
			if(tmp[j] == i){
				f = 1;
				break;
			}
		}
		if(f == 0){
			s[k] = i;
			k++;
		}
		else{
			continue;
		}
	}
	strcat(tmp,s);
}


void CircleEncryption(){
	int cnt = 0;
	for(i = 0; i < strlen(tmp); i++){
		if(head == NULL){
			p = (struct node *)malloc(sizeof(struct node ));
			head = p;
		}
		else{
			p->next = (struct node *)malloc(sizeof(struct node));
			p = p->next;
		}
		p->data = tmp[i];
		p->next = NULL;
	}
	p->next = head;					//构成循环链表 
	temp = head->data; 				//temp存头节点的字母
	ch = temp;						//ch待加密的字母
	time = head->data;				//time移动次数
	q = head;
	head = head->next;
	p->next = p->next->next;
	free(q);								//删除头节点
	p = head;
	while(p->next != p){
		for(i = 1; i < time-1; i++){		//找到加密字母 
			p = p->next;
		}
		enc[(int)ch-32] = p->next->data;	//加密 
		ch = p->next->data;					//ch待加密的字母
		time = ch;							//time移动次数
		q = p->next;
		p->next = p->next->next;
		free(q);							//删除节点 
		p = p->next;
		cnt++;
	}
	enc[(int)ch-32] = p->data;  
	enc[(int)(p->data)-32] = temp;			//最后对头节点加密 
}


void Output(FILE *fp1,FILE *fp2){
	memset(s,0,sizeof(s));
	ch = fgetc(fp1);
	i = 0;
	while(ch != EOF){
		s[i] = ch;
		i++;
		ch = fgetc(fp1);
	}
	for(i = 0; i < strlen(s); i++){
		if(s[i] >= 97 && s[i] <= 122)
			fputc(enc[s[i]-32],fp2);
		else
			fputc(s[i],fp2);
	}
	fclose(fp1);
	fclose(fp2);
}


void ReadFile(FILE *fpread){
	char b;
	while((b = fgetc(fpread)) != EOF)
		printf("%c",b);
	fclose(fpread);
}
