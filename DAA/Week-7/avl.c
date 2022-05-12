#include<stdio.h>
#include<stdlib.h>
 
typedef struct node* nodeptr;
typedef struct node {
    int data;
    nodeptr left;
    nodeptr right;
    int height;
}node;

nodeptr stack[100];
int tos = -1;
 
int max(int a, int b) {
    return a > b? a : b;
}

int height(nodeptr N){
    if (!N) return 0;
    return 1 + max(height(N->left), height(N->right));
}
 
nodeptr getNode(int data){
    nodeptr newnode = (nodeptr)malloc(sizeof(*newnode));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    newnode->height = 0;
    return newnode;
}
 
nodeptr rightRotate(nodeptr* y)
{
    nodeptr og = *y;
    nodeptr x = og->left;
    nodeptr T2 = x->right;
    x->right = og;
    og->left = T2;
    og->height = height(og);
    x->height = height(x);
    return x;
}

nodeptr leftRotate(nodeptr* x){
    nodeptr og = *x;
    nodeptr y = og->right;
    nodeptr T2 = y->left;
    y->left = og;
    og->right = T2;
    og->height = height(og);
    y->height = height(y);
    return y;
}
 
int getBalance(nodeptr N){
    if (!N) return 0;
    return height(N->left) - height(N->right);
}


nodeptr balance(int data, nodeptr *root){
    nodeptr newRoot = *root;
    while(tos != -1){
        nodeptr node = stack[tos--];
        nodeptr prev = tos == -1 ? NULL : stack[tos];
        node->height = height(node);
        int balance = getBalance(node);
        if (balance > 1 && data < node->left->data) node = rightRotate(&node);
        if (balance < -1 && data > node->right->data) node = leftRotate(&node);
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(&node->left);
            node = rightRotate(&node);
        }
        if (balance < -1 && data < node->right->data){
            node->right = rightRotate(&node->right);
            node = leftRotate(&node);
        }
        if(prev){
            if(prev->data > node->data) prev->left = node;
            else prev->right = node;
        }
        newRoot = node;
    }
    return newRoot;
}

nodeptr insertIntoBST(nodeptr* node, int data){
    tos = -1;
    nodeptr curr = *node;
    while(1){
        if(!curr) {
            curr = getNode(data);
            break;
        }
        stack[++tos] = curr;
        if(data > curr->data){
            if(!curr->right) {
                curr->right = getNode(data);
                break;
            }
            else curr = curr->right;
        } 
        else if(data < curr->data){ 
            if(!curr->left) {
                curr->left = getNode(data);
                break;
            }
            else curr = curr->left;
        }
    }
    return balance(data, node);
}

void inOrder(nodeptr root) {
    if(root) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
 
int main() {
    nodeptr root = getNode(10);
    root = insertIntoBST(&root, 20);
    root = insertIntoBST(&root, 30);
    root = insertIntoBST(&root, 40);
    root = insertIntoBST(&root, 50);
    root = insertIntoBST(&root, 25);
    printf("Preorder Traversal of AVL Tree is : ");
    inOrder(root);
    return 0;
}
