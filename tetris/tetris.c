#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE_COLS 12 //게임판 가로
#define MAP_SIZE_LINES 24 //게임판 세로
#define MAP_X 20 //게임판 x좌표이동
#define MAP_Y 7  //게임판 y좌표이동
#define MAP_WALL 2 //게임판 벽
#define MAP_EMPTY -1 //게임판 빈공간,블록이 이동할수있는좌표
#define C_BLOCK 4 //이동이 끝난 블록

#define CRASH 1 //충돌시
#define N_CRASH 0 //비충돌시

#define LEFT 75 // 왼쪽이동
#define RIGHT 77 // 오른쪽이동
#define UP 72 // 블록 회전
#define DOWN 80 // 한칸 내리기

int block[7][4][4][4]={ //블록 경우의수 7=블록의종류 4=블록의 회전 4=블록의가로 4=블록의세로
{{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}, //정사각형 블록
 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}}, 
{{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}, //l자블록
 {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
{{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}, //z자블록
 {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}},
{{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}, //z반대블록
 {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}},
{{0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0}, //ㄱ자블록
 {0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0}},
{{0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0}, //ㄴ자블록
 {0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},{0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0}},
{{0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0}, //ㅗ자블록
 {0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},{0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}}
};
int r_block; //7가지 블록을 저장
int b_rotation=0; //블록 회전
int block_x=MAP_X+MAP_SIZE_COLS/2+2; //현재블록의x좌표저장
int block_y=MAP_Y+2;//현재블록의y좌표저장
int map[MAP_SIZE_LINES][MAP_SIZE_COLS]; //게임판
int keyb;
FILE*log_f=NULL; // 로그가 저장될 파일

void gotoxy(int,int); //좌표 조정
void CursorView(char); //커서숨기기
void console_area_title(); //콘솔창의 크기,제목
void intro(); //인트로
void game_map(); //게임판
void random_block(); //난수 저장
void creat_random_block(); //처음블록생성
int check_crash(int,int,int); //반환값으로 충돌검사
void m_r_block(); // 블록 이동및 회전
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
            gotoxy(x,y+0); printf("  ■■■■■ ■■■ ■■■■■ ■■■■ ■■■  ■■■  ■■■");
            gotoxy(x,y+1); printf("\t■     ■\t  ■\t ■    ■   ■   ■       ■");
            gotoxy(x,y+2); printf("\t■     ■■■\t  ■\t ■■■■   ■    ■■■  ■■■");
            gotoxy(x,y+3); printf("\t■     ■\t  ■\t ■  ■     ■         ■ ■  ");
            gotoxy(x,y+4); printf("\t■     ■■■\t  ■\t ■    ■ ■■■  ■■■  ■■■");
            gotoxy(x+27,y+6); printf("Press Number!");
            gotoxy(x,y+8); printf("  ─────────────────────────────────────────────────────────────");
            gotoxy(x+28,y+12); printf("1.게임시작");
            gotoxy(x+28,y+16); printf("2.기록보기");
            gotoxy(x+28,y+20); printf("3.게임종료");
            gotoxy(x,y+24); printf("  ─────────────────────────────────────────────────────────────");
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
                printf("▦");
            }
            if(map[i][j]==MAP_EMPTY){
                gotoxy(MAP_X+j*2,MAP_Y+i);
                printf("");
            }
        }
    gotoxy(MAP_X+40,MAP_Y);printf("↑ : 블록 모양 바꾸기");
    gotoxy(MAP_X+38,MAP_Y+1);printf("←  → : 좌우 이동");
    gotoxy(MAP_X+40,MAP_Y+2);printf("↓ : 블록 빨리 내리기");
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
                printf("■");
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
