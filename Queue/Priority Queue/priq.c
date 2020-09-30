#include<stdio.h>
#include<stdlib.h>
#define size 5
int q[size];
int rear=-1;
void enq()
{
	if(rear==size-1)
	{
		printf("queue is full\n");
		return;
	}
	else
	{
		printf("enter the value\n");
		int ele,i;
		scanf("%d",&ele);
		if(rear==-1)
		{
			q[++rear]=ele;
		}
		else
		{
			for(i=rear;i>=0;i--)
			{
				if(ele>q[i])
					q[i+1]=q[i];
				else 
					break;
			}
			q[i+1]=ele;
			rear++;
		}
	}
}
void deq()
{
	if(rear==-1)
	{
		printf("q is empty\n");
		return;
	}
	else
	{
		q[rear--];
	}
}
void display()
{
	if(rear==-1)
	{
		printf("q is empty\n");
	}
	else
	{
		int i;
		printf("contents of q are\n");
		for(i=0;i<=rear;i++)
		{
			printf("%d\n",q[i]);
		}
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf("1:enq,2:deq,3:display,4:exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enq();
				break;
			case 2: deq();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default:printf("invalid choice\n");
				break;
		}
	}
}
