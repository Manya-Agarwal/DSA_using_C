#define size 5    
#include <stdio.h>
#include<stdlib.h>  
int deque[size];  
int f=-1, r=-1;  
//  enqueue_front function will insert the value from the front  
void enqueue_front(int x)  
{  
    if((r+1)%size==f)  
    {  
        printf("deque is full");  
    }  
    else if((f==-1) && (r==-1))  
    {  
        f=r=0;  
        deque[f]=x;  
    }  
    else if(f==0)  
    {  
        f=size-1;  
        deque[f]=x;  
    }  
    else  
    {  
        f=f-1;  
        deque[f]=x;  
    }  
}  
  
// enqueue_rear function will insert the value from the rear  
void enqueue_rear(int x)  
{  
    if((r+1)%size==f)  
    {  
        printf("deque is full");  
    }  
    else if((f==-1) && (r==-1))  
    {  
        r=0;  
        deque[r]=x;  
    }  
    else if(r==size-1)  
    {  
        r=0;  
        deque[r]=x;  
    }  
    else  
    {  
        r++;  
        deque[r]=x;  
    }  
  
}  
  
// display function prints all the value of deque.  
void display()  
{  
    int i=f;  
    printf("\n Elements in a deque : ");  
      
    while(i!=r)  
    {  
        printf("%d ",deque[i]);  
        i=(i+1)%size;  
    }  
     printf("%d",deque[r]);  
}  
  
// getfront function retrieves the first value of the deque.  
void getfront()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else  
    {  
        printf("\nThe value of the front is: %d", deque[f]);  
    }  
      
}  
  
// getrear function retrieves the last value of the deque.  
void getrear()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else  
    {  
        printf("\nThe value of the rear is: %d", deque[r]);  
    }  
      
}  
  
// dequeue_front() function deletes the element from the front  
void dequeue_front()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else if(f==r)  
    {  
        printf("\nThe deleted element is %d", deque[f]);  
        f=-1;  
        r=-1;  
          
    }  
     else if(f==(size-1))  
     {  
         printf("\nThe deleted element is %d", deque[f]);  
         f=0;  
     }  
     else  
     {  
          printf("\nThe deleted element is %d", deque[f]);  
          f=f+1;  
     }  
}  
  
// dequeue_rear() function deletes the element from the rear  
void dequeue_rear()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else if(f==r)  
    {  
        printf("\nThe deleted element is %d", deque[r]);  
        f=-1;  
        r=-1;  
          
    }  
     else if(r==0)  
     {  
         printf("\nThe deleted element is %d", deque[r]);  
         r=size-1;  
     }  
     else  
     {  
          printf("\nThe deleted element is %d", deque[r]);  
          r=r-1;  
     }  
} 
void isfull() 
{
	if((r+1)%size==f)
	printf("\nQueue is full\n");
	else
	printf("\nQueue is not full\n");
}
void isempty()
{
	if(f==-1 && r==-1 )
	printf("\nQueue is empty\n");
	else
	printf("\nQueue is not empty\n");
}  
int main()  
{ 
    int choice,x;
    do
    {
    	printf("\nEnter 0 to exit \nEnter 1 to enqueue at front \nEnter 2 to enqueue at rear\nEnter 3 to dequeue at front\nEnter 4 to dequeue at rear\nEnter 5 to get front element\nEnter 6 to get rear element\nEnter 7 to check if the deque is full\nEnter 8 to check if the deque is empty\nEnter 9 to display: ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 0:
    			printf("\nProgram Terminated\n");
    			exit(0);
    			break;
    		case 1:
				printf("\nEnter the data: ");
				scanf("%d",&x);
				enqueue_front(x);
			    break;
			case 2:
				printf("\nEnter the data: ");
				scanf("%d",&x);
				enqueue_rear(x);
				break;
			case 3:
				dequeue_front();
				break;
			case 4:
				dequeue_rear();
				break;
			case 5:
				getfront();
				break;
			case 6:
				getrear();
				break;
		    case 7:
		    	isfull();
		    	break;
		    case 8:
		    	isempty();
		    	break;
		    case 9:
		    	display();
		    	break;
			default:
			printf("\nEnter invalid choice!!!!");
			break;	
		}
	}while(choice!=0);
     return 0;  
}  

