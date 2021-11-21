#include<stdio.h>
int a[100];
void merge(int,int);
void mergesort(int,int);
int main()
{
	int n,i;
	printf("Enter the no of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	mergesort(0,n-1);
	
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	
	return 0;
}

void mergesort(int p,int q)
{
	int mid=(p+q)/2;
	
	  if(p<q)
	{
		mergesort(p,mid);
		mergesort(mid+1,q);
		merge(p,q);
	}
}

void merge(int beg,int end)
{
	int mid=(beg+end)/2;
	int i=beg,j=mid+1,k=0;
	int b[100];
	
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			i++;
		}
		k++;
	 } 
	 
	 while(a[i]<=mid)
	 {
	 	b[k]=a[i];
	 	k++;
	 	i++;
	 }
	 
	 while(a[j]<=end)
	 {
        b[k]=a[j];
		k++;
		j++;	 	
	 }
	
	for(i=beg;i<end;i++)
	{
		a[i]=b[i-beg];
		printf("%d",b[i-beg]);
		
	}
	
}
