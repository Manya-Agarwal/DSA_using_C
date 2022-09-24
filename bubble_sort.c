#include<stdio.h>
void Bubble(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		    }
		}
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
	printf("before sorting array elements are-\n");
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
	Bubble(a,n);
	printf("\nafter sorting array elements are-\n");
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
}
