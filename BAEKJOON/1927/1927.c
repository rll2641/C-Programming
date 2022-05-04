#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001

typedef struct {
    int key;
} Element;

typedef struct {
    Element heap[MAX_SIZE];
    int heap_size;
} HeapType;

HeapType* init() {
    HeapType* new_heap = (HeapType*)malloc(sizeof(HeapType));
    new_heap->heap_size = 0;
    return new_heap;
}

void insert_min_heap(HeapType* h, Element item) {
    int i = ++h->heap_size;

    while((i != 1) && item.key < h->heap[i/2].key) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

Element delete_min_heap(HeapType* h) {
    int p = 1, c = 2;
    Element item, temp;

    item = h->heap[p];
    temp = h->heap[h->heap_size--];

    while(c <= h->heap_size) {
        if(c < h->heap_size && h->heap[c].key > h->heap[c + 1].key) {
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
    int n, num;

    scanf("%d", &n);
    while(n--) {
        scanf("%d", &num);
        if(num == 0) {
            if(heap->heap_size == 0) {
                printf("0\n");
            }
            else {
                Element item = delete_min_heap(heap);
                printf("%d\n", item.key);
            }
        }
        else {
            Element item;
            item.key = num;
            insert_min_heap(heap, item);
        }
    }
    return 0;
}