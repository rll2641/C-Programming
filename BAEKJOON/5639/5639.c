#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *llink, *rlink;
} TreeNode;

TreeNode* create_new_node(int data) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->data = data;
    new_node->llink = new_node->rlink = NULL;
    return new_node;
}

TreeNode* insert_data(TreeNode* root, int data) {
    if(root == NULL) return create_new_node(data);
    if(root->data > data) {
        root->llink = insert_data(root->llink, data);
    }
    else if(root->data < data) {
        root->rlink = insert_data(root->rlink, data);
    }
    return root;
}

void postorder(TreeNode* root) {
    if(root != NULL) {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\n", root->data);
    }
}

int main() {
    TreeNode* root = NULL;
    int num;

    while(scanf("%d", &num) != EOF) {
        root = insert_data(root, num);
    }
    postorder(root);
    return 0;
}