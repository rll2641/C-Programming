#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} stacktype;

void init_stack(stacktype* s) {
    s->top = -1;
}

int is_empty(stacktype* s) {
    return (s->top == -1);
}

int is_full(stacktype* s) {
    return (s->top >= MAX_STACK_SIZE - 1);
}

void push(stacktype *s, int item) {
    if(is_full(s)) {
        fprintf(stderr, "스택이 포화 상태입니다.\n");
        return ;
    }
    else s->data[++(s->top)] = item;
}

char pop(stacktype* s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택이 공백상태입니다.\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

int peek(stacktype *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택이 공백 상태입니다.\n");
        exit(1);
    }
    else return s->data[s->top];
}

/* 연습문제 11번용 pop함수
int pop(stacktype* s) {
    int count = s->data[s->top--];
    return count;
}*/

/* 연습문제 10번
void reverse(int list[]) {

    int print[6];
    stacktype s;

    init_stack(&s);

    for(int i=0; i<6; i++)
        push(&s, list[i]);
    for(int i=0; i<6; i++) {
        print[i] = pop(&s);
        printf("%d ", print[i]);
    }
    puts("");
}

int main() {

    int list[6];

    printf("정수를 입력하시오: ");
    for(int i=0; i<6; i++) {
        scanf("%d", &list[i]);
    }
    printf("반전된 정수 배열: ");
    reverse(list);
    return 0;    
} */

/* 연습문제 11번
짝 시스템과 스택구조를 알면 쉽다.
void brackets(char list[]) {

    stacktype s;
    int pu_count = 1, po_count = 0, len = strlen(list);
    char ch;

    init_stack(&s);

    for(int i=0; i<len; i++) {
        ch = list[i];
        switch (ch) {
        case '(':
            push(&s, pu_count);
            printf("%d ", pu_count);
            pu_count++;
            break;
        case ')':
            po_count = pop(&s);
            printf("%d ", po_count);
            break;
        }
    }
}

int main() {

    char list[] = "((())(()))";

    printf("수식: %s\n", list);
    brackets(list);
    return 0;
} */

/* 연습문제 12번
문자열 중 첫번째 문자를 push한 뒤, 2번째 문자부터 스택에 있는 알파벳과 동일할 시 값+1, 다른 알파벳일 경우 push
void number(char list[]) {

    stacktype s;
    int slist[MAX_STACK_SIZE] = {0}, count = 0, length = strlen(list);
    char ch, alpha[MAX_STACK_SIZE];

    init_stack(&s);

    for(int i=0; i<length; i++) {
        ch = list[i];
        if(i == 0){ 
            push(&s, ch);
            alpha[count] = peek(&s);
            slist[count] += 1;
        }
        else {
            if(ch == peek(&s) || (ch+32) == peek(&s) || (ch-32) == peek(&s)) {
                slist[count] += 1;
            }
            else {
                push(&s, ch);
                count++;
                slist[count] += 1;
                alpha[count] = peek(&s);
            }
        }
    }
    for(int i=0; i<=count; i++) {
        printf("%c%d", alpha[i], slist[i]);
    }

}

int main() {

    char list[] = "aaaAbBb";

    number(list);

    return 0;
} */

/* 연습문제 13번
void compare(int list[],int length) {

    stacktype s;
    int slist[MAX_STACK_SIZE], count = 0;

    init_stack(&s);

    for(int i=0; i<length; i++) {
        if(i == 0){
            push(&s, list[i]);
            slist[count] = list[i];
            printf("%d ", pop(&s));
        }
        else {
            if(slist[count] == list[i]) 
                continue;
            else {
                push(&s, list[i]);
                printf("%d ", pop(&s));
                count++;
                slist[count] = list[i];
            }
        }
    }
}

int main() {

    int ilist[] = {1,2,2,2,3,3,4};
    int length = sizeof(ilist) / sizeof(int);
    compare(ilist, length);

    return 0;
 }  */

/* 연습문제 14번
int stack_number(stacktype* s){
    return (s->top+1);
} */

/* 연습문제 15번은 책 예제 프로그램 4.9와 동일 */

/* 연습문제 16번
void change_string(char list[], int length) {

    for(int i=0; i<length; i++) 
        if('A' <= list[i] && 'Z' >= list[i]) 
            list[i] += 32;
    
    printf("문자열 : %s\n", list);
        
}


void examine_string(char list[], int length) {

    stacktype s;
    int count = 0;

    init_stack(&s);
    
    for(int i=0; i<length; i++) {

        // 문자열의 절반 push를 하고 절반은 pop의 반환값과 비교
        if(i < length / 2) {
            push(&s, list[i]);
        }
        // 아래는 문자열이 홀수일 때 중간값을 건너뛴다. ex madam일 경우 d무시하고 비교
        else if((length%2==1) && i == length/2) {
            continue;
        }
        else {
            if(pop(&s) == list[i]){
                count++;
                if(count == length/2)
                    printf("회문입니다.\n");
                else if(i+1 == length)
                    printf("회문이아닙니다.\n");
            }
        }
    }
}

int main() {
    
    char list[] = "Mabbm";
    int len = strlen(list);

    change_string(list, len);
    examine_string(list, len);
    return 0;
} */