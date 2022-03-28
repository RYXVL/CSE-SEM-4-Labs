#include<stdio.h>
#include<stdlib.h>

void searchString(char *main_string, int size_of_main_string, char *search_string, int size_of_search_string) {
    int flag = 0;
    int opcount = 0;
    for(int i=0; i<size_of_main_string-size_of_search_string+1; i++) {
        for(int j=i; j<=i+size_of_search_string-1; j++) {
            opcount++;
            if(main_string[j]==search_string[flag]) {
                flag++;
                continue;
            }
            else {
                flag = 0;
                break;
            }   
        }
        if(flag==size_of_search_string) {
            printf("Substring found!\n");
            printf("Opcount: %d\n", opcount);
            return;
        }
    }
    printf("Substring not found!\n");
    printf("%d\n", opcount);
}

int main() {
    
    char main_string[21] = "aaaaaaaaaaaaaaaaaaaa\0";
    
    for(int i=0; i<20; i++) {
        if(i==0) {
            char* search_string = (char*)calloc(i+1, sizeof(char));
            search_string[i] = 'b';
            searchString(main_string, 20 , search_string, i+1);
            continue;
        }
        char* search_string = (char*)calloc(i+1, sizeof(char));
        for(int j=0; j<(i+1); j++) {
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
