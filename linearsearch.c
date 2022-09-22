#include<stdio.h>
int search_unsorted(int a[], int key, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		return i+1;
	}
	return -1;
}
int main()
{
	int a[]={8,7,9,76,54,32,1};
	int key,n,pos;
	n=sizeof(a)/sizeof(a[0]);
	printf("enter the key\n");
	scanf("%d",&key);
	pos=search_unsorted(a,key,n);
	if (pos>0)
	printf("\nElement found at %d position",pos);
	else
	printf("\nElement not found");
	
	return 0;
}
