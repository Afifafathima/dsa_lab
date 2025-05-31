#include<stdio.h>
#include<stdlib.h>
struct calendar
{
	char *name,*description;
	int day;
};
typedef struct calendar cal;
cal* create()
{
	return((cal*)malloc(7*sizeof(cal)));
}
void read(cal* d)
{
	int i,j,flag;
	char temp[50];
	for(i=0;i<7;i++)
	{
		d[i].name=NULL;
		d[i].day=-1;
		d[i].description=NULL;
	}
	do
	{
		printf("enter day number");
		scanf("%d",&i);
		if(i<0||i>6)
		{
			printf("invalid day number");
		}
		else
		{
			d[i].day=i;
			printf("enter name and description");
			scanf("%s",temp);
			d[i].name=strdup(temp);
			scanf("%s",temp);
			d[i].description=strdup(temp);
		}
		printf("enter 1 for more else 0");
		scanf("%d",&flag);
	}
	while(flag!=0);
}
void display(cal* d)
{
	int i;
	printf("\ndaynumber\tdayname\tdescription");
	for(i=0;i<7;i++)
	{
		if(d[i].day!=-1)
		{
			printf("\n%d\t%s\t%s\n",d[i].day,d[i].name,d[i].description);
		}
	}
}
void deallocate(cal* d)
{
	int i;
	for(i=0;i<7;i++)
	{
		free(d[i].name);
		free(d[i].description);
	}
	free(d);
}
int main()
{
	cal* d=create();
	read(d);
	display(d);
	deallocate(d);
}
