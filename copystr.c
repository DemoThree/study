#include<stdio.h>
void copystr(char *p,char *p2,int m){

    int n=0;
    while(n<m-1){
        n++;
        p++;

    }
while (*p!='\0')
{
    *p2=*p;
    p++;
    p2++;
    
    /* code */
}
*p2='\0';
}
int main(int argc, char const *argv[])
{

    char arr[]="ABCDEF",arr2[20]="";
    copystr(arr,arr2,3);
    /* code */
 
    return 0;
}
