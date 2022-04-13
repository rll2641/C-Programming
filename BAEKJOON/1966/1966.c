#include <stdio.h>
#include <stdlib.h>

#define MAX_QUE_STACK 101

typedef struct {
    int point;
    int idx;
} Dict;

typedef struct {
    Dict que[MAX_QUE_STACK];
    int front, rear, len, count;
} Queue;

Queue* init() {
    Queue* q = (Queue*)calloc(MAX_QUE_STACK, sizeof(Queue));
    q->front = q->rear = q->len = q->count = 0;
    return q;
}

void push(Queue* q, Dict data) {
    q->rear = (q->rear + 1) % MAX_QUE_STACK;
    q->que[q->rear] = data;
    q->len++;
}

Dict pop(Queue* q) {
    q->front = (q->front + 1) % MAX_QUE_STACK;
    q->len--;
    return q->que[q->front];
}

int find_max(Queue* q) {
    int idx = (q->front + 1) % MAX_QUE_STACK;
    int max = q->que[idx].point;

    for(int i=0; i<q->len-1; i++) {
        idx = (idx + 1) % MAX_QUE_STACK;
        if(max < q->que[idx].point)
            return 1;
    }
    return 0;
}

int main() {
    int test, n, m;
    Dict data, save;
    scanf("%d", &test);
    while(test--) {
        Queue* q = init();
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) {
            scanf("%d", &data.point);
            data.idx = i;
            push(q, data);
        }
        while(1) {
            while(find_max(q) != 0) {
                save = pop(q);
                push(q, save);
            }
            save = pop(q);
            q->count++;
            if(save.idx == m) {
                printf("%d\n", q->count);
                break;
            }
        }
    }
    return 0;
}