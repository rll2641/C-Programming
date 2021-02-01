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
void intro() //��Ʈ��
{
	int x = 10, y = 11;
	system("mode con cols=76 lines=35");
	SetConsoleTitle(TEXT("��������������"));
	gotoxy(x, y); printf("####################################################\n");
	gotoxy(x, y + 1); printf("###\t\t\t\t\t\t   ###\n");
	gotoxy(x, y + 2); printf("###\t\t\t\t\t\t   ###\n");
	gotoxy(x, y + 3); printf("###\t1.���ӽ���\t2.��������\t3.�α׿��� ###\n");
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
		printf("����->0\t����->1\t��->2\n������ �Է��Ͻðڽ��ϱ�?(���ڷ� �Է�):");
		input = getchar();
		getchar();
		if (input >= '0' && input < '3')
		{
			break;
		}
		else
		{
			puts("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���.");
			continue;
		}

	}
	if (input == 0)
		puts("����ڴ� ������ �����Ͽ����ϴ�");
	else if (input == 1)
		puts("����ڴ� ������ �����Ͽ����ϴ�");
	else
		puts("����ڴ� ���ڱ⸦ �����Ͽ����ϴ�");
	return input;
}
int computerselect()
{
	srand((unsigned)time(NULL));
	int cs = rand() % 3;
	if (cs == 0)
		puts("��ǻ�ʹ� ������ �����Ͽ����ϴ�");
	else if (cs == 1)
		puts("��ǻ�ʹ� ������ �����Ͽ����ϴ�");
	else
		puts("��ǻ�ʹ� ���ڱ⸦ �����Ͽ����ϴ�");
	return cs;
}
void rsp(int userresult, int computerresult)
{
	if (userresult == computerresult)
	{
		puts("�����ϴ�");
	}
	if (userresult == 0)
	{
		if (computerresult == 1)
		{
			puts("����ڰ� �����ϴ�");
		}
		if (computerresult == 2)
		{
			puts("����ڰ� �̰���ϴ�");
		}
	}
	else if (userresult == 1)
	{
		if (computerresult == 0)
		{
			puts("����ڰ� �̰���ϴ�");
		}
		if (computerresult == 2)
		{
			puts("����ڰ� �����ϴ�");
		}
	}
	else
	{
		if (computerresult == 0)
		{
			puts("����ڰ� �����ϴ�");
		}
		if (computerresult == 1)
		{
			puts("����ڰ� �̰���ϴ�");
		}
	}
}
int tryagain()
{
	char again;
	puts("�ٽ��Ͻðڽ��ϱ�? Y/N");
	while (1)
	{
		again = _getch();
		if (again == 'Y' || again == 'y')
			break;
		else if (again == 'n' || again == 'N')
			break;
		else
		{
			puts("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���.");
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
		fprintf(log_file, "%d-%d-%d %d:%d:%d\t����ڴ� �����ϴ�.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		fclose(log_file);
	}
	if (user == 0)
	{
		if (com == 1)
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t����ڴ� �����ϴ�.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
		else
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t����ڴ� �̰���ϴ�.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
	}
	else if (user == 1)
	{
		if (com == 0)
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t����ڴ� �̰���ϴ�.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
		else
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t����ڴ� �����ϴ�.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
	}
	else
	{
		if (com == 0)
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t����ڴ� �����ϴ�.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(log_file);
		}
		else
		{
			log_file = fopen("log_file.txt", "a");
			fprintf(log_file, "%d-%d-%d %d:%d:%d\t����ڴ� �̰���ϴ�.\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
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