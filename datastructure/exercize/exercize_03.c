#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/* 연습문제 4번
int main() {

    int two[10];

    for(int i=0; i<10; i++) 
        two[i] = pow(2, i);

    for(int i=0; i<10; i++) 
        printf("%d ", two[i]);

    puts("");

    return 0;
} */

/* 연습문제 5번
typedef struct Person {
    char name[10];
    int age;
    float pay;
} Person; */

/* 연습문제 6번
typedef struct Complex {
    float real;
    float imaginary;
} Complex;

int main() {
    Complex c1, c2;
    return 0;
} */

/* 연습문제 7번
typedef struct Complex {
    float real, image;
} Complex;

Complex Complex_Add(Complex a, Complex b) {

    Complex result;
    
    result.real = a.real + b.real;
    result.image = a.image + b.image;

    return result;
} */

/* 연습문제 8번
void insert(int array[], int loc, int value) {
    
    int array2[10];
    memmove(array2, array ,sizeof(int)*10);

    for(int i=loc; i<10; i++) {
        array[i] = array2[i-1];  // 1 = 0,  2 = 1
    } 
    array[loc-1] = value;
}

int main() {

    int list[10] = {1, 2, 3, 4, 5, 6};
    insert(list, 1, 9);
    for(int i=0; i<10; i++) {
        printf("%d ", list[i]);
    }
    puts("");
    return 0;
} */

/* 연습문제10번
void delete(int array[], int loc) {

    int array2[10];

    memcpy(array2, array, sizeof(int)*10);

    for(int i=loc-1; i<10; i++) {
        array[i] = array2[i+1];
    }
}

int main() {

    int array[10] = {1,2,3,4,5,6};
    int loc = 1;

    delete(array, loc);

    for(int i=0; i<10; i++) {
        printf("%d ", array[i]);
    }
    puts("");
    return 0;
} */

/* 연습문제 12번
typedef struct {
    char ch[20];
    int integer;
} just;

int main() {

    just* a = (just*)malloc(sizeof(just));

    a->integer = 100;
    memcpy(a->ch, "just telling", sizeof(char)*20);

    printf("%d, %s\n", a->integer, a->ch);
    return 0;
} */

