#include<stdio.h>
#include<stdlib.h>

void permute(int* arr, int n) {
	int temp;
	if(n==0) {
		for(int i=0; i<n; i++)
			printf("%d ", arr[i]);
		return;
	}
	for(int i=0; i<n; i++) {
		permute(arr, n-1);
		if(n%2!=0) {
			temp = arr[0];
			arr[0] = arr[n-1];
			arr[n-1] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[n-1];
			arr[n-1] = temp;	
		}
	}
}

int main() {
	int n;
	printf("Enter value of n\n");
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	for(int i=0; i<n; i++)
		arr[i]=i+1;
	permute(arr, n);
	return 0;
}
