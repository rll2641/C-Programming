#include <stdio.h>
#include <stdlib.h>

/* 연습문제 3,4번
typedef struct CircleNode{
    int data;
    struct CircleNode* link;
} CircleNode;

CircleNode* insert_first(CircleNode* head, int data) {

    CircleNode* p = (CircleNode*)malloc(sizeof(CircleNode));
    p->data = data;
    if (head == NULL){
        head = p;
        p->link = head;
    }
    else {
        // head->link는 선행노드의 주소를 가지고 있음
        p->link = head->link;
        head->link = p;
    }
    return head;
}

CircleNode* insert_last(CircleNode* head, int data) {

    CircleNode* p = (CircleNode*)malloc(sizeof(CircleNode));
    p->data = data;
    if(head == NULL) {
        head = p;
        p->link = head;
    }
    else {
        // head->link는 항상 첫번째 노드의 주소를 가지고 있음
        p->link = head->link;
        // 선행노드가 새로운 노드의 주소를 저장하게 만듬
        head->link = p;
        head = p;
    }
    return head;
}

CircleNode* search(CircleNode* head, int data) {

    CircleNode* s = head->link;

    for(; s != head; s = s->link) {
        if(s->data == data)
        return s;
    }
    return NULL;
}

void print_list(CircleNode* head) {

    CircleNode* p = head->link;

    for(; p != head; p = p->link)
        printf("%d->", p->data);
    printf("%d->", p->data);

}

int get_size(CircleNode* head) {

    CircleNode* s = head->link;
    int count = 0;

    for(; s != head; s = s->link) {
        count++;
    }
    return count+1;
}

CircleNode* delete(CircleNode* head, CircleNode* pre) {

    CircleNode* removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

int main() {

    CircleNode* head = NULL;
    CircleNode* s = NULL;
    int data;

    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    head = insert_first(head, 5);
    print_list(head);
    puts("");

    s = search(head, 10);
    head = delete(head, s);

    print_list(head);

    return 0;
} */

/* 연습문제 6,7번
typedef struct ListNode{
    int data;
    struct ListNode* llink;
    struct ListNode* rlink;
} ListNode;

ListNode* init() {
    ListNode* headnode = (ListNode*)malloc(sizeof(ListNode));
    headnode->llink = headnode;
    headnode->rlink = headnode;
    return headnode;
}

void print_list(ListNode* head) {
   ListNode* p = head->rlink;

   for(; p != head; p = p->rlink) {
       printf("<-%d->", p->data);
   }  
   puts("");
}

void insert(ListNode* pre, int data) {
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->data = data;

    newnode->llink = pre;
    newnode->rlink = pre->rlink;
    pre->rlink->llink = newnode;
    pre->rlink = newnode;
}

void delete(ListNode* head, ListNode* removed) {
    if(removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

ListNode* search(ListNode* head, int data) {

    ListNode* s = head->rlink;
    for(; s != head; s = s->llink) {
        if(s->data == data)
        return s;
    }
    return NULL;
}

void reverse(ListNode* head) {

    ListNode* s = head->llink;
    for(; s != head; s = s->llink) {
        printf("<-%d->", s->data);
    }
    puts("");
}

int main() {

    ListNode* head = init();
    insert(head, 2);
    insert(head, 6);
    insert(head, 9);

    print_list(head);
    reverse(head);

    return 0;    
} */
