 #include<stdio.h>
 struct stack
 {
 	int top;
 	int a[10];
 };
  struct stack s1;
 struct stack push(struct stack s,int x);
 struct stack pop(struct stack s);
 int size=10;
 int main()
 {
 	int i,k,l,n;

 s1.top=-1;
 printf("Enter the no of elements");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 	printf("Enter element to push");
 	scanf("%d",&k);
 	s1=push(s1,k);
 }
  printf("Enter no of elements to pop");
  scanf("%d",&l);
  
  for(i=0;i<l;i++)
  s1=pop(s1);
  
  
 return 0;	
 }
 
 struct stack push(struct stack s,int x)
 {
 	int n;
 	if(s.top==size-1)
 	printf("stack is full");
 	
	 else
 	{
 		s.top = s.top+1;
 		s.a[s.top]=x;
 		printf("Top=%d",s.top);
 		
	 }
 	return s;
 }
 
 struct stack pop(struct stack s)
 {
   int x;
 	if(s.top==-1)
 	printf("Cant pop");
 	
	 else
 	{
	 x=s.a[s.top];
 	printf("%d",x);
	 s.top=s.top-1;
 	 }
 	return s;
 }
