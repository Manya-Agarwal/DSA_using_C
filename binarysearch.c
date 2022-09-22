#include<stdio.h>
int binarysearch(int a[],int l,int h,int key)
{
	int mid;
	mid=(l+h)/2;
	if(h<l)
	return -1;
    if(a[mid]==key)
	return mid;
	else if(key>a[mid])
	return binarysearch(a,mid+1,h,key);
    else
	return binarysearch(a,l,mid-1,key);     
	
}
int main()
{
int a[]={1,5,8,16,20};
int n,h,l,key,index;
n=sizeof(a)/sizeof(a[0]);
h=n-1;
l=0;
puts("enter the key");
scanf("%d",&key);
index=binarysearch(a,l,h,key);
if (index==-1)
printf("Element does not exist");
else
printf("search position at %d",index+1);
return 0;
}
