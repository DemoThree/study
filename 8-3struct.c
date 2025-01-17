#include<stdio.h>
typedef struct People
{int id;
char name[10];
float salary;
float welfare;
    /* data */
};
typedef struct 
{
    /* data */
}STU,*PSTU;

int main(int argc, char const *argv[])
{
    People p[10]={
    {1,"tt",20.0,30.0},
    {2,"zz",20.3,2.03},
    {3,"rrs",19.9,3.4},
    {4,"rdsar",14.9,3.4},
    {5,"rfar",19.5,3.4},
    {6,"rdwadr",12.9,3.4},
    {7,"rgasdr",19.3,4.4},
    {8,"rwrtar",19.0,3.4},
    {9,"rasdr",13.9,3.4},
    {10,"rr",12.9,3.4}};
    float avg=0.0;
    for (int i = 0; i < sizeof(p)/sizeof(People); i++)
    {
        avg+=(p[i].salary+p[i].welfare);

        printf("id:%5d name:%10s salary%5.2f welfear%5.2f,real%5.2f\n",
        p[i].id,p[i].name,p[i].salary,p[i].welfare,p[i].salary+p[i].welfare);

        /* code */
    }
    printf("Avg:%5.2f",avg/10);
    return 0;
}
