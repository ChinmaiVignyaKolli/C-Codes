#include<stdio.h>
int main()
{
int i,j,n,r;
	printf("Enter n and r");
	scanf("%d \n %d",&n,&r);
	int a[n+1][r+1];
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if((j=0)|| (i==j))
{
	a[i][j]==1;

}
else
{
	a[i][j]=a[i-1][j-1]+a[i-1][j];
}
}
}
printf("%d",a[n][r]);	
return 0;	
}
