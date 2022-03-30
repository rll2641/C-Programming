#include <stdio.h>

int fibonacci(int save[], int n) {
    
    if(n == 0){
        save[0] = 0;
        return 0;
    }      
    else if(n == 1){
        save[1] = 1;
        return 1;
    }
    if(save[n] != 0){
        return save[n];
    }
    else{
        return save[n] = fibonacci(save, n-1) + fibonacci(save, n-2);
    }
}

int main() {

    int test, n;
    int save[100] = {0};

    scanf("%d", &test);

    for(; test != 0; test--) {

        scanf("%d", &n);
        if(n == 0) 
            printf("%d %d\n", 1, 0);
        else if(n == 1)
            printf("%d %d\n", 0, 1);
        else
            printf("%d %d\n", fibonacci(save, n-1), fibonacci(save, n));
    }
    return 0;
}