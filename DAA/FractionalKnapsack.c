#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int p[MAX], w[MAX], m, n;
float x[MAX], maxProfit = 0.0;

void FractionalKnapsack(int p[], int w[], int n, int m) {
	float ratio[MAX];
	for (int i = 0; i < n; i++) ratio[i] = (float)p[i] / w[i];

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ratio[i] < ratio[j]) {
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                
                int temp1 = p[i];
                p[i] = p[j];
                p[j] = temp1;
                
                temp1 = w[i];
                w[i] = w[j];
                w[j] = temp1;
			}
		}
	}
	
	int currentWeight = 0;
	for (int i = 0; i < n; i++) {
	    if (currentWeight + w[i] <= m) {
	        x[i] = 1;
	        currentWeight += w[i];
	        maxProfit += p[i];
	    } else {
	        x[i] = (m - currentWeight) / (float)w[i];
	        maxProfit += p[i] * x[i];
	        break;
	    }
	}
	printf("\nMax Profit is %f", maxProfit);
	printf("\nSolution Vector: ");
	for (int i = 0; i < n; i++) printf("%f\t", x[i]);
}

int main() {
	printf("Enter the number of items: ");
	scanf("%d", &n);
	printf("Enter the profit and weight of each item:\n");
	for (int i = 0; i < n; i++) {
	    printf("Item %d: ", i + 1);
	    scanf("%d%d", &p[i], &w[i]);
	}
	printf("Enter the maximum capacity of knapsack: ");
	scanf("%d", &m);
	FractionalKnapsack(p, w, n, m);
	return 0;
}