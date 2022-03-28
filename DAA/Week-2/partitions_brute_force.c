#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char* binaryString(int number, int number_of_terms) {
    int top_of_stack = -1;
    int top_of_stack_final = -1;
    char* stack = (char*)calloc(number_of_terms, sizeof(char));
    char* final_stack = (char*)calloc(number_of_terms, sizeof(char));
    while(number>0) {
        stack[++top_of_stack] = ((number%2)+'0');
        number/=2;
    }
    for(int i=0; i<number_of_terms-top_of_stack-1; i++)
        final_stack[++top_of_stack_final] = '0';
    int top_of_stack_copy = top_of_stack;
    for(int i=0; i<=top_of_stack; i++)
        final_stack[i+top_of_stack_final+1] = stack[top_of_stack_copy--];
    return final_stack;
}

void subsets(int* terms, int number_of_terms, int total) {
    char* str = (char*)calloc(number_of_terms, sizeof(char));
    int iteration_count;
    for(int i=1; i<=(pow(2, number_of_terms)-2); i++) {
        str = binaryString(i, number_of_terms);
        iteration_count = 0;
        for(int j=0; j<number_of_terms; j++) {
            iteration_count = iteration_count + ((str[j]-'0')*terms[j]);
        }
        if(iteration_count==total/2) {
            printf("Set1: ");
            for(int j=0; j<number_of_terms; j++) {
                if(str[j]=='1')
                    printf("%d ", terms[j]);
            }
            printf("Set2: ");
            for(int j=0; j<number_of_terms; j++) {
                if(str[j]=='0')
                    printf("%d ", terms[j]);
            }
            printf("\n");
            return;
        }
    }
}

int main() {
    printf("Enter the number of terms: ");
    int number_of_terms;
    scanf("%d", &number_of_terms);

    int terms[number_of_terms];
    printf("Enter the terms: ");
    for(int i=0; i<number_of_terms; i++)
        scanf("%d", &terms[i]);

    int total = 0;
    for(int i=0; i<number_of_terms; i++)
        total+=terms[i];
    subsets(terms, number_of_terms, total);

    return 0;
}
