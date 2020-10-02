#include <stdio.h>
#include<stdlib.h>
typedef struct myBintree
{
    int marks;
    struct myBintree *left;
    struct myBintree *right;
    
}myBintree;

int strict = 0;
myBintree *root = NULL;

myBintree * createBinTree()
{
    int m; myBintree *ptr;
    
    printf("\n Press -1 if you dont want to enter marks ");
    scanf("%d", &m); //Remove '&' To DEMO Segmentation Fault
    
    if(m == -1) return NULL;
    else
    {
        ptr = (myBintree *)malloc(sizeof(myBintree));
        ptr->marks = m; ptr->left = NULL; ptr->right =NULL;
        printf("\n Enter Marks for LEFT node of %d ", ptr->marks);
        
        ptr->left = createBinTree();
        
        printf("\n Enter Marks for RIGHT node of %d ", ptr->marks);
        
        ptr->right = createBinTree();
        return ptr;
    }
    
}//End of createBinTree

int IsStrictlyBinTree(myBintree* root) {
    
    if(root->left == NULL && root->right == NULL)
    {
        printf("\n Test Case #2 \n");
        return 1;
    }
    
    else if ((root->left == NULL && root->right != NULL)  ||
             (root->right == NULL && root->left != NULL))
    {
        printf("\n Test Case #3 \n");
        return 0;
    }
    else
        
        if(IsStrictlyBinTree(root->left))
        {
            strict = IsStrictlyBinTree(root->right);
            return strict;
        }
        else
            return 0;
    /*
     The above code can be written shortly by using the ternary operator in the way given below:
     
     return ((IsStrictlyBinTree(root->left))?IsStrictlyBinTree(root->right):0);
     */
    
}//End of IsStrictlyBinTree

void displayBinTree(myBintree * root,int i)
{
    int j;
    
    
    if(root !=NULL)
    {
        displayBinTree(root->left,i+1);
        for(j=1;j<=i;j++) printf("\t"); //DEMO : Only prints tab
        //Donot enclose the two printf in brackets as the actual print happens
        //outside the for loop when loop condition fails
        //printf("%d(%d:%d)\n",root->marks,i,j);
        
        printf("%d \n",root->marks);
        displayBinTree(root->right,i+1);
    }
    
}//End of displayBinTree

int main()
{
    root = createBinTree();
    printf("\n Displaying....\n");
    
    if(root == NULL)
    {
        printf("\nTest Case #1 \n");
        printf("\n Root Node is NULL - Tree does not have even one node\n");
    }
    else
    {
    strict = IsStrictlyBinTree(root);
    if(strict == 1) printf("\n Created Tree is Strict Binary tree\n");
    else printf("\n Created Tree is NOT Strict Binary tree\n");
    displayBinTree(root, 1);
    }
    
}






