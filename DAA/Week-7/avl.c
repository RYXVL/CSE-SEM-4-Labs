#include<stdio.h>
#include<stdlib.h>

typedef struct node* nodeptr;
typedef struct node {
	int data;
	int balfac;
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

// void countNodes(nodeptr root, int *count, int *opcount) {
// 	if(!root) return;
// 	countNodes(root->llink, count, opcount);
// 	(*opcount)++;
// 	(*count)++;
// 	countNodes(root->rlink, count, opcount);
// }



int heightOfTree(nodeptr root) {
	if(!root) return 0;
	return 1+(heightOfTree(root->llink)>heightOfTree(root->rlink)?heightOfTree(root->rlink):heightOfTree(root->rlink));
}

void balanceFactor(nodeptr root) {
	int lh = heightOfTree(root->llink);
	int rh = heightOfTree(root->rlink);
	root->balfac = (lh - rh);
}

void checkBalancedTree(nodeptr *root) {
	if(!(*root)) return;
	checkBalancedTree(&((*root)->llink));
	balanceFactor(*root);
	checkBalancedTree(&((*root)->rlink));
}

void inOrder(nodeptr root) {
	if(!root) return;
	inOrder(root->llink);
	printf("%d ", root->balfac);
	inOrder(root->rlink);
}

int main() {
	int data;
	nodeptr root = NULL;
	printf("Enter data to be inserted in the root: ");
	scanf("%d", &data);
	do {
		insertIntoBST(&root, data);
		// checkBalancedTree(&root);
		printf("Enter data to be inserted or enter -1 to exit: ");
		scanf("%d", &data);
	} while(data!=-1);
	checkBalancedTree(&root);
	inOrder(root);
	return 0;
}
