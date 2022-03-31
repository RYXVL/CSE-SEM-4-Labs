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

void inOrder(nodeptr root) {
	if(!root)
		return;
	inOrder(root->llink);
	printf("%d ", root->data);
	inOrder(root->rlink);
}

void preOrder(nodeptr root) {
	if(!root)
		return;
	printf("%d ", root->data);
	inOrder(root->llink);
	inOrder(root->rlink);
}

void postOrder(nodeptr root) {
	if(!root)
		return;
	inOrder(root->llink);
	inOrder(root->rlink);
	printf("%d ", root->data);
}

int main() {
	nodeptr root = NULL;
	int iteration = 1;
	int choice;
	int data;
	while(iteration) {
		printf("1. Insert into BST\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter data to be inserted: ");
				scanf("%d", &data);
				insertIntoBST(&root, data);
				break;
			case 2:
				printf("Inorder Traversal:\n");
				inOrder(root);
				printf("\n");
				break;
			case 3:
				printf("Preorder Traversal:\n");
				preOrder(root);
				printf("\n");
				break;
			case 4:
				printf("Postorder Traversal:\n");
				postOrder(root);
				printf("\n");
				break;
			case 5:
				exit(0);
		}
	}
	return 0;
}
