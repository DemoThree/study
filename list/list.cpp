#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Node

{
    int data;
    struct Node *next;
    /* data */
}Node,*List;//后面*list 与定义 int *i一样 为指针变量

struct Node* Ininit(){
    List L;
    //这里形参L变量把穿过来的实参l的地址复值
    //类似与LinList* L =&L指针变量赋值变为一个二级指针    
    L=(List)malloc(sizeof(Node));
    if (L==NULL)
    {

        perror("false");
        /* code */
    }
    L->next=NULL;
   
    return L;

}
//引用参数尾插法创建链表
void _tail_insert(List &list,int total)
{
   List Temp; // 临时节点指针
   List Tail = list; // 尾节点指针，初始指向头结点

   for (int i=0;i<total;i++){
   Temp = (Node *)malloc(sizeof(Node)); // 分配内存并创建新节点
   Temp->data = i+1; // 尾节点的下一个指针指向新节点
   Tail->next = Temp; // 更新尾节点指针，使其指向新节点
   Tail = Temp; // 读取下一个数据
   }
   Tail->next=NULL;
 
};
//二级指针参数尾插法创建链表
void _tail_towpoint(List *list,int count){
    List Temp,Tail;
    Tail=*list;
  int j=1;
   while (Tail->next!=NULL)
   {
    Tail=Tail->next;
    /* code */
    
   }
   j=Tail->data;
 


 for (int i = 0; i < count; i++)
 {
     Temp=(Node *)malloc(sizeof(Node));
     Temp->data=j+i+1;
     Tail->next=Temp;
     Tail=Temp;
 }
 Tail->next=NULL;

}
int Get_length(List *L){
    int count=0;
 for ( List p=*L;p!= NULL;p=p->next) // 从头结点的下一个节点开始，遍历链表直到链表结束（节点为NULL）。
    count++; // 每经过一个节点，有效节点数量加1。
return count;

}


void insert(List &L,int x){
     List T=L,Tail;

if (x<0||x>=Get_length(&T))perror("false");

for (int i=0; i<x;i++)
{T=T->next;
    /* code */

}
if(T!=NULL)
{
    Tail=(List)malloc(sizeof(Node));
    
    Tail->next=T->next;
    Tail->data=1;
    T->next=Tail;

}
}
int empty(List &L){
    printf("链表判空：%s\n",L==NULL ? "空" : "非空");
    return L==NULL;
}
void printfList(List &L){
    List cur=L;//这里赋值是把L存储的node节点内存单元的地址复制到cur上，node里面存放了next地址
    while(cur!=NULL){
        printf("L->data: %d",cur->data);
        cur=cur->next;
    }
}
//链表反转
void reverse(List &L){
    if (L==NULL){
    
        /* code */
        return;
    }
    List pre,Temp;
    
    while (L!=NULL)
    {
    Temp=L->next;//这一把通过->指针运算找到node内存的next同时赋值给temp
    L->next=pre; //这句内存更改一变都变；   
    pre=L;
    L=Temp;
        /* code */
    }
    L=pre;


    


}




int main(int argc, char const *argv[])
{
    List L;
    empty(L);
    int length;
    L= Ininit();
    _tail_insert(L,2);
    _tail_towpoint(&L,2);
    length=Get_length(&L);
    cout<<length<<endl;
    reverse(L);
    printfList(L);
    

}
