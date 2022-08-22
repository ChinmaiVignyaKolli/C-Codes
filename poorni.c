#include<stdio.h>
#include<stdlib.h>

struct node{
	int d;
	struct node *next;
	}*temp=NULL;

int modify(struct node **r, int p);
void create(struct node **root, int a);
void display(struct node **rot);
void addend(struct node **rt, int g);
void addpos(struct node **rto, int g, int j );

void create(struct node **root, int a)
{  struct node *nn=(struct node*) malloc(sizeof(struct node));
	temp=*root;
	nn->next=NULL;
	nn->d=a;
	if(*root==NULL)
	*root=nn;
	else
	{
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=nn;
	}
	
}

void display(struct node **rot)
{
    temp=*rot;
    while(temp->next!=NULL)
    {
    printf("%d\t",temp->d);
    temp=temp->next;
    }
    printf("%d",temp->d);
    
}

int main()
{
	int a,n,i,k,l;
	struct node *start=NULL;
	printf("\nEnter n value:");
	scanf("%d",&n);
	printf("enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		create(&start,a);
	}
	printf("\nEntered list is:\n");
	display(&start);
	printf("\nenter elements to be added:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&k);
		l=modify(&start,k);
	
	if(l==0) addend(&start,k);
	else addpos(&start,k,l);
}
	display(&start);	
}

int modify(struct node **r, int p)
{
int f=0;
temp=*r;
while(temp->next!=NULL)
{
f++;
if(p<=temp->d)
return f; 
temp=temp->next;
}
f=0;
return f;
}

void addend(struct node **rt, int g)
{
struct node *newnode;

temp=*rt;
while(temp->next!=NULL)
temp=temp->next;
newnode=malloc(sizeof(struct node));
newnode->d=g;
newnode->next=NULL;
temp->next=newnode;
}

void addpos(struct node **rto, int g, int j )
{
int i;
struct node  *newnode;
temp=*rto;
newnode=malloc(sizeof(struct node));
newnode->d=g;
newnode->next=NULL;
if(j==1) {newnode->next=*rto; *rto=newnode;}
else
{
for(i=1;i<=j-2;i++)
temp=temp->next;

newnode->next=temp->next;
temp->next=newnode;
}
}

