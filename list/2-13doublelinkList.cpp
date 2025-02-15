#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;

    /* data */
} Node;

Node *init();
// 创建链表
void creatList(Node *l, int n);
// 插入节点
void insert(Node *l, int n, int data);
// 删除节点
void del(Node *l, int n);
// 更新节点
void update(Node *l, int n, int data);
// 查训选择节点
void select(Node *l, int n);
// 查询选择所有节点
void selectAll(Node *l);
// 排序 采用冒泡排序
void sort(Node *l);
// 销毁链表
void destroy(Node *l);
// 链表是否为空
void isEmpty(Node *l);
// 链表长度
void length(Node *l);
// 数据定位
void locate(Node *l, int data);
// 数据获取
void get(Node *l, int n);
int main(int argc, char const *argv[])
{
    Node *List;
    List = init();
    printf("%d\n", List->data);

    return 0;
}

Node *init()
{
    Node *l = (Node *)malloc(sizeof(Node));
    l->data = 0;
    l->pre = NULL;
    l->next = NULL;
    return l;
}
void creatList(Node *l, int n)
{
    Node *p = l;
    for (int i = 0; i < n; i++)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = i;
        temp->pre = p;
        p->next = temp;
        p = temp;
    }
    p->next = NULL;
}
void insert(Node *l, int n, int data)
{
    Node *p = l;
    // 找到第n个节点
    for (int i = 0; i < n; i++)
    {
        p = p->next;
    }
    Node *temp = (Node *)malloc(sizeof(Node));
    // 插入节点
    temp->data = data;

    temp->pre = p;
    temp->next = p->next;
    // 修改前后节点的指针
    p->next->pre = temp;
    // 修改前一个节点的指针
    p->next = temp;
}
void del(Node *l, int n)
{
    Node *p = l;
    // 找到第n个节点
    for (int i = 0; i < n; i++)
    {
        p = p->next;
    }
    // 修改前后节点的指针
    p->pre->next = p->next;
    p->next->pre = p->pre;
    free(p);
}
void update(Node *l, int n, int data)
{
    Node *p = l;
    // 找到第n个节点
    for (int i = 0; i < n; i++)
    {
        p = p->next;
    }
    p->data = data;
}
void select(Node *l, int n)
{
    Node *p = l;
    // 找到第n个节点
    for (int i = 0; i < n; i++)
    {
        p = p->next;
    }
    printf("%d\n", p->data);
}
void selectAll(Node *l)
{
    Node *p = l->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
void sort(Node *l)
{ // 冒泡排序
    Node *p = l->next;
    Node *q = p->next;
    while (p != NULL)
    {
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                // 交换数据
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}
void destroy(Node *l)
{
    Node *p = l->next;
    while (p != NULL)
    { // 储存下一个节点
        Node *temp = p->next;
        free(p);
        // 重新赋值
        p = temp;
    }
    l->next = NULL;
}
void clear(Node *l)
{
    Node *p = l->next;
    while (p != NULL)
    {
        Node *temp = p->next;
        free(p);
        p = temp;
    }
    l->next = NULL;
}
void isEmpty(Node *l)
{
    if (l->next == NULL)
    {
        printf("链表为空\n");
    }
    else
    {
        printf("链表不为空\n");
    }
}
void length(Node *l)
{
    Node *p = l->next;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    printf("链表长度为%d\n", count);
}
// 数据定位
void locate(Node *l, int data)
{
    Node *p = l->next;
    int count = 0;
    while (p != NULL)
    {
        count++;
        if (p->data == data)
        {
            printf("数据%d在链表中的位置为%d\n", data, count);
            return;
        }
        p = p->next;
    }
    printf("数据%d不在链表中\n", data);
}
// 获取第n个数据
void get(Node *l, int n)
{
    Node *p = l->next;
    int count = 0;
    while (p != NULL)
    {
        count++;
        if (count == n)
        {
            printf("第%d个数据为%d\n", n, p->data);
            return;
        }
        p = p->next;
    }
    printf("链表长度小于%d\n", n);
}