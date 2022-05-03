#include <stdio.h>

int opcount = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lb, int ub) {
    int pivot, start, end;
    pivot = arr[lb];
    start = lb;
    end = ub + 1;
    do {
        do {
            opcount++;
            start++;
        } while (arr[start] < pivot);
        do {
            opcount++;
            end--;
        } while (arr[end] > pivot);
        if (start < end)
            swap(&arr[start], &arr[end]);
    } while (start < end);
    swap(&arr[lb], &arr[end]);
    return end;
}

void quickSort(int arr[], int lb, int ub) {
    int loc;
    if (lb < ub) {
        loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}

int main() {
    for(int i=0; i<20; i++) {
        opcount = 0;
        int arr[i+1];
        for(int j=0; j<i+1; j++)
            arr[j] = j+1;
        quickSort(arr, 0, i);
        for(int j=0; j<i+1; j++)
            printf("%d ", arr[j]);
        printf("Opcount: %d", opcount);
        printf("\n");
    }
    return 0;
}
