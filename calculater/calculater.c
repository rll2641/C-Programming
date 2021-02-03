#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x,int y) 
{
COORD pos={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
void console_area_title() //콘솔창의 크기,제목
{
    system("mode con cols=80 lines=30");
    SetConsoleTitle(TEXT("계산기"));
}
void title() //타이틀
{
   gotoxy(18,8);printf("========================================\n");
   gotoxy(18,9);printf("------------------계산기----------------\n");
   gotoxy(18,10);printf("========================================\n");
   gotoxy(18,18);printf("[1.계산하기      2.기록보기      3.종료]\n");
}
void menu() //메뉴선택
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
    puts("1.덧셈 2.뺄셈 3.나눗셈 ");
    opt=_getch()-'0';
    system("cls");
    if(opt==1){
        puts("수식입력");
        scanf("%d%c%d",&a,&c,&b);
        printf("%d+%d=%d", a,b,a+b);
    }
    else if(opt==2){
       puts("수식입력");
        scanf("%d%c%d",&a,&c,&b);
        printf("%d-%d=%d", a,b,a-b);
    }
    else{
        puts("수식입력");
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