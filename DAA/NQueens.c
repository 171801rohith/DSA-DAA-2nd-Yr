#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int count = 0, x[5], n;

int place(int k, int i) {
	for (int j = 1; j < k; j++)
		if (x[j] == i || (abs(x[j] - i) == abs(j - k))) return 0;
	return 1;
}

int n_queens(int k, int n) {
	for (int i = 1; i <= n; i++) {
		if (place(k, i)) {
			x[k] = i;

			if (k == n) {
				count++;
				printf("\nSolution %d\n", count);
				for (int j = 1; j <= n; j++) {
				    for (int p = 1; p <= n; p++) 
				        if (x[j] == p) printf("$\t");
				        else printf("0\t");
				    printf("\n");
				}
				printf("\n");
			} else {
				n_queens(k + 1, n);
			}
		}
	}
}

int main() {
	printf("Enter the number of Queens: ");
	scanf("%d", &n);
	n_queens(1, n);
	if (count == 0) printf("\nNo solutions found for %d queens.", n);
	else printf("\nSolutions found for %d queens are %d.", n, count);
	return 0;
}