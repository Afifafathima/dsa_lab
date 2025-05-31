#include<stdio.h>
#include<stdlib.h>
#define size 4
int stack[size],top=-1;
void push(int ele)
{
	if(top==size-1)
	printf("stack overflow\n");
	else
	stack[++top]=ele;
}
int pop()
{
	if(top==-1)
	{
		printf("stack underflow\n");
		return -999;
	}
	else
	return(stack[top--]);
}
void display()
{
	int i;
	if(top==-1)
	printf("stack is empty\n");
	else
	{
		printf("stack elements are\n");
		for(i=top;i>=0;i--)
		printf("%d\t",stack[i]);
	}
}
void palindrome()
{
	top=-1;
	int num,ncopy;
	printf("enter number:");
	scanf("%d",&num);
	ncopy=num;
	while(num!=0)
	{
		push(num%10);
		num=num/10;
	}
	while(top!=-1)
	{
		if(ncopy%10!=pop())
		{
			printf("not palindrome\n");
		    return;
		}
		ncopy=ncopy/10;
	}
	printf("palindrome\n");
}
int main()
{
	
	int choice,ele;
	while(1)
	{
		printf("\nenter the choice\n1 for push\n2 for pop\n3 for display\n4 palindrome\n5 for exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter number:");
			scanf("%d",&ele);
			push(ele);
			break;
			case 2:ele=pop();
			if(ele!=-999)
			printf("popped element=%d",ele);
			break;
			case 3:display();
			break;
			case 4:palindrome();
			break;
			case 5:exit(0);
			default:printf("invalid\n");
		}
	}
}
