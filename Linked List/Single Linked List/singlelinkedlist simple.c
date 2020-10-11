#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *ptr,*newnode,*temp;
struct node *head=NULL;
void insertbeg()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void insertend()
{
	newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&newnode->data);
	if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=NULL;
	}
}
void insertpos()
{
	int pos,count=0,i=1;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the node position at which data has to be inserted\n");
	scanf("%d",&pos);
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	if(pos==1)
	{
		insertbeg();
	}
	else if(pos==count+1)
	{
		insertend();
	}
	else if(pos>count || pos<0)
	{
		printf("cant insert, out of bound\n");
	}
	else
	{
		temp=head;
		printf("enter the data\n");
		scanf("%d",&newnode->data);
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	
}
void deletebeg()
{
	if(head==NULL)
	{
		printf("empty list \n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
	}
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
	}

}
void deletepos()
{
	int pos,count=0,i=1;
	if(head==NULL)
		printf("empty list\n");
	else
	{
		temp=head;
		printf("enter node's position whose data is to be deleted\n");
		scanf("%d",&pos);
		while(temp!=NULL)
		{
			temp=temp->next;
			count++;
		}
		if(pos==1)
		{
			deletebeg();
		}
		else if(pos==count)
		{
			deleteend();
		}
		else if(pos>count || pos<0)
		{
			printf("out of bound cant delete\n");
		}
		else
		{
			temp=head;
			while(i<pos-1)
			{
				temp=temp->next;
				i++;
			}
			ptr=temp->next;
			temp->next=ptr->next;
			free(ptr);
		}
	}
}
void deleteend()
{
	if(head==NULL)
	{
		printf("empty list\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		free(temp);
	}
}

void display()
{
	if(head==NULL)
		printf("empty list\n");
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf("1.display,2.insertbeg,3.insertend,4.insertpos,5.deletebeg,0.quit\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: display();
				break;
			case 2: insertbeg();
				break;
			case 3: insertend();
				break;
			case 4: insertpos();
				break;
			case 5: deletebeg();
				break;
			case 6: deleteend();
				break;
			case 7: deletepos();
				break;
			case 0: exit(0);
			default: printf("invalid choice\n");
				 break;
		}
	}
}
