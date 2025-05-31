#include<stdio.h>
#include<stdlib.h>
char *stack,max,top=-1;
void push(int ele)
{
	if(top==max-1)
	{
		printf("stack overflow");
	}
	else
	stack[++top]=ele;
}
int pop()
{
	if(top==-1)
	{
		printf("stack underflow");
		return -1;
	}
	else
	{
		return(stack[top--]);
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("empty");
	}
	else
	{
		printf("stack elements are");
		for(i=top;i>=0;i--)
		{
			printf("%d",stack[i]);
		}
	}
}
void palindrome()
{
	int num,rev,rem,ncopy;
	printf("enter number");
	scanf("%d",&num);
	ncopy=num;
	top=-1;
	while(num!=0)
	{
		rem=num%10;
		push(rem);
		num=num/10;
	}
	while(ncopy!=0)
	{
		rem=ncopy%10;
		if(rem!=pop())
		{
			printf("not palindrome");
			top=-1;
		}
		ncopy=ncopy/10;
	}
	printf("it is palindrome");
}
int main()
{
	int choice,ele;
	printf("enetr size of staclk");
	scanf("%d",&max);
	stack=(int*)malloc(sizeof(int));
	while(1)
	{
		printf("\nenter your choice");
		printf("\n1-push\n2-pop\n3-display\n4-palindrome\n5-exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter ele");
			scanf("%d",&ele);
			push(ele);
			break;
			case 2:ele=pop();
			if(ele!=-1)
			printf("deleted ele is %d",ele);
			break;
			case 3:display();
			break;
			case 4:palindrome();
			break;
			case 5:exit(0);
			break;
			default:printf("invalid");
		}
	}
}
