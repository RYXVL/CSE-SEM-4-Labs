#include<stdio.h>

void searchString(char *main_string, int size_of_main_string, char *search_string, int size_of_search_string) {
    // printf("%s\n",  main_string);
    // printf("%s\n", search_string);
    // printf("%d\n",  size_of_main_string);
    // printf("%d\n", size_of_search_string);
    int flag = 0;
    for(int i=0; i<size_of_main_string; i++) {
        // flag = 0;
        if(main_string[i]==search_string[flag]) {
            flag++;
            continue;
        }
        if(main_string[i]!=search_string[flag]) flag=0;
    }
    if(flag==size_of_search_string)
        printf("Substring found!");
    else
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
    fflush(stdin);
    scanf("%s", main_string);
    printf("Enter the string to be searched for: ");
    fflush(stdin);
    scanf("%s ", search_string);

    // printf("%s\n",  main_string);
    // printf("%s\n", search_string);

    searchString(main_string, size_of_main_string, search_string, size_of_search_string);

    return 0;
}
