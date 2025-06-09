#include <stdio.h>
#include <stdlib.h>

int dist[10], cost[10][10], n;

void readMatrix() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("(%d, %d):", i, j);
			scanf("%d", &cost[i][j]);
			if (cost[i][j] == 0) cost[i][j] = 999;
		}
	}
}

int min(int a, int b) {
	return a < b ? a : b;
}

void DijkstraShortestPath(int n, int s) {
	int visited[n], c, u;
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
		dist[i] = cost[s][i];
	}
	dist[s] = 0;
	visited[s] = 1;

	for (int k = 1; k <= n; k++) {
		c = 999;
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0 && dist[i] <= c) {
				c = dist[i];
				u = i;
			}
		}
		visited[u] = 1;
		for (int i = 1; i <= n; i++) dist[i] = min(dist[i], dist[u] + cost[u][i]);
	}

}

int main() {
    int s;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Enter the cost matrix:\n");
	readMatrix();
	printf("Enter the source vertex: ");
	scanf("%d", &s);
	DijkstraShortestPath(n, s);
	for (int i = 1; i <= n; i++) {
	    printf("\nShortest Path from %d to %d is %d", s, i, dist[i]);
	}
	return 0;
}