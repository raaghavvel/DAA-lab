//CH.SC.U4CSE24155
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }
    swap(&arr[low], &arr[j]);
    return j;
}

int partitionLast(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int partitionRandom(int arr[], int low, int high) {
    int randIndex = low + rand() % (high - low + 1);
    swap(&arr[randIndex], &arr[high]);
    return partitionLast(arr, low, high);
}

void quickSort(int arr[], int low, int high, int mode) {
    if (low < high) {
        int pi;

        if (mode == 1)
            pi = partitionFirst(arr, low, high);
        else if (mode == 2)
            pi = partitionLast(arr, low, high);
        else
            pi = partitionRandom(arr, low, high);

        quickSort(arr, low, pi - 1, mode);
        quickSort(arr, pi + 1, high, mode);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main() {
    srand(time(NULL));

    int arr[] = {157, 110, 147, 122, 149, 151, 111, 141, 112, 123, 133, 117};
    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[12];

    printf("Original Array:\n");
    printArray(arr, n);

    for (int i = 0; i < n; i++) temp[i] = arr[i];
    quickSort(temp, 0, n - 1, 1);
    printf("\nSorted using First Element Pivot:\n");
    printArray(temp, n);

    for (int i = 0; i < n; i++) temp[i] = arr[i];
    quickSort(temp, 0, n - 1, 2);
    printf("\nSorted using Last Element Pivot:\n");
    printArray(temp, n);

    for (int i = 0; i < n; i++) temp[i] = arr[i];
    quickSort(temp, 0, n - 1, 3);
    printf("\nSorted using Random Pivot:\n");
    printArray(temp, n);
}
