#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE_COLS 12 //������ ����
#define MAP_SIZE_LINES 24 //������ ����
#define MAP_X 20 //������ x��ǥ�̵�
#define MAP_Y 7  //������ y��ǥ�̵�
#define MAP_WALL 2 //������ ��
#define MAP_EMPTY -1 //������ �����,����� �̵��Ҽ��ִ���ǥ
#define C_BLOCK 4 //�̵��� ���� ���

#define CRASH 1 //�浹��
#define N_CRASH 0 //���浹��

#define LEFT 75 // �����̵�
#define RIGHT 77 // �������̵�
#define UP 72 // ��� ȸ��
#define DOWN 80 // ��ĭ ������

int block[7][4][4][4]={ //��� ����Ǽ� 7=��������� 4=����� ȸ�� 4=����ǰ��� 4=����Ǽ���
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
int r_block; //7���� ����� ����
int b_rotation=0; //��� ȸ��
int block_x=MAP_X+MAP_SIZE_COLS/2+2; //��������x��ǥ����
int block_y=MAP_Y+2;//��������y��ǥ����
int map[MAP_SIZE_LINES][MAP_SIZE_COLS]; //������
int keyb;
FILE*log_f=NULL; // �αװ� ����� ����

void gotoxy(int,int); //��ǥ ����
void CursorView(char); //Ŀ�������
void console_area_title(); //�ܼ�â�� ũ��,����
void intro(); //��Ʈ��
void game_map(); //������
void random_block(); //���� ����
void creat_random_block(); //ó����ϻ���
int check_crash(int,int,int); //��ȯ������ �浹�˻�
void m_r_block(); // ��� �̵��� ȸ��
int main(){
    console_area_title();
    CursorView(0);
    random_block();
    intro();
    while(1){
    game_map();
    creat_random_block();
    m_r_block();
    }
    return 0;
}
void gotoxy(int x,int y){ 
    COORD pos={x,y};
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
void console_area_title(){
    system("mode con cols=105 lines=35");  
    SetConsoleTitle(TEXT("Tetris"));
}
void intro(){ 
    const int x=18,y=6;
    int i,input;
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
                log_f=fopen("log_file.txt","rt");
                fclose(log_f);
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
void game_map(){
    int i, j;
    for (i = 0; i < MAP_SIZE_LINES; i++)
        for (j = 0; j < MAP_SIZE_COLS; j++) {
            if (i == 0 || i == MAP_SIZE_LINES-1)
                map[i][j] = MAP_WALL;
            else if (j == 0 || j == MAP_SIZE_COLS-1)
                map[i][j] = MAP_WALL;
            else
                map[i][j] = MAP_EMPTY;
        }
    for (i = 0; i < MAP_SIZE_LINES; i++)
        for (j = 0; j < MAP_SIZE_COLS; j++) {
            if(map[i][j]==MAP_WALL){
                gotoxy(MAP_X+j*2,MAP_Y+i);
                printf("��");
            }
            if(map[i][j]==MAP_EMPTY){
                gotoxy(MAP_X+j*2,MAP_Y+i);
                printf("");
            }
        }
    gotoxy(MAP_X+40,MAP_Y);printf("�� : ��� ��� �ٲٱ�");
    gotoxy(MAP_X+38,MAP_Y+1);printf("��  �� : �¿� �̵�");
    gotoxy(MAP_X+40,MAP_Y+2);printf("�� : ��� ���� ������");
}
void random_block(){
    srand((unsigned)time(NULL));
    r_block=rand()%7;
}
void creat_random_block(){
    int i=0,j=0;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(block[r_block][b_rotation][i][j]==1){
                gotoxy(block_x+j*2,block_y+i);
                printf("��");
            }
            else
                gotoxy(block_x+j*2,block_y+i);
                printf("");
        }
    }
}
int check_crash(int x,int y,int rb){
    int i,j;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(block[r_block][rb][i][j]==1 && map[y+i][x+j]>0)
            return CRASH;
            else
            {
                return N_CRASH;
            }   
        }
    }
}
void m_r_block(){
    if(kbhit()){
        keyb=_getch();
        switch(keyb){
            case 72:
            b_rotation++;
            if(b_rotation>=4)
            b_rotation=0;
            break;
            case 75:
            if(check_crash(block_x-2,block_y,b_rotation)==N_CRASH)
            block_x-=2;
            break;
            case 77:
            if(check_crash(block_x+2,block_y,b_rotation)==N_CRASH)
            block_x+=2;
            break;
            case 80:
            if(check_crash(block_x,block_y+1,b_rotation)==N_CRASH)
            block_y+=+1;
            break;
        }
        system("cls");
    }
    while(kbhit())
    _getch();
}
