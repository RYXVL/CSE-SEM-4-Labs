#include<stdio.h>
#include<stdlib.h>

typedef struct node* nodeptr;
typedef struct node {
	int data;
	nodeptr llink;
	nodeptr rlink;
}node;

nodeptr getNode(int data) {
	nodeptr newNode = (nodeptr)malloc(sizeof(*newNode));
	newNode->data = data;
	newNode->llink = newNode->rlink = NULL;
	return newNode;
}

void insertIntoBST(nodeptr* root, int data) {
	nodeptr newNode = getNode(data);
	if(!(*root)) {
		*root = newNode;
		return;
	}
	nodeptr before = *root;
	nodeptr after = *root;
	if(data == (*root)->data) {
		printf("Key Found\n");
		return;
	}
	else if(data < (*root)->data)
		after = (*root)->llink;
	else if(data > (*root)->data)
		after = (*root)->rlink;
	while(after) {
		if(data == after->data) {
			printf("Key Found\n");
			return;
		}
		else if(data < after->data) {
			before = after;
			after = after->llink;
		}
		else if(data > after->data) {
			before = after;
			after = after->rlink;
		}
	}
	if(data < before->data) {
		before->llink = newNode;
		printf("Data Inserted.\n");
		return;
	}
	else if(data > before->data) {
		before->rlink = newNode;
		printf("Data Inserted.\n");
		return;
	}
}

void countNodes(nodeptr root, int *count) {
	if(!root) return;
	countNodes(root->llink, count);
	(*count)++;
	countNodes(root->rlink, count);
}

int main() {
	// int n;
	int data;
	int count = 0;
	nodeptr root = NULL;
	printf("Enter data to be inserted in the root: ");
	scanf("%d", &data);
	do {
		insertIntoBST(&root, data);
		printf("Enter data to be inserted or enter -1 to exit: ");
		scanf("%d", &data);
	} while(data!=-1);
	countNodes(root, &count);
	printf("Number of nodes in the tree are: %d\n", count);
	return 0;
}
