#include <stdio.h>
#include <stdlib.h>

int a, b, u, v, visited[10], cost[10][10], min, mincost = 0, n, ne = 1;

void readMatrix() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("(%d, %d):", i, j);
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = 999;
        }
    }
}

int main() {
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Enter the cost matrix:\n");
	readMatrix();
	for (int i = 1; i <= n; i++) visited[i] = 0;
	printf("\nMinimal Spanning tree with Prim's Algorithm: ");
	visited[1] = 1;
	while (ne < n) {
	    min = 999;
	    for (int i = 1; i <= n; i++) {
	        for (int j = 1; j <= n; j++) {
	            if (cost[i][j] < min) {
	                if (visited[i] == 0) continue;
	                else {
	                    min = cost[i][j];
	                    a = u = i;
	                    b = v = j;
	                }
	            }
	        }
	    }
	    if (visited[u] == 0 || visited[v] == 0) {
	        printf("%d: (%d, %d) = %d \t", ne++, a, b, min);
	        mincost += min;
	        visited[b] = 1;
	    }
	    cost[a][b] = cost[b][a] = 999;
	}
	printf("\nMinimun cost of tree is %d", mincost);
	return 0;
}