 #include<stdio.h>
 #include<stdlib.h>
 struct node
 {
int data;
struct node*nptr; 
struct node *pptr;
 
 } ;
 struct node *hptr=NULL;
 void insert(int,int);
 void delete(int);
 void display();
 int main()
 {
 	insert(7,1);
 	insert(5,2);
 	insert(4,3);
 	insert(8,4);
 	
 	display();
 	return 0;
 }
 
 
 void insert(int x,int pos)
 {
 	
 	struct node *temp; 
 	temp=(struct node*)malloc(sizeof(struct node));
 	temp->data=x;
 	if(hptr==NULL)
 	{
 		temp->pptr=NULL;
 		temp->nptr=NULL;
		temp=hptr;
 		
	 }
	 
	 else if(pos==1)
	 {
	 	temp->pptr=NULL; 
	 temp->nptr=hptr;
	 hptr=temp;
	 	
	 }
	 else
	 { int i=1;
	 	struct node *thptr=hptr;
	 	while(i<pos-1)
	 	{
	 		thptr=thptr->nptr;
	 		i++;
		 }
		 temp->nptr=thptr->nptr;
		 temp->pptr=thptr;
		  
		  
		if(thptr->nptr!=NULL)
		{
		    (thptr->nptr)->pptr=temp;
			thptr->nptr=temp;
			
				}		
		
		 
	 }
	
 }
 
 
 void delete(int pos)
 {int i=1;
 	struct node *thptr=hptr;
 	if(pos==1)
 	{
 	
 		hptr=hptr->nptr;
	 }
	 else
	 {
	 	while(i<pos-1)
	 	{
	 		thptr=thptr->nptr;
	 		i++;
		 }
		
		 thptr->nptr=(thptr->nptr)->nptr;
	 }
 }
 
 
 void display()
 {
 	struct node *thptr=hptr;
 	while(thptr!=NULL)
 	{
 		printf("%d",thptr->data);
 		thptr=thptr->nptr;
	 }
 }
