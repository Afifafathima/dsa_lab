#include<stdio.h>
void findreplace(char *str,char *pat,char *rep)
{
	char ans[100];
	int i,j,k=0,l,found=0;
	for(i=0;str[i]!='\0';i++)
	{
		for(j=0;pat[j]!='\0';j++)
		{
			if(str[i+j]!=pat[j])
			break;
		}
		if(pat[j]=='\0')
		{
			found=1;
			for(l=0;rep[l]!='\0';l++)
			ans[k++]=rep[l];
			i=i+j-1;
		}
		else
		{
			ans[k++]=str[i];
		}
	}
	ans[k]='\0';
	if(found==0)
	{
		printf("string not found");
	}
	else
	{
		printf("resultant string is\n%s",ans);
	}
}
int main()
{
	char str[100],pat[20],rep[20];
	printf("enter the string\n");
	gets(str);
	printf("enter the pattern:");
	gets(pat);
	printf("enter the replace:");
	gets(rep);
	findreplace(str,pat,rep);
}
