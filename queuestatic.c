#include<stdio.h>   
#include<stdlib.h>  
#define maxsize 5  
void Enqueue();  
void Dequeue();  
void display();
void peek();
void isempty();
void isfull();  
int front = -1, rear = -1;  
int queue[maxsize];  
void main ()  
{  
    int choice;
	do   
    {     
        printf("\n\t\tMain Menu\t\t\n");  
        printf("\n=================================================================\n");  
        printf("\n0.Exit\n1.enqueue an element\n2.Dequeue an element\n3.Display the queue\n4.Peek the queue\n5.Empty or not\n6.Full or not");  
        printf("\nEnter your choice ?");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:
			{  
            Enqueue();  
            break;
		    }
            case 2:  
            Dequeue();  
            break;  
            case 3:  
            display();  
            break;  
            case 0:  
            exit(0);  
            break;
			case 4:
			peek();
			break;
			case 5:
			isempty();
			break;
			case 6:
			isfull();
			break; 
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }while(choice!=0);  
}  
void Enqueue()  
{  
    int item;  
    printf("\nEnter the element\n");  
    scanf("\n%d",&item);      
    if(rear == maxsize-1)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;  
    printf("\nValue inserted ");  
      
}  
void Dequeue()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
              
    }  
    else  
    {  
        item = queue[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        }  
        printf("\nvalue deleted ");  
    }  
      
      
}  
      
void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        for(i=front;i<=rear;i++)  
        {  
            printf("\n%d",queue[i]);  
        }     
    }  
} 

void peek()
{
	if(front==-1 && rear==-1)
	  printf("Queue is empty");
	else
	  printf("%d",queue[front]);
}

void isempty()
{
    if(front==-1 && rear==-1)
	  printf("Queue is empty");
	else
	  printf("Queue is not empty");	
} 

void isfull()
{
	if(rear== maxsize-1)
	  printf("Queue is full");
	else
	  printf("Queue is not full");
}
