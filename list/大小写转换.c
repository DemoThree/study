#include<stdio.h>

int my_toupper(char c){
return c-'A'+'a';


}
int main(int argc, char const *argv[])
{
    int i;
    char c1;
    c1=my_toupper('B');
        printf("%c",c1);
    return 0;
}
