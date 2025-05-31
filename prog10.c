#include<stdio.h>
#include<stdlib.h>
struct bst
{
	int data;
	struct bst *left,*right;
};
typedef struct bst node;
node *insert(node *root,int key)
{
	node *newnode;
	if(root==NULL)
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=key;
		newnode->left=newnode->right=NULL;
		return newnode;
	}
	else if(key<root->data)
	{
		root->left=insert(root->left,key);
	}
	else
	root->right=insert(root->right,key);
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
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
	printf("key not found");
	else if(root->data==key)
	printf("key found");
	else if(key<root->data)
	search(root->left,key);
	else
	search(root->right,key);
}
int main()
{
	int n,i,key,choice;
	node *root=NULL,*temp;
	printf("enter no of nodes:");
	scanf("%d",&n);
	printf("enter the element:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&key);
		root=insert(root,key);
	}
	while(1)
	{
		printf("enter 1 inoder 2 preoder 3 postorder 4 search 5 exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("inorder\n");
			inorder(root);
			break;
			case 2:printf("preorder\n");
			preorder(root);
			break;
			case 3:printf("postorder\n");
			postorder(root);
			break;
			case 4:printf("enter element serch:");
			scanf("%d",&key);
			search(root,key);
			break;
			case 5:exit(0);
			default:printf("invalid");
		}
	}
}
