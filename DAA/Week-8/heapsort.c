#include<stdio.h>

int opcount = 0;

void swap(int* a, int* b) {
    opcount++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int end) {
    int flag = 1;
    int largest;
    opcount++;
    while (flag) {
        flag = 0;
       
        for (int i = (end - 1) / 2; i >= 0; i--) {
           
            largest = i;
            if (2 * i + 1 <= end && arr[largest] < arr[2 * i + 1]) {
                largest = 2 * i + 1;
                flag = 1;
                opcount++;
            }
            if (2 * i + 2 <= end && arr[largest] < arr[2 * i + 2]) {
                largest = 2 * i + 2;
                flag = 1;
                opcount++;
            }
            if (largest != i)
                swap(&arr[i], &arr[largest]);
        }
    }
}

void heapsort(int* arr, int n) {
    heapify(arr, n - 1);

    for (int i = n - 1; i > 0; i--) {
        opcount++;
        swap(&arr[0], &arr[i]);
        heapify(arr, i - 1);
    }
}

int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[100];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    heapsort(arr, size);

    printf("Array after heapsort: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("opcount=%d", opcount);
    return 0;
}
