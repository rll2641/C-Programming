#include <stdio.h>
#include <stdlib.h>

typedef struct NodeList{
    int value;
    struct NodeList* link;
} NodeList;

typedef struct ListType {
    int size;
    NodeList* head;
    NodeList* tail;
    NodeList* save;
} ListType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListType* create() {
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

// 첫번째 삽입
void insert_first(ListType* plist, int value) {

    NodeList* p = (NodeList*)malloc(sizeof(NodeList));
    
    p->value = value;
    p->link = NULL;

    if(plist->tail == NULL){
        plist->head = plist->tail = plist->save = p;
    }
    else {
        plist->head = p;
        plist->head->link = plist->save;
        plist->save = p;
    }
    plist->size++;
}

// 마지막 삽입 
void insert_last(ListType* plist, int value) {

    NodeList* p =(NodeList*)malloc(sizeof(NodeList));

    p->value = value;
    p->link = NULL;

    if(plist->tail == NULL)
        error("노드 없음");
    else {
        plist->tail->link = p;
        plist->tail = p;
    }
    plist->size++;
}

void print_list(ListType* plist) {

    NodeList* p = plist->head;

    for(; p; p = p->link) {
        printf("%d->", p->value);
    }
    puts("");
}

/* 연습문제 9번
int main() {

    int size, value;
    ListType* list1 = NULL;
    
    printf("노드의 개수: ");
    scanf("%d", &size);
    list1 = create();

    for(int i=1; i<size+1; i++) {
        printf("노드 #%d 데이터 : ");
        scanf("%d", &value);
        if( i == 1){
            insert_first(list1, value);
        }
        else
            insert_last(list1, value);
    } 

    print_list(list1);

    return 0;
} */

/* 연습문제 10번
int main() {

    int size, value;
    ListType* list1 = NULL;
    
    printf("노드의 개수: ");
    scanf("%d", &size);
    list1 = create();

    for(int i=1; i<size+1; i++) {
        printf("노드 #%d 데이터 : ");
        scanf("%d", &value);
        if( i == 1){
            insert_first(list1, value);
        }
        else
            insert_last(list1, value);
    } 

    printf("연결 리스트 노드의 개수: %d \n", list1->size);

    return 0;
} */

/* 연습문제 11번
int add(ListType* plist) {

    int result = 0;

    for(NodeList* p = plist->head; p != NULL; p = p->link) {
        result += p->value;
    }
    return result;
}

int main() {

    int size, value, result;
    ListType* list1 = NULL;
    
    printf("노드의 개수: ");
    scanf("%d", &size);
    list1 = create();

    for(int i=1; i<size+1; i++) {
        printf("노드 #%d 데이터 : ");
        scanf("%d", &value);
        if( i == 1){
            insert_first(list1, value);
        }
        else
            insert_last(list1, value);
    } 

    result = add(list1);

    printf("리스트 데이더 합 : %d \n", result);

    return 0;
} */

/* 연습문제 12번
void search_num(ListType* plist, int value) {

    int count = 0;

    for(NodeList* p = plist->head; p != NULL; p = p->link) 
        if(p->value == value)
            count++;

    printf("%d는 연결리스트에서 %d번 나타납니다.\n", value, count);

}

int main() {

    int size, value, result;
    ListType* list1 = NULL;
    
    printf("노드의 개수: ");
    scanf("%d", &size);
    list1 = create();

    for(int i=1; i<size+1; i++) {
        printf("노드 #%d 데이터 : ", i);
        scanf("%d", &value);
        if( i == 1){
            insert_first(list1, value);
        }
        else
            insert_last(list1, value);
    } 

    search_num(list1, 5);
    
    return 0;
} */

/* 연습문제 13번
NodeList* search_value(ListType* plist, int value) {

    for(NodeList* p = plist->head; p != NULL; p = p->link) {
        if(p->value == value)
            return p;
    }
    return NULL;
}

ListType* delete(ListType* plist, NodeList* pre) {

    NodeList* removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return plist;
}

int main() {

    int size, value, result;
    ListType* list1 = NULL;
    NodeList* pre = NULL;

    printf("노드의 개수: ");
    scanf("%d", &size);
    list1 = create();

    for(int i=1; i<size+1; i++) {
        printf("노드 #%d 데이터 : ", i);
        scanf("%d", &value);
        if( i == 1){
            insert_first(list1, value);
        }
        else
            insert_last(list1, value);
    } 

    pre = search_value(list1, 1);
    list1 = delete(list1, pre);
    print_list(list1);
    
    return 0;
} */

/* 연습문제 14번
구조체 재선언과 tail을 쓰지 않은 단순 연결 리스트
#define MAX_STRING_SIZE 10

typedef struct {
    char name[MAX_STRING_SIZE];
    int age;
    float heigh;
} Human;

typedef struct NodeList{
    Human human;
    struct NodeList* link;
} NodeList;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
}

NodeList* insert_first(NodeList* head, Human infor ) {

    NodeList* p = (NodeList*)malloc(sizeof(NodeList));

    strcpy(p->human.name, infor.name);
    p->human.age = infor.age;
    p->human.heigh = infor.heigh;

    p->link = head;
    head = p;

    return head;
}

NodeList* insert(NodeList* head, NodeList* pre, Human infor) {
    
    NodeList *p = (NodeList*)malloc(sizeof(NodeList));

    strcpy(p->human.name, infor.name);
    p->human.age = infor.age;
    p->human.heigh = infor.heigh;

    p->link = pre->link;
    pre->link = p;

    return head;
}

void print_list(NodeList* head) {

    for(NodeList* p = head; p != NULL; p = p->link){
        printf("이름 : %s, 나이: %d, Heigh: %1.1f -> ", p->human.name, p->human.age, p->human.heigh);
    }
    puts("");
}

int main() {

    NodeList* head = NULL;

    Human people1, people2, people3;

    strcpy(people1.name, "KIM");
    strcpy(people2.name, "JANG");
    strcpy(people3.name, "CHO");

    people1.age = 98; people2.age = 97; people3.age = 97;
    people1.heigh = 1.7; people2.heigh = 1.2; people3.heigh = 1.4;

    head = insert_first(head, people1);
    head = insert_first(head, people2);
    head = insert_first(head, people3);

    print_list(head);

    return 0;
} */

/* 연습문제 15번
void compare_num(ListType* plist) {

    NodeList* p = plist->head;

    int min = p->value, max = p->value;

    for(; p; p = p->link) {
        if(p->value > max){
            max = p->value;
        }
        else if(p->value < min) {
            min = p->value;
        }
    }

    printf("최대값 : %d, 최소값: %d\n", max, min);

}

int main() {

        int size, value, result;
    ListType* list1 = NULL;
    NodeList* pre = NULL;

    printf("노드의 개수: ");
    scanf("%d", &size);
    list1 = create();

    for(int i=1; i<size+1; i++) {
        printf("노드 #%d 데이터 : ", i);
        scanf("%d", &value);
        if( i == 1){
            insert_first(list1, value);
        }
        else
            insert_last(list1, value);
    } 
    print_list(list1);
    compare_num(list1);
    
    return 0;

} */

/* 연습문제 16번
void delete_oddNumber(ListType* plist) {

    NodeList* p = plist->head;
    NodeList* removed = NULL;

    //3번째부터 삭제를 위해 
    p = p->link;

    while(p != NULL) {
        removed = p->link;
        p->link = removed->link;
        free(removed);
        p = p->link;
    }
    print_list(plist);
}

int main() {

        int size, value, result;
    ListType* list1 = NULL;
    NodeList* pre = NULL;
    printf("노드의 개수: ");
    scanf("%d", &size);
    list1 = create();

    for(int i=1; i<size+1; i++) {
        printf("노드 #%d 데이터 : ", i);
        scanf("%d", &value);
        if( i == 1){
            insert_first(list1, value);
        }
        else
            insert_last(list1, value);
    } 
    print_list(list1);
    delete_oddNumber(list1);
    return 0;
} */

/* 연습문제 17번
void concat_list(NodeList* head, NodeList* head2) {

    NodeList* a = head;
    NodeList* b = head2;
    NodeList* c = NULL;
    int count = 1;

    while(a && b) {
        if(count % 2 == 1){
            c = insert_first(c, a->data);
            a = a->link;
        }
        else if(count % 2 == 0) {
            c = insert_first(c, b->data);
            b = b->link;
        }
        count++;
    }

    for(; a; a = a->link)
        c = insert_first(c, a->data);
    for(; b; b = b->link)
        c = insert_first(c, b->data);

    print_list(c);
}

int main() {

    NodeList* head = NULL;
    NodeList* head2 = NULL;

    head = insert_first(head, 5);
    head = insert_first(head, 3);
    head = insert_first(head, 1);

    head2 = insert_first(head2, 4);
    head2 = insert_first(head2, 2);

    print_list(head);
    print_list(head2);
    concat_list(head, head2);

    return 0;

} */

/* 연습문제 18번
void concat_list(NodeList* head, NodeList* head2) {

    NodeList* a = head;
    NodeList* b = head2;
    NodeList* c = NULL;

    while(a && b) {
        if(a->data > b->data){
            c = insert_first(c, b->data);
            b = b->link;
        }
        else{
            c = insert_first(c, a->data);
            a = a->link;
        }
    }

    for(; a; a = a->link)
        c = insert_first(c, a->data);
    for(; b; b = b->link)
        c = insert_first(c, b->data);

    print_list(c);
}

int main() {

    NodeList* head = NULL;
    NodeList* head2 = NULL;

    head = insert_first(head, 5);
    head = insert_first(head, 3);
    head = insert_first(head, 1);

    head2 = insert_first(head2, 4);
    head2 = insert_first(head2, 2);

    print_list(head);
    print_list(head2);

    concat_list(head, head2);

    return 0;

} */

/* 연습문제 19번
void split_list(NodeList* list) {

    NodeList* a = NULL;
    NodeList* b = NULL;
    int count = 1;

    for(NodeList* p = list; p != NULL; p = p->link) {
        if(count % 2 == 1) {
            a = insert_first(a, p->data);
        }
        else{
            b = insert_first(b, p->data);
        }
        count++;
    }

    print_list(a);
    print_list(b);
}

int main() {

    NodeList* list = NULL;

    for(int i=0; i<5; i++)
        list = insert_first(list, i);
    
    split_list(list);
    
    return 0;   
} */

/* 연습문제 20번
void compare(ListType* list, ListType* list2) {

    NodeList* plist = list->head;
    NodeList* plist2 = list2->head;
    ListType* list3 = NULL;
    int sum = 0;

    list3 = create();

    while(plist && plist2) {

        if(plist->expon == plist2->expon) {
            sum = plist->coef + plist2->coef;
            if(sum != 0)
                add_last(list3, sum, plist->expon);
            plist = plist->link; plist2 = plist2->link;
        }
        else if(plist->expon > plist2->expon){
            add_last(list3, plist->coef, plist->expon);
            plist = plist->link;
        }
        else{
            add_last(list3, plist2->coef, plist2->expon);
            plist2 = plist2->link;
        }

    }

    for(; plist; plist = plist->link) {
        add_last(list3, plist->coef, plist->expon);
    }
    for(; plist2; plist2 = plist2->link) {
        add_last(list3, plist2->coef, plist2->expon);
    }

    print_list(list3);
}

int main() {

    ListType* list = NULL;
    ListType* list2 = NULL;

    list = create();
    list2 = create();

    add_last(list, 3, 6);
    add_last(list, 7, 3);
    add_last(list, -2, 2);
    add_last(list, -9, 0);

    add_last(list2, -2, 6);
    add_last(list2, -4, 4);
    add_last(list2, 6, 2);
    add_last(list2, 6, 1);
    add_last(list2, 1, 0);

    print_list(list);
    print_list(list2);

    compare(list, list2);
    
    return 0;
} */

/* 연습문제 21번
void poly_eval(ListType* list, int x) {

    NodeList* p = list->head;
    int sum = 0, total = 0;
    for(; p; p = p->link){
        total = polynomail(x, p->expon);
        sum += p->coef*total;
    }

    printf("다항식의 값: %d\n", sum);
}

int polynomail(int x, int n) {
    
    if(n == 0) return 1;
    else if(n%2 == 0)
        return polynomail(x*x, n/2);
    else 
        return x*polynomail(x*x, n/2);
}

int main() {

    ListType* list = NULL;
    int n = 0;
    list = create();

    add_last(list, 3, 6);
    add_last(list, 7, 3);
    add_last(list, -2, 2);
    add_last(list, -9, 0);

    print_list(list);
    poly_eval(list, 2);

    return 0;
} */

/* 연습문제22번
선택정렬 활용
#define MAX_ARRAY_SIZE 10

typedef struct {
    int len;
    int list[MAX_ARRAY_SIZE];
} Array;

Array* init_Array() {
    Array* p = (Array*)malloc(sizeof(Array));
    p->len = 0;
    
    return p;
}

int is_empty(Array* ar) {
    return (ar->len == 0);
}

int is_full(Array* ar) {
    return (ar->len >= MAX_ARRAY_SIZE - 1);
}

int get_length(Array* ar) {
    return ar->len;
}

void display(Array* ar) {
    
    for(int i=0; i<ar->len; i++) 
        printf("%d, ", ar->list[i]);
    
    puts("");
}

void add(Array* ar, int item) {
    
    ar->list[ar->len] = item;
    ar->len++;
}

void delete(Array* ar, int item) {

    for(int i=0; i<ar->len; i++) 
        if(ar->list[i] == item) 
            for(int j=i; j<ar->len; j++) 
                ar->list[j] = ar->list[j+1];
    
}

void is_in_list(Array* ar, int value) {

    for(int i=0; i<ar->len; i++) 
        if(ar->list[i] == value)
            printf("%d는 %d번째 요소입니다.\n", value, ar->list[i]+1);
    
}

void sorting(Array* ar) {
    
    int temp;

    for(int i=0; i<ar->len-1; i++) {
        for(int j = i+1; j<ar->len; j++)
            if(ar->list[i] > ar->list[j]){
                temp = ar->list[i];
                ar->list[i] = ar->list[j];
                ar->list[j] = temp;
            }            
    }


}

int main() {

    Array* ar = init_Array();

    for(int i=6; i>=1; i--)
        add(ar, i);
    display(ar);
    is_in_list(ar, 3);
    delete(ar, 6);
    sorting(ar);
    display(ar);

    return 0;
} */

/* 연습문제 23번
void insert_sort(ListType* plist, int value) {

    NodeList* p = (NodeList*)malloc(sizeof(NodeList));
    NodeList* s = plist->head, *pre;

    p->value = value;
    p->link = NULL;

    if(plist->head == NULL)
        plist->head = plist->tail = p;
    else {
        if(p->value < plist->head->value) {
            p->link = plist->head;
            plist->head = p;
        }
        else {
            // 쌍방향으로 포인트를 주는게 핵심. 이러면 중간에 넣거나 마지막에 넣는것이 아무문제가 없게됌
            while(s != NULL && p->value > s->value) {
                pre = s;
                s = s->link;
            }
            p->link = pre->link;
            pre->link = p;
        }
    }
    
}

int main() {

    ListType* list = create();

    insert_sort(list, 3);
    insert_sort(list, 1);
    insert_sort(list, 5);
    insert_sort(list, 9);
    insert_sort(list, 7);
    
    print_list(list);

    return 0;
} */