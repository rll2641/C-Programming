#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_X 12   // ���� ���α���
#define MAP_Y 24   // ���� ���α���

#define EMPTY -1   // ����� ,����� �̵��� ������ ����������
#define CEILING 2  // õ�� ,����� �浹�� ����Ű�� ������ ���������
#define WALL 3     // �� 
#define L_BLOCK 4  // �������Ϸ�� ���

#define N_CRASH 0  // ���浹 
#define CRASH 1    // �浹

#define LEFT 75    // �����̵�
#define RIGHT 77   // �������̵�
#define UP 72      // ��� ȸ��
#define DOWN 80    // ��ĭ ������

FILE * r_f = NULL; // �������

clock_t startdrop, end, ground; // �ʴ��� ���

int map[MAP_Y][MAP_X]={   // ��Ʈ���� ��
    {2,2,2,2,2,2,2,2,2,2,2,2},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3},
    {3,3,3,3,3,3,3,3,3,3,3,3}
};
int block[7][4][4][4]={   // ��� ����Ǽ� 7=��������� 4=����� ȸ�� 4=����ǰ��� 4=����Ǽ���
{{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}, //���簢�� ���
 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}},
{{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}, //l�ں��
 {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}}, 
{{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}, //z�ں��
 {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}}, 
{{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}, //z�ݴ���
 {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}}, 
{{0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0}, //���ں��
 {0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0}},
{{0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0}, //���ں��
 {0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},{0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0}},
{{0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0}, //���ں��
 {0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},{0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}}
};
int b_rotation=0;         // ����� ȸ������
int r_block;              // ��� ��������
int block_x=12;           // ����� ���� x��ǥ
int block_y=2;            // ����� ���� y��ǥ
int input;                // ����Ű �Է�

void gotoxy(int,int);     // ��ǥ�̵��� Ȱ��Ǵ� �Լ�
void CursorView(char);    // Ŀ�� ����� �Լ�
void console_title();     // â�� ũ��� ����
void intro();             // ��Ʈ��
void t_map();             // ��Ʈ���� ���� �����ϴ� �Լ�
void random_block();      // ����� ���������ϴ� �Լ�
void create_block();      // ����� ������Լ�
int check_crash(int,int,int); // �浹���θ� �˻��ϴ� �Լ�
void drop_block();        // ����� �������� ����� �Լ�
void stop_block();        // �̵��� �Ϸ�� ����� ���� ��Ű�� �Լ�
void m_r_block();         // ����� �̵� �� ȸ�� ��Ű�� �Լ�
void clear_line();        // ����� ������ �ϼ��� ��� ����

int main(){
    console_title();
    CursorView(0);
    startdrop=clock();
    random_block();
    intro();
    while(1){
        t_map();
        create_block();
        drop_block();
        stop_block();
        //clear_line();
        m_r_block();
    }
    return 0;
}

