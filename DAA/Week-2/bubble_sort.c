#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr, int size) {
    int opcount = 0;
    int flag = 1;
    int temp;
    while(flag != 0) {
        flag = 0;
        for(int i=0; i<size-1; i++) {
            opcount++;
            if(arr[i]>arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = 1;
            }
        }
    }
    printf(" Opcount: %d\n", opcount);
}

int main() {
    int size_of_array = 20;
    for(int i=0; i<20; i++) {
        int *arr = (int*)calloc(i+1, sizeof(int));
        for(int j=0; j<=i; j++)
            arr[j]=j+1;
        for(int j=0 ;j<=i; j++)
            printf("%d ", arr[j]);
        bubbleSort(arr, i+1);
    }
    printf("\n");
    for(int i=19; i>=0; i--) {
        int *arr = (int*)calloc(20-i, sizeof(int));
        for(int j=20; j>i; j--)
            arr[20-j]=j;
        for(int j=20 ;j>i; j--)
            printf("%d ", arr[20-j]);
        bubbleSort(arr, 20-i);
    }
    return 0;
}
