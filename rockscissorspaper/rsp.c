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

	printf("��ǻ���� ������? %d.\n", computer);

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
	printf("����->0\t����->1\t��->2");
	printf("������ ���ǰǰ���?(���ڷ� ����):");
	scanf("%d", &input);
	result = rcp(input);

	if (result == 0)
	{
		puts("�����ϴ�!");
		return 0;
	}
	else if (result == 1)
	{
		puts("�����ϴ� �Ф�");
		return 0;
	}
	else
	{
		puts("�̰���ϴ�!");
		return 0;
	}
}