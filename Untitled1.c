#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct polynomial
{
	int coeff,expo1,expo2,expo3;
	int flag;
	struct polynomial *next;
};
typedef struct polynomial node;
node *insertend(node *head,int c,int e1,int e2,int e3)
{
	node *temp=head->next;
	node *newnode=(node*)malloc(sizeof(node));
	newnode->coeff=c;
	newnode->expo1=e1;
	newnode->expo2=e2;
	newnode->expo3=e3;
	newnode->next=NULL;
	while(temp->next!=head)
	temp=temp->next;
	temp->next=newnode;
	newnode->next=head;
}
void readpoly(node *head)
{
	int i,n,c,e1,e2,e3;
	printf("enter no.of terms");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter coeff expo1 expo2 expo3");
		scanf("%d%d%d%d",&c,&e1,&e2,&e3);
		insertend(head,c,e1,e2,e3);
	}
}
void addpoly(node *head1,node *head2,node *head3)
{
	int c;
	node *p1=head1->next,*p2;
	while(p1!=head1)
	{
		p2=head2->next;
		while(p2!=head2)
		{
			if(p1->expo1==p2->expo1&&p1->expo2==p2->expo2&&p1->expo3==p2->expo3)
			{
				c=p1->coeff+p2->coeff;
				insertend(head3,c,p1->expo1,p1->expo2,p1->expo3);
				p1->flag=1;
				p2->flag=1;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	p1=head1->next;
	p2=head2->next;
	while(p1!=head1)
	{
		if(p1->flag==0)
		{
			insertend(head3,c,p1->expo1,p1->expo2,p1->expo3);
		}
		p1=p1->next;
	}
	while(p2!=head2)
	{
		if(p2->flag==0)
		{
			insertend(head3,c,p2->expo1,p2->expo2,p2->expo3);
		}
		p2=p2->next;
	}
}
void display(node *head)
{
	node *p1=head->next;
	while(p1->next!=head)
	{
		printf("%dx^%dy^%dz^%d+",p1->expo1,p1->expo2,p1->expo3);
		p1=p1->next;
	}
	printf("%dx^%dy^%dz^%d+",p1->expo1,p1->expo2,p1->expo3);
}
void evaluate(node *head)
{
	node *p1=head->next;
	int x,y,z,sum=0;
	printf("enter x y z");
	scanf("%d%d%d",&x,&y,&z);
	while(p1!=head)
	{
		sum=sum+p1->coeff*pow(x,p1->expo1)*pow(y,p1->expo2)*pow(z,p1->expo3);
		p1=p1->next;
	}
	printf("result=%d",sum);
}
int main()
{
	node *head1=(node*)malloc(sizeof(node));
	head1->next=head1;
	node *head2=(node*)malloc(sizeof(node));
	head2->next=head2;
	node *head3=(node*)malloc(sizeof(node));
	head3->next=head3;
	printf("read 1st poly\n");
	readpoly(head1);
	printf("read 2nd poly\n");
	readpoly(head2);
	printf("1st poly is\n");
	display(head1);
	printf("2nd poly is\n");
	display(head2);
	addpoly(head1,head2,head3);
	printf("resultant poly is\n");
	display(head3);
	evaluate(head3);
	free(head1);
	free(head2);
	free(head3);
}
