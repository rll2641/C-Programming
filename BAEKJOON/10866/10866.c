#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEQUE_SIZE 10001

typedef struct {
    int deque[MAX_DEQUE_SIZE];
    int front, rear, count;
} Deque;

Deque* init() {
    Deque* d = (Deque*)malloc(sizeof(Deque));
    d->front = d->rear = d->count = 0;
    return d;
}

int empty(Deque *d) {
    return (d->rear == d->front);
}

void push_rear(Deque* d, int data) {
    if(d->front == (d->rear + 1) % MAX_DEQUE_SIZE)
        return ;
    d->rear = (d->rear + 1) % MAX_DEQUE_SIZE;
    d->deque[d->rear] = data;
    d->count++;
}

int pop_rear(Deque* d) {
    if(empty(d))
        return -1;
    d->count--;
    int temp = d->deque[d->rear];
    d->rear = (d->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return temp;
}

void push_front(Deque* d, int data) {
    if(d->rear == (d->rear + 1) % MAX_DEQUE_SIZE)
        return;
    d->count++;
    d->deque[d->front] = data;
    d->front = (d->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

int pop_front(Deque* d) {
    if(d->rear == d->front)
        return -1;
    d->count--;
    d->front = (d->front + 1) % MAX_DEQUE_SIZE;
    return d->deque[d->front];
}

int size(Deque* d) {
    if(d->count < 0)
        return 0;
    else
        return d->count;
}

int get_front(Deque* d) {
    if(size(d) == 0) 
        return -1;
    else 
        return d->deque[(d->front + 1) % MAX_DEQUE_SIZE];
}

int get_rear(Deque* d) {
    if(size(d) == 0)
        return -1;
    else
        return d->deque[(d->rear)];
}

int main() {
    Deque* d = init();
    int test, n;
    char option[20];
    scanf("%d", &test);

    while(test--) {
        scanf("%s", option);
        if(strcmp(option, "push_front") == 0) {
            scanf("%d", &n);
            push_front(d, n);
        }
        else if(strcmp(option, "push_back") == 0) {
            scanf("%d", &n);
            push_rear(d, n);
        }
        else if(strcmp(option, "pop_front") == 0) {
            printf("%d\n", pop_front(d));
        }
        else if(strcmp(option, "pop_back") == 0) {
            printf("%d\n", pop_rear(d));
        }
        else if(strcmp(option, "size") == 0) {
            printf("%d\n", size(d));
        }
        else if(strcmp(option, "empty") == 0) {
            printf("%d\n", empty(d));
        }
        else if(strcmp(option, "front") == 0) {
            printf("%d\n", get_front(d));
        }
        else if(strcmp(option, "back") == 0) {
            printf("%d\n", get_rear(d));
        }
    }

    return 0;
}