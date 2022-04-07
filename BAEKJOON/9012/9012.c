#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 50

typedef struct {
    char stack[MAX_STACK_SIZE];
    int top;
} Stack;

char pop(Stack* s) {
    return s->stack[--s->top];
}

int is_vps(Stack* s) {

    int len, count = 0;
    char ch;
    
    len = s->top;
    for(int i=0; i<len; i++) {
        ch = pop(s);
        if(count < 0)
            return 1;
        if(ch == '(')
            count--;
        else if(ch == ')')
            count++;
    }
    return count;
}

int main() {

    Stack s;
    int num;

    scanf("%d", &num);
    while(num--) {
        scanf("%s", s.stack);
        s.top = strlen(s.stack);
        if( is_vps(&s) == 0 )
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}