void gotoxy(int x ,int y){ 
    COORD pos = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
void CursorView(char show){ 
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}
void console_title(){ 
    system("mode con cols=100 lines=40");
    SetConsoleTitle(TEXT("Tetris"));
}
void intro(){ 
    int x = 18 , y = 6;
    int i , input;
    for (i = 0; ; i++) {
        if (i % 2 == 0) {
            gotoxy(x,y+0); printf("  ������ ���� ������ ����� ����  ����  ����");
            gotoxy(x,y+1); printf("\t��     ��\t  ��\t ��    ��   ��   ��       ��");
            gotoxy(x,y+2); printf("\t��     ����\t  ��\t �����   ��    ����  ����");
            gotoxy(x,y+3); printf("\t��     ��\t  ��\t ��  ��     ��         �� ��  ");
            gotoxy(x,y+4); printf("\t��     ����\t  ��\t ��    �� ����  ����  ����");
            gotoxy(x+27,y+6); printf("Press Number!");
            gotoxy(x,y+8); printf("  ��������������������������������������������������������������������������������������������������������������������������");
            gotoxy(x+28,y+12); printf("1.���ӽ���");
            gotoxy(x+28,y+16); printf("2.��Ϻ���");
            gotoxy(x+28,y+20); printf("3.��������");
            gotoxy(x,y+24); printf("  ��������������������������������������������������������������������������������������������������������������������������");
            Sleep(1200);
        }
        if (i % 5 == 0) {
            gotoxy(x,y+0); printf("                                                                    ");
            gotoxy(x,y+1); printf("                                                                    ");
            gotoxy(x,y+2); printf("                                                                    ");
            gotoxy(x,y+3); printf("                                                                    ");
            gotoxy(x,y+4); printf("                                                                    ");
            gotoxy(x,y+6); printf("                                                                    ");
            Sleep(400);
        }
        if(kbhit()){
            input=_getch()-'0';
            if(input==1){
                system("cls");
                break;
            }
            else if(input==2){
                r_f=fopen("record.txt","rt");
                fclose(r_f);
                system("log_file.txt");
                continue;
            }
            else if(input==3)
                exit(0);
            else
                continue;
        }
    }
    while(kbhit())
        _getch();
}
void t_map(){
    int i,j;
    for(i=0; i<MAP_Y; i++){
        for(j=0; j<MAP_X; j++){
            if(map[i][j]==CEILING || map[i][j]==WALL){
                gotoxy(j*2,i);
                printf("��");
            }
            else if(map[i][j]==L_BLOCK){
                gotoxy(j*2,i);
                printf("��");

            }
        }
    }
    gotoxy(50,6);printf("  �� : ��� ��� �ٲٱ�");
    gotoxy(50,7);printf("��  �� : �¿� �̵�");
    gotoxy(50,8);printf("  �� : ��� ���� ������");
}
void random_block()
{
    srand((unsigned)time(NULL));
    r_block = rand() % 7;
}
void create_block()
{
    int i ,j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            if(block[r_block][b_rotation][i][j] == 1)
            {
                gotoxy(MAP_X+j*2 ,i+block_y);
                printf("��");
            }
}
int check_crash(int x ,int y ,int rotation)
{
    int i ,j;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++)
        { ////Ư�����ڰ� 2����Ʈũ���̹Ƿ� x�� ������2�� �ؼ� �ε��������� ǥ����
            if(block[r_block][rotation][i][j]==1 && map[i+y][x/2+j] > 0)
                return CRASH;
        }
    }
    return N_CRASH;
}
void drop_block()
{
    end = clock();
    if((float)(end - startdrop)>= 700)
    {
        if(check_crash(block_x,block_y+1,b_rotation) == N_CRASH)
        {
            block_y++;
            startdrop = clock();
            ground = clock();
            system("cls");
        }
    }
}
void stop_block()
{
    int i,j;
    if(check_crash(block_x,block_y+1,b_rotation) == CRASH)
    {
        if((float)(end - ground)>=1200
        ){
            for(i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(block[r_block][b_rotation][i][j]==1)
                    {
                        map[i+block_y][j+block_x/2]=L_BLOCK;
                    }
                }
            }
            block_x=12; // �ٽ� �ʱⰪ���� ����
            block_y=2;  // ���� ����
            create_block(); // ����� ������Ų�� �ٽ� ������� ����    
        }
    }
}
void m_r_block()
{
    if(kbhit())
    {
        input=_getch();
        switch(input)
        {
            case 72:
                b_rotation++;
                if(b_rotation>=4)
                    b_rotation=0;
                break;
            case 75:
                if(check_crash(block_x-2,block_y,b_rotation)==N_CRASH)
                {
                    block_x-=2;
                }
                break;
            case 77:
                if(check_crash(block_x+2,block_y,b_rotation)==N_CRASH)
                {
                    block_x+=2;
                }
                break;
            case 80:
                if(check_crash(block_x,block_y+1,b_rotation)==N_CRASH)
                {
                    block_y+=1;
                }
                break;
        }
        system("cls");
    }
}
void clear_line()
{
    int  i,j,k,cnt;
    for(i=MAP_Y-2; i>=0; i++)
    {
        cnt=0;
        for(j=1; j<MAP_X-1; j++)
            if(map[i][j]==L_BLOCK)
                cnt++;
        if(cnt==10)
            for(j=0; i-j>=0; j++)
                for(k=1; k<MAP_X-1; k++)
                {
                    if(i-j>=CEILING)
                        map[i-j][k]=map[i-j-1][k];
                    else
                        map[i-j][k]=CEILING;
                }
    }
}