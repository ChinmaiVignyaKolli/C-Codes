#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack
{
	int top;
	int a[100];
	
}s;
void push(char n);
int pop();
int size=100;

int main()
{
	int p,q,r,k;
	int len,i,val;
	char b[100];
	printf("Enter the postfix expression");
	scanf("%s",b);
	len=strlen(b);
	s.top=-1;
	
	for(i=0;i<=len;i++)
	{
		if(b[i]>47 && b[i]<57)
		{
			
			
			k=b[i]-48;
			
			push (k);
		}

	else if(b[i]==47)
	{
		p=pop();
		q=pop();
		r=q/p;
		push(r);
	}
	else if(b[i]==42)
	{
		p=pop();
		q=pop();
		r=p*q;
		push(r);
		
	}
	else if(b[i]==45)
	{
		p=pop();
		q=pop();
		r=q-p;
		push(r);
	}
	else if(b[i]==43)
	{
		p=pop();
		q=pop();
		r=p+q;
		push(r);
	}
	 
	 
}
    
    val=pop();
    if(s.top==-1)
    {

     printf("val %d",val);	
	}
	
	 return 0;
}

void push(char x)
{
	if(s.top==size-1)
	{
		printf("stack is full");
	}
	else 
	{
		s.top=s.top+1;
		s.a[s.top]=x;
		printf("%d",x);
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
