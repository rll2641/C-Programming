#include <stdio.h>
#include <string.h>

#define MAX_SIZE_STACK 10001

typedef struct {
    int data[MAX_SIZE_STACK];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int empty(Stack* s) {
    return (s->top == -1);
}

int full(Stack* s) {
    return (s->top + 1 >= MAX_SIZE_STACK);
}

void push(Stack* s, int x) {
    if(full(s)) return;
    s->data[++(s->top)] = x;
}

int size(Stack* s){
    return (s->top + 1); 
}

int pop(Stack *s) {
    if(empty(s)) return -1;
    return s->data[(s->top)--]; 
}

int top(Stack* s) {
    if(empty(s))
        return -1;
    return (s->data[s->top]);
}

int main() {
    Stack s;
    int num, n;
    char option[MAX_SIZE_STACK];

    scanf("%d", &num);
    init(&s);
    
    for(int i=0; i<num; i++) {
        scanf("%s", option);
        if(!strcmp(option, "push")) {
            scanf("%d", &n);
            push(&s, n);
        }
        else if(!strcmp(option, "top")) {
            printf("%d\n", top(&s));
        }
        else if(!strcmp(option, "pop")) {
            printf("%d\n", pop(&s));
        }
        else if(!strcmp(option, "empty")) {
            printf("%d\n", empty(&s));
        }
        else if(!strcmp(option, "size")) {
            printf("%d\n", size(&s));
        }
    }
    return 0;
}