#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int a[MAX][MAX], visited[MAX], n, cost = 0;

int least(int c) {
    int nc = 999, min = 999;
    for (int i = 1; i <= n; i++) {
        if (a[c][i] != 0 && visited[i] == 0 && a[c][i] < min) {
            min = a[c][i];
            nc = i;
        }
    }
    if (min != 999) cost += min;
    return nc;
}

void mincost(int city) {
    visited[city] = 1;
    printf("%d -> ", city);
    int ncity = least(city);
    if (ncity == 999) {
        ncity = 1;
        printf("%d\n", ncity);
        cost += a[city][ncity];
        return;
    }
    mincost(ncity);
}

void readMatrix() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
}

int main() {
	printf("Enter the number of cities: ");
	scanf("%d", &n);
	printf("Enter the cost matrix of cities: ");
	readMatrix();
	printf("\nMinimum Cost path: ");
	mincost(1);
	printf("\nMinimum Cost to travel: %d", cost);
	return 0;
}