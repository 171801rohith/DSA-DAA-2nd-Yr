#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[min_index] > a[j]) min_index = j;
        }
        if (min_index != i) {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
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
    selectionSort(a, n);
    end = clock();
    printf("\nArray after sorting: ");
    display(a, n);
    timetaken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken to sort: %lf", timetaken);
    return 0;
}