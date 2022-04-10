#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUE_SIZE 500001

typedef struct {
    int que[MAX_QUE_SIZE];
    int front, rear;
} Queue;

Queue* init() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = 0;
    return  q;
}

void push(Queue* q, int data) {
    if(q->front == (q->rear + 1) % MAX_QUE_SIZE)
        return;
    q->rear = (q->rear + 1) % MAX_QUE_SIZE;
    q->que[q->rear] = data;
}

void pop(Queue* q) {
    if(q->front == q->rear)
        exit(1);
    q->front = (q->front + 1) % MAX_QUE_SIZE;
}

void move(Queue* q) {
    q->rear = (q->rear + 1) % MAX_QUE_SIZE;
    q->front = (q->front + 1) % MAX_QUE_SIZE;
    q->que[q->rear] = q->que[q->front];
    q->que[q->front] = 0;
}

int main() {
    Queue* q;
    q = init();
    int num;
    scanf("%d", &num);

    for(int i=1; i<=num; i++) {
        push(q, i);
    }

    for(int i=0; i<num-1; i++) {
        pop(q);
        if(i + 1 == num)
            break;
        else {
            move(q);
        }
    }

    printf("%d\n", q->que[q->rear]);
    return 0;
}