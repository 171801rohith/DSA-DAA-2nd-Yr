#include <stdio.h>
#include <stdlib.h>

int w[10][10], n;

void readMatrix() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			printf("(%d,%d):",i,j);
			scanf("%d", &w[i][j]);
		}
}

void warshall(int w[][10], int n) {
	for (int k = 1; k <= n; k++)
		for (int j = 1; j <= n; j++)
			for (int i = 1; i <= n; i++)
				w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
}

int main() {
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Enter the cost matrix:\n");
	readMatrix();
	warshall(w, n);
	printf("\nAll pair distance matrix:\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d\t", w[i][j]);
		printf("\n");
	}
	return 0;
}