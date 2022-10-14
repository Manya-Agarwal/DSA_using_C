#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*head=0;
void insert(int x)
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	if(head==0)
	{
		newnode->next=0;
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void display()
{
	struct node*temp=head;
	if(head==0)
	  printf("\nNothing to Print\n");
	else
	{
		printf("\n\tPrinting Values\t\n");
		while(temp->next!=0)
		{
			printf("\n%d",temp->data);
			temp=temp->next;
		}
		printf("\n%d",temp->data);
	}
}
void main()
{
	int choice,x;
	do
	{
	printf("\nEnter 0 to exit\nEnter 1 to insert\nEnter 2 to display: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 0:
			printf("\nProgram Terminated\n");
			exit(0);
			break;
		case 1:
			printf("\nEnter data: ");
			scanf("%d",&x);
			insert(x);
			break;
		case 2:
			display();
			break;
		default:
			printf("\nEnter Valid Choice!!\n");
	}
    }while(choice!=0);
}
