#include <stdio.h>
struct studentsStruct
{
    int id;
    char name[10];
    int sex;
    /* data */
}s[3]={{1,"zhang",1},{2,"li",0},{3,"wang",1}};

int main(int argc, char const *argv[])
{   
    struct studentsStruct *p=s;
    printf("%d\n",sizeof(*p));
    
    for (int i = 0; i < sizeof(s)/sizeof(studentsStruct); i++)
    {
        /* code */
        printf("%-5d%-5s%5d\n",p[i].id,p[i].name,p[i].sex);
    }
    

    /* code */
    return 0;
}
