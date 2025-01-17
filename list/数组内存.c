#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[3]={0};//数组本质就是连在一起的指针；[]>=*;
    printf("%x||arr---&arr||%x",arr,&arr);//结果相等；
    
    return 0;
}

