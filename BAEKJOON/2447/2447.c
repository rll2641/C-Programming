#include <stdio.h>

void star(int i, int j, int n){

    if( (i/n)%3==1 && (j/n)%3==1 ) 
        printf(" ");
    else{
        if(n/3 == 0)
            printf("*");
        else
            star(i, j, n/3);
    }

}

int main() {

    int num;
    scanf("%d", &num);

    for(int i=0; i<num; i++) {
        for(int j=0; j<num; j++) {
            star(i, j, num);
        }
        puts("");
    }

    return 0;
}