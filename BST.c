#include<stdio.h>
struct node
{
	int data;
	struct node *lcptr;
	struct node *rcptr;
	
};
 struct node *rptr=NULL;
 void insert(int x);
 void preorder();
 void inorder();
 void postorder();
 void delete(int);
int main()
{
insert(80);
insert(90);
insert(70);
insert(60);
insert(20);
insert(75);
inorder(rptr);

delete(60);
delete(75);
inorder(rptr);
return 0;	
}

void insert(int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->lcptr=NULL;
	temp->rcptr=NULL;
	if(rptr==NULL)
	{
		rptr=temp;
	}
	else
	{
		struct node *trptr=rptr;
		struct node *ptrptr=NULL;
		
		while(trptr!=NULL)
		{
			ptrptr=trptr;
			if(x<trptr->data)
			trptr=trptr->lcptr;
			else
			trptr=trptr->rcptr;
				
			
		}
		if(x<ptrptr->data)
		ptrptr->lcptr=temp;
		else
		ptrptr->rcptr=temp;
	}
	return;
}

void preorder(struct node *ptr)
{
if(ptr!=NULL)
	{
	
	printf("%d",ptr->data);
	preorder(ptr->lcptr);
	preorder(ptr->rcptr);
    }
	
}
void inorder(struct node *ptr)
{
if(ptr!=NULL)
	{
	
	inorder(ptr->lcptr);
	printf("%d",ptr->data);
	inorder(ptr->rcptr);
    }
	
}
void postorder(struct node *ptr)
{
if(ptr!=NULL)
	{
	
	postorder(ptr->lcptr);
	postorder(ptr->rcptr);
	printf("%d",ptr->data);
    }
	
}

void delete(int x)
{
struct node *ptr=rptr;
struct node *pptr=NULL;

while(ptr!=NULL)
{
	if(x==ptr->data)
     break;
     else if(x<ptr->data)
     {
     	pptr=ptr;
		 ptr=ptr->lcptr;
	 }
     
     else
     {
     	pptr=ptr;
     	ptr=ptr->rcptr;
	 }
	 
	
}
if(ptr->lcptr==NULL && ptr->rcptr==NULL)
{
	if(pptr==NULL)
	{
		rptr=NULL;
		return;
	}
	if(x<pptr->data)
	pptr->lcptr=NULL;
	else
	pptr->rcptr=NULL;
	}
	
	else if(ptr->lcptr!=NULL && ptr->rcptr!=NULL)
	{
		struct node *succ=ptr->rcptr,*psucc=ptr;
		
		while(succ->lcptr!=NULL)
		{
			psucc=succ;
			succ=succ->lcptr;
		}
		ptr->data=succ->data;
		
		if(succ->data < psucc->data)
		{
			if(succ->rcptr!=NULL)
			{
			psucc->lcptr=succ->rcptr;	
			}
			else
			psucc->lcptr=NULL;
		}
		else
		psucc->rcptr=succ->rcptr; 
		}	
	else
	{
		if(pptr==NULL)
		{
			if(ptr->lcptr!=NULL)
			{
				rptr=ptr->lcptr;
			}
			else if(ptr->rcptr!=NULL)
			{
				rptr=ptr->rcptr;
			}
		}
		else if(x<pptr->data)
 			{
				if(ptr->lcptr!=NULL)
				pptr->lcptr=ptr->lcptr;
				else
				pptr->lcptr=ptr->rcptr;
			}
		
		else
		{
			
		   if(ptr->lcptr!=NULL)
		   {
		   	pptr->rcptr=ptr->lcptr;
		   }
		   else if(ptr->rcptr!=NULL)
		   pptr->rcptr=ptr->rcptr;
		   else
		   pptr->rcptr=NULL;
		}
	}
}
