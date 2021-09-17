#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* input_studentInfor() { 

    static char student[30][15]; // 함수가 종료되더라도 주소가 유지될수 있게 static사용

    printf("차례대로 이름,소속,학번,국어,영어,수학성적 입력\n");

    for(int i=0; i<30; i++) {  
        scanf("%s", student[i]);

        if(i == 5 || i == 11 || i == 17 || i == 23) {
            printf("차례대로 이름,소속,학번,국어,영어,수학성적 입력\n");
        }
    }

    return (char*)student; // 반환형은 2차원배열의 포인터형
}

int main() {
    char (*stuInfor)[15] = (char(*)[15])input_studentInfor(); //stuInfor은 2차원배열의 포인터형
    double num[5];  // 학생들의 평균점수 저장
    double sum = 0; // 성적점수 총합
    int count = 0;

    for(int i=3; i<30; i++) { // 문자열 속에 있는 점수를 실수로 변환
        if(i > 2 && i <6) {
            count = 0;
            sum += atof(stuInfor[i]); // 문자열을 실수로 변환 후 변수에 저장
            if(i == 5) {
                num[count] = sum;
                sum = 0;
            }
        }
        if(i > 8 && i <12) {
            count = 1;
            sum += atof(stuInfor[i]);
            if(i == 11) {
                num[count] = sum;
                sum = 0;
            }
        }
        if(i > 14 && i <18) {
            count = 2;
            sum += atof(stuInfor[i]);
            if(i == 17){
                num[count] = sum;
                sum = 0;
            }
        }
        if(i > 20 && i <24) {
            count = 3;
            sum += atof(stuInfor[i]);
            if(i == 23){
                num[count] = sum;
                sum = 0;
            }
        }
        if(i > 26 && i< 30) {
            count = 4;
            sum += atof(stuInfor[i]);
            if(i == 29){
                num[count] = sum;
            }
        }
    } 

    printf("이름\t소속\t\t학번\t\t평점\n");

    for(int i=0; i<30; i++) { // 모니터 출력
        if(i >= 0 && i <3) {
            printf("%s\t", stuInfor[i]);
        }
        if(i == 3) {
            count = 0;
            printf("%.2f\n", num[count]/3);
        } 
        if(i >5 && i <9) {
            printf("%s\t", stuInfor[i]);
        }
        if(i == 9) {
            count =1;
            printf("%.2f\n", num[count]/3);
        }
        if(i >11 && i<15) {
            printf("%s\t", stuInfor[i]);
        }
        if(i == 15) {
            count =2;
            printf("%.2f\n", num[count]/3);
        }
        if(i >17 && i<21) {
            printf("%s\t", stuInfor[i]);
        }
        if(i == 21) {
            count =3;
            printf("%.2f\n", num[count]/3);
        }
        if(i > 23 && i<27) {
            printf("%s\t", stuInfor[i]);
        }
        if(i == 27) {
            count=4;
            printf("%.2f\n", num[count]/3);
        }
    }

    _getch();
    
    return 0;
}