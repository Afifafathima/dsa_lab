#include<stdio.h>
#include<stdlib.h>
struct sll
{
	int sem;
	char usn[11],name[20],prog[5],phone[10];
	struct sll *next;
};
typedef struct sll node;
node *start=NULL;
node *createnode()
{
	node *newnode=(node*)malloc(sizeof(node));
	printf("enter usn name sem prog phone\n");
	scanf("%s",newnode->usn);
	scanf("%s",newnode->name);
	scanf("%d",newnode->sem);
	scanf("%s",newnode->prog);
	scanf("%s",newnode->phone);
	newnode->next=NULL;
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
}
void deletebegin()
{
	node *temp=start;
	if(start==NULL)
	{
		printf("list is empty");
		return;
	}
	start=temp->next;
	printf("deleted node=%s%s%d%s%s",temp->usn,temp->name,temp->sem,temp->prog,temp->phone);
	free(temp);
}
void deleteend()
{
	node *temp=start,*prev;
	if(start==NULL)
	{
		printf("list is empty");
	}
	else if(temp->next==NULL)
	{
	    printf("deleted node=%s%s%d%s%s",temp->usn,temp->name,temp->sem,temp->prog,temp->phone);
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
		printf("deleted node=%s%s%d%s%s",temp->usn,temp->name,temp->sem,temp->prog,temp->phone);;
		free(temp);
		prev->next=NULL;
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
		printf("%s\t%s\t%d\t%s\t%s\n",temp->usn,temp->name,temp->sem,temp->prog,temp->phone);
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
			case 1:printf("enter stu:\n");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				insertbegin();
			}
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
