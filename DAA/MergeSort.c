#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid, int high) {
	int k = low, i = low, j = mid + 1, res_a[10000];
	while (i <= mid && j <= high) {
		if (a[i] < a[j]) res_a[k++] = a[i++];
		else res_a[k++] = a[j++];
	}
	while (i <= mid) res_a[k++] = a[i++];
	while (j <= high) res_a[k++] = a[j++];
	
	for (int m = low; m <= high; m++) a[m] = res_a[m];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void display(int a[], int n) {
	for (int i = 0; i < n; i++) printf("%d\t", a[i]);
}

int main() {
	int n, a[10000];
	clock_t end, start;
	double timetaken;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	srand(time(NULL));
	for (int i = 0; i < n; i++) a[i] = rand() % 1000;
	printf("\nArray before sorting: ");
	display(a, n);
	start = clock();
	mergeSort(a, 0, n - 1);
	end = clock();
	printf("\nArray after sorting: ");
	display(a, n);
	timetaken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
	printf("\nTime taken to sort: %lf", timetaken);
	return 0;
}