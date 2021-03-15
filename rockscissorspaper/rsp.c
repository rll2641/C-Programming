#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void intro() //인트로
{
	printf("###################################################\n");
	printf("###\t\t\t\t\t\t###\n");
	printf("###\t\t\t\t\t\t###\n");
	printf("###\t1.게임시작\t\t2.게임종료\t###\n");
	printf("###\t\t\t\t\t\t###\n");
	printf("###\t\t\t\t\t\t###\n");
	printf("###################################################\n");
}
void introinput()
{
	int input = 0;
	while (1)
	{
		input = _getch() - '0';
		if (input == 1)
		{
			system("cls");
			break;
		}
		else if (input == 2)
		{
			exit(1);
			break;
		}
		else
		{
			continue;
		}
	}
}

char rcp(int rcp)
{
	srand((unsigned)time(NULL));

	int computer = rand() % 3;

	printf("컴퓨터의 선택은? %d.\n", computer);

	if (rcp == computer)

	{
		return 0;
	}
	if (rcp == 0)
	{
		if (computer == 1)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (rcp == 1)
	{
		if (computer == 0)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if (computer == 0)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
}
int main()
{
	intro();
	introinput();
	int input = 0;
	int result = 0;
	printf("가위->0\t바위->1\t보->2");
	printf("무엇을 내실건가요?(숫자로 선택):");
	scanf("%d", &input);
	result = rcp(input);

	if (result == 0)
	{
		puts("비겼습니다!");
		return 0;
	}
	else if (result == 1)
	{
		puts("졌습니다 ㅠㅠ");
		return 0;
	}
	else
	{
		puts("이겼습니다!");
		return 0;
	}
}