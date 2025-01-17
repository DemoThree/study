#include <stdio.h>
void ltrim(char *p){

for (;*p!='\0' ; p++)
{   
     printf("%c",*p);
     
     if(*p!=32){
        p=p;
        break;
     }

     
     
    /* code */
}
for (;*p!='\0' ; p++)
{   
     printf("%c",*p);
    /* code */
}

    
}
int main(int argc, char const *argv[])
{
    /* code */
 char p[]="   ABC DEF";
 ltrim(p);
    return 0;
}
