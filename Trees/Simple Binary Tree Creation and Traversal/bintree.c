#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	struct tree *left;
	struct tree *right;
	int marks;
}tree;
tree *root=NULL;
tree *createtree()
{
	tree *ptr;
	int m;
	printf("enter data and -1 for no data\n");
	scanf("%d",&m);
	if(m==-1)
		return NULL;
	ptr=(tree*)malloc(sizeof(tree));
	ptr->marks=m;
	printf("enter the left child of tree\n");
	ptr->left=createtree();
	printf("enter the right child of tree\n");
	ptr->right=createtree();
	return ptr;
}
void treeInorder(tree *temp)
{
	if(temp!=NULL)
	{
		treeInorder(temp->left);
		printf("%d\n",temp->marks);
		treeInorder(temp->right);
	}
}
void treePreorder(tree *temp)
{
	if(temp!=NULL)
	{
		printf("%d\n",temp->marks);
		treePreorder(temp->left);
		treePreorder(temp->right);
	}
}
void treePostorder(tree *temp)
{
	if(temp!=NULL)
	{
		treePostorder(temp->left);
		treePostorder(temp->right);
		printf("%d\n",temp->marks);
	}
}
void display(tree *temp,int i)
{
	int j;
	if(temp!=NULL)
	{
		display(temp->right,i+1);
		for(j=0;j<i;j++)
			printf("\t");
		printf("%d(%d,%d)\n",temp->marks,i,j);
		display(temp->left,i+1);
	}
}
void main()
{
	root=createtree();
	printf("the tree is:\n");
	display(root,1);
	printf("preorder traversal is:\n");
	treePreorder(root);
	printf("inorder traversal is:\n");
	treeInorder(root);
	printf("postorder traversal is:\n");
	treePostorder(root);
}
