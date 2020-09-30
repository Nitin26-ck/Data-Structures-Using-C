#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int myq[SIZE];
int ch,ele;
int front=-1;
int rear=-1;
void enq()
{
	printf("enter the element to be added\n");
	scanf("%d",&ele);
	if(rear==(SIZE-1))
		printf("queue is full\n");
	else
	{
		if(front=-1)
			front=0;
		{
			myq[++rear]=ele;
		}
	}
	printf("enqueued element is %d\n",ele);
}
void deq()
{
	if(front==-1 || front>rear)
	{
		printf("empty queue\n");
	}
	else
	{
		ele=myq[front++];
	}
	printf("dequeued element is %d\n",ele);
	if(front>rear+1)
	{
		front=-1;
		rear=-1;
	}

}
void display()
{
	int i;
	if((front==-1)||(front>rear))
	{
		printf("empty q\n");
	}
	else
	{

		printf("contents of queue are\n");
		for(i=front;i<=rear;i++)
		{	
			printf("%d\n",myq[i]);
		}
	}
}
void main()
{
	front=0;
	rear=-1;
	while(1)
	{
		printf("1-enq,2-deq,3-dispaly,4-exit\n");
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
			case 4: 
				printf("you exit the code\n");
				exit(0);
			default: 
				printf("invalid code entered\n");
				break;
		}
	}
}

