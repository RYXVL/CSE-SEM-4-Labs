#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int* arr, int end) {
	int flag = 1;
	while(flag) {
		flag = 0;
		for(int i=0; i<=end/2-1; i++) {
			opcount+=4;
			if(2*i+1<=end && arr[i]<arr[2*i+1]) {
				swap(&arr[i], &arr[2*i+1]);
				flag = 1;
			}
			if(2*i+2<=end && arr[i]<arr[2*i+2]) {
				swap(&arr[i], &arr[2*i+2]);
				flag = 1;
			}
		}
	}
}

// void heapify(int* arr, int end) {
// 	int flag = 1;
// 	while(flag) {
// 		flag = 0;
// 		for(int i=0; i<=end/2-1; i++) {
// 			opcount+=2;
// 			if(arr[i]<arr[2*i+1]) {
// 				// opcount++;
// 				swap(&arr[i], &arr[2*i+1]);
// 				flag = 1;
// 			}
// 			if(arr[i]<arr[2*i+2]) {
// 				// opcount++;
// 				swap(&arr[i], &arr[2*i+2]);
// 				flag = 1;
// 			}
// 		}
// 	}
// }

int main() {
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	int *arr = (int*)calloc(n, sizeof(int));
	printf("Enter the elements of the array: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
		heapify(arr, i);
	}
	printf("The Heap is: ");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("Opcount: %d", opcount);
	return 0;
}
