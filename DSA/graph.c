#include<stdio.h>
int a[20][20], q[20], visited[20], reach[20], n, i, j, f = 0, r = -1, count = 0;

void bfs(int v){
	int u;
	q[++r] = v;
	visited[v] = 1;
	while(f <= r){
		u = q[f++];
		for(i = 1; i <= n; i++){
			if(a[u][i] && !visited[i]){
				q[++r] = i;
				visited[i] = 1;
				printf("->%d", i);
			}
		}
	}
}

void dfs(int v){
	int i;
	reach[v] = 1;
	for(i = 1; i <= n; i++){
		if(a[v][i] && !reach[i]){			
			printf("->%d", i);
			dfs(i);
		}
	}
}

void main(){
	int v;
	printf("Enter number of officers :");
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		q[i] = 0;
		reach[i] = 0;
		visited[i] = 0;
	}
	printf("\nEnter graph data in matrix form indicating people who can communicate directly with each other :\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	printf("Enter the officer as a starting node :");
	scanf("%d", &v);
	if((v < 1) || (v > n)){
		printf("\nInvalid Node");
		return;
	}
	printf("\n All the officers which are reachable from a given officer as a starting node using BFS algorithm\n %d", v);	
	bfs(v);
	printf("\n All the officers which are reachable from a given officer as a starting node using DFS algorithm\n %d", v);	
	dfs(v);
	printf("\n");	
}
