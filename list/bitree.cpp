#include <stdio.h>
#include <stdlib.h>

typedef struct bitree
{
    int data;
    struct bitree *left;
    struct bitree *right;
    /* data */

} bitree;
bitree *init()
{
    bitree *b = (bitree *)malloc(sizeof(bitree));

    return b;
}

int main(int argc, char const *argv[])
{

    return 0;
}
