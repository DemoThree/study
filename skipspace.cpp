#include <stdio.h>

int main(int argc, char const *argv[])
{
 char arr[]="AabczFZ",*p=arr;
 int arr2[2]={0};
 for(;*p!='\0';p++){
 printf("%c",*p);
 if(*p>=65&&*p<=90)
    arr2[0]++;
 if (*p>=97&&*p<=97+25)
    arr2[1]++;
    /* code */
 }

 for (;p>=arr;p--)
 {
    if (*p>=65&&*p<=90)
       printf("%c",*p);
    /* code */
    /* code */
 }
 printf("%d--%d",arr2[0],arr2[1]);
 
 


    /* code */
    return 0;
}
