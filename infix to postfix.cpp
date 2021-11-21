#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 100
struct stack
{
	int top;
	char a[size];
	
}s;
void push(char n);
int pop();
int prio(char ch);
int size=100; 

int main()
{
	char b[100];
char ch;
struct stack s;
int i,len;
printf("Enter the string");
scanf("%s",b);
len=strlen(b);

for(i=0;i<len;i++)
{
	if(isdigit(b[i]))
	{
		printf("%c",b[i]);
	}
	else if(b[i]=='(')
	{
		push(b[i]);
	}
	else if(b[i]==')')
	{
		while((s.top!=-1) && (s.a[s.top]!='('))
		{
			ch=pop();
			printf("%c",ch);
		}
		ch=pop();
	}
	else if(b[i]=='+' || b[i]=='-' || b[i]=='*' || b[i]=='/')
	{
		while(s.top!=-1 && s.a[s.top]!='(' && (prio(s.a[s.top]>=prio[b[i]])))
		{
			ch=pop();
			printf("%c",ch);
			
		}
		push(b[i]);
	}
}

while(s.top!=-1)
{
	ch=pop();
	printf("%c",ch);
	}	
	
}
void push(char n)
{
	if(s.top==size-1)
	{
		printf("stack is full");
	}
	else 
	{
		s.top=s.top+1;
		s.a[s.top]=n;
		printf("%d",n);
	}
}
int pop()
{
	int z;
	if(s.top==-1)
	printf("Stack is empty");
	else
	{
		z=s.a[s.top];
		s.top=s.top-1;
	}
	
	return z;
}

int prio(char ch)
{
	if(ch=='*' || ch=='/')
	return 1;
	else
	return 0;
}

