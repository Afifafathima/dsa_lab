#include<stdio.h>
#include<stdlib.h>
struct bst
{
	int data;
	struct bst *left;
	struct bst *right;
};
typedef struct bst node;
node *insert(node *root,int key)
{
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->data=key;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(key<root->data)
	root->left=insert(root->left,key);
	else
	root->right=insert(root->right,key);
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}
void search(node *root,int key)
{
	if(root==NULL)
	{
		printf("not foubd");
	}
	else if(root->data==key)
	{
		printf("found");
	}
	else if(key<root->data)
	search(root->left,key);
	else
	search(root->right,key);
}
int main()
{
	int n,i,key,choice;
	node *root=NULL,*temp;
	printf("enter no.of nodes");
	scanf("%d",&n);
	printf("enter the key");
	for(i=0;i<n;i++)
	{
		scanf("%d",&key);
		root=insert(root,key);
	}
	while(1)
	{
		printf("enter 1 for inorder 2 for preorder 3 for postorder 4 for search 5 for exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("inorder is\n");
			inorder(root);
			break;
			case 2:preorder(root);
			break;
			case 3:postorder(root);
			break;
			case 4:printf("entr key");
			scanf("%d",&key);
			search(root,key);
			break;
			case 5:exit(0);
			default:printf("invalid");
		}
	}
}
