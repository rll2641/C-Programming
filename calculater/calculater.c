#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x,int y) 
{
COORD pos={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
void console_area_title() //�ܼ�â�� ũ��,����
{
    system("mode con cols=80 lines=30");
    SetConsoleTitle(TEXT("����"));
}
void title() //Ÿ��Ʋ
{
   gotoxy(18,8);printf("========================================\n");
   gotoxy(18,9);printf("------------------����----------------\n");
   gotoxy(18,10);printf("========================================\n");
   gotoxy(18,18);printf("[1.����ϱ�      2.��Ϻ���      3.����]\n");
}
void menu() //�޴�����
{
    char input=0;
    while(1){
        input=_getch()-'0';
        if(input==1){
            system("cls");
            break;
        }
        else if(input==2){
            system("log_file.txt");
            continue;
        }
        else if(input==3)
            exit(1);
        else
            continue;
    }   
}
void calculate()
{
    int opt,a,b;
    char c;
    puts("1.���� 2.���� 3.������ ");
    opt=_getch()-'0';
    system("cls");
    if(opt==1){
        puts("�����Է�");
        scanf("%d%c%d",&a,&c,&b);
        printf("%d+%d=%d", a,b,a+b);
    }
    else if(opt==2){
       puts("�����Է�");
        scanf("%d%c%d",&a,&c,&b);
        printf("%d-%d=%d", a,b,a-b);
    }
    else{
        puts("�����Է�");
        scanf("%d%c%d",&a,&c,&b);
        printf("%d-%d=%2f", a,b,(double)a/b);
    }
}
int main()
{
    console_area_title();
    title();
    menu();
    calculate();
    return 0;
}