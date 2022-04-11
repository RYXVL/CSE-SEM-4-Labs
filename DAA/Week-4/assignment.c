#include<stdio.h>

int number_of_people;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *a, int l, int r, int permutations_matrix[], int* min_cost, int cost_matrix[][number_of_people]) {
    int i;
    int sum;
    if (l == r) {
        sum = 0;
        for(int i=0; i<=r; i++)
            sum+= cost_matrix[a[i]-1][i];
        if(sum<*min_cost){
            *min_cost = sum;
            for(int i=0; i<number_of_people; i++)
            permutations_matrix[i] = a[i];
        }
    }
    else {
        for (i = l; i <= r; i++) {
            swap((a+l), (a+i));
            permute(a, l+1, r, permutations_matrix, min_cost, cost_matrix);
            swap((a+l), (a+i));
        }
    }
}

int main() {
    printf("Enter the number of people: ");
    scanf("%d", &number_of_people);
    int cost_matrix[number_of_people][number_of_people];
    for(int i=0; i<number_of_people; i++) {
        for(int j=0; j<number_of_people; j++) {
            printf("Enter cost of person %d for job %d: ", i+1, j+1);
            scanf("%d", &cost_matrix[i][j]);
        }
    }
    int person_order[number_of_people];
    for(int i=0; i<number_of_people; i++)
        person_order[i] = i+1;
    int permutations_matrix[number_of_people];
    int min_cost = 0;
    for(int i=0; i<number_of_people; i++) {
        for(int j=0; j<number_of_people; j++) {
            if(i!=j)
                continue;
            min_cost+=cost_matrix[i][j];
        }
    }
    permute(person_order, 0, number_of_people-1, permutations_matrix, &min_cost, cost_matrix);
    printf("Min Cost: %d\n", min_cost);
    for(int i=0; i<number_of_people; i++)
        printf("Person %d Does Job %d Cost %d\n", i+1, permutations_matrix[i], cost_matrix[i][permutations_matrix[i]-1]);
    return 0;
}
