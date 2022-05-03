#include<stdio.h>

int opcount = 0;

void merge(int arr[], int temp[], int left, int mid, int right) {
    int left_end = mid - 1;
    int k = 0;
    while(left<=left_end && mid<=right) {
        opcount++;
        if(arr[left]<arr[mid]) {
            temp[k] = arr[left];
            left++;
            k++;
        }
        else {
            temp[k] = arr[mid];
            mid++;
            k++;
        }
    }
    while(left<=left_end) {
        opcount++;
        temp[k] = arr[left];
        left++;
        k++;
    }
    while(mid<=right) {
        opcount++;
        temp[k] = arr[mid];
        mid++;
        k++;
    }
}

void mergeSort(int arr[], int temp[], int left, int right) {
    int mid;
    if(left < right) {
        mid = (left + right)/2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid+1, right);
        merge(arr, temp, left, mid + 1, right);
    }
}

int main() {
    for(int i=0; i<20; i++) {
        opcount = 0;
        int arr[i+1];
        int temp[i+1];
        for(int j=0; j<i+1; j++)
            arr[j] = j+1;
        mergeSort(arr, temp, 0, i);
        for(int j=0; j<i+1; j++)
            printf("%d ", temp[j]);
        printf("Opcount: %d", opcount);
        printf("\n");
    }
    return 0;
}
