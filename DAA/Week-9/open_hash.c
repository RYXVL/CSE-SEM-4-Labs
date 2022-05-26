#include<stdio.h>
#include<stdlib.h>

#define size 7
int c=0;

typedef struct node * nodeptr;
typedef struct node {
  int data;
  nodeptr link;
}node;

nodeptr chain[size];

void init() {
  int i;
  for (i = 0; i < size; i++)
      chain[i] = NULL;
}

void insert(int value) {
  nodeptr newNode = malloc(sizeof(struct node));
  newNode -> data = value;
  newNode -> link = NULL;
  int key = value % size;
  if (chain[key] == NULL)
    chain[key] = newNode;
  else {
    nodeptr temp = chain[key];
    while (temp -> link) 
      temp = temp -> link;
    temp -> link = newNode;
  }
}

void print() {
  int i;
  for (i = 0; i <size; i++) {
    nodeptr temp = chain[i];
    printf("chain[%d]-->", i);
    while (temp) {
      printf("%d -->", temp -> data);
      temp = temp -> link;
    }
    printf("NULL\n");
  }
}

void search(){
   int i;
    printf("\n Enter element to be searched:");
    int key;
    scanf("%d",&key);
    nodeptr temp = chain[key%size];
    while (temp) {
      c++;
      if(temp->data==key){
        printf("\n Element found:");
        printf("\n Number of comparisons: %d",c);
        return;
      }
      temp = temp -> link;
    }
    printf("\n Element not found:");
    printf("\n Number of comparisons: %d",c);
  
}

int main() {
  init();
  int choice;
  printf("\n Menu \n 1. Insert \n 2. Display \n 3. Search \n 4. Exit \n ");
  while(1){
    printf("\n Enter your choice:");
    scanf("%d", &choice);
    switch(choice){
     case 1: printf("\n Enter the value:");
             int input;
             scanf("%d",&input);
             insert(input);
             break;
     case 2:
            printf("\n");
            print();       
            break; 
     case 3:c=0;
            search();
            break;
     case 4: 
             printf("\n");
             exit(0);
             break;
    }
  }
  return 0;
}
