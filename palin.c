#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*start=NULL,*startcopy=NULL;
void compare(){
	struct node *current=start,*currentcopy=startcopy;
	while(current!=NULL){
		if(current->data!=currentcopy->data){
			printf("Not a Palindrome\n");
			return;
		}
		current=current->next;
		currentcopy=currentcopy->next;
	}
	printf("Palindrome\n");
}
void copy(void){
	struct node *current=start,*newNode,*currentcopy;
	while(current!=NULL){
		newNode=(struct node *)malloc(sizeof(struct node));
		newNode->next=NULL;
		if(startcopy==NULL){
			startcopy=newNode;
			currentcopy=newNode;
		}
		else{
			currentcopy->next=newNode;
			currentcopy=newNode;
		}
		currentcopy->data=current->data;
		current=current->next;
	}		
}
void create(void){
	struct node *newNode,*current=start;
	int ch;
	do{
		newNode=(struct node *)malloc(sizeof(struct node));
		newNode->next=NULL;
		if(start==NULL){
			start=newNode;
			current=newNode;
		}
		else{
			current->next=newNode;
			current=newNode;
		}
		printf("Enter the data:");
		scanf("%d",&current->data);
		printf("Add another data(1/0):");
		scanf("%d",&ch);
	}while(ch!=0);
}
void display(void){
	struct node *current=startcopy;
	while(current!=NULL){
		printf("%d-->",current->data);
		current=current->next;
	}
	printf("NULL\n");
}
void reverse(void){
	struct node* prev   = NULL;
    struct node* current = start;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    start = prev;
}
 
	

int main(void){
	create();
	copy();
	display();
	reverse();
	printf("\n");
	display();
	compare();
	return 0;
}
