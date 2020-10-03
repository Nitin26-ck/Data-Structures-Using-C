#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree
{
    char data; //char type because it can store operator or operand
    struct tree *left,*right;
};

int top=-1;
struct tree *stack[20]; //An array of structures of tree type.
struct tree *node; //To make a temporary operator or operand node

void push(struct tree* node)
{
    stack[++top]=node;
}


struct tree * pop()
{
    return(stack[top--]);
}


int check(char ch)
{
    if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
        return 2;
    else
        return 1;
}


int cal(struct tree *node)
{
    int ch;
    ch=check(node->data);
    if(ch==1)
        return node->data-48;
    
    else if(ch==2)
    {
        if(node->data=='+')
            return cal(node->left)+cal(node->right);
        if(node->data=='-')
            return cal(node->left)-cal(node->right);
        if(node->data=='*')
            return cal(node->left)*cal(node->right);
        if(node->data=='/')
            return cal(node->left)/cal(node->right);
    }
    else
        return 0;
}


void inorder(struct tree *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%c",node->data);
        inorder(node->right);
    }
}



void operand(char b)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=b;
    node->left=NULL;
    node->right=NULL;
    push(node);
}


void operators(char a)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=a;
    node->right=pop();
    node->left=pop();
    push(node);
}

int main()
{
    int i,op,result;
    char postfix[20];
    
    printf("Enter the expression in postfix form \n");
    fflush(stdin);
    scanf("%s",postfix);
    
    i=0;
    for(i=0;postfix[i]!='\0';i++)
    {
        op=check(postfix[i]); //Check if operator or operand
        if(op==1)
            operand(postfix[i]);
        else if(op==2)
            operators(postfix[i]);
    }
    result=cal(stack[top]);
    printf("\nThe value of the postfix expression you entered is %d\n",result);
    printf("\nThe inorder traversal of the tree is: ");
    inorder(stack[top]);
    printf("\n");
}

