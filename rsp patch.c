#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void intro() //��Ʈ��
{
	printf("###################################################\n");
	printf("###\t\t\t\t\t\t###\n");
	printf("###\t\t\t\t\t\t###\n");
	printf("###\t1.���ӽ���\t\t2.��������\t###\n");
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