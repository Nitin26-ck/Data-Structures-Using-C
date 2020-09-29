/*C Program to evaluate a valid Postfix expression using Stacks*/
#include<stdio.h>
#include<string.h>
#include<math.h>

double op(char symbol, double op1, double op2)
{
	switch(symbol)
	{
		case '+':
			return op1 + op2;
		
		case '-':
			return op1 - op2;
		
		case '*':
			return op1 * op2;
		
		case '/':
			return op1 / op2;
		
	
	}
}

void push(double item, int *top, double s[])
{
	(*top)++;
	s[*top] = item;
}

double pop(int *top, double s[])
{
	double item_deleted;
	
	item_deleted = s[*top];
	(*top)--;
	
	return item_deleted;
}

int isDigit(char symbol)
{
	return (symbol >= '0' && symbol <= '9');
}

void main()
{
	double s[20], res, op1, op2;
	int top, i;
	char postfix[20], symbol;
	
	printf("Enter a valid postfix expression\n");
	scanf("%s",postfix);
	
	top = -1;
	
	for(i = 0; i < strlen(postfix); i++)
	{
		symbol = postfix[i];
		
		if(isDigit(symbol))
			push(symbol - '0', &top, s);
		else
		{
			op2 = pop(&top, s);
			op1 = pop(&top, s);
			
			res = op(symbol, op1, op2);
			
			push(res, &top, s);
		}
	}
	
	res = pop(&top, s);
	
	printf("The result of evaluated postfix expression is:\t%lf\n", res);
}
