#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
	int data;
	struct bst *left;
	struct bst *right;
}bst;
bst *createbst(bst*root,int item)
{
	if(root==NULL)
	{
		root=(bst*)malloc(sizeof(bst));
		root->left=root->right=NULL;
		root->data=item;
		return root;
	}
	else
	{
		if(item<root->data)
			root->left=createbst(root->left,item);
		else if(item>root->data)
			root->right=createbst(root->right,item);
		else
			printf("duplicants are not allowed\n");
		return root;
	}
}
void display(bst *root,int i)
{
	int j;
	if(root!=NULL)
	{
		display(root->right,i+1);
		for(j=0;j<i;j++) printf("\t");
		printf("%d(%d,%d)\n",root->data,i,j);
		display(root->left,i+1);
	}
}
void preorder(bst*root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(bst*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}
void postorder(bst*root)
{
	 if(root!=NULL)
        {
                postorder(root->left);
		postorder(root->right);
                printf("%d\n",root->data);
               
        }
}
void main()
{
	int item,n,i;
      	bst*root=NULL;
	printf("enter no of nodes\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("enter data for node\n");
		scanf("%d",&item);
		root=createbst(root,item);
	}
	printf("inorder traversal is:\n");
	inorder(root);
	printf("preorder traversal is:\n");
        preorder(root);
	printf("postorder traversal is:\n");
        postorder(root);
	printf("displaying tree:\n");
	display(root,1);
}

