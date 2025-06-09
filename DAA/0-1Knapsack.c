#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int p[MAX], w[MAX], n, max, v[MAX][MAX];

int max_value(int a, int b) {
	return a > b ? a : b;
}

int main() {
	printf("Enter the number of items: ");
	scanf("%d", &n);
	printf("Enter the profit and weight of each item:\n");
	for (int i = 1; i <= n; i++) {
		printf("Item %d: ", i);
		scanf("%d%d", &p[i], &w[i]);
	}
	printf("Enter the maximum capacity of knapsack: ");
	scanf("%d", &max);
	for (int i = 0; i <= n; i++) v[i][0] = 0;
	for (int i = 0; i <= max; i++) v[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= max; j++) {
			if (w[i] > j) v[i][j] = v[i - 1][j];
			else v[i][j] = max_value(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
		}
	}

	printf("The Table : \n");
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= max; j++)
			printf("%d\t", v[i][j]);
		printf("\n");
	}
	printf("Maximum Profit is %d\n", v[n][max]);
	printf("Solution vector: {");
	int j = max;
	for (int i = n; i >= 1; i--) {
	    if (v[i][j] != v[i - 1][j]) {
	        printf("Item %d: 1\t", i);
	        j -= w[i];
	    } else {
	        printf("Item %d: 0\t", i);
	    }
	}
	printf("}\n"); 
	return 0;
}