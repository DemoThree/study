#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *next;

} Stack;
// 初始化
Stack *init();
// 人栈
void push(Stack *s, int data);
// 出栈
void pop(Stack *s);
// 获取栈顶元素
void getTop(Stack *s);
// 是否为空
void isEmpty(Stack *s);
// 清空
void clear(Stack *s);

int main(int argc, char const *argv[])
{

    return 0;
}
// 初始化栈顶指针
Stack *init()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}
// 入栈
void push(Stack *s, int data)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = data;
    // 头插法入栈
    p->next = s->next;
    // 栈顶指针指向新节点
    s->next = p;
}
// 出栈
void pop(Stack *s)
{
    if (s->next == NULL)
    {
        printf("栈为空\n");
        return;
    }
    Stack *p = s->next;
    s->next = p->next;
    free(p);
}
// 获取栈顶元素
void getTop(Stack *s)
{
    if (s->next == NULL)
    {
        printf("栈为空\n");
        return;
    }
    printf("栈顶元素为：%d\n", s->next->data);
}
