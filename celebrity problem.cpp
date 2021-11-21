#include<stdio.h>

int main()
{
	
	int n,i,j;
	printf("Enter the no of ppl");
	scanf("%d",&n);
int a[n][n];
int b[n];
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
	printf("Enter a[%d][%d]",i,j);
	scanf("%d",&a[i][j]);
}
}
for(i=0;i<n;i++)
{
	b[i]=1;
for(j=0;j<n;j++)
{
	if((i!=j) && (a[i][j]==1))
	b[i]=0;
	else if(a[i][j]==0)
	b[j]=0;
}
}
for(i=0;i<n;i++)
{
	if(b[i]==1)
	printf("%d is a celebrity",i);
	}	
	for(i=0;i<n;i++)
{
	
	printf("%d ",b[i]);
	}	


//if(i==n)
//printf("there is no celebrity");
}
