#include<stdio.h>
#include<stdlib.h>
struct SLL
{
	int sem;
	char usn[11],name[20],branch[20],ph[20];
	struct SLL *next;
};
typedef struct SLL node;
node *start=NULL;
node *getNode()
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("enter sem,usn,branch,ph,name");
	scanf("%d%s%s%s%s",&newnode->sem,newnode->usn,newnode->name,newnode->branch,newnode->ph);
	node *next=NULL;
	return newnode;
}
void insertbegin()
{
	node *newnode;
	newnode=getNode();
	if(start==NULL)
	{
		start=newnode;
		return;
	}
	newnode->next=start;
	start=newnode;
}
void insertend()
{
	node *newnode,*temp=start;
	newnode=getNode();
	if(start==NULL)
	{
		start=newnode;
		return;
	}
	while(temp->next!=NULL)
	    temp=temp->next;
	temp->next=newnode;
}
void deletebegin()
{
	node *temp=start;
	if(start==NULL)
	{
		printf("empty");
		return;
	}
	start=temp->next;
	printf("deleted node is %s",temp->name);
	free(temp);
}
void display()
{
	int count=0;
	node *temp=start;
	if(start==NULL)
	{
		printf("empty");
		return;
	}
	printf("list elements are\n");
	while(temp!=NULL)
	{
		printf("%s\n3",temp->usn);
		temp=temp->next;
		count++;
	}
	printf("count=%d\n",count);
}
void deleteend()
{
	node *temp=start,*prev;
	if(start==NULL)
	{
		printf("empty");
		return;
	}
	if(start->next==NULL)
	{
		printf("deleted is %s",temp->name);
		free(temp);
		start=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		printf("deleted is %s",temp->name);
		free(temp);
	}
}
int main()
{
	int n,i,choice;
	while(1)
	{
		printf("enter your choice");
		printf("\n1-insertend\n2-insertbegin\n3-deletebegin\n4-deleteend\n5-display\n6-exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	insertend();
				break;
			case 2:printf("enter no.of atudents");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			insertbegin();
			break;
			case 3:deletebegin();
			break;
			case 4:deleteend();
			break;
			case 5:display();
			break;
			case 6:exit(0);
			break;
			default:printf("invalid");
		}
	}
}
