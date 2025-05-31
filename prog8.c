#include<stdio.h>
#include<stdlib.h>
struct dll
{
	int ssn,sal;
	char name[20],dept[20],desi[10],phone[10];
	struct dll *prev,*next;
};
typedef struct dll node;
node *start=NULL;
node *createnode()
{
	node *newnode=(node*)malloc(sizeof(node));
	printf("enter ssn name dept desi phone sal\n");
	scanf("%d",&newnode->ssn);
	scanf("%s",newnode->name);
	scanf("%s",newnode->dept);
	scanf("%s",newnode->desi);
	scanf("%s",newnode->phone);
	scanf("%d",&newnode->sal);
	newnode->next=newnode->prev=NULL;
	return newnode;
}
void insertbegin()
{
	node *newnode=createnode();
	if(start==NULL)
	{
		start=newnode;
		return;
	}
	newnode->next=start;
	start->prev=newnode;
	start=newnode;
}
void insertend()
{
	node *temp=start;
	node *newnode=createnode();
	if(start==NULL)
	{
		start=newnode;
		return;
	}
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=newnode;
	newnode->prev=temp;
}
void deletebegin()
{
	node *temp=start;
	if(start==NULL)
	{
		printf("list is empty");
		return;
	}
	if(start->next==NULL)
	{
		printf("deleted node=%d",temp->ssn);
		free(temp);
		start=NULL;
		return;
	}
	start=temp->next;
	(temp->next)->prev=NULL;
	printf("deleteed node=%s",temp->ssn);
	free(temp);
}
void deleteend()
{
	node *temp=start;
	if(start==NULL)
	{
		printf("list is empty");
	}
	else if(temp->next==NULL)
	{
		printf("delted node=%s",temp->ssn);
		free(temp);
		start=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		(temp->prev)->next=NULL;
		printf("delted node=%s",temp->ssn);
		free(temp);
	}
}
void display()
{
	int count=0;
	node *temp=start;
	if(start==NULL)
	{
		printf("list is empty");
		return;
	}
	printf("elements are\n");
	while(temp!=NULL)
	{
		printf("%d %s %s %s %s %d",temp->ssn,temp->name,temp->dept,temp->desi,temp->phone,temp->sal);
		temp=temp->next;
		count++;
	}
	printf("count=%d",count);
}
int main()
{
	int choice,n,i;
	while(1)
	{
		printf("enter 1 inseetbegin 2 insertend 3 deletebegin 4 deleteend 5 display 6 exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insertbegin();
			       break;
			case 2:insertend();
		        	break;
		   	case 3:deletebegin();
		        	break;
			case 4:deleteend();
		        	break;
			case 5:display();
		        	break;
			case 6:exit(0);
			default:printf("invalid");
		}
	}
}
