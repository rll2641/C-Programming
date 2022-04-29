#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *llink,*rlink;
} TreeNode;

TreeNode* create_new_node(char alpha) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->data = alpha;
    new_node->llink = new_node->rlink = NULL;
    return new_node;
}

TreeNode* search_data(TreeNode* root, char alpha) {
    TreeNode* result = NULL;
    if(root != NULL) {
        if(root->data == alpha) {
            return root;
        }
        else {
            TreeNode* save = search_data(root->llink, alpha);
            if(save != NULL) {
                return save;
            }
            return search_data(root->rlink, alpha);
        }
    }
    else {
        return NULL;
    }
}

void insert_node(TreeNode* root, char ch2, char ch3) {
    if(root == NULL) {
        return;
    }
    if(ch2 != '.') {
        root->llink = create_new_node(ch2);
    }
    if(ch3 != '.') {
        root->rlink = create_new_node(ch3);
    }
}

void preorder(TreeNode* root) {
    if(root != NULL) {
        printf("%c", root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void inorder(TreeNode* root) {
    if(root != NULL) {
        inorder(root->llink);
        printf("%c", root->data);
        inorder(root->rlink);
    }
}

void postorder(TreeNode* root) {
    if(root != NULL) {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%c", root->data);
    }
}

int main() {
    TreeNode* root = NULL;
    TreeNode* search;
    int n, i=0, j=0, len, count = 0;
    char save_ch[1000];
    scanf("%d", &n);
    getchar();
    while(n--) {
        char ch1, ch2, ch3;
        scanf("%c %c %c", &ch1, &ch2, &ch3);
        getchar();
        if(ch1 == 'A') {
            root = create_new_node(ch1);
            root->llink = create_new_node(ch2);
            root->rlink = create_new_node(ch3);
            continue;
        }
        search = search_data(root, ch1);
        if(search != NULL) {
            insert_node(search, ch2, ch3);
        }
        else {
            save_ch[i++] = ch1;
            save_ch[i++] = ch2;
            save_ch[i++] = ch3;
            count++;
        }
    }
    len = strlen(save_ch);
    while(1) {
        search = search_data(root, save_ch[j]);
        if(search != NULL) {
            insert_node(search ,save_ch[j+1], save_ch[j+2]);
            save_ch[j] = 'a';
            count--;
        }
        j+=3;
        if(j >= len) {
            j = 0;
        }
        if(count == 0) {
            break;
        }
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}