#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack *next;
}stack;
stack *top=NULL;
stack *push(stack *top,int val)
{
	stack *ptr;
	ptr=(stack*)malloc(sizeof(stack));
	ptr->data=val;
	if(top==NULL)
	{
		ptr->next=NULL;
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
	return top;
}
stack *pop(stack *top)
{
	stack *ptr;
	ptr=top;
	if(top==NULL)
	{
		printf("stack underflow\n");
	}
	else
	{
		top=top->next;
		printf("value deleted is %d\n",ptr->data);
		free(ptr);
	}
	return top;
}
stack *display(stack *top)
{
	stack *ptr;
	ptr=top;
	if(top==NULL)
	{
		printf("stack underflow\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
	}
	return top;
}
void main()
{
	int val,ch;
	while(1)
	{
		printf("1.push,2.pop,3.display,4.exit\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the item to be pushed into stack\n");
				scanf("%d",&val);
				top=push(top,val);
				break;
			case 2: top=pop(top);
				break;
			case 3: top=display(top);
				break;
			case 4: exit(0);
			default: printf("invalid choice\n");
				 break;
		}
	}
}







