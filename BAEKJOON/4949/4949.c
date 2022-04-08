#include <stdio.h>
#include <string.h>

#define MAX_SIZE_STACK 101

typedef struct {
    char stack[MAX_SIZE_STACK];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

void push(Stack* s, char ps) {
    s->stack[++s->top] = ps;
}

char pop(Stack* s) {
    return (s->stack[s->top--]);
}

int is_balance(char ch[], int len) {
    Stack s;
    int check;

    init(&s);
    for(int i=0; i<len; i++) {

        if(ch[i] == '(' || ch[i] == '['){ 
            push(&s, ch[i]);
        }
        else if(ch[i] == ')'){ 
            if(pop(&s) != '(') 
                return 1;
        }
        else if(ch[i] == ']'){
            if(pop(&s) != '[')
                return 1;
        }
    }
    if(s.top != -1)
        return 1;
    else
        return 0;
}

int main() {
    char ch[MAX_SIZE_STACK];
    int check;
    while(1){
        fgets(ch, MAX_SIZE_STACK, stdin);
        if(strcmp(ch, ".\n") == 0)
            break;
        if(is_balance(ch, strlen(ch)) == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
    
    return 0;
}