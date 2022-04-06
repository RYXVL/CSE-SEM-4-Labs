#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

int subsetSum(int* terms, int number_of_terms, int index, int sum) {
    opcount++;
    if(sum == 0)
        return 1;
    if(index + 1 == number_of_terms && terms[index] != sum)
        return 0;
    if(index + 1 == number_of_terms && terms[index] == sum) 
	return 1;
    return subsetSum(terms, number_of_terms, index + 1, sum - terms[index]) | subsetSum(terms, number_of_terms, index + 1, sum);
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

	int existence = subsetSum(terms, number_of_terms, 0, sum/2);
    if(existence == 1)
        printf("Subsets Exist!\n");
    else
        printf("Subsets Do Not Exist!\n");
    printf("Opcount: %d\n", opcount);
	return 0;
}
