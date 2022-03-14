#include <stdio.h>

/* 연습문제 7

int sum(int n) {
    printf("%d\n", n);
    if( n<1 ) return 1;
    else return ( n+sum(n-1));
}

void main() {
    int n = 5;
    printf("%d\n",sum(5));
} */

/* 연습문제 8

int recursion(int n) {
    printf("%d\n", n);
    if( n<1 ) return 2;
    else return (2*recursion(n-1)+1);
}

void main() {
    int n = 5;
    printf("%d\n", recursion(n));
} */

/* 연습문제 9번

int recursion(int n) {
    printf("%d\n", n);
    if( n<1 ) return -1;
    else return recursion(n-3)+1;
}

void main() {
    printf("%d\n", recursion(10));
} */

/* 연습문제 10번 

int recursion(int n) {
    if(n != 1) recursion(n-1);
    printf("%d\n", n);
}

void main() {
    printf("%d\n", recursion(5));
} */

/* 연습문제  11번 

void asterisk(int i) {
    if( i>1 ) {
        asterisk(i/2);
        asterisk(i/2);
    }
    printf("*");
}

void main() {
    asterisk(5);
}  *함수가 스택메모리상에 몇번 호출되는지 그 구조를 알고 있어야 풀 수 있다. */

/* 연습문제 12번

void unknown() {
    int ch;
    if( (ch=getchar()) != '\n')
        unknown();
    putchar(ch);
}

void main() {
    unknown();
} 재귀함수와 스택메모리의 구조를 보여주고 있다. */

/* 연습문제 13번

int add(int n) {
    printf("%d\n", n);
    if( n==1 ) return 1;
    else {
        return n + add(n-1);
    }
}

void main() {
    printf("%d", add(5));
} */

/* 연습문제 14번

double mul(double n) {
    if( n==1 ) return 1;
    else return 1/n + mul(n-1);
}

void main() {
    printf("%f", mul(5));
} */

/* 연습문제 15번

int fib(int n) {
    printf("fib(%d) is called\n", n);
    if( n==0 ) return 0;
    else if( n==1 ) return 1;
    else return fib(n-1) + fib(n-2);
}

void main() {
    fib(6);
} 스택에 쌓이는 순서를 이해하면 풀기 쉽다.*/

/* 연습문제 16번 

int sum(int n) {
    int result = 0;
    for(int i=n; i>=1; i--) {
        result += i;
    }
    return result;
}

void main() {
    printf("%d\n", sum(5));
} */

/* 연습문제 17번

순환 함수
int binomial_coefficient(int n, int k) {
    if ( k==0 || k==n ) return 1;
    else return binomial_coefficient(n-1, k-1) + binomial_coefficient(n-1, k); // 전제조건 o<k<n
} 

void main() {
    printf("%d\n", binomial_coefficient(4,3));
} 순환은 명시적으로 적어두기만 하면 컴퓨터가 알아서 계산하니 중요 포인트만 알고있으면 만들 수 있다. 

반복 함수
int binomial_coefficient(int n, int k) {
    if( k==0 || k==n ) return 1;

    int nf = 1, kf = 1, kmnf = 1;
    for(int i=1; i<=n; i++){
        nf *= i;
        if( i<=k ){
            kf *= i;
        }
        if( i<=(n-k) ){
            kmnf *= i;
        }
    }
    return (nf/(kf*kmnf));
}

void main() {
    printf("%d\n", binomial_coefficient(5, 3));
} 여기서 중요 포인트는 n!, k!, (n-k)!의 값을 구하는 것이다. */

/* 연습문제 18번
순환 함수
int ackermamn(int  m, int n) {
    if( m==0 ) return n+1;
    else if( n==0 ) return ackermamn(m-1, 1);
    else return ackermamn(m-1, ackermamn(m, n-1));
}

void main() {
    printf("%d\n", ackermamn(2,1));
} 

반복 함수
int ackermamn(int m, int n) {
	int list[100000];
	int esp = 0;

	list[esp++] = m;
	list[esp] = n;

	while (1) {
		if (esp == 0) {
			return list[esp];
		}
		else if (list[esp - 1] == 0) {
			count++;
			list[esp - 1] = list[esp] + 1;
			esp = esp - 1;
		}
		else if (list[esp] == 0) {
			count++;
			list[esp - 1] = list[esp - 1] - 1;
			list[esp] = 1;
		}
		else {
			count++;
			list[esp + 1] = list[esp] - 1;
			list[esp] = list[esp - 1];
			list[esp - 1] = list[esp - 1] - 1;

			esp = esp + 1;
		}
	}
} */


/* 연습문제 19번 
피보나치 수열의 순환 알고리즘의 경우 2번씩 트리의 높이 k만큼 반복하게 되는데
이 경우 O(2^n)을 띄고 있다. 반복 알고리즘 같은 경우 반복문을 통해 대입연산과
덧셈연산을 했으므로 간략히 O(n)을 띄고 있다. 둘의 시간복잡도를 계산해보면 
n이 커질수록 순환의 효율이 더욱 안좋아지게 된다. */

/* 연습문제 20번 
팩토리얼에서 순환이 한번 일어날 때마다 1씩 작아진다.
일반적인 하노이 타워 문제에서, 한 기둥에 있는 n개의 원판을 다른 기둥으로 완전히 이동시키는 데 필요한 원판 이동 횟수를 F(n) 이라 할 때, F(n)을 n에 대한 식으로 나타내보자.
먼저, F(0) = 0, F(1) = 1 이다.
자연수 n에 대해, F(n) = F(n - 1) + 1(제일큰원판을 목적기둥으로 옮길때) + F(n - 1) = 2F(n - 1) + 1 이다.
n개 원판의 하노이 탑을 해결하는데 필요한 연산 횟수
T(n) = 2T(n-1) + 1
       = 2(2T(n-2) + 1) + 1
       = 2^2 * T(n-2) + 2^1 + 2^0
       = 2^2 * (2T(n-3) + 1) + 2^1 + 2^0
       = 2^3 * T(n-3) + 2^2 + 2^1 + 2^0
       ...
       = 2^(n-1) + 2^(n-2) + ... + 2^1 + 2^0
       = 2^n - 1 따라서 O(2^n)
http://swworld.woobi.co.kr/hanoi_tower.htm 출처참고 */

/* 연습문제 21번

시작좌표 4,5기준으로 인접한 항을 검색 후 조건에 맞으면 색칠하고 아니면 다시 되돌아오는 함수를 생각하면 쉽다.

#define WHITE 0
#define BLACK 1
#define YELLOW 2
#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT];

char read_pixel(int x, int y){
    return screen[x][y];
}

void write_pixel(int x, int y, int color){
    screen[x][y] = color;
}

void flood_fill(int x, int y){
    if( read_pixel(x, y) == WHITE ){
        write_pixel(x, y, BLACK);
        flood_fill(x, y+1);
        flood_fill(x+1, y);
        flood_fill(x, y-1);
        flood_fill(x-1, y);
    }
}

void main() {

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            screen[i][j] = YELLOW;
        }
    }

    for(int i=2; i<6; i++) {
        for(int j=4; j<7; j++) {
            screen[i][j] = WHITE;
        }
    }

    screen[2][3] = WHITE;
    for(int i=6; i<=8; i++){
        screen[i][4] = WHITE;
    }

    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            printf("%d ", screen[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    flood_fill(4, 5);
    printf("\n");
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            printf("%d ", screen[i][j]);
        }
        printf("\n");
    }

} */