#include<stdio.h>
#include<stdlib.h> //malloc


struct node
	{
		struct node *rcptr;
		int data;
		int height;
		struct node *lcptr;
	};

struct node *rptr=NULL;

struct node* insert(struct node* , int x);

void inorder(struct node*);

int HT(struct node*ptr);

int main()
{
	rptr=insert(rptr,50);
	rptr=insert(rptr,40);
	rptr=insert(rptr,30);
	rptr=insert(rptr,20);
	rptr=insert(rptr,10);
	rptr=insert(rptr,5);
	
	
	inorder(rptr);
	printf("\n%d ",HT(rptr));


return(0);
}				



int HT( struct node*ptr) // HT height of given node
{
	if(ptr!=NULL)
		return(ptr->height);
	else
	return(-1);
}



void HeightUpdate(struct node* ptr)
{

	int h1=HT(ptr->lcptr),h2=HT(ptr->rcptr);
	
	if(h1<h2) 
	{
		ptr->height=h2+1;
		
	}

	else
	{
		ptr->height=h1+1;
	}
}

void inorder(struct node* ptr)
{
	if(ptr)
	{
		
		inorder(ptr->lcptr);
		printf("%d  ",ptr->data);
		inorder(ptr->rcptr);
	}
}

struct node *RotateRight(struct node* ptr)
{

	struct node *jptr=ptr;
	struct node * kptr=jptr->lcptr;
	
	jptr->lcptr=kptr->rcptr;
	kptr->rcptr=jptr;
	HeightUpdate(jptr);
	HeightUpdate(kptr);
	return(kptr);
}

struct node *RotateLeft(struct node* ptr)
{

	struct node *jptr=ptr;
	struct node * kptr=jptr->rcptr;
	
	jptr->rcptr=kptr->lcptr;
	kptr->lcptr=jptr;

	HeightUpdate(jptr);
	HeightUpdate(kptr);
	return(kptr);
	
}

struct node *RotateLeftRight(struct node* ptr)
{

	struct node *jptr=ptr;
	struct node * kptr=jptr->lcptr;
	
	jptr->lcptr=RotateLeft(kptr);
	
	
	return(RotateRight(jptr));

}

struct node *RotateRightLeft(struct node* ptr)
{

	struct node *jptr=ptr;
	struct node * kptr=jptr->rcptr;
	
	jptr->rcptr=RotateRight(kptr);
	
	
	return(RotateLeft(jptr));

}


struct node* insert( struct node *ptr ,int x)
{
	int h1,h2;
	if(ptr==NULL)
	{	ptr= (struct node* ) malloc(sizeof(struct node));
		ptr->data=x;
		ptr->height=0;
		ptr->lcptr=NULL;
		ptr->rcptr=NULL;
	}

	else
	{
					if(x<ptr->data)
					{
						ptr->lcptr=insert(ptr->lcptr,x);	
						
						h1=HT(ptr->lcptr);
						h2=HT(ptr->rcptr);
					
						if(((h1-h2)==2) || ((h1-h2)==-2))
						{
						 if(x<(ptr->lcptr)->data)
						 	ptr=RotateRight(ptr);
						 else
						 	ptr=RotateLeftRight(ptr);
						}
					}
					
					else
					{
						ptr->rcptr=insert(ptr->rcptr,x);
					
						h1=HT(ptr->lcptr);
						h2=HT(ptr->rcptr);
					
						if(((h1-h2)==2) || ((h1-h2)==-2))
						{
							 if(x<(ptr->rcptr)->data)
							 	ptr=RotateRightLeft(ptr);
							 else
							 	ptr=RotateLeft(ptr);
						}
					
					
					
					}
					
					HeightUpdate(ptr);
					
	}

	return(ptr);
}


