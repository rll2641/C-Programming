#include <stdio.h>

#define MAX_VERTEX 1001

int visited_bfs[MAX_VERTEX];
int visited_dfs[MAX_VERTEX];
int adj_mat[MAX_VERTEX][MAX_VERTEX];
int queue[MAX_VERTEX];

void dfs_mat(int vertex, int size) {
    visited_dfs[vertex] = 1;
    printf("%d ", vertex);

    for(int i=1; i<=size; i++) {
        if(adj_mat[vertex][i] && !visited_dfs[i]) {
            dfs_mat(i, size);
        }
    }
}

void bfs_mat(int vertex, int size) {
    int front = 0, rear = 0, pop;
    queue[rear++] = vertex;

    visited_bfs[vertex] = 1;
    printf("%d ", vertex);
    while(front < rear) {
        pop = queue[front++];
        for(int i=1; i<=size; i++) {
            if(adj_mat[pop][i] && !visited_bfs[i]) {
                queue[rear++] = i;
                visited_bfs[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

int main() {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    while(m--) {
        int e1, e2;
        scanf("%d %d", &e1, &e2);
        adj_mat[e1][e2] = 1;
        adj_mat[e2][e1] = 1;
    }

    dfs_mat(v, n);
    puts("");
    bfs_mat(v, n);
    return 0;
}