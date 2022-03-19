#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node* nodeptr;
typedef struct node {
    char node_name;
    nodeptr link;
}node;

nodeptr getNode(char node_name) {
    nodeptr newNode = (nodeptr)malloc(sizeof(*newNode));
    newNode->node_name = node_name;
    newNode->link = NULL;
    return newNode;
}

void printList(nodeptr start) {
    printf("%c", start->node_name);
    start = start->link;
    while(start) {
        printf("->%c", start->node_name);
        start = start->link;
    }
}

int main() {
    int number_of_nodes;
    nodeptr temp;
    char connecting_node;

    printf("Enter number of nodes: ");
    scanf("%d", &number_of_nodes);

    int adjacency_list[number_of_nodes][number_of_nodes];

    for(int i=0; i<number_of_nodes; i++) {
        for(int j=0; j<number_of_nodes; j++)
            adjacency_list[i][j] = 0;
    }

    nodeptr arr[number_of_nodes];

    for(int i=0; i<number_of_nodes; i++)
        arr[i] = getNode(i+65);

    for(int i=0; i<number_of_nodes; i++) {
        temp = arr[i];
        printf("Enter the nodes which %c is connected to and press 0 to move to next starting node.\n", i+65);
        while(1) {
            fflush(stdin);
            scanf("%c", &connecting_node);
            if(connecting_node=='0')
                break;
            if(connecting_node==(i+65))
                continue;
            adjacency_list[i][connecting_node-65]=1;
            temp->link = getNode(connecting_node);
            temp = temp->link;
        }
    }

    for(int i=0; i<number_of_nodes; i++) {
        for(int j=0; j<number_of_nodes; j++) {
            printf("%d ", adjacency_list[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<number_of_nodes; i++) {
        printList(arr[i]);
        printf("\n");
    }

    return 0;
}
