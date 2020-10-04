#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct polynode
{
	int coeff;
	int pow;
	struct polynode *next;
}polynode;
polynode *head;
void createpoly()
{
	polynode *ptr,*newnode,*prev;
	ptr=newnode=prev=NULL;
	int pow,coeff;
	//printf("enter coeff and pow terminated when coeff and pow is 0\n");
	//scanf("%d%d",&coeff,&pow);
	printf("enter the value of coeff\n");
	scanf("%d",&coeff);
	printf("enter the value of power\n");
	scanf("%d",&pow);
	while(coeff!=0)
	{
		newnode=(polynode*)malloc(sizeof(polynode));
		newnode->coeff=coeff;
		newnode->pow=pow;
		newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
			}
		else
		{
			if(newnode->pow>head->pow)
			{
				newnode->next=head;
				head=newnode;
			}
			else
			{
				ptr=head;
				while((ptr!=NULL)&&(newnode->pow<ptr->pow))
				{
					prev=ptr;
					ptr=ptr->next;
				}
				if(ptr=NULL)
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
		printf("enter coeff\n");
		scanf("%d",&coeff);
		printf("enter power\n");
		scanf("%d",&pow);
	}
}
int evaluatepoly()
{
	polynode *ptr;
	int res,x;
	res=x=0;
	printf("enter the value of x \n");
	scanf("%d",&x);
	ptr=head;
	while(ptr!=NULL)
	{
		res=res+ptr->coeff*pow(x,ptr->pow);
		ptr=ptr->next;
	}
	return res;
}
void display()
{
	polynode *ptr;
	if(head==NULL)
	{
		printf("empty polynomial\n");
		return;
	}
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d*x^%d->",ptr->coeff,ptr->pow);
		ptr=ptr->next;
	}
}
int main()
{
	int ch,res;
	while(1)
	{
		printf("1.create polynomial,2.evaluate polynomial,3.display,4.exit\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: createpoly();
				break;
			case 2: res=evaluatepoly();
				printf("result is%d\n",res);
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("invalid choice\n");
				 break;
		}
	}
}
	
