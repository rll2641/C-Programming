#include <stdio.h>
#include <stdlib.h>

/* 연습문제 11번
#define MAX_SIZE 200

typedef struct {
    int key;
    char str[MAX_SIZE];
} Element;

typedef struct {
    Element heap[MAX_SIZE];
    int heap_size;
} HeapType;

HeapType* init() {
    HeapType* h = (HeapType*)malloc(sizeof(HeapType));
    h->heap_size = 0;
    return h;
}

void insert_max_heap(HeapType* h, Element item) {
    int i = ++h->heap_size;

    while((i != 1) && (item.key > h->heap[i/2].key)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

Element delete_max_heap(HeapType* h) {
    int p = 1, c = 2;
    Element item, temp;

    item = h->heap[1];
    temp = h->heap[h->heap_size--];

    while(c <= h->heap_size) {
        if(c < h->heap_size && (h->heap[c].key < h->heap[c + 1].key)) {
            c++;
        }
        if(temp.key > h->heap[c].key) {
            break;
        }
        h->heap[p] = h->heap[c];
        p = c;
        c *= 2;
    }
    h->heap[p] = temp;
    return item;
}

int main() {
    HeapType* heap = init();
    char option;

    do {
        printf("insert(i), delete(d), exit(e): ");
        scanf("%c", &option);
        getchar();
        if(option == 'i') {
            Element input;
            printf("Have to do: ");
            fgets(input.str, MAX_SIZE, stdin);
            printf("que: ");
            scanf("%d", &input.key);
            getchar();
            insert_max_heap(heap, input);
        }
        else if(option == 'd') {
            Element save = delete_max_heap(heap);
            printf("most of que: %s", save.str);
        }
    } while(option != 'e');
    return 0;
} */

/* 연습문제 13번
#define MAX_SIZE 200

typedef struct {
    int key;
} Element;

typedef struct {
    Element heap[MAX_SIZE];
    int heap_size;
} HeapType;

HeapType* init() {
    HeapType* h = (HeapType*)malloc(sizeof(HeapType));
    h->heap_size = 0;
    return h;
}

void insert_min_heap(HeapType* h, Element item) {
    int i = ++h->heap_size;

    while((i != 1) && (item.key < h->heap[i/2].key)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

Element delete_min_heap(HeapType* h) {
    int p = 1, c = 2;
    Element item, temp;

    item = h->heap[1];
    temp = h->heap[h->heap_size--];
    while(c <= h->heap_size) {
        if(c < h->heap_size && (h->heap[c].key > h->heap[c + 1].key)) {
            c++;
        }
        if(temp.key < h->heap[c].key) {
            break;
        }
        h->heap[p] = h->heap[c];
        p = c;
        c *= 2;
    }
    h->heap[p] = temp;
    return item;
}

int main() {
    HeapType* heap = init();
    char option;

    do {
        printf("insert(i), delete(d), show(s), exit(e): ");
        scanf("%c", &option);
        getchar();
        if(option == 'i') {
            Element input;
            scanf("%d", &input.key);
            getchar();
            insert_min_heap(heap, input);
        }
        else if(option == 'd') {
            delete_min_heap(heap);
        }
        else if(option == 's') {
            printf("show min_heap: ");
            for(int i=1; i<=heap->heap_size; i++) {
                printf("%d->", heap->heap[i].key);
            }
            puts("");
        }
    } while(option != 'e');
    return 0;
} */

/* 연습문제 15번
typedef struct Linked {
    int key;
    struct Linked *link;
} Linked;

typedef struct {
    Linked* head;
    Linked* tail;
} Top;

Top* insert_max(Top* t, int key) {
    Linked* new_node = (Linked*)malloc(sizeof(Linked));
    new_node->key = key;

    if(t->head == NULL) {
        new_node->link = NULL;
        t->head = t->tail = new_node;
    }
    else {
        if(t->head->key < key) {
            new_node->link = t->head;
            t->head = new_node;
        }
        else {
            Linked* p = t->head;
            while(p != NULL) {
                if(p->link == NULL){
                    new_node->link = NULL;
                    p->link = new_node;
                    return t;
                }
                else if(p->link->key > key) {
                    p = p->link;
                }
                else if(p->link->key < key) {
                    new_node->link = p->link;
                    p->link = new_node;
                    return t;
                }
            }
        }
    }
    return t;
}

Top* delete_max(Top* t) {
    Linked* removed = t->head;
    t->head = removed->link;
    free(removed);
    return t;
}

int main() {
    Top* t;
    t->head = t->tail = NULL;

    t = insert_max(t, 5);
    t = insert_max(t, 10);
    t = insert_max(t, 20);
    t = insert_max(t, 30);
    t = insert_max(t, 3);
    t = delete_max(t);
    for(Linked* p = t->head; p != NULL; p = p->link) {
        printf("%d->", p->key);
    }
    puts("");
    return 0;
} */

/* 연습문제 16번
#define MAX_SIZE 200

typedef struct {
    int key;
} Element;

typedef struct {
    Element heap[MAX_SIZE];
    int heap_size;
} HeapType;

HeapType* init() {
    HeapType* h = (HeapType*)malloc(sizeof(HeapType));
    h->heap_size = 0;
    return h;
}

void insert_min_heap(HeapType* h, Element item) {
    int i = ++h->heap_size;

    while((i != 1) && (item.key < h->heap[i/2].key)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}
// 임의의 요소 삭제
Element delete_element(HeapType* h, Element item) {
    int index;

    for(int i=1; i<=h->heap_size; i++) {
        if(item.key == h->heap[i].key) {
            index = i;
        }
    }

    int p = index, c = index*2;
    Element tem, temp;

    tem = h->heap[index];
    temp = h->heap[h->heap_size--];

    while(c <= h->heap_size) {
        if(c < h->heap_size && (h->heap[c].key > h->heap[c + 1].key)) {
            c++;
        }
        if(temp.key < h->heap[c].key) {
            break;
        }
        h->heap[p] = h->heap[c];
        p = c;
        c *= 2;
    }
    h->heap[p] = temp;
    return tem;
}

int main() {
    HeapType* heap = init();
    Element input;
    char option;

    do {
        printf("insert(i), delete(d), show(s), exit(e): ");
        scanf("%c", &option);
        getchar();
        if(option == 'i') {
            scanf("%d", &input.key);
            getchar();
            insert_min_heap(heap, input);
        }
        else if(option == 'd') {
            scanf("%d", &input.key);
            getchar();
            Element save = delete_element(heap, input);
            printf("delete element: %d\n", save.key);
        }
        else if(option == 's') {
            printf("show min_heap: ");
            for(int i=1; i<=heap->heap_size; i++) {
                printf("%d->", heap->heap[i].key);
            }
            puts("");
        }
    } while(option != 'e');
    return 0;
} */

// 17번은 예제참고