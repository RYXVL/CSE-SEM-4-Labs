#include<stdio.h>

int opcount = 0;
void swap(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int partition(int arr[], int size, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for(int j = low; j<=high - 1; j++){
		opcount++;
        if(arr[j]<pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
    }
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void quickSort(int arr[], int size, int low, int high) {
	if(low<high) {
		int pi = partition(arr, size, low, high);
		quickSort(arr, size, low, pi - 1);
		quickSort(arr, size, pi + 1, high);
	}
}

int main() {
    for(int i=0; i<20; i++) {
        opcount = 0;
        int arr[i+1];
        // int arr[i+1];
        // int temp[i+1];
        for(int j=0; j<i+1; j++)
            arr[j] = j+1;
        quickSort(arr, i+1, 0, i+1);
        for(int j=0; j<i+1; j++)
            printf("%d ", arr[j]);
        printf("Opcount: %d", opcount);
        printf("\n");
    }
	// int size;
	// printf("Enter the size of the array: ");
	// scanf("%d", &size);
	// int arr[size];
	// printf("Enter the elements of the array: ");
	// for(int i=0; i<size; i++)
	// 	scanf("%d", &arr[i]);
	// quickSort(arr, size, 0, size - 1);
	// printf("The sorted array is: ");
	// for(int i=0; i<size; i++)
	// 	printf("%d ", arr[i]);
    //     printf("Opcount: %d", opcount);
	return 0;
}
