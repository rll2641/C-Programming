#include <stdio.h>

int power(int x, int n, int c) {
    if(n == 0) return 1;
    else if(n == 1) return x;

    long long result = power(x, n/2, c);

    if(n%2==0) return (result * result) % c;
    else return (x * ((result*result)%c)) % c;   
}
int main() {
    int a, b, c;
    int result;
    scanf("%d %d %d", &a, &b, &c);

    result = power(a%c, b, c);
    printf("%d\n", result);
    return 0;
}