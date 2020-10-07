#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head;
void createlist(int n)
{
	struct node *newnode,*ptr,*temp;
	int data,i;
	if(n<=0)
	{
		printf("no nodes in the list\n");
	}
	head=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("unable to locate in the memory\n");
	}
	else
	{
		printf("enter the data of node 1\n");
		scanf("%d",&data);
		head->data=data;
		head->next=NULL;
		temp=head;
		for(i=2;i<=n;i++)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			if(newnode==NULL)
			{
				printf("unable to allocate memory\n");
			}
			else
			{
				printf("enter data of node%d\n",i);
				scanf("%d",&data);
				newnode->data=data;
				newnode->next=NULL;
				temp->next=newnode;
				temp=temp->next;
			}
		}
		printf("list created\n");
	}
}
void reverselist()
{
	struct node *prevnode,*curnode;
	if(head!=NULL)
	{
		prevnode=head;
		curnode=head->next;
		head=head->next;
		prevnode->next=NULL;
		while(head!=NULL)
		{
			head=head->next;
			curnode->next=prevnode;
			prevnode=curnode;
			curnode=head;
		}
		head=prevnode;
	}
	printf("list reversed\n");
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("data=%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void main()
{
	int ch,i,n;

	printf("enter no of nodes\n");
	scanf("%d",&n);
	createlist(n);
	printf("elements in the list is:\n");
	display();
	printf("enter 1 to reverse a list\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		reverselist();
		printf("contents of the list after reversing is:\n");
		display();
	}
}




