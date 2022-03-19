#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* sieve(int number) {
	int arr[(number+1)];
	int count = 0;

    arr[0]=arr[1]=0;

	for(int i=2; i<=number; i++)
		arr[i]=i;

	for(int i=2; i<=(int)floor(sqrt(number)); i++) {
		if(arr[i]!=0) {
			int j=i*i;
			while(j<=number) {
				arr[j]=0;
				j+=i;
			}
		}
	}

	for(int i=0; i<number; i++) {
        if(arr[i]>0)
            count++;
    }
	
    int j = 1;
    int* brr=(int*)calloc(count+1,sizeof(int));
	brr[0] = count;

	for(int i=2;i<=number;i++) {
		if(arr[i]!=0) {
			brr[j]=arr[i];
			j++;
		}
	}

	return brr;
}

int gcd(int m, int n) {
	int *arr, *brr;
    int answer = 1;
    
	arr = sieve(m);
	brr = sieve(n);

	int tosa = -1;
    int tosb = -1;
	int a[100], b[100];
	
	for(int i=0;i<100;i++) {
		a[i]=0;
		b[i]=0;
	}

	int i = 1;
    
	while(m>0 && i<=arr[0]) {
        if(m%arr[i]==0) {
            m/=arr[i];
            a[++tosa]=arr[i];
            i--;
        }
        i++;
	}

	i=1;
	while(n>0 && i<=brr[0]) {
        if(n%brr[i]==0) {
            n/=brr[i];
            b[++tosb]=brr[i];
            i--;
        }
        i++;
	}
	
	for(int i=0 ;i<=tosa; i++) {
        for(int j=0; j<=tosb; j++) {
            if(b[j]==a[i]){
                answer*=b[j];
                b[j]=0;
            }
        }
    }

    return answer;
}

int main() {
	printf("Enter m and n:\n");
	int m,n;
	scanf("%d %d",&m, &n);
	int ans = gcd(m,n);
	printf("GCD of %d & %d is: %d\n", m, n, ans);
	return 0;
}