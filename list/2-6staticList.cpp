#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef int ElemType;
typedef struct sqlist
{
    ElemType data[MAX_SIZE];
    int length;

} sqlist;
typedef struct sqlists
{
    ElemType *data;
    int length;
    int MaxSize;

    /* data */
} sqlists;
void SeqListInit(sqlist &l)
{
    l.length = 0;
}

int main(int argc, char const *argv[])
{
    sqlist  l;
    SeqListInit(l);

     return 0;
}