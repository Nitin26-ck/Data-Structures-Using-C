#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int ch,del,ele;
int top=-1;
int mystk[SIZE];
void push()
{
	printf("enter the element to be pushed\n");
	scanf("%d",&ele);
	if(top==(SIZE-1))
	{
		printf("stack overflow\n");
	}
	else
	{
		mystk[++top]=ele;
	}
	printf("pushed element is %d\n",ele);
}
void pop()
{
	if(top==-1)
	{
		printf("stack underflow\n");
	}
	else 
	{
		del=mystk[top--];
	}
	printf("popped element is %d\n",del);
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("stack underflow\n");
	}
	else
	{

		printf("contents of the stack are\n");
		for(i=0;i<=top;i++)
		{
			printf("%d\n",mystk[i]);
		}
	}
}
void main()
{
    top=-1;
    while(1)
    {
	    printf("1-push,2-pop,3-display\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		    case 1:
			    push();
			    break;
	    	    case 2:
			    pop();
			    break;
	            case 3:
			    display();
			    break;
                    default:
			    exit(0);
			    break;
	    }
    }
}



