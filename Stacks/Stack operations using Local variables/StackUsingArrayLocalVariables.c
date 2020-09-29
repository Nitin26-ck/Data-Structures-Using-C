#include <stdio.h>
#include<stdlib.h> //Needed for exit(0) used in switch-case default 
 
#define SIZE 5


void push(int enter,int mystack[],int top)
{
	
	if (top == SIZE-1) 
	{
		printf("\n Stack Overflow"); return; }
    else 
	{
		mystack[top] = enter; return;}		
}

int pop(int mystack[],int top)
{
	
	if(top == -1) 
	{
		printf("\n Stack Underflow");return 0; }
	else 
	{
		int del = mystack[top]; return del; }
}
void display(int mystack[],int top)
{
	int i=0; printf("\n Top is %d", top); 
	if(top == -1) 
	{
		printf("\n Stack Underflow");return; 
	}
	printf("\n Printing the elements remaining in the stack after push & pop"); 	
	for (i=top; i>=0; i--)
		printf("\n %d", mystack[i]); 	
}

int main()
{
	
int top = -1;
int mystack[SIZE]; //Stack inpmlemented using Array 
int enter, del,choice;

for(;;)
{
 
printf("\nEnter the choice\n");
		printf("1: Push\n2: Pop\n3: Display\n4: Exit\n");
		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n Enter the element to be pushed"); 
					scanf("%d", &enter); ++top; //NOTE: top needs to be manipulated in main as local copy is present in push function 
					push(enter,mystack,top); break; 
            case 2: del=pop(mystack,top); top --; //NOTE: top needs to be manipulated in main as local copy is present in push function 
                       if(del==0) printf("\n Stack Empty - no item to pop"); 
                       else printf("\n Element Popped is %d", del); break;  
            case 3: display(mystack,top); break; 
			default: exit (0); 
}}}