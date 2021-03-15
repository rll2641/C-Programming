#include <stdio.h>

typedef struct //정수값을 위한 구조체선언
{
	int x;
	int y;
} Integer;

void Intro() //소개
{
	printf("안녕하세요! 조지훈(10191541)입니다.\n\n");
}

Integer Input_int() //return의 값을 2개 받기 위해 구조체 활용
{
	Integer two;
	printf("두개의 정수입력: ");
	scanf("%d%d", &two.x, &two.y);
	return two;
}

void Add_Minu_Mul_Div(Integer num) //사칙연산 함수
{	
	printf("덧셈의 결과: %d\n", num.x + num.y);
	printf("뺄셈의 결과: %d\n", num.x - num.y);
	printf("곱셈의 결과: %d\n", num.x * num.y);
	printf("나눗셈의 결과: %d\n", num.x / num.y);
	printf("나머지의 결과: %d\n", num.x % num.y);
}

int main()
{
	Intro();
	Integer XY = Input_int();
	Add_Minu_Mul_Div(XY);
	return 0;
}