#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void intro() //인트로
{
	int x = 10, y = 11;
	system("mode con cols=76 lines=35");
	SetConsoleTitle(TEXT("가위바위보게임"));
	gotoxy(x, y); printf("####################################################\n");
	gotoxy(x, y + 1); printf("###\t\t\t\t\t\t   ###\n");
	gotoxy(x, y + 2); printf("###\t\t\t\t\t\t   ###\n");
	gotoxy(x, y + 3); printf("###\t1.게임시작\t2.게임종료\t3.로그열기 ###\n");
	gotoxy(x, y + 4); printf("###\t\t\t\t\t\t   ###\n");
	gotoxy(x, y + 5); printf("###\t\t\t\t\t\t   ###\n");
	gotoxy(x, y + 6); printf("####################################################\n");
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
		else if (input == 3)
		{
			system("log_file.txt");
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
void rsp_log_w(int user, int com)
{
	FILE* log_file;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if (user == com)
	{
		log_file = fopen("log_file.txt", "a");
		fprintf(log_file, "%d-%d-%d %d:%d:%d\t사용자는 비겼습니다.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		fclose(log_file);
	}
	if (user == 0)
	{
		if (com == 1)
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t사용자는 졌습니다.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
		else
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t사용자는 이겼습니다.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
	}
	else if (user == 1)
	{
		if (com == 0)
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t사용자는 이겼습니다.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
		else
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t사용자는 졌습니다.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
	}
	else
	{
		if (com == 0)
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t사용자는 졌습니다.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
		else
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t사용자는 이겼습니다.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
	}
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
		rsp_log_w(userresult, computerresult);
		again = tryagain();
		if (again == 'Y' || again == 'y')
			continue;
		else
			break;
	}
	return 0;
}