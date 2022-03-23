#include<stdio.h>

void gcd(int a, int b){
    int opcount = 0;
    int res = a <= b ? a : b;
    int i = 0;
    for(i = res; i > 1; i--){
        opcount++;
        if(a % i == 0 && b % i == 0) break;
    }
    printf("%d : %d : %d\n", i, a+b, opcount);
}

int main(){
    int a = 2, b = 3, c = 0;
    int iter = 20;
    printf("gcd : m+n : opcount\n");
    while(iter--){
        gcd(a, b);
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}
