// 包含头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 将存储数据类型重定义方便修改存储数据的类型
// SL(动态顺序表SeqList的缩写) DataType(数据类型)
typedef int SLDataType;

// 动态顺序表
typedef struct SeqList
{
	SLDataType *list; // 动态开辟数据存储数据元素
	int size;		  // 存储的数据个数
	int capacity;	  // 存储空间大小
} SeqList;

// 打印
void SeqListPrint(SeqList *psl);
// 初始化
void SeqListInit(SeqList *psl);
// 检查空间大小是否已满，若已满则扩容
void SeqListCheckCapacity(SeqList *psl);
// 顺序表销毁
void SeqListDestroy(SeqList *psl);

// 尾插
void SeqListPushBack(SeqList *psl, SLDataType x);
// 尾删
void SeqListPopBack(SeqList *psl);
// 头插
void SeqListPushFront(SeqList *psl, SLDataType x);
// 头删
void SeqListPopFront(SeqList *psl);

// 数据查找
int SeqListFind(SeqList *psl, SLDataType x);
// 数据插入
void SeqListInsert(SeqList *psl, size_t pos, SLDataType x);
// 数据删除
void SeqListErase(SeqList *psl, size_t pos);
// 数据修改
void SeqListModify(SeqList *psl, size_t pos, SLDataType x);

int main()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	return 0;
}
// 打印顺序表1
void SeqListPrint(SeqList *psl)
{
	// 对空指针进行断言，显示出错位置
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->list[i]);
	}
	printf("\n");
}
// 动态顺序表的初始化
void SeqListInit(SeqList *psl)
{
	assert(psl);
	psl->list = NULL;
	psl->size = 0;
	psl->capacity = 0;
}
// 顺序表销毁
void SeqListDestroy(SeqList *psl)
{
	assert(psl);
	free(psl->list);
	psl->list = NULL;
	psl->capacity = psl->size = 0;
}
// 顺序表空间扩容
void SeqListCheckCapacity(SeqList *psl)
{
	assert(psl);
	// 当数据个数与存储空间相等时，数组已满
	// 如果数组满了，使用realloc进行扩容
	if (psl->size == psl->capacity)
	{
		// 当capacity为0时为其赋值为4，若不为0则进行倍增
		size_t NewCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		// 将当前的空间翻倍扩容
		SLDataType *tmp = (SLDataType *)realloc(psl->list, sizeof(SLDataType) * NewCapacity);
		// realloc扩容可能失败，需要对其进行检查
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1); // 终止程序
		}
		else
		{
			psl->list = tmp;
			psl->capacity = NewCapacity;
		}
	}
}
// 顺序表尾插
void SeqListPushBack(SeqList *psl, SLDataType x)
{
	assert(psl);

	// 检查顺序表是否已满，若满则扩容
	SeqListCheckCapacity(psl);

	// 在表尾部插入数据
	psl->list[psl->size] = x;
	psl->size++;
}
