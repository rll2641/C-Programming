#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1001

typedef struct LinkNode {
    int data;
    struct LinkNode *llink, *rlink;
} LinkNode;

LinkNode* init() {
    LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
    head->data = 0;
    head->rlink = head->llink = head;
    return head;
}

void insert_last(LinkNode* head, int data) {
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    new_node->data = data;
    new_node->llink = head->llink;
    new_node->rlink = head;
    head->llink = new_node;
    new_node->llink->rlink = new_node;
}

int delete_node(LinkNode* top) {
    LinkNode* removed = top;
    int data = removed->data;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
    return data;
}

int main() {
    LinkNode* head = NULL;
    head = init();

    int n, num[MAX_SIZE];
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        insert_last(head, i);
        scanf("%d", &num[i]);
    }
    
    LinkNode* save = head->rlink;
    for(int i=0; i<n; i++) {
        LinkNode* save_l = save->llink;
        LinkNode* save_r = save->rlink;
        int b_num = num[save->data];
        num[save->data] = 0;
        int data = delete_node(save);
        printf("%d ", data);
        if(i+1 == n) {
            break;
        }
        if(b_num > 0) {
            save = save_l;
            while(b_num--) {
                save = save->rlink;
                while(save == head) {
                    save = save->rlink;
                }
            }    
        }
        else if(b_num < 0) {
            save = save_r;
            b_num = -b_num;
            while(b_num--) {
                save = save->llink;
                if(save == head) {
                    save = save->llink;
                }
            }
        }
    }
    return 0;
}