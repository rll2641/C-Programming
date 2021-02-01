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
void menu()
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
int userselect()
{
	int input;
	while (1)
	{
		printf("가위->0\t바위->1\t보->2\n무엇을 입력하시겠습니까?(숫자로 입력):");
		input = getchar();
		getchar();
		if (input >= '0' && input < '3')
		{
			break;
		}
		else
		{
			puts("잘못입력하셨습니다. 다시입력해주세요.");
			continue;
		}

	}
	if (input == 0)
		puts("사용자는 가위를 선택하였습니다");
	else if (input == 1)
		puts("사용자는 바위를 선택하였습니다");
	else
		puts("사용자는 보자기를 선택하였습니다");
	return input;
}
int computerselect()
{
	srand((unsigned)time(NULL));
	int cs = rand() % 3;
	if (cs == 0)
		puts("컴퓨터는 가위를 선택하였습니다");
	else if (cs == 1)
		puts("컴퓨터는 바위를 선택하였습니다");
	else
		puts("컴퓨터는 보자기를 선택하였습니다");
	return cs;
}
void rsp(int userresult, int computerresult)
{
	if (userresult == computerresult)
	{
		puts("비겼습니다");
	}
	if (userresult == 0)
	{
		if (computerresult == 1)
		{
			puts("사용자가 졌습니다");
		}
		if (computerresult == 2)
		{
			puts("사용자가 이겼습니다");
		}
	}
	else if (userresult == 1)
	{
		if (computerresult == 0)
		{
			puts("사용자가 이겼습니다");
		}
		if (computerresult == 2)
		{
			puts("사용자가 졌습니다");
		}
	}
	else
	{
		if (computerresult == 0)
		{
			puts("사용자가 졌습니다");
		}
		if (computerresult == 1)
		{
			puts("사용자가 이겼습니다");
		}
	}
}
int tryagain()
{
	char again;
	puts("다시하시겠습니까? Y/N");
	while (1)
	{
		again = _getch();
		if (again == 'Y' || again == 'y')
			break;
		else if (again == 'n' || again == 'N')
			break;
		else
		{
			puts("잘못입력하셨습니다. 다시입력해주세요.");
			continue;
		}
	}
	return again;
}
int main()
{
	int userresult, computerresult, again;
	intro();
	menu();
	while (1)
	{
		userresult = userselect();
		computerresult = computerselect();
		rsp(userresult, computerresult);
		again = tryagain();
		if (again == 'Y' || again == 'y')
			continue;
		else
			break;
	}
	return 0;
}