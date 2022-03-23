#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* sieve(int number) {
	int arr[number+1];
	int count = 0;
	int opcount = 0;
    arr[0] = arr[1] = 0;

	for(int i = 2; i <= number; i++)
		arr[i] = i;

	for(int i = 2; i <= (int)floor(sqrt(number)); i++) {
		if(arr[i] != 0) {
			int j = i*i;
			while(j <= number) {
				opcount++;
				arr[j] = 0;
				j += i;
			}
		}
	}

	for(int i = 0; i < number; i++) 
        if(arr[i] > 0) count++;
	
    int j = 2;
    int* brr=(int*)calloc(count+2, sizeof(int));
	brr[0] = count;
	brr[1] = opcount;

	for(int i = 2;i <= number; i++) 
		if(arr[i] != 0){
			brr[j] = arr[i];
			j++;
		}
	return brr;
}

void gcd(int m, int n) {
	int *arr, *brr;
	int c = m+n;
    int answer = 1;
    
	arr = sieve(m);
	brr = sieve(n);
	
	int opcount = arr[1] + brr[1];
	int tosa = -1;
    int tosb = -1;

	int a[100] = {0}, b[100] = {0};

	int i = 2;
    
	while(m > 0 && i <= arr[0]) {
       while(m % arr[i] == 0) {
            m /= arr[i];
            a[++tosa] = arr[i];
        }
        i++;
	}

	i = 2;
	while(n > 0 && i <= brr[0]) {
        while(n % brr[i] == 0) {
            n /= brr[i];
            b[++tosb] = brr[i];
        }
        i++;
	}
	
	for(int i = 0; i <= tosa; i++)
        for(int j = 0; j <= tosb; j++) 
            if(b[j] == a[i]){
                answer *= b[j];
                b[j] = 0;
				break;
            }

    printf("%d : %d : %d\n", answer, c, opcount);
}

int main() {
	printf("gcd : m+n : opcount\n");
    int iter = 15;
    int a = 1, b = 2, c = 0;
    while(iter--){
        gcd(a, b);
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}
