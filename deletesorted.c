#include<stdio.h>
int binarysearch(int a[],int l,int h,int key)
{
	int mid;
	mid=(l+h)/2;
	if(h<l)
		return -1;
    else if(a[mid]==key)
	return mid;
	else if(key>a[mid])
	return binarysearch(a,mid+1,h,key);
    else
	return binarysearch(a,l,mid-1,key);     
}
int deletion(int a[],int key,int n)
{
	int l=0,h=n-1,i;
	int pos= binarysearch(a,l,h,key);
	if(pos==-1)
	puts("Element do not exist");
	else
	{
		for(i=pos;i<n-1;i++)
			a[i]=a[i+1];
	}
	n--;
	return n ;
}
int main()
{
	int a[]={1,2,3,4,5,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	int i,j,key,loc;
	puts("Array before deletion\n\n");
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	printf("\nEnter key");
	scanf("%d",&key);
	deletion(a,key,n);
	puts("\n\nArray after deletion\n\n");
	for(i=0;i<n-1;i++)
	printf("%d",a[i]);
	return 0;
}
