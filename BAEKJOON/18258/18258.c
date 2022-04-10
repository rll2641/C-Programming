#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUE_SIZE 2000001

typedef struct {
   int que[MAX_QUE_SIZE];
   int front, rear;
} Queue;

int is_empty(Queue* q) {
   if(q->front == q->rear)
      return 1;
   else
      return 0;
}

void push(Queue* q, int data) {
   if(q->front == (q->rear +1) % MAX_QUE_SIZE)
      return;
   q->rear = (q->rear + 1) % MAX_QUE_SIZE;
   q->que[q->rear] = data;
}

int pop(Queue* q) {
   if(is_empty(q))
      return -1;
   q->front = (q->front + 1) % MAX_QUE_SIZE;
   return q->que[q->front];
}

int size(Queue* q) {
   return (q->rear - q->front);
}

int front(Queue* q) {
   if(is_empty(q))
      return -1;
   return (q->que[(q->front+1) % MAX_QUE_SIZE]);
}

int back(Queue* q) {
   if(is_empty(q))
      return -1;
   return q->que[q->rear];
}

int main() {
   Queue q;
   int num, n;
   char option[20];

   scanf("%d", &num);

   q.front = q.rear = 0;
   while(num--) {
      scanf("%s", option);
      if(strcmp(option, "push") == 0) {
         scanf("%d", &n);
         push(&q, n);
      }
      else if(strcmp(option, "pop") == 0) {
         printf("%d\n", pop(&q));
      }
      else if(strcmp(option, "size") == 0) {
         printf("%d\n", size(&q));
      }
      else if(strcmp(option, "empty") == 0) {
         printf("%d\n", is_empty(&q));
      }
      else if(strcmp(option, "front") == 0) {
         printf("%d\n", front(&q));
      }
      else if(strcmp(option, "back") == 0) {
         printf("%d\n", back(&q));
      }
   }
   return 0;
}