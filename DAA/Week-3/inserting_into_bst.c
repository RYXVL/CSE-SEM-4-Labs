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
	int top = -1;
	nodeptr stack[100];
	nodeptr current = root;
	while(current) {
		stack[++top] = current;
		current = current->llink;
	}
	while(top != -1) {
		current = stack[top--];
		printf("%d ", current->data);
		current = current->rlink;
		while(current) {
			stack[++top] = current;
			current = current->llink;
		}
	}
}

void preOrder(nodeptr root) {
	int top = -1;
	nodeptr stack[100];
	nodeptr current = root;
	while(current) {
		printf("%d ", current->data);
		stack[++top] = current;
		current = current->llink;
	}
	while(top != -1) {
		current = stack[top--];
		current = current->rlink;
		while(current) {
			printf("%d ", current->data);
			stack[++top] = current;
			current = current->llink;
		}
	}
}

void postOrder(nodeptr root) {
	int top = -1;
	nodeptr stack[100];
	nodeptr temp;
	nodeptr current = root;
	do {
		while(current) {
			if(current->rlink)
				stack[++top] = current->rlink;
			stack[++top] = current;
			current = current->llink;
		}
		current = stack[top--];
		if(current->rlink && current->rlink == stack[top]) {
			top--;
			stack[++top] = current;
			current = current->rlink;
		}
		else {
			printf("%d ", current->data);
			current = NULL;
		}
	} while(top != -1);
}

int main() {
	nodeptr root = NULL;
	int iteration = 1;
	int n;
	int choice;
	int data;
	while(iteration) {
		printf("1. Insert into BST\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter number of numbers to be inserted: ");
				scanf("%d", &n);
				for(int i=0; i<n; i++) {
					printf("Enter data to be inserted: ");
					scanf("%d", &data);
					insertIntoBST(&root, data);
				}
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
