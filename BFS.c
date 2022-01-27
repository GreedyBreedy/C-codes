#include <stdio.h>
int static a[100][100],q[100],visited[100];
int o,i,j,f=0,r=-1;

void BFSinC(int vertex){
	for(i=1;i<=o;i++)
		if(a[vertex][i]&&!visited[i])
			q[r++]=i;
		if(f<=r){
			visited[q[f]]=1;
			BFSinC(q[f++]);
		}
}
void main(){
	int v;
	printf("\n Number of vertices in mind: ");
	scanf("%d",&o);
	for(i=1;i<=o;i++){
		q[i]=0;
		visited[i]=0;
	}
	printf("\nA graph must be inserted in a matrix format:\n");
	for(i=1;i<=o;i++)
		for(j=1;j<=o;j++)
			scanf("%d",&a[i][j]);
	printf("\n We have to start somewhere:");
	scanf("%d",&v);
	BFSinC(v);
	printf("\nIn this BFS we can try to see which nodes we can reach or not\n");
	printf("\nReachable nodes:\n");
	for(i=1;i<=o;i++)
		if(visited[i])
			printf("%d\t",i);
		else
			printf("\n:( I am sorry but BFS doesnt work here");
			printf("\n End of BFS\n");
		

}
