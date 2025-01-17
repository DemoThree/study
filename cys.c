#include <stdio.h>
int letter=0,digite=0,space=0,other=0;
void count(char[]);
void main(){
char text[80]="";
gets(text);
count("qwer");
printf("letter:%d-digite:%d-space:%d-other:%d",letter,digite,space,other);
}
void count (char str[]){
    for(int i=0;str[i]!='\0';i++){
        if (str[i]==' ')
        {space++;
            /* code */
        }else if (97<=str[i]&&str[i]<=122)
        {
            letter++;
            /* code */
        }else if (str[i]>=48&&str[i]<=57)
        {
            /* code */
            digite++;
        }
        
        
        
    }
}