#include <stdio.h>
#include <conio.h>

typedef struct {
    char name[10];
    char major[15];
    char classof[10];
    double math,kr,en,avg;
} Student;

int main(){

    Student infor[5];

    for(int i=0; i<5; i++) { // 학생정보 입력
        printf("차례대로 이름 소속 학번 국어 영어 수학성적 입력\n");
        scanf("%s %s %s %lf %lf %lf", infor[i].name,infor[i].major,infor[i].classof,
               &infor[i].kr,&infor[i].en,&infor[i].math);     
    }

    for(int i=0; i<5; i++) { // 점수 평균
        infor[i].avg = (infor[i].en + infor[i].kr + infor[i].math) / 3;
    }

    printf("이름\t소속\t\t학번\t\t평점\n");

    for(int i=0; i<5; i++) {
        printf("%s\t%s\t%s\t%.2f\n", infor[i].name,infor[i].major,infor[i].classof,
        infor[i].avg);
    }

    _getch();
    
    return 0;

}