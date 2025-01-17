#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;

    
}Node,*List;
void init(List &L,int length){
    List node,temp;

L=(Node*)malloc(sizeof(Node));
temp=L;
for (int i = 0; i < length-1; i++)
{
node=(Node*)malloc(sizeof(Node));

temp->next=node;
temp=temp->next;
    /* code */
}
}

void reverse(List &L){
List pre=NULL, temp=NULL;
while (L!=NULL)
{
temp=L->next;
L->next=pre;
pre=L;
L=temp;
    /* code */
}
L=pre;

}



int main(int argc, char const *argv[])
{
List L;
init(L,5);
reverse(L);
while (L!=NULL)
{
    printf("%d",L->data);
    
    /* code */
}

    return 0;
}
