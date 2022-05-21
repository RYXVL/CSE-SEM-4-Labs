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
    int largest;
	while(flag) {
		flag = 0;
		for(int i=0; i<=(end-1)/2; i++) {
            largest = i;
			opcount+=4;
			if(2*i+1<=end && arr[largest]<arr[2*i+1]) {
				largest = 2*i+1;
				flag = 1;
			}
			if(2*i+2<=end && arr[largest]<arr[2*i+2]) {
				largest = 2*i+2;
				flag = 1;
			}
            if(largest!=i)
                swap(&arr[i], &arr[largest]);
		}
	}
}

int main() {
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int arr[n];
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
