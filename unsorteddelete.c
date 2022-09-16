#include<stdio.h>
int search_unsorted(int a[], int key, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		return i;
	}
	return -1;
}
int deletion(int a[],int key, int n)
{
	int loc,i;
	loc=search_unsorted(a,key,n);
	for(i=loc;i<n-1;i++)
	a[i]=a[i+1];
	n--;
	return n;
}
int main()
{
	int a[]={9,6,8,4,3,5};
	int n=sizeof(a)/sizeof(a[0]);
	int i,j,key,ok;
	puts("Array before deletion\n\n");
	for(i=0;i<n;i++)
	printf("  %d",a[i]);
	printf("\nEnter key");
	scanf("%d",&key);
	ok=deletion(a,key,n);
	puts("\n\nArray after deletion\n\n");
	for(j=0;j<ok;j++)
	printf("  %d",a[j]);
	return 0;
}
