#include <stdio.h>
void reverse(int);
void main()
{
    int i;

    scanf("%d", &i);
    if (i < 0)
    {
        i = -i;
        printf("-");
    }

    reverse(i);
}
void reverse(int a)
{

    printf("%d", a % 10);
    a = a / 10;
    if (a != 0)
    {
        /* code */
        reverse(a);
    }
}