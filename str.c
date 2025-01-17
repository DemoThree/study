#include <stdio.h>
#include <string.h>
int main(){
    printf("%d",'a'-'b');
char arr[]="qwertt";
printf("------%lu\n",sizeof(arr));
int i= 'a'-2;
printf("%d",i);

char arr2[]="aaa";
strcpy(arr,arr2);
puts(arr);
printf("%s******%lu",arr,strlen(arr));
if (-1)
{
    printf("\n-1");
    /* code */
}
return 0;
}