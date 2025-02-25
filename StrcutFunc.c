#include <stdio.h>
typedef void (*func)(void);
typedef struct
{
    func myFunc;
} FuncStruct;
void func1(void)
{
    printf("func1\n");
}
int main(int argc, char const *argv[])
{
    FuncStruct f;
    f.myFunc = func1;
    f.myFunc();
    return 0;
}