#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* input_studentInfor() { 

    static char student[30][15]; // �Լ��� ����Ǵ��� �ּҰ� �����ɼ� �ְ� static���

    printf("���ʴ�� �̸�,�Ҽ�,�й�,����,����,���м��� �Է�\n");

    for(int i=0; i<30; i++) {  
        scanf("%s", student[i]);

        if(i == 5 || i == 11 || i == 17 || i == 23) {
            printf("���ʴ�� �̸�,�Ҽ�,�й�,����,����,���м��� �Է�\n");
        }
    }

    return (char*)student; // ��ȯ���� 2�����迭�� ��������
}

int main() {
    char (*stuInfor)[15] = (char(*)[15])input_studentInfor(); //stuInfor�� 2�����迭�� ��������
    double num[5];  // �л����� ������� ����
    double sum = 0; // �������� ����
    int count = 0;

    for(int i=3; i<30; i++) { // ���ڿ� �ӿ� �ִ� ������ �Ǽ��� ��ȯ
        if(i > 2 && i <6) {
            count = 0;
            sum += atof(stuInfor[i]); // ���ڿ��� �Ǽ��� ��ȯ �� ������ ����
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

    printf("�̸�\t�Ҽ�\t\t�й�\t\t����\n");

    for(int i=0; i<30; i++) { // ����� ���
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