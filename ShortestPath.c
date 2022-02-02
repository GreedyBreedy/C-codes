#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999 //comparative
#define MAX 10 // To reduce the fatality error of overflow

void dijkstra(int G[MAX][MAX],int n,int startnode);
 
int main(){
	int G[MAX][MAX],i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	//brute force exit 1 vertex = no path 
 	if(n<=1){
 		printf("This graph contains less than or equal to 1 vertex thus has no path :).\n");
 		exit(0);
 	}
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
		/* 1 10 9 8 
		   10 5 6 2
		   5  4 20 1
		   10 3 12 2*/
		
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	dijkstra(G,n,u);
	return 0;
}
 
void dijkstra(int G[MAX][MAX],int n,int startnode)
{//A method taken from java translated to C
 

	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindistance=INFINITY;
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
	visited[nextnode]=1;
	for(i=0;i<n;i++)
		if(!visited[i])
			if(mindistance+cost[nextnode][i]<distance[i])
			{
				distance[i]=mindistance+cost[nextnode][i];
				pred[i]=nextnode;
			}
	count++;
	}
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\nPath=%d",i);
			j=i;
			do
			{		
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
			printf("\n");
	}	
}