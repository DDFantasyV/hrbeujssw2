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

char s[100];		//Դ 
char tmp[100];		//ȥ�� 
char enc[100];		//���� 
int i , j , k , f , time ;
char temp , ch ;

void WriteFile();								//д�� 
void DelRepeated();								//ȥ��
void Upcat();									//����׷��
void CircleEncryption();						//������
void Output(FILE *fp1,FILE *fp2);				//���
void ReadFile(FILE *fpread);					//��ȡ 

int main() {
	gets(s);									//���� 
	WriteFile();								//���������� 
	FILE *fp1 = fopen("in.txt","r");
	FILE *fp2 = fopen("out.txt","w");
	DelRepeated();								//ȥ�� 
	Upcat();									//����׷��
	CircleEncryption();							//������
	Output(fp1,fp2);							//���
	FILE *fpread = fopen("out.txt","rt");
	ReadFile(fpread);							//�Ѽ������� 
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
				s[j] = '0';			//�ظ���Ϊ0
			}
		}
	}
	j = 0;
	for(i = 0; i < n; i++) {
		if(s[i] != '0') {			//�ظ������
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
		for(j = 0; j < strlen(tmp); j++){		//�ж�ȥ������������û�и���ĸ 
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
	p->next = head;					//����ѭ������ 
	temp = head->data; 				//temp��ͷ�ڵ����ĸ
	ch = temp;						//ch�����ܵ���ĸ
	time = head->data;				//time�ƶ�����
	q = head;
	head = head->next;
	p->next = p->next->next;
	free(q);								//ɾ��ͷ�ڵ�
	p = head;
	while(p->next != p){
		for(i = 1; i < time-1; i++){		//�ҵ�������ĸ 
			p = p->next;
		}
		enc[(int)ch-32] = p->next->data;	//���� 
		ch = p->next->data;					//ch�����ܵ���ĸ
		time = ch;							//time�ƶ�����
		q = p->next;
		p->next = p->next->next;
		free(q);							//ɾ���ڵ� 
		p = p->next;
		cnt++;
	}
	enc[(int)ch-32] = p->data;  
	enc[(int)(p->data)-32] = temp;			//����ͷ�ڵ���� 
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
