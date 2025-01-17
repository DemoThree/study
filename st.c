#include <stdio.h>
#include <string.h>
#define N 100 
void main (){
int i,j=0,c[26]={0};
char str[N];
printf("输入：");
gets(str);

for (i=2;i<strlen(str);i++){
    for(j=0;j<26;j++){
        if(str[i]=='a'+j){
            c[j]++;
            break;
        }
    }
}
for(i=0;j<26;i++){
    printf("%c-%d",'a'+i,c[i]);
}
}