#include<stdio.h>
#include<stdlib.h>
#define max 4
char q[max];
int front=0,rear=-1,count=0;
void enqueue(char ele)
{
	if(count==max)
	{
		printf("queue of");
	}
	else
	{
		rear=(rear+1)%max;
		q[rear]=ele;
		count++;
	}
}
void dequeue()
{
	if(count==0)
	{
		printf("queue uf");
	}
	else
	{
		printf("deleted ele=%d",q[front]);
		front=(front+1)%max;
		count--;
	}
}
void display()
{
	int i,k;
	if(count==0)
	{
		printf("empty");
	}
	else
	{
		k=front;
		for(i=1;i<=count;i++)
		{
			printf("%c\t",q[k]);
			k=(k+1)%max;
		}
	}
}
int main()
{
	char ele;
	int choice;
	while(1)
	{
		printf("enter 1 enqueue 2 dequeue 3 display 4 exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter ele:");
			scanf(" %c",&ele);
			enqueue(ele);
			break;
			case 2:dequeue();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			default:printf("invalid");
		}
	}
}
