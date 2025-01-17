#include <stdio.h>
#define MAX 100
 typedef struct sqlist
 {
    /* data */
    int data[MAX];
    int length;

 }sqlist,*sqlist;
 
void init(sqlist l);

   
int main(){
sqlist l;
init (l);


}
void init(sqlist l ){

l->data=(int *)malloc(sizeof(int)*MAX);




}
