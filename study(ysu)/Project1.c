#include <stdio.h>

typedef struct //�������� ���� ����ü����
{
	int x;
	int y;
} Integer;

void Intro() //�Ұ�
{
	printf("�ȳ��ϼ���! ������(10191541)�Դϴ�.\n\n");
}

Integer Input_int() //return�� ���� 2�� �ޱ� ���� ����ü Ȱ��
{
	Integer two;
	printf("�ΰ��� �����Է�: ");
	scanf("%d%d", &two.x, &two.y);
	return two;
}

void Add_Minu_Mul_Div(Integer num) //��Ģ���� �Լ�
{	
	printf("������ ���: %d\n", num.x + num.y);
	printf("������ ���: %d\n", num.x - num.y);
	printf("������ ���: %d\n", num.x * num.y);
	printf("�������� ���: %d\n", num.x / num.y);
	printf("�������� ���: %d\n", num.x % num.y);
}

int main()
{
	Intro();
	Integer XY = Input_int();
	Add_Minu_Mul_Div(XY);
	return 0;
}