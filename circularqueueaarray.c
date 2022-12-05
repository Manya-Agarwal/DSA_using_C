#include <stdio.h>  
#include<stdlib.h>  
# define max 6  
int queue[max];   
int front=-1;  
int rear=-1;    
void enqueue(int element)  
{ 
    if(front==-1 && rear==-1)   
    {  
        front=0;  
        rear=0;  
        queue[rear]=element;  
    }  
    else if((rear+1)%max==front)   
    {  
        printf("Queue is overflow..");  
    }  
    else  
    {  
        rear=(rear+1)%max;        
        queue[rear]=element;     
    }  
}  
  
int dequeue()  
{  
    if((front==-1) && (rear==-1))    
    {  
        printf("\nQueue is underflow..");  
    }  
 else if(front==rear)  
{  
   printf("\nThe dequeued element is %d", queue[front]);  
   front=-1;  
   rear=-1;  
}   
else  
{  
    printf("\nThe dequeued element is %d", queue[front]);  
   front=(front+1)%max;  
}  
}    
void display()  
{  
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        printf("\n Queue is empty..");  
    }  
    else  
    {  
        printf("\nElements in a Queue are :"); 
        while(i!=rear)  
        {  
            printf("%d,", queue[i]);  
            i=(i+1)%max;  
        }
		printf("%d",queue[i]);  
    }  
}
void frontprint()
{
	if(front==-1 && rear==-1)
	printf("\nQueue is empty");
	else
	printf("\nThe element at front is %d",queue[front]);
} 
void rearprint()
{
	if(front==-1 && rear==-1)
	printf("\nQueue is empty");
	else
	printf("\nThe element at rear is %d",queue[rear]);
 } 
void isfull()
{
	if((rear+1)%max==front)
	printf("\nQueue is full");
	else
	printf("\nQueue is not full");
}
void isempty()
{
	if(front==-1 && rear==-1)
	printf("\nQueue is empty");
	else
	printf("\nQueue is not empty");
}
int main()  
{  
    int choice,x;     
      
    do     
    {
	printf("\n\nPress 0: To exit");  
    printf("\n Press 1: Enqueue an element");  
    printf("\nPress 2: Dequeue an element");  
    printf("\nPress 3: Display the element"); 
	printf("\nPress 4: To display the front of element");
	printf("\nPress 5: To display the rear of element");
	printf("\nPress 6: To check if the queue is full");
	printf("\nPress 7: To check if the queue is empty"); 
    printf("\nEnter your choice");  
    scanf("%d", &choice);  
      
    switch(choice)  
    { 
	    case 0:
	    	printf("\nProgram Terminated\n");
	    	exit(0);
	    	break;
          
        case 1:  
      
        printf("Enter the element which is to be inserted");  
        scanf("%d", &x);  
        enqueue(x); 
        break;  
        case 2:  
        dequeue();  
        break;  
        case 3:  
        display();
        break;
        case 4:
        frontprint();
        break;
        case 5:
        	rearprint();
        	break;
        case 6:
        	isfull();
        	break;
        case 7:
        	isempty();
        	break;
		default:
		printf("\nEnter invalid choice!!!\n"); 
  
    }
	}while(choice!=0); 
    return 0;  
} 


