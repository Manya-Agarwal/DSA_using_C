#include<stdio.h>
int merge(int a[],int lb,int mid,int ub)
{   
    int b[ub+1];
	int i=lb;
	int j=mid+1;
	int k=lb;
	while(i<=mid && j<=ub)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
if(i>mid)
{  while(j<=ub)
	{
		b[k]=a[j];
		j++;
		k++;
	}
}
	else
{
    while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}

}
   
	for(i=lb;i<=ub;i++)
	{
		a[i]=b[i];
	}
}
int mergesort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
	  int mid=(lb+ub)/2;
	  mergesort(a,lb,mid);
	  mergesort(a,mid+1,ub);
	  merge(a,lb,mid,ub);
	}
}
void main()
{	
	int n,i;
	printf("enter number of elements:");
	scanf("%d",&n);
	int a[n];
	printf("enter elements in the array:");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int lb=0;
	int ub=n-1;
	mergesort(a,lb,ub);
	int j;
	for(j=0;j<n;j++)
	{
	printf(" %d ",a[j]);
	}
}

