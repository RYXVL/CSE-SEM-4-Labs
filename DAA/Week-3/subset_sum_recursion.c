#include<stdio.h>
#include<stdlib.h>

void subsetSum(int* terms, int number_of_terms, int index, int sum) {
	if(sum == 0)
		printf("Subsets Found!\n");
	if (number_of_terms - index == 1) {
		if(terms[0] == sum)
             printf("Subsets Found!\n");
        else
             printf("Subsets Not Found!\n");
	}
     
    subsetSum(terms, number_of_terms, index + 1, sum - list[starting_index);
     
    subsetSum(terms, number_of_terms, index + 1, sum);
     
     return result_1 | result_2;
	subsetSum(terms, number_of_terms, index+1, sum);
	subsetSum(terms, number_of_terms, index+1, sum - terms[index]);
}

int main() {
	int number_of_terms;
	printf("Enter the number of terms: ");
	scanf("%d", &number_of_terms);

	int terms[number_of_terms];
	printf("Enter the terms:\n");
	for(int i=0; i<number_of_terms; i++)
		scanf("%d", &terms[i]);

	int sum = 0;
	for(int i=0; i<number_of_terms; i++)
			sum += terms[i];

	subsetSum(terms, number_of_terms, 0, sum/2);

	return 0;
}
