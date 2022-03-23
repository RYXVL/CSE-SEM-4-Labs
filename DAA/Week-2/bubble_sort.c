#include<stdio.h>

void bubbleSort(int *arr, int size) {
    int flag = 1;
    int temp;
    while(flag!=0) {
        flag = 0;
        for(int i=0; i<size-1; i++) {
            
            if(arr[i]>arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = 1;
            }
        }
    }
    for(int i=0 ;i<size; i++)
        printf("%d ", arr[i]);
}

int main() {
    int size_of_array;
    printf("Enter the size of the array: ");
    scanf("%d", &size_of_array);
    int arr[size_of_array];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<size_of_array; i++)
        scanf("%d", arr+i);
    bubbleSort(arr, size_of_array);
    return 0;
}
