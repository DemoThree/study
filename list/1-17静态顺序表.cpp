#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10 // 定义顺序表最大长度

typedef struct {
int data[MaxSize]; // 静态数组存放数据元素
int length; // 顺序表的当前长度clear
}SqList,*List;
//初始化顺序表时，将表的长度设置为0，并将数组中的所有元素初始化为0。
void InitList(SqList *L) {
for (int i = 0; i < MaxSize; i++) {
L->data[i] = 0;
}
L->length = 0;
}

// 在顺序表的指定位置插入元素时，需要将该位置及其后的元素依次后移，空出插入位置，然后将新元素插入。
// bool ListInsert(SqList L, int i, int e) {
// if (i < 1 || i > L->length + 1) {
// return false; // 判断插入位置是否合法
// }
// if (L->length >= MaxSize) {
// return false; // 判断顺序表是否已满
// }
// for (int j = L->length; j >= i; j--) {
// L->data[j] = L->data[j - 1]; // 将元素后移
// }
// L->data[i - 1] = e; // 插入新元素
// L->length++;
// return true;
// }
// bool ListDelete(SqList L, int i, int e) {
// if (i < 1 || i > L->length) {
// return false; // 判断删除位置是否合法
// }
// e = L->data[i - 1]; // 保存被删除的元素
// for (int j = i; j < L->length; j++) {
// L->data[j - 1] = L->data[j]; // 将元素前移
// }
// L->length--;
// return true;
// }

// int GetElem(SqList L, int i) {
// if (i < 1 || i > L->length) {
// printf("查找位序不合法！");
// return -1;
// }
// return L->data[i - 1];
// }
int main() {
SqList L;
int arr[10];
InitList(&L);
// ListInsert(L, 3, 3);
// int e = -1;
// if (ListDelete(L, 3, e)) {
// printf("已经删除第3个元素，删除元素为%d\n", e);
// } else {
// printf("位序i不合法，删除失败\n");
// }
return 0;
}