#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *temp=NULL, *ptr=NULL, *last=NULL;
void insertbeg()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(last==NULL)
	{
		last=temp;
		last->next=temp;
	}
	else
	{
		temp->next=last->next;
		last->next=temp;
	}
}
void insertend()
{
	temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&temp->data);
        temp->next=NULL;
	if(last==NULL)
	{
		last=temp;
		last->next=temp;
	}
	else
	{
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
}
void insertpos()
{
	int pos,count=0,i;
	ptr=last->next;
	while(ptr!=last)
	{
		count++;
		ptr=ptr->next;
	}
	count++;
	printf("enter the position of node at which insertion has to be done\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		insertbeg();
	}
	else if(pos==count+1)
	{
		insertend();
	}
	else if(pos>1 && pos<count)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter data\n");
		scanf("%d",&temp->data);
		temp->next=NULL;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
}
void deletebeg()
{
	if(last==NULL)
	{
		printf("empty list\n");
	}
	else if(last->next==NULL)
	{
		free(last);
		last=NULL;
		
	}
	else
	{
		ptr=last->next;
		last->next=ptr->next;
		free(ptr);
	}
}
void deleteend()
{
	if(last==NULL)
	{
		printf("empty list\n");
	}
	else if(last->next==last)
	{
		free(last);
		last=NULL;
	}
	else
	{
		ptr=last->next;
		while(ptr->next!=last)
		{
			ptr=ptr->next;
		}
		ptr->next=last->next;
		free(last);
		last=ptr;
	}
}
void deletepos()
{
	int pos=0,count=0,i=1;
	if(last==NULL)
	{
		printf("empty list\n");
	}
	else
	{
		ptr=last->next;
		while(ptr!=last)
		{
			count++;
			ptr=ptr->next;
		}
		count++;
		printf("enter the nodes position at which deletion has to be done\n");
		scanf("%d",&pos);
		if(pos==1)
		{
			deletebeg();
		}
		else if(pos==count)
		{
			deleteend();
		}
		else 
		{
			ptr=last->next;
			while(i<pos-1)
			{
				ptr=ptr->next;
				i++;
			}
			ptr->next=temp->next;
			free(temp);

		}
	}
}

void display()
{
	if(last==NULL)
	{
		printf("empty list\n");
	}

	else
	{
		ptr=last->next;
		while(ptr!=last)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\n",ptr->data);
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

