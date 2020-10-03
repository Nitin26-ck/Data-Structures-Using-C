#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *temp,*front,*rear,*front1;
void create()
{
	front=rear=NULL;
}
void enq(int data)
{
	if(rear==NULL)
	{
		rear=(struct node*)malloc(sizeof(struct node));
		rear->next=NULL;
		rear->data=data;
		front=rear;
	}
	else
	{
		temp=(struct node*)malloc(sizeof(struct node));
		rear->next=temp;
		temp->data=data;
		temp->next=NULL;
		rear=temp;
	}
}
void deq()
{
	front1=front;
	if(front1==NULL)
	{
		printf("cant dequeue\n");
		return;
	}
	else
	{
		if(front->next!=NULL)
		{
			front1=front1->next;
			printf("dequeued value is %d\n",front->data);
			free(front);
			front=front1;
		}
		else
		{
			printf("dequeued value is %d\n",front->data);
			free(front);
			front=NULL;
			rear=NULL;
		}
	}
}
void display()
{
	front1=front;
	if((front1==NULL)&&(rear==NULL))
	{
		printf("empty q\n");
		return;
	}
	while(front1!=rear)
	{
		printf("%d\n",front->data);
		front1=front1->next;
	}
	if(front1==rear)
	{
		printf("%d\n",front1->data);
	}
}
void main()
{
	int n,ch,ele;
	while(1)
	{
		printf("1.enq,2.deq,3.display,4.exit\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter data\n");
				scanf("%d",&n);
				enq(n);
				break;
			case 2: deq();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("invalid choice\n");
				 break;
		}
	}
}
