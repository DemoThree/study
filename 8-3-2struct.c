#include<stdio.h>
typedef struct 
{   int id;
    char name[10];
    double price;
    /* data */
}Price;
int main(int argc, char const *argv[])
{   Price p[5]={
    {101,"鸡蛋",10.0},
    {102,"猪肉",15.0},
    {103,"白菜",2.0},
    {201,"苹果",4.5},
    {202,"香蕉",2.5}};
    Price *p1=p;
    int id ,number;
    printf("%d\n",sizeof(p));
    scanf("%d %d",&id,&number);
    for (int i=0; i<sizeof(p)/sizeof(p[0]); i++)
    {
        /* code */
       if (p1[i].id==id)
       {
           printf("i:%d---id:%d----name:%s----price:%f----number:%f\n"
        ,i,p1[i].id,p1[i].name,p1[i].price,p1[i].price*number);
        /* code */
       }
        /* code */
    
    }
        
    




    
    
    
    /* code */
    return 0;
}
