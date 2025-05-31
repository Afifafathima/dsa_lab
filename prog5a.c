#include<stdio.h>
static int count=0;
void toh(int n,char s,char t,char d)
{
	if(n==1)
	{
		printf("move disk %d from %c to %c\n",n,s,d);
		count++;
	}
	else
	{
		toh(n-1,s,d,t);
		printf("move disk %d from %c to %c\n",n,s,d);
		count++;
		toh(n-1,t,s,d);
	}
}
int main()
{
	int n;
	printf("enter no of disks:");
	scanf("%d",&n);
	if(n>0)
	{
		toh(n,'s','t','d');
		printf("total no of moves=%d",count);
	}
	else
	{
		printf("invalid");
	}
}
