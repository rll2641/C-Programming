#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct LinkNode {
    char data;
    struct LinkNode *llink, *rlink;
} LinkNode;

LinkNode* init() {
    LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
    head->llink = head->rlink = head;
    return head;
}

void push(LinkNode* node, LinkNode* top, char data) {
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    new_node->data = data;
    if(top == node->llink) {
        new_node->llink = node->llink;
        new_node->rlink = node;
        new_node->llink->rlink = new_node;
        node->llink = new_node;
    }
    else {
        new_node->llink = top;
        new_node->rlink = top->rlink;
        top->rlink->llink = new_node;
        top->rlink = new_node;
    }
}

void delete_node(LinkNode* top) {
    LinkNode* removed = top;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main() {
    LinkNode* head = init();
    LinkNode* top = head;
    char string[MAX_SIZE], order, ch;
    int m, len;

    scanf("%s", string);
    getchar();
    len = strlen(string);
    for(int i=0; i<len; i++) {
        push(head, top, string[i]);
        top = head->llink;
    }

    scanf("%d", &m);
    getchar();
    while(m--) {
        scanf("%c", &order);
        getchar();
        if(order == 'P') {
            scanf("%c", &ch);
            getchar();
            push(head, top, ch);
            top = top->rlink;
        }
        else if(order == 'L') {
            if(top == head) {
                continue;
            }
            else {
                top = top->llink;
            }
        }
        else if(order == 'D') {
            if(top == head->llink) {
                continue;
            }
            else {
                top = top->rlink;
            }
        }
        else if(order == 'B') {
            if(top == head) {
                continue;
            }
            else {
                top = top->llink;
                delete_node(top->rlink);
            }
        }
    }
    for(LinkNode* p = head->rlink; p != head; p = p->rlink) {
        printf("%c", p->data);
    }
    puts("");
    return 0;
}