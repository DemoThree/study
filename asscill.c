#include <stdio.h>
#include <string.h>
int main (){
    char arr[50]="";
    
    int count[26]={0},j=0;
    scanf("%s",&arr);
    for(int i=0;i<sizeof(arr);i++){
        count[arr[i]-'a']+=1;
    }
    while(j<26){    
        printf("%d",count[j]);
        j++;
    }
}
