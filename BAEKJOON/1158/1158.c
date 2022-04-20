#include <stdio.h>
#include <stdlib.h>

int count;

typedef struct LinkNode {
    int data;
    struct LinkNode* link;
} LinkNode;

LinkNode* insert_last(LinkNode* head, int data) {
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    new_node->data = data;
    if(head == NULL) {
        head = new_node;
        new_node->link = head;
    }
    else {
        new_node->link = head->link;
        head->link = new_node;
        head = new_node;
    }
    count++;
    return head;
}

int delete_first(LinkNode* head) {
    LinkNode* removed = head->link;
    int data = removed->data;
    head->link = removed->link;
    free(removed);
    count--;
    return data;
}

int main() {
    int n, k, data;
    scanf("%d %d", &n, &k);

    LinkNode* head = NULL;
    
    for(int i=1; i<=n; i++) {
        head = insert_last(head, i);
    }
    
    printf("<");
    while(count != 1) {
        for(int i=0; i<k-1; i++) {
            data = delete_first(head);
            head = insert_last(head, data);
        }
        data = delete_first(head);
        printf("%d, ", data);
    }
    data = delete_first(head);
    printf("%d>\n", data);
    return 0;
}