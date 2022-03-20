#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 20

/* 연습문제 8번
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} queuetype;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
void init_queue(queuetype* q) {
    q->front = q->rear = 0;
}

int is_empty(queuetype* q) {
    return (q->front == q->rear);
}

int is_full(queuetype* q) {
    return (q->front == (q->rear +1) % MAX_QUEUE_SIZE);
}

void enqueue(queuetype* q, int value) {
    if(is_full(q))
        error("스택이 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
}

int dequeue(queuetype* q) {
    if(is_empty(q))
        error("스택이 공백상태입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
} 
 
int get_count(queuetype* q) {
    if(q->rear > q->front) 
        return (q->rear - q->front);
    else
        return 0;
} */

/* 연습문제 9번

조건0 스택2개
조건1 입력이 들어오면 스택1에 넣는다. 
조건2 출력 요청이 들어오면 스택2에서 요소를 꺼낸다.
조건3 스택2가 비어있을 때는 스택1의 모든 요소를 꺼내 스택2에 넣는다.

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int top;
} stacktype;

typedef struct {
    stacktype s1,s2;
} queuetype;

void init_queue(queuetype* q) {
    q->s1.top = q->s2.top = -1;
}

int is_empty(stacktype* s) {
    return (s->top == - 1);
}

int is_full(stacktype* s) {
    return (s->top >= MAX_QUEUE_SIZE-1);
}

void push(stacktype*s, int value) {
    if(is_full(s)){
        fprintf(stderr, "스택이 포화상태\n");
        return ;
    }
    s->data[++(s->top)] = value;
}

int pop(stacktype* s) {
    if(is_empty(s)){
        fprintf(stderr, "스택이 공백상태\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int main() {

    // 조건0
    queuetype q;
    int num;

    init_queue(&q);

    printf("정수 입력: ");
    for(int i=0; i<3; i++) {
        scanf("%d", &num);
        // 조건1
        push(&q.s1, num);
    }

    if(is_empty(&q.s2)) 
        for(int i=0; i<3; i++) 
            // 조건3
            push(&q.s2, pop(&q.s1));
    
    // 조건2
    for(int i=0; i<3; i++)
        printf("%d ", pop(&q.s2));

    return 0;

} */

/* 연습문제 10번

조건1 큐에 f(0), f(1)이 들어가 있어야 한다.
조건2 f(2)를 계산할 때 f(0)을 큐에서 제거
조건3 계산된 f(2)를 다시 큐에 push

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear, total;
} queuetype;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}
void init_queue(queuetype* q) {
    q->front = q->rear = q->total = 0;
}

int is_empty(queuetype* q) {
    return (q->front == q->rear);
}

int is_full(queuetype* q) {
    return (q->front == (q->rear +1) % MAX_QUEUE_SIZE);
}

void enqueue(queuetype* q, int value) {
    if(is_full(q))
        error("스택이 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
}

int dequeue(queuetype* q) {
    if(is_empty(q))
        error("스택이 공백상태입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
} 

int peek(queuetype* q) {
    if(is_empty(q))
        error("큐가 공백상태입니다.\n");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int fibo(queuetype* q, int num) {

    if(num == 0)
        return 0;
    else if(num == 1)
        return 1;
    
    for(int i=2; i<=num; i++) {
        // 조건2
        int value = dequeue(q);
        int total = peek(q);
        // 조건3
        enqueue(q, value+total);
    }

    printf("피보나치 f(%d)의 값 = %d\n", num, dequeue(q));
    
}

int main() {

    queuetype q;

    init_queue(&q);

    // 조건1
    enqueue(&q, 0);
    enqueue(&q, 1);

    fibo(&q, 6);

    return 0;
} */

/* 연습문제 11번
조건1 구두점,공백,대소문자 무시
조건2 덱을 이용하여 주어진 문자열이 회문인지 아닌지 결정

typedef struct {
    char data[MAX_QUEUE_SIZE];
    int front, rear;
} dequetype;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_deque(dequetype* d) {
    d->front = d->rear = 0;
}

int is_empty(dequetype* d) {
    return (d->front == d->rear);
}

int is_full(dequetype* d) {
    return ((d->rear + 1) % MAX_QUEUE_SIZE == d->front);
}

void add_rear(dequetype* d, char item) {
    if(is_full(d))
        error("큐가 포화상태입니다.");
    d->rear = (d->rear + 1) % MAX_QUEUE_SIZE;
    d->data[d->rear] = item;
}

char delete_front(dequetype* d) {
    if(is_empty(d))
        error("큐가 공백상태입니다.");
    d->front = (d->front + 1) % MAX_QUEUE_SIZE;
    return d->data[d->front];
}

char peek_front(dequetype* d) {
    if(is_empty(d))
        error("큐가 공백상태입니다.");
    return d->data[(d->front+1) % MAX_QUEUE_SIZE];
}

void add_front(dequetype* d, int item) {
    if(is_full(d))
        error("큐가 포화상태입니다.");
    d->data[d->front] = item;
    d->front = (d->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

char delete_rear(dequetype* d) {
    int prev = d->rear;
    if(is_empty(d))
        error("큐가 공백상태입니다.");
    d->rear = (d->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return d->data[prev];
}

int change_string(char list[]) {

    int len = strlen(list);

    for(int i=0; i<len; i++) {
        if('A' <= list[i] && 'Z' >= list[i]) {
            list[i] += 32;
        }
    }

    return len;
}

int dequeue(dequetype* d, char list[], int len) {

    int count = 0, save = 0;

    init_deque(d);

    // 영어만 덱에 저장
    for(int i=0; i<len; i++) 
        if('a' <= list[i] && 'z' >= list[i]) 
            add_rear(d, list[i]);
    
    // 덱에 저장되어있는 길이 반환
    save = d->rear/2;

    for(int i=0; i<save; i++) 
        // 덱에서 2개씩 빼서 검사하기 때문에 반복은 2분의1로 축소
        if(delete_rear(d) == delete_front(d))
            count++;
    
    if(count == save)
        return 1;
    else
        return 0;

}

int main() {

    dequetype d;
    char list[] = "Madam I'm Ada,m";

    printf("문자열 입력: %s\n", list);

    int len = change_string(list);
    int result = dequeue(&d,list,len);

    if(result == 1)
        printf("회문입니다.\n");
    else
        printf("회문이 아닙니다.\n");

    return 0;
} */

/* 연습문제 15번 이해가 안감
n개의 덱 중 1개의 덱이 태스크 종료 시 다른 덱이 
태스크가 끝난 덱의 끝에 있는 요소를 가지고 오는 것?

-> 연습문제 11번의 구조체 중 dequetype을 배열로 선언
난수로 10번이하 push 후 끝나면 그 덱의 마지막 요소를
다음 인덱스가 가져오는 방식으로 진행 */