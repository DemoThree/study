#include <stdio.h>

int main() {
  int c;
  while((c=getchar())!='\n'){
   switch(c-'2'){
      case 0:printf("0:");
      case 1:printf("1:");putchar(c+4);
      case 2:printf("2:");putchar(c+4);break;
      case 3:printf("3:");putchar(c+3);
      default:printf("df");putchar(c+2);break;
   }
  }
   return 0;
}