#include <stdio.h>
#include<stdlib.h>
typedef struct  Node
{
    int data;
    struct Node *next;

    /* data */
}Node ,*List;
void insertEnd(List l,int data);
void deleteNode(List l,int key);
List creatList(List l);


void swap(List l1,List l2){
    printf("引用:%x副本:%x",&l1,&l2);


};
int main(int argc, char const *argv[])
{ List l;
l=creatList(l);
printf("本体:%x",&l);
swap(l,l);
    /* code */ nsertEnd(l,5);
    return 0;}

List creatList(List l){
    if (l!=NULL)
    {
        perror("creatlist:");
        exit(0);
        /* code */
    }
    
return (List)malloc(sizeof(Node));
}

void insertEnd(List l,int data){
while (l->next!=NULL)
{
    l=l->next;

    /* code */
}
l->next=(List)malloc(sizeof(Node));
l->next->data=data;

}