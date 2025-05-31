#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct calender
{
	char *name,*des;
	int date;
};
typedef struct calender cal;
cal* create()
{
	return((cal*)malloc(7*sizeof(cal)));
}
void read(cal *d)
{
	int flag,i;
	char temp[20];
	for(i=0;i<7;i++)
	{
		d[i].date=-1;
		d[i].name=NULL;
		d[i].des=NULL;
	}
	do{
		printf("enter date:");
		scanf("%d",&i);
		if(i<0||i>6)
			printf("invalid");
		else
		{
			d[i].date=i;
			printf("enter name:");
			scanf("%s",temp);
			d[i].name=strdup(temp);
			printf("enter description:");
			scanf("%s",temp);
			d[i].des=strdup(temp);
		}
		printf("enter 1 to continue:");
		scanf("%d",&flag);
	}while(flag==1);
}
void display(cal *d)
{
	int i;
	for(i=0;i<7;i++)
	{
		if(d[i].date!=-1)
		{
			printf("%d\t%s\t%s\n",d[i].date,d[i].name,d[i].des);
		}
	}
}
void deallocate(cal *d)
{
	int i;
	for(i=0;i<7;i++)
	{
		free(d[i].name);
		free(d[i].des);
	}
	free(d);
}
int main()
{
	cal *d=create();
	read(d);
	display(d);
	deallocate(d);
}
