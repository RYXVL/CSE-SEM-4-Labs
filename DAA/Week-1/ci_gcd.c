#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int consec_int(int m, int n) {
    int t = m<n?m:n;
    while(1) {
        if(m%t==0) {
            if(n%t==0)
                return t;
        }
        t--;
    }
}

int main() {
    int m, n;
    printf("Enter both the numbers: ");
    scanf("%d %d", &m, &n);
    if((m<0 && n<0) || (m==0 && n==0)){
        printf("Incorrect Input Entered.");
        exit(0);
    }
    int consec_int_no = consec_int(m, n);
    printf("The gcd of %d and %d is %d.", m, n, consec_int_no);
    return 0;
}
