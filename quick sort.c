#include<stdio.h>
void quicksort(int,int);
int partition(int,int);
int main()
{
	
	return 0;
}
void quicksort(int p,int q)
{
	int j;
	if(p<q)
	{
		j=partition(p,q);
		quicksort(p,j-1)
		quicksort(j+1,q);
		
	}
	
}

int partition(int beg,int end)
{
	int pivot=a[beg];
	int i=beg,j=end,temp;
	while(i<=j)
	{
	
	while(a[i]<=pivot && i<=end)
		i++;
	while(a[j]>pivot && j>=beg)
	j--;
	
	if(i<j)
	{
		temp=a[j];
		a[j]=a[i];
		a[j]=temp;
	}
}
temp=a[j];
a[j]=a[beg];
a[beg]=temp;
return j;
}

