#include<stdio.h>
#include<stdlib.h>
struct node
{
	int bucket;
	struct node *l1;
	struct node *l2;
	struct node *l3;
	int a[4];
	int size;
	struct node *pptr;
};

struct node *rptr=NULL;

struct node* createnew()
{
	struct node *tptr=malloc(sizeof(struct node));
	tptr->bucket=1;
	tptr->l1=NULL;
	tptr->l2=NULL;
	tptr->l3=NULL;
	tptr->pptr=NULL;
	tptr->a[0]=-111;
	tptr->a[1]=-111;
	tptr->a[2]=-111;
	tptr->a[3]=-111;
	tptr->size=0;
	return(tptr);
}

struct node* createnode()
{
  struct node *tptr=malloc(sizeof(struct node));
     tptr->bucket=0;
     tptr->pptr=NULL;
     tptr->l1=NULL;
     tptr->l2=NULL;
     tptr->l3=NULL;
	
     tptr->a[0]=-111;
     tptr->a[1]=-111;
     tptr->a[2]=-111;
     tptr->a[3]=-111;
     tptr->size=0;
    return(tptr);
}

void print(struct node *ptr)
{
	int i;

	if(ptr->bucket==0)
	{
		print(ptr->l1);     //display values in node
		if(ptr->l2!=NULL)
			print(ptr->l2);
		if(ptr->l3!=NULL)
			print(ptr->l3);
	}

	else
	{
		//display values in bucket
		for(i=0;i<3;i++)
		printf(" %d\n",ptr->a[i]);
		
	}
}

struct node* sort(struct node *ptr)
{
	int i,j,temp;

	if(ptr->bucket==0)
	{
	    ptr->l1=sort(ptr->l1);
		
                   if(ptr->l2!=NULL)
                       {                      //To place elements in ascending order in node and bucket
			ptr->l2=sort(ptr->l2);
		       }    
                        if(ptr->l3!=NULL)
                      {
			ptr->l3=sort(ptr->l3);
	              }
         }

	else
	{
		
		for(i=0;i<3;i++)
		{
		  for(j=0;j<3-i;j++)
	            {
			 if(ptr->a[j]!=-111 && ptr->a[j+1]!=-111)
			    {
			       if(ptr->a[j]>ptr->a[j+1])
				{
				      temp=ptr->a[j];
				      ptr->a[j]=ptr->a[j+1];
				      ptr->a[j+1]=temp;
				}
			    }
	           }
	    }
	}
 return(ptr);
}

int min(struct node *ptr)
{
  int i,m1=ptr->a[0];
	if(ptr->bucket==0)
	{
	 m1=min(ptr->l1);
	}
	else
	{
	if(ptr==NULL)
		return(-111);
	else if(ptr->bucket==1)
	{
		for(i=0;i<2,ptr->a[i]!=-111;i++)
			if(ptr->a[i]<m1)
				m1=ptr->a[i];

		return(m1);
	}
	}
}

struct node* insert(int n,struct node *ptr)
{



	if(ptr==NULL)
	{
		struct node *temp;
		 temp=createnew();
		 temp->a[0]=n;
		 ptr=temp;
		 ptr->size++;
	}

	else if(ptr->bucket==1 && ptr->size<4)
	{
		int i=0;
		while(i<4 && ptr->a[i]!=-111)
			i++;
		ptr->a[i]=n;
		ptr->size++;
		ptr=sort(ptr);


	}

	else if(ptr->bucket==0)
	{
		if(ptr->a[0]<n && ptr->a[1]==-111)
			ptr->l2=insert(n,ptr->l2);
		
                 else if(ptr->a[0]>n)
			ptr->l1=insert(n,ptr->l1);
		
                   else
			ptr->l3=insert(n,ptr->l3);
	}

	     if(ptr->bucket==1 && ptr->size==4 && ptr->pptr==NULL)
		{
			struct node *temp;struct node *b;
			temp=createnode();
                        b=createnew();
			temp->l1=ptr;
			temp->l1->pptr=temp;
			temp->l2=b;
			temp->l2->pptr=temp;
			temp->l2->a[0]=ptr->a[2];
			temp->l2->size++;
			temp->l2->a[1]=ptr->a[3];
			temp->l2->size++;
			ptr->a[2]=-111;
			ptr->size--;
			ptr->a[3]=-111;
			ptr->size--;
			temp->a[0]=min(temp->l2);
			ptr->pptr=temp;
		  return(temp);

	       }


