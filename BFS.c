#include <stdio.h>
#include <conio.h>
static int n;
int a[n][n],q[n],visited[n],o,i,j,f=0;r=-1;

void BFSinC(int vertex){
	for(i=1;i<=n;i++)
		if(a[v][i]&&!visited[i])
			q[r++]=i;
		if(f<=r){
			visited[q[f]]=1;
			voidBFSinC(q[f++]);
		}
}
void main(){
	int v;
	clrscr();
	printf("\n Number of vertices in mind: ");
	scanf("%d",&o);
	for(i=1;i<=o;i++){
		q[i]=0;
		visited[i]=0;
	}
	printf("\nA graph mus be inserted in a matrix format:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("\n We have to start somewhere:");
	sanf("%d",&v);
	BFSinC(v);
	printf("\nIn this BFS we can try to see which nodes we can reach or not\n");
	for(i=1;i<=n;i++)
		if(visited[i])
			printf("%d\t",i);
		else
			printf("\n:( I am sorry but BFS doesnt work here");
		getch();

}
