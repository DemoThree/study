#include <stdio.h>
void insert(char *);
void main(){
    char str1="string";//char *str1;str1="string"
    int a[5][5], (*p)[5],*s, i=3;
//int (*p)[2] = a; // int a[][2] = {1, 2, 3, 4, 5, 6};
for (p = &a[0]; p < &a[5]; p++){
  (*p)[i] = 1;}
for (s = a[i]; s < a[i] + 5; s++)
  {*s = 4;}
}
