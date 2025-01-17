#include <stdio.h>

/* 定义结构体, 存储一个字符串和年龄 */
typedef struct student
{
    char name[20];
    int age;
}student ;//加typedefbixu使用后面加student

int main()
{
    // 要写入文件的结构体
    student s1[2] = {{"Tom", 18}, {"Jerry", 20}};

    // 打开要写入的文件
    FILE *p = fopen("Tom.txt", "wb");
    // 打开失败直接退出
    if(p == NULL)
        return 0;

    // 将结构体写出到文件中
    fwrite(s1, sizeof (struct student),2, p);
    // 关闭文件
    fclose(p);



    // 读取文件中的结构体



    // 存储读取到的结构体数据
    struct student s2[2] = {0};

    // 打开文件
    FILE *p2 = fopen("Tom.txt", "rb");
    // 如果打开失败, 退出
    if(p2 == NULL)
        return 0;

    // 从文件中读取结构体信息
    fread(s2,sizeof(struct student),2, p2);
    // 关闭文件
    fclose(p2);

    // 打印数据
    int i = 0;
    for(i = 0; i < 2; i ++)
        printf("student : name=%s, age=%d\n", s2[i].name, s2[i].age);

    return 0;
}


