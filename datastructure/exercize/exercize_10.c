#include <stdio.h>
#include <stdlib.h>

/* 문제 9, 10번
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX 50

typedef struct {
    int n;
    int adj_mat[MAX_VERTEX][MAX_VERTEX];
} GraphType;

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct {
    int n;
    GraphNode* adj_list[MAX_VERTEX];
} GraphType_list;
*/

/* 9번
int out_degree(GraphType* g, int v) {
    int sum = 0;

    for(int i=0; i<g->n; i++) {
        if(g->adj_mat[v][i] == 1) {
            sum++;
        }
    }
    return sum;
}

int in_degree(GraphType* g, int v) {
    int sum = 0;

    for(int i=0; i<g->n; i++) {
        if(g->adj_mat[i][v] == 1) {
            sum++;
        }
    }
    return sum;
}

int sum_edge(GraphType* g) {
    int sum = 0;
    for(int i=0; i<g->n; i++) {
        for(int j=0; j<g->n; j++) {
            if(g->adj_mat[i][j] == 1) {
                sum++;
            }
        }
    }
    return sum;
} */

/* 10번
int out_degree(GraphType_list* g, int v) {
    int sum = 0;

    for(GraphNode* p = g->adj_list[v]; p != NULL; p = p->link) {
        sum++;
    }
    return sum;
}

int in_degree(GraphType_list* g, int v) {
    int sum = 0;

    for(int i=0; i<g->n; i++) {
        if(i == v) {
            continue;
        }
        for(GraphNode* p = g->adj_list[i]; p != NULL; p = p->link) {
            sum++;
        }
    }
    return 0;
}

int sum_edge(GraphType_list* g) {
    int sum = 0;
    for(int i=0; i<g->n; i++) {
        for(GraphNode* p = g->adj_list[i]; p != NULL; p = p->link) {
            sum++;
        }
    }
    return 0;
} */

