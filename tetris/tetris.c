#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_X 12   // 맵의 가로길이
#define MAP_Y 24   // 맵의 세로길이

#define EMPTY -1   // 빈공간 ,블록이 이동할 공간을 음수로정함
#define CEILING 2  // 천장 ,블록이 충돌을 일으키는 구간을 양수로정함
#define WALL 3     // 벽 
#define L_BLOCK 4  // 착지가완료된 블록

#define N_CRASH 0  // 비충돌 
#define CRASH 1    // 충돌

#define LEFT 75    // 왼쪽이동
#define RIGHT 77   // 오른쪽이동
#define UP 72      // 블록 회전
#define DOWN 80    // 한칸 내리기

FILE * r_f = NULL; // 기록저장

clock_t startdrop, end, ground; // 초단위 계산

int map[MAP_Y][MAP_X]={   // 테트리스 맵
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
int block[7][4][4][4]={   // 블록 경우의수 7=블록의종류 4=블록의 회전 4=블록의가로 4=블록의세로
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
int b_rotation=0;         // 블록의 회전상태
int r_block;              // 블록 난수저장
int block_x=12;           // 블록의 현재 x좌표
int block_y=2;            // 블록의 현재 y좌표
int input;                // 방향키 입력

void gotoxy(int,int);     // 좌표이동시 활용되는 함수
void CursorView(char);    // 커서 숨기는 함수
void console_title();     // 창의 크기와 제목
void intro();             // 인트로
void t_map();             // 테트리스 맵을 제작하는 함수
void random_block();      // 블록을 난수설정하는 함수
void create_block();      // 블록을 만드는함수
int check_crash(int,int,int); // 충돌여부를 검사하는 함수
void drop_block();        // 블록을 떨어지게 만드는 함수
void stop_block();        // 이동이 완료된 블록을 정지 시키는 함수
void m_r_block();         // 블록을 이동 및 회전 시키는 함수
void clear_line();        // 블록이 한줄이 완성될 경우 비우기

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
                printf("■");
            }
            else if(map[i][j]==L_BLOCK){
                gotoxy(j*2,i);
                printf("□");

            }
        }
    }
    gotoxy(50,6);printf("  ↑ : 블록 모양 바꾸기");
    gotoxy(50,7);printf("←  → : 좌우 이동");
    gotoxy(50,8);printf("  ↓ : 블록 빨리 내리기");
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
                printf("■");
            }
}
int check_crash(int x ,int y ,int rotation)
{
    int i ,j;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++)
        { ////특수문자가 2바이트크기이므로 x에 나누기2를 해서 인덱스값으로 표현함
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
            block_x=12; // 다시 초기값으로 설정
            block_y=2;  // 위와 동일
            create_block(); // 블록을 정지시킨뒤 다시 랜덤블록 생성    
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