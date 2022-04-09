#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int data) {
    s->stack[++s->top] = data;
}

int pop(Stack* s) {
    return s->stack[s->top--];
}

int peek(Stack* s) {
    return s->stack[s->top];
}

int is_empty(Stack* s) {
    return (s->top == -1);
}

int main() {
    Stack s;
    int num, k;
    int n[MAX_STACK_SIZE];
    int save_value[MAX_STACK_SIZE];

    scanf("%d", &num);
    
    for(int i=0; i<num; i++) {
        scanf("%d", &n[i]);
        save_value[i] = -1;
    }

    init(&s);
    for(int i=0; i<num; i++) {

        while(!is_empty(&s) && n[peek(&s)] < n[i]) {
            save_value[pop(&s)] = n[i];
        }
        push(&s, i);
    }

    for(int i=0; i<num; i++) {
        printf("%d ", save_value[i]);
    }
    return 0;
}