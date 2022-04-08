#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100000

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int data) {
    if(s->top + 1 >= MAX_STACK_SIZE)
        return;
    s->data[++s->top] = data;
}

void pop(Stack* s) {
    s->data[s->top--] = 0;
}

int main() {
    Stack s;
    int num, n, sum = 0;
    init(&s);
    scanf("%d", &num);

    for(int i=0; i<num; i++) {
        scanf("%d", &n);
        if(n != 0) 
            push(&s, n);
        else
            pop(&s);
    }
    
    for(int i=0; i<=s.top; i++) {
        sum += s.data[i];
    }
    printf("%d\n", sum);
    return 0;
}