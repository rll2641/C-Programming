#include <stdio.h>

#define MAX_STACK_SIZE 100000

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
} Stack;

char save[MAX_STACK_SIZE*2];
int idx;

void init(Stack* s) {
    s->top = -1;
}

int pop(Stack* s, int data) {

    if(data == s->stack[s->top]) {
        s->stack[s->top--] = 0;
        save[idx++] = '-';
        return 1;
    }
    else
        return 0;
}

void push(Stack* s, int max, int data) {

    for(int i=max+1; i<=data; i++) {
        s->stack[++s->top] = i;
        save[idx++] = '+'; 
    }
    pop(s, data);
}

int main() {
    Stack s;
    int result = 1, num, n, max = 0;
    init(&s);
    scanf("%d", &num);
    
    while(num--) {
        scanf("%d", &n);
        if(result == 0) break;
        if(max <= n) {
            push(&s, max, n);
            max = n;
        }
        else {
            result = pop(&s, n);
        }
    }
    
    if(result == 0)
        printf("NO\n");
    else {
        for(int i=0; i<idx; i++) 
            printf("%c\n", save[i]);
    }

    return 0;
}