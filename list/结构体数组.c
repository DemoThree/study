#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student students[3];

    // 初始化
    strcpy(students[0].name, "Alice");
    students[0].age = 20;
    students[0].gpa = 3.5;

    strcpy(students[1].name, "Bob");
    students[1].age = 21;
    students[1].gpa = 3.7;

    strcpy(students[2].name, "Charlie");
    students[2].age = 19;
    students[2].gpa = 3.8;
    FILE *fp=fopen("结构体属组fwrite.txt","w");

    // 输出
    for (int i = 0; i < 3; i++) {
        //printf("%x-%x",&students[i],&students[i].name);//存放每个结构体地址，后一个为整体结构体地址
        /*
        数组里面存放每个结构体首地址！！
        */
        
        
         printf("Name:%s,Age:%d,GPA:%.2f\n", students[i].name, students[i].age, students[i].gpa);
    
        //fprintf(fp,"Name: %s,Age:%d,GPA:%.2f\n", students[i].name, students[i].age, students[i].gpa);
  fprintf(fp,"%s %d %.2f\n", students[i].name, students[i].age, students[i].gpa);

    }int j=0;
 


 
 

    fclose(fp);

    return 0;
}



