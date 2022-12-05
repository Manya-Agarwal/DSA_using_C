#include<stdio.h>
#include<stdlib.h>
int a[]={5,6,9,1,2};
void swap(int i,int j)
{
	int temp=a[j];
	a[j]=a[i];
	a[i]=temp;
}

int partition(int start,int end)
{
	int pivot=a[end];
	int i= start-1;
	int j;
	for(j=start;j<end;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(i,j);
		}
	}
	swap(i+1,end);
	return (i+1);
}

int randompartition(int start,int end)
{
	srand(time(NULL));
    int random = start + rand() % (end - start);
	swap(end,random);
	return partition(start,end);
}

int quicksort(int start, int end)
{
	if (start<end)
	{
		int pivot=randompartition(start,end);
		quicksort(start,pivot-1);
		quicksort(pivot+1,end);
	}
}

void print(int size)
{
	int i;
	for (i=0;i<size;i++)
	printf(" %d ",a[i]);
}

int main()
{
	int n=sizeof(a)/sizeof(a[0]);
	printf("Before sorting\n");
	print(n);
	quicksort(0,n-1);
	printf("\n\nAfter randomised quicksort\n");
	print(n);
	return 0;
}
