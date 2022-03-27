#include<stdio.h>
#include<stdlib.h>

void searchString(char *main_string, int size_of_main_string, char *search_string, int size_of_search_string) {
    int flag = 0;
    for(int i=0; i<size_of_main_string; i++) {
        if(main_string[i]==search_string[flag]) {
            flag++;
            continue;
        }
        flag=0;
    }
    if(flag==size_of_search_string)
        printf("Substring found!\n");
    else
        printf("Substring not found!\n");
}

int main() {
    
    char main_string[20] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
    
    for(int i=0; i<20; i++) {
        if(i==0) {
            char* search_string = (char*)calloc(i+1, sizeof(char));
            search_string[i] = 'b';
            searchString(main_string, 20 , search_string, i+1);
            continue;
        }
        char* search_string = (char*)calloc(i+1, sizeof(char));
        for(int j=0; j<i+1; j++) {
            if(j==i) {
                search_string[j]='b';
                continue;
            }
            search_string[j] = 'a';
        }
        searchString(main_string, 20 , search_string, i+1); 
    }

    return 0;
}
