

#include<stdio.h>
#define SIZE 4
struct student_type{
    char name[10];
    int num;
    int age;
    char addr[15];
}stud[SIZE];
void save()
{
    FILE *fp;
    int i;
    if((fp=fopen("suzu.txt","wb"))==NULL)
    {
        printf("cannot open file\n");
        return ;
    }
    for(i=0;i<SIZE;i++)
    {
        if(fwrite(&stud[i],sizeof(struct student_type),1,fp)!=1)
        {
            printf("file write error\n");
        }
    }
    fclose(fp);
 } 
 
int main()
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        scanf("%s %d %d %s",&stud[i].name,&stud[i].num,&stud[i].age,&stud[i].addr);
    }
    save();
}
/****输入：
Zhang 1001 19 room_101
Fun 1002 20 room_102
Tan 1003 21 room_103
King 1004 21 room_104
**/