#include<stdio.h>
int a[10][10],n,visited[10];
void dfs(int s)
{
	int i;
	visited[s]=1;
	printf("%d->",s);
	for(i=0;i<n;i++)
	{
		if(a[s][i]==1 && visited[i]==0)
		dfs(i);
	}
}
void bfs(int s)
{
	int i,f=0,r=-1,q[n];
	visited[s]=1;
	while(1)
	{
		printf("%d->",s);
		for(i=0;i<n;i++)
		{
			if(a[s][i]==1  && visited[i]==0)
			{
				visited[i]=1;
				q[++r]=i;
			}
		}
		if(f>r)
		return;
		s=q[f++];
	}
}
int main()
{
	int i,j,s;
	printf("enter nodes:");
	scanf("%d",&n);
	printf("enter fraph in adj matrix form\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
	visited[i]=0;
	printf("enter starting node:");
	scanf("%d",&s);
	printf("dfs\n");
	dfs(s);
	for(i=0;i<n;i++)
	visited[i]=0;
	printf("bfs\n");
	bfs(s);
}
