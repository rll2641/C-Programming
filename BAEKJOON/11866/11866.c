#include <stdio.h>
#include <stdlib.h>

#define MAX_QUE_SIZE 1001

typedef struct {
    int que[MAX_QUE_SIZE];
    int front, rear, count;
} Queue;

Queue* init() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = q->count = 0;
    return q;
}

void push(Queue* q, int data) {
    if(q->front == (q->rear + 1) % MAX_QUE_SIZE)
        return;
    q->rear = (q->rear + 1) % MAX_QUE_SIZE;
    q->que[q->rear] = data;
}

int pop(Queue* q) {
    if(q->front == q->rear)
        exit(1);
    q->front = (q->front + 1) % MAX_QUE_SIZE;
    return q->que[q->front];
}

int main() {
    Queue* q = init();
    int num, n, result;
    scanf("%d %d", &num, &n);

    for(int i=1; i<=num; i++) {
        push(q, i);
        q->count++;
    }

    printf("<");
    while(num--) {

        for(int i=0; i<n-1; i++) {
            result = pop(q);
            push(q, result);
        }
        if(q->count == 1) {
            printf("%d>", result);
            break;
        }
        result = pop(q);
        printf("%d, ", result);
        q->count--;
    }
    puts("");
    return 0;
}