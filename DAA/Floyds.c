#include <stdio.h>
#include <stdlib.h>

int w[10][10], n;

void readMatrix() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &w[i][j]);
}

int min(int a, int b) {
	return a < b ? a : b;
}

void floyd(int w[][10], int n) {
	#pragma omp parallel for private(i, j, k) shared(w)
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
}

int main() {
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Enter the cost matrix:\n");
	readMatrix();
	floyd(w, n);
	printf("\nShortest Path matrix:\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d\t", w[i][j]);
		printf("\n");
	}
	return 0;
}