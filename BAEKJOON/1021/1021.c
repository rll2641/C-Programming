#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 100

typedef struct {
    int deque[MAX_DEQUE_SIZE];
    int front, rear, len, count;
} Deque;

Deque* init() {
    Deque* d = (Deque*)malloc(sizeof(Deque));
    d->front = d->rear = d->len = d->count = 0;
    return d;
}

void push_rear(Deque* d, int data) {
    d->rear = (d->rear + 1) % MAX_DEQUE_SIZE;
    d->deque[d->rear] = data;
    d->len++;
}

void push_front(Deque* d, int data) {
    d->deque[d->front] = data;
    d->front = (d->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    d->len++;
}

int pop_rear(Deque* d) {
    int data = d->deque[d->rear];
    d->rear = (d->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    d->len--;
    return data;
}

int pop_front(Deque* d) {
    d->front = (d->front + 1) % MAX_DEQUE_SIZE;
    d->len--;
    return d->deque[d->front];
}

int find_idx(Deque* d, int loc) {
    int left=0, right=0, count = 0;
    for(int i=1; i<=d->len; i++) {
        if(loc == d->deque[(d->front + i) % MAX_DEQUE_SIZE]) {
            left = count;
            break;
        }
        count++;
    }
    count = 0;
    for(int i=0; i<d->len; i++) {
        count++;
        if(loc == d->deque[(d->rear - i + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE]) {
            right = count;
            break;
        }
    }
    if(left < right) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    Deque* d = init();
    int n, m, loc, save;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++)  {
        push_rear(d, i);
    }
    
    while(m--) {
        scanf("%d", &loc);
        int idx = find_idx(d, loc);
        int i = (d->front + 1) % MAX_DEQUE_SIZE;
        int j = d->rear;
        if(idx == 1) {
            while(d->deque[i] != loc) {
                save = pop_front(d);
                push_rear(d, save);
                i = (i + 1) % MAX_DEQUE_SIZE;
                d->count++;
            }
        }
        else {
            while(d->deque[j] != loc) {
                save = pop_rear(d);
                push_front(d, save);
                j = (j - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
                d->count++;
            }
            if(d->len > 1) {
                save = pop_rear(d);
                push_front(d, save);
                d->count++;
            }
        }
        pop_front(d);
    }
    printf("%d\n", d->count);
    return 0;
}