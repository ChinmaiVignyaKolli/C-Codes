#include<stdio.h>
struct queue
{
	int rear,front;
	int a[10];	
};
struct queue enqueue(struct queue q,int);
struct queue dequeue(struct queue q);
int size=10;
int main()
{
	int p,r,i;
struct queue q1;
q1.front=-1;
q1.rear=-1;
q2.front=-1;
q2.rear=-1;
q3.front=-1;
q3.rear=-1;
q1=enqueue(q1,10);
q1=enqueue(q2,1);
q1=enqueue(q3,15);
q1=enqueue(q1,12);
q1=enqueue(q1,18);
q1=enqueue(q1,5);

if(q1.rear!=)
q1=dequeue(q); 
p=q1.rear;
r=q1.front;
for(i=0;i<=p;i++)
{
	printf("%d",q1.a[i]);
}

return 0;
}

struct queue enqueue(struct queue q,int b)
{

	if(q.rear==size-1)
	{
		printf("Not possible");
	}
	else if(q.front==-1)
	{
		q.front=0;
		q.rear=q.rear+1;
		q.a[q.rear]=b;
	}
	else
	{
		q.rear=q.rear+1;
		q.a[q.rear]=b;
	}
	return q;
}

struct queue dequeue(struct queue q)
{
	int x;
	if(q.rear==-1)
	{
		printf("Not possible");
		
	}
	else 
	{
		x=q.a[q.front];
		if(q.rear==q.front)
		{
			q.rear=q.front=-1;
		}
		else
		{
			q.front=q.front+1;
		}
		return q;
	}
}
