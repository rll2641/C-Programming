#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct Nodelink {
    int data, size;
    struct Nodelink *left, *right;
} Nodelink;

Nodelink* init() {
    Nodelink* head_node = (Nodelink*)malloc(sizeof(Nodelink));
    head_node->size = 0;
    head_node->left = head_node->right = head_node;
    return head_node;
}

void insert_right(Nodelink* node, int data) {
    Nodelink* new_node = (Nodelink*)malloc(sizeof(Nodelink));
    node->size++;
    new_node->data = data;
    new_node->left = node;
    new_node->right = node->right;
    node->right->left = new_node;
    node->right = new_node;
}

void delete_first(Nodelink* head) {
    Nodelink* removed = head->right;
    head->size--;
    removed->left->right = removed->right;
    removed->right->left = removed->left;
    free(removed);
}

int main() {
    int test, c, n;

    scanf("%d", &test);
    while(test--) {
        int r_count = 0, d_count = 0, array[MAX_SIZE];
        char p[MAX_SIZE], ch;
        Nodelink *d, *node = init();

        scanf("%s", p);
        scanf("%d", &n);
        getchar();

        if(n != 0) {
            scanf("%c", &ch);
            for(int i=0; i<n; i++) {
                scanf("%d", &array[i]);
                getchar();
            }
        }
        else {
            scanf("%c %c", &ch, &ch);
        }

        for(int i=0; i<strlen(p); i++) {
            if(p[i] == 'R') {
                r_count++;
            }
            else if(p[i] == 'D') {
                d_count++;
            }
        }
        
        if(r_count%2 == 1) {
            for(int i=0; i<n; i++) {
                insert_right(node, array[i]);
            }
        }
        else if(r_count%2 == 0) {
            for(int i=n-1; i>=0; i--) {
                insert_right(node, array[i]);
            }
        }

        if(d_count == node->size) {
            printf("[]\n");
            continue;
        }
        else if(d_count > node->size) {
            printf("error\n");
            continue;
        }

        while(d_count--) {
            delete_first(node);
        }

        printf("[");
        for(d = node->right; d != node->left; d = d->right) {
            printf("%d,", d->data);
        }
        printf("%d]\n", d->data);
        free(node);
    }
    return 0;
}