#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* 연습문제 13번~20번
typedef struct TreeNode {
    int data;
    struct TreeNode* left, *right;
} TreeNode;
*/

/* 연습문제 13~17번
TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode* root = &n6;
 */

/* 연습문제 13번

#define Max(a, b) ((a > b) ? a : b)

int get_height(TreeNode* root) {
    int height = 0;

    if(root != NULL)
        height = 1 + Max(get_height(root->left), get_height(root->right));

    return height;
}

void isBalanced(TreeNode* root) {

    int left_tree, right_tree;

    left_tree = get_height(root->left);
    right_tree = get_height(root->right);
    
    if(left_tree - right_tree == 1 || left_tree - right_tree == -1)
        printf("균형트리 입니다.\n");
    else
        printf("균형트리가 아닙니다.\n");
}

int main() {

    isBalanced(root);
    return 0;
} */

/* 연습문제 14번
int get_sum(TreeNode* root) {

    int sum = 0;
    if(root != NULL) 
        sum += root->data + get_sum(root->left) + get_sum(root->right);
    
    return sum;
}

int main() {
    printf("트리의 합: %d\n", get_sum(root));
    return 0;
} */

/* 연습문제 15번
void compare(TreeNode* root, int value) {

    if(root != NULL) {
        if(root->data < value)
            printf("%d ", root->data);
        compare(root->left, value);
        compare(root->right, value);
    }
}

int main() {

    compare(root, 30);
    return 0;
} */

/* 연습문제 16번
int get_one_node(TreeNode* root) {
    int count = 0;

    if(root != NULL) {
        if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) 
            count++;
         count += get_one_node(root->left) + get_one_node(root->right);
    }
    return count;
}

int main() {

    printf("자식이 하나만 있는 노드의 개수: %d\n", get_one_node(root));
    return 0;
} */

/* 연습문제 17번
int Max;

int search_max(TreeNode* root) {

    if(root != NULL) {
        int max;
        if(root->data < (max = search_max(root->left))) 
            Max = max;
        else
            Max = root->data;
        if(root->data < (max = search_max(root->right)))
            Max = max;
        else
            Max = root->data;
    }
    return Max;
}

int Min = INT_MAX;

int search_min(TreeNode* root) {

    if(root != NULL) {
        int min;
        if(root->data > (min = search_min(root->left))) 
            Min = min;
        else
            Min = root->data;
        if(root->data > (min = search_min(root->right)))
            Min = min;
        else
            Min = root->data;
    }
    return Min;
}

#define MAX(a, b) ((a > b) ? a : b)

int search_max2(TreeNode* root) {

    if(root != NULL) {
        int max = root->data;
        max = MAX(max, search_max2(root->left));
        max = MAX(max, search_max2(root->right));
        return max;
    }

}

#define MIN(a, b) ((a < b) ? a : b)

int search_min2(TreeNode* root) {

    if(root != NULL) {
        int min = INT_MAX;
        min = MIN(min, search_min(root->left));
        min = MIN(min, search_min(root->right));
        return min;
    }
}

int main() {
    printf("%d %d\n", search_max2(root), search_min2(root));
    return 0;
} */

/* 연습문제 18번~20번 
TreeNode* new_node(int data) {
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

TreeNode* insert_node(TreeNode* root, int data) {

    if(root == NULL) return new_node(data);
    if(data < root->data) 
        root->left = insert_node(root->left, data);
    else if(data > root->data)
        root->right = insert_node(root->right, data);
    
    return root;
}

void inorder(TreeNode* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
} */

/*
// 문제 18번 오름차순 (중위순회)
// 문제 19번 내림차순 (역중위순회)

void reverse_inorder(TreeNode* root) {
    if(root != NULL){
        inorder(root->right);
        printf("%d->", root->data);
        inorder(root->left);
    }
}

int main() {

    TreeNode* root = NULL;

    int data;
    for(int i=0; i<11; i++) {
        scanf("%d", &data);
        root = insert_node(root, data);        
    }

    inorder(root);
    reverse_inorder(root);
    return 0;
} */

/* 연습문제 20번
void increase_value(TreeNode* root) {
    if(root != NULL) {
        increase_value(root->left);
        root->data += 1;
        increase_value(root->right);
    }
}

int main() {
    TreeNode* root = NULL;

    int data;
    for(int i=0; i<11; i++) {
        scanf("%d", &data);
        root = insert_node(root, data);        
    }

    inorder(root);
    puts("");
    increase_value(root);
    puts("");
    inorder(root);
    
    return 0;
} */

/* 연습문제 21번 
이진 탐색 트리에서 가장 큰 수는 가장 오른쪽에 위치한 노드이다.
*/

/* 연습문제 22번
typedef struct {
    char name[20];
    char phone[20];
} People;

typedef struct TreeNode {
    People data;
    struct TreeNode *left, *right;
} TreeNode;

int compare(People p1, People p2) {
    return strcmp(p1.name, p2.name);
}

TreeNode* new_node(People data) {

    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

TreeNode* insert_node(TreeNode* root, People data) {

    if(root == NULL) return new_node(data);
    if(compare(data, root->data) < 0)
        root->left = insert_node(root->left, data);
    else if(compare(data, root->data) > 0)
        root->right = insert_node(root->right, data);
    
    return root;
}

TreeNode* search(TreeNode* root, People data) {
    
    if(root == NULL) 
        return NULL;
    if(compare(data, root->data) == 0) 
        return root;
    if(compare(data, root->data) < 0) 
        return search(root->left, data);
    else if(compare(data, root->data) > 0)
        return search(root->right, data);
}

TreeNode* search_min_value(TreeNode* root) {
    
    TreeNode* current = root;

    while(current != NULL)
        current = current->left;
    
    return current;
}

TreeNode* delete_node(TreeNode* root, People data) {

    if(root == NULL) return NULL;
    if(compare(data, root->data) < 0) 
        root->left = delete_node(root->left, data);
    else if(compare(data, root->data) > 0)
        root->right = delete_node(root->right, data);
    else {
        if(root->left == NULL) {
            TreeNode* tmp = root->right;
            free(root);
            return tmp;
        }
        else if(root->right == NULL) {
            TreeNode* tmp = root->left;
            free(root);
            return tmp;
        }
        else {
            TreeNode* tmp = search_min_value(root->right);
            root->data = tmp->data;
            root->right = delete_node(root->right, tmp->data);
        }
    }
    return root;
}

void help() {
    printf("insert(i), search(s), delete(d), print(p), quit(q): ");
}

void display(TreeNode* root) {

    if(root != NULL) {
        printf("%s %s", root->data.name, root->data.phone);
        display(root->left);
        display(root->right);
    }
}

int main() {
    char option;
    People p;
    TreeNode* root = NULL, *tmp;

    do {
        help();
        option = _getch();
        switch (option) {
            case 'i':
                printf("name: ");
                fgets(p.name, sizeof(p.name), stdin);
                printf("phone: ");
                fgets(p.phone, sizeof(p.phone), stdin);
                root = insert_node(root, p);
                break;
            case 's':
                printf("name: ");
                fgets(p.name, sizeof(p.name), stdin);
                tmp = search(root, p);
                if(tmp != NULL)
                    printf("phone: %s", tmp->data.phone);
                break;
            case 'd':
                printf("name: ");
                fgets(p.name, sizeof(p.name), stdin);
                root = delete_node(root, p);
                break;
            case 'p':
                display(root);
                break;
            }
    } while(option != 'q');   

    return 0;
} */