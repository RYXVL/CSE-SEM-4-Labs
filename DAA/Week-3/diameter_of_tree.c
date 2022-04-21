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

int heightOfTree(nodeptr root) {
	if(!root) return 0;
	return 1+(heightOfTree(root->llink)>heightOfTree(root->rlink)?heightOfTree(root->rlink):heightOfTree(root->rlink));
}

int diameterOfTree(nodeptr root) {
	if (root == NULL)
        return 0;
    int lh = heightOfTree(root->llink);
    int rh = heightOfTree(root->rlink);
    int ld = diameterOfTree(root->llink);
    int rd = diameterOfTree(root->rlink);
    int max_d = ld>rd?ld:rd;
    return (lh+rh+1>max_d?lh+rh+1:max_d);
}

int main() {
	int n;
	int data;
	nodeptr root = NULL;
	printf("Enter number of numbers to be inserted: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		printf("Enter data to be inserted: ");
		scanf("%d", &data);
		insertIntoBST(&root, data);
	}
	printf("Diameter of the tree is: %d", diameterOfTree(root));
	return 0;
}
