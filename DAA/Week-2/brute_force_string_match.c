#include<stdio.h>

void searchString(char *main_string, int size_of_main_string, char *search_string, int size_of_search_string) {
    int flag;
    int iterations;
    for(int i=0; i<size_of_main_string-size_of_search_string+1; i++) {
        iterations = 0;
        flag = 0;
        if(main_string[i]==search_string[iterations]) {
            i++;
            iterations++;
            flag++;
            for(iterations; iterations<size_of_search_string; iterations++) {
                if(main_string[i]!=search_string[iterations]) {
                    i+=iterations;
                    break;
                }
                i++;
                iterations++;
                flag++;
            }
            if(flag==size_of_search_string)
                printf("Substring found!");
        }
    }
    printf("Substring not found!");
}

int main() {
    int size_of_main_string;
    int size_of_search_string;

    printf("Enter the size of the main string: ");
    scanf("%d", &size_of_main_string);
    printf("Enter the size of the string to be searched for: ");
    scanf("%d", &size_of_search_string);

    char main_string[size_of_main_string];
    char search_string[size_of_search_string];

    printf("Enter the main string: ");
    scanf("%s", main_string);
    printf("Enter the string to be searched for: ");
    scanf("%s ", search_string);

    searchString(main_string, size_of_main_string, search_string, size_of_search_string);

    return 0;
}