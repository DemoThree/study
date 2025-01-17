#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int a;//系数
    int b;//指数
    struct Node *next;

}Node,*list;
int empty(list L){
  if (L==NULL)
    {

        perror("false");
        return 1;
        /* code */
    }
return 0;
}
void init(list L){
        //初始化头节点
    L=(Node*)malloc(sizeof(Node));
    L->next=NULL;
}
void createTailNode(list L,int x){
     list tail,node;
     tail=L;
     if (empty(L)){
        init(L);
        /* code */
     }
     
     for (int i = 0; i < x; i++)
     {
     node=(Node*)malloc(sizeof(Node));
     printf("%daxb:",i+1);
     scanf("%dx%d",&node->a,&node->b);
     tail->next=node;
     tail=node;

        /* code */
     }
     
     
}
void printfList(list l){
    list cur;
    cur=l->next;
    printf("List:");
    while (cur!=NULL)
    {
        printf("%dX^%d ",cur->a,cur->b);
        cur=cur->next;
        /* code */
    }
    
}

int main(int argc, char const *argv[])
{
list L; 
init(L);
createTailNode(L,2);
printfList(L);
    /* code */
    return 0;
}
