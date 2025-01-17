#include <stdio.h>
f(int b){
    static int y=3;
    return (b+y++);
}
int main(){
    int a =2,i,k;
    for(i=0;i<2;i++)
    k=f(a++);
    printf("%d",k);
    return 0;
}