	if(ptr->bucket==0 && ptr->l1->bucket==1)
	   {
					
	           if(ptr->l3==NULL)
			{
                           struct node *temp;
			   temp=createnew();
				
                               if(ptr->l1->size==4)
				{
 
					ptr->l3=ptr->l2;
					ptr->l2=temp;
					temp->a[0]=ptr->l1->a[2];
					temp->size++;
					
                                        temp->a[1]=ptr->l1->a[3];
					temp->size++;
					ptr->l1->a[2]=-111;
					ptr->l1->size--;
					ptr->l1->a[3]=-111;
					ptr->l1->size--;
					temp->pptr=ptr;
				
                                ptr->a[0]=min(ptr->l2);     //Finding min to put in node
				ptr->a[1]=min(ptr->l3);

				}


				else if(ptr->l2->size==4)
				{

					ptr->l3=temp;
					temp->a[0]=ptr->l2->a[2];
					temp->size++;
					temp->a[1]=ptr->l2->a[3];
					temp->size++;
					ptr->l2->a[2]=-111;
					ptr->l2->size--;
					ptr->l2->a[3]=-111;
					ptr->l2->size--;
					temp->pptr=ptr;
									ptr->a[0]=min(ptr->l2);
				ptr->a[1]=min(ptr->l3);

				}

				
			}

			else if(ptr->l3!=NULL)
			{
				struct node *temp;
				temp=createnode();
				struct node *b;
				b=createnew();
				struct node *root;
				root=createnode();



				if(ptr->l1->size==4)
				{
					b->a[0]=ptr->l1->a[2];
					b->size++;
					b->a[1]=ptr->l1->a[3];
					b->size++;
					ptr->l1->a[2]=-111;
					ptr->l1->size--;
					ptr->l1->a[3]=-111;
					ptr->l1->size--;
					ptr->pptr=root;
					temp->l2=ptr->l3;
					temp->l2->pptr=temp;
					temp->l1=ptr->l2;
					temp->l1->pptr=temp;
					ptr->l3=NULL;
					ptr->l2=b;
					b->pptr=ptr;

					temp->a[0]=min(temp->l2);
					ptr->a[1]=-111;
					root->l1=ptr;
					root->l2=temp;
					temp->pptr=root;
					root->a[0]=min(root->l2);
					ptr=root;


				}

				else if(ptr->l2->size==4)
				{
					b->a[0]=ptr->l2->a[2];
					b->size++;
					b->a[1]=ptr->l2->a[3];
					b->size++;
					ptr->l2->a[2]=-111;
					ptr->l2->size--;
					ptr->l2->a[3]=-111;
					ptr->l2->size--;
					ptr->pptr=root;
					temp->l2=ptr->l3;
					temp->l2->pptr=temp;
					temp->l1=b;
					temp->l1->pptr=temp;
					ptr->l3=NULL;

					temp->a[0]=min(temp->l2);
					ptr->a[1]=-111;
					root->l1=ptr;
					root->l2=temp;
					temp->pptr=root;
					root->a[0]=min(root->l2);
					ptr=root;

				}

				else if(ptr->l3->size==4)
				{
					b->a[0]=ptr->l3->a[2];
					b->size++;
					b->a[1]=ptr->l3->a[3];
					b->size++;
					ptr->l3->a[2]=-111;
					ptr->l3->size--;
					ptr->l3->a[3]=-111;
					ptr->l3->size--;
					ptr->pptr=root;

					
					
					temp->l1=ptr->l3;
					temp->l1->pptr=temp;
					temp->l2=b;
					temp->l2->pptr=temp;
					
					ptr->l3=NULL;
					ptr->a[1]=-111;
					temp->a[0]=min(temp->l2);
					root->l1=ptr;
					root->l2=temp;
					temp->pptr=root;
					root->a[0]=min(root->l2);
					ptr=root;
				}

			}
		}

		if(ptr->bucket==0 && ptr->pptr!=NULL)
		{
			int count1=0,count2=0;
			struct node *current=ptr;
			while(current!=NULL && current->bucket==0)
			{
				current=current->l1;
				count1++;
			}

			current=ptr;
			while(current!=NULL && current->bucket==0)
			{
				current=current->l2;
				count2++;
			}

			if(count1>count2)
			{
				if(ptr->l1->l3==NULL)
				{
					ptr->l3=ptr->l2;
					ptr->l2=ptr->l1->l2;
					ptr->l1=ptr->l1->l1;
				}

				else
				{
					struct node *new;
					new=createnode();
					new->l2=ptr->l2;
					new->l1=ptr->l1->l3;
					ptr->l2=new;
					ptr->l1->l3=NULL;
					new->pptr=ptr;
					new->l1->pptr=new;
					new->l2->pptr=new;

					new->a[0]=min(new->l2);
					
				}
			}

			else if(count2>count1)
			{
				if(ptr->l2->l3==NULL)
				{
					ptr->l3=ptr->l2->l2;
					ptr->l2=ptr->l2->l1;
				}

				else
				{
					struct node *new;
					new=createnode();
					new->l1=ptr->l1;
					new->l2=ptr->l2->l1;
					ptr->l2->l1=ptr->l2->l2;
					ptr->l2->l2=ptr->l2->l3;
					ptr->l2->l3=NULL;
					ptr->l1=new;
					new->l1->pptr=new;
					new->l2->pptr=new;

					new->a[0]=min(new->l2);

				}
			}
			ptr->l1->pptr=ptr;
			ptr->l2->pptr=ptr;
			if(ptr->l3!=NULL)
			ptr->l3->pptr=ptr;	

			

					ptr->a[0]=min(ptr->l2);
					if(ptr->l3!=NULL)
					ptr->a[1]=min(ptr->l3);	
		}
						
			





	return(ptr);
}


int main()
{
	int i,n,k;
	for(i=0;;i++)
	{
		printf("\n 1.Insert 2.Display \n");
		scanf("%d",&n);

		if(n==1)
		{
			printf("\n Enter the key: \n");
			scanf("%d",&k);
			rptr=insert(k,rptr);
		}

		if(n==2)
			print(rptr);

	}
	



	
	return(0);
}

