#include<stdio.h>
#include<string.h>
void findreplace(char *text,char *pat,char *rep)
{
	int i,j,k=0,l,found=0;
	char ans[100];
	for(i=0;text[i]!='\0';i++)
	{
		for(j=0;pat[j]!='\0';j++)
		{
			if(text[i+j]!=pat[j])
			break;
		}
		if(pat[j]=='\0')
		{
			found=1;
			for(l=0;rep[l]!='\0';l++)
			{
				ans[k++]=rep[l];
			}
			i=i+j-1;
		}
		else
		{
			ans[k++]=text[i];
		}
	}
	ans[k]='\0';
	if(found==0)
	{
		printf("not found");
	}
	else
	{
		printf("resultant string is %s",ans);
	}
}
int main()
{
	char text[20],pat[30],rep[30];
	printf("enter text");
	gets(text);
	printf("enter pattern");
	gets(pat);
	printf("enter replace string");
	gets(rep);
	findreplace(text,pat,rep);
}
