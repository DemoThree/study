#include <stdio.h>
void fun(int *p){
printf("%d",*p);
}
int main(int argc, char const *argv[])
{   int *p,i=2;
        p=&i;
    fun(&i);
    fun(p);
    return 0;
}
