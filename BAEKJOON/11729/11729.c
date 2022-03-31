#include <stdio.h>
#include <math.h>

void hanoi(int n, int a, int b, int c) {
    if(n == 1){
        printf("%d %d\n", a, c);
    }
    else {
        hanoi(n-1, a, c, b);
        hanoi(1, a, b, c);
        hanoi(n-1, b, a, c);
    }
}

int main() {

    int n, k;
    scanf("%d", &n);

    k = pow(2, n) - 1;
    printf("%d\n", k);
    hanoi(n, 1, 2, 3);
    return 0;
}