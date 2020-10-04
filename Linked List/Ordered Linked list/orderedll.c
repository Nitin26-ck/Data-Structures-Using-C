#include<stdio.h>
#include<stdlib.h>
typedef struct orderedll
{
	int data;
	struct node *next;
}orderedll;
orderedll *head;
void createorderedll()
{
	orderedll *ptr,*newnode,*prev;
	ptr=newnode=prev=NULL;
	int value;
	printf("enter data\n");
	scanf("%d",&value);
	newnode=(orderedll*)malloc(sizeof(orderedll));
	newnode->data=value;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		if(newnode->data>head->data)
		{
			newnode->next=head;
			head=newnode;
		}
		else
		{
			ptr=head;
			while((ptr!=NULL)&&(newnode->data<ptr->data))
			{
				prev=ptr;
				ptr=ptr->next;
			}
			if(ptr==NULL)
			{
				prev->next=newnode;
				newnode->next=ptr;
			}
			else
			{
				prev->next=newnode;
				newnode->next=ptr;
			}
		}
	}
}
void display()
{
	orderedll *ptr;
	if(head==NULL)
	{
		printf("empty list\n");
	}
	ptr=head;
	int count=0;
	while(ptr!=NULL)
	{
		printf("node #%d data is %d\n",++count,ptr->data);
		ptr=ptr->next;
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("1.createorderedll,2.display,3.exit\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: createorderedll();
				break;
			case 2: display();
				break;
			case 3: exit(0);
			default: printf("invalid choice\n");
				 break;
		}
	}
	return 0;
}

