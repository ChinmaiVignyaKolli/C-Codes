#include<stdio.h>
#include<ctype.h>

#define SIZE 50

char s[SIZE];
int top=-1;

push(char element){
	s[++top]=element;
}

char pop(){
	return s[top--];
}

int pr(char ch){
	switch(ch){
		case '#':
			return 0;
		case '(':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
		case '%':
			return 3;
		case '^':
			return 4;
	}
}

int main(void){
	char infx[SIZE],pofx[SIZE],ch,elem;
	int i=0,k=0;
	printf("Enter the infix expression: ");
	scanf("%s",infx);
	push('#');
	while((ch=infx[i++])!='\0'){
		if(ch=='(')
			push(ch);
		else if(isalnum(ch))
			pofx[k++]=ch;
		else if(ch==')'){
			while(s[top]!='(')
				pofx[k++]=pop();
			elem=pop();
		}
		else{
			while(pr(s[top])>=pr(ch))
				pofx[k++]=pop();
			push(ch);
		}
	}
	while(s[top]!='#'){
		pofx[k++]=pop();
	}
	pofx[k]='\0';
	printf("postfix Expression :%s",pofx);
	return 0;
}
