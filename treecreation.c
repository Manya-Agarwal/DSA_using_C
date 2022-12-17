#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*left;
	struct node*right;
};
struct node*create()
{
	struct node*newnode;
	int data,choice;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter 0 to exit\nEnter 1 to insert: ");
	scanf("%d",&choice);
	if(choice==0)
	return;
	else
	{
	printf("\nEnter data: ");
    scanf("%d",&data);
	newnode->data=data;
    printf("\nEnter left child for %d",data);
	newnode->left=create();
	printf("\nEnter right child for %d",data);
	newnode->right=create();
    return newnode;
    }
}
void inorder(struct node*root)
{
	printf("\n\tINORDER TRAVERSAL\t\n");
	if(root==0)
	return;
	else
	{
		inorder(root->left);
		printf("%d,",root->data);
		inorder(root->right);
	}
}
void preorder(struct node*root)
{
	printf("\n\PREORDER TRAVERSAL\t\n");
	if(root==0)
	return;
	else
	{
		printf("%d,",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node*root)
{
	printf("\n\POSTORDER TRAVERSAL\t\n");
	if(root==0)
	return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d,",root->data);
	}
}
void main()
{
	int code;
	struct node*root;
	root=create();
	printf("\nEnter 0 to exit\nEnter 1 to traverse inorder\nEnter 2 to traverse preorder\nEnter 3 to traverse postorder: ");
	scanf("%d",&code);
	switch(code)
	{
		case 0:
			printf("\nprogram terminated\n");
			exit(0);
			break;
		case 1:
			inorder(root);
			break;
		case 2:
			preorder(root);
			break;
		case 3:
			postorder(root);
			break;
		default:
			printf("\nenter valid choice!!\n");
	}
}
