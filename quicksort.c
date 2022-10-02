#include<stdio.h>
int swap(int a[],int c,int b)
{
	int temp=a[c];
	a[c]=a[b];
	a[b]=temp;
}
int partition( int a[],int l, int h)
{
	int pivot=a[l];
	int start=l;
	int end=h;
	while(start<end)
	{
		while(a[start]<=pivot)
		start++;
		while(a[end]>pivot)
		end--;
		if(start<end)
		swap(a,start,end);
	}
	swap(a,l,end);
	return end;
}
int Quicksort(int a[],int l,int h)
{
	if(l<h)
	{
	int pivot=partition(a,l,h);
	Quicksort(a,l,pivot-1);
	Quicksort(a,pivot+1,h);
    }
}
int main()
{
	int a[]={7,6,10,5,9,2,1,15,7};
	int n=sizeof(a)/sizeof(a[0]);
	int l=0;
	int h=n-1;
	Quicksort(a,l,h);
	int x;
	for(x=0;x<n;x++)
	{
		printf(" %d ",a[x]);
	}
	return 0;
}
