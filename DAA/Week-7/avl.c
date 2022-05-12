#include<stdio.h>
#include<stdlib.h>
 
typedef struct node* nodeptr;
typedef struct node{
    int key;
    nodeptr left;
    nodeptr right;
    int height;
}node;

nodeptr stack[100];
int tos = -1;
 
int max(int a, int b){
    return a>b?a:b;
}

int height(nodeptr root){
    if (!root) return 0;
    return 1+max(height(root->left), height(root->right));
}
 
nodeptr getNode(int key){
    nodeptr newnode = (nodeptr)malloc(sizeof(*newnode));
    newnode->key = key;
    newnode->left = newnode->right = NULL;
    newnode->height = 0;
    return newnode;
}
 
void rightRotate(nodeptr* root, nodeptr* y)
{
    nodeptr og = *y;
    nodeptr x = (*y)->left;
    nodeptr T2 = x->right;
    x->right = *y;
    (*y)->left = T2;
    (*y)->height = height(*y);
    x->height = height(x);
    og = x;
    nodeptr new = stack[tos--];
    if(!(new)) *root = x;
    else {
        if((new)->left->key = (*y)->key)
            (new)->left = x;
        else
            (new)->right = x;
    }
}

void leftRotate(nodeptr* root, nodeptr* x){
    nodeptr og = *x;
    nodeptr y = (*x)->right;
    nodeptr T2 = y->left;
    y->left = *x;
    (*x)->right = T2;
    (*x)->height = height(*x);
    y->height = height(y);
    og = y;
    nodeptr new = stack[tos--];
    if(!(new)) *root = y;
    else {
        if((new)->left->key = (*x)->key)
            (new)->left = y;
        else
            (new)->right = y;
    }
}
 
int getBalance(nodeptr root){
    if (!root) return 0;
    return height(root->left) - height(root->right);
}


void balance(nodeptr* root, int key){
    while(tos != -1){
        nodeptr node = stack[tos--];
        node->height = height(node);
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key) rightRotate(root, &node);
        if (balance < -1 && key > node->right->key) leftRotate(root, &node);
        if (balance > 1 && key > node->left->key) {
            leftRotate(root, &node->left);
            rightRotate(root, &node);
        }
        if (balance < -1 && key < node->right->key){
            rightRotate(root, &node->right);
            leftRotate(root, &node);
    }
    }
}

void insert(nodeptr* root, int key){
    nodeptr curr = *root;
    while(1){
        if(!curr) {
            curr = getNode(key);
            break;
        }
        stack[++tos] = curr;
        if(key > curr->key){
            if(!curr->right) {
                curr->right = getNode(key);
                break;
            }
            else curr = curr->right;
        } 
        else if(key < curr->key){ 
            if(!curr->left) {
                curr->left = getNode(key);
                break;
            }
            else curr = curr->left;
        }
    }
    balance(root, key);
}

void inOrder(nodeptr root){
    if(root){
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
 
int main()
{
    nodeptr root = getNode(10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 25);
  /*

            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Inorder traversal of the constructed AVL tree is \n");
  inOrder(root);
  return 0;
}
