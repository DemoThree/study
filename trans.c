#include <stdio.h>
int fun(char *p){
    int i=1,num=0,total=0,num2=0,reverse=0;
    while(*p!='\0'){
        num=*p-'0';
        total+=num*i;
        i*=10;
        p++;

    }
     for (int j=10; j <=i; j*=10)
     {
        num2=total%10;
        reverse*=10;
        reverse+=num2;
        total=total/10;
        /* code */
     }
     return reverse;

}
int main(int argc, char const *argv[])
{
    char ar[]="12345789";
    printf("%d",fun(ar));
    return 0;
}
