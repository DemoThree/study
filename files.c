#include<stdio.h>
#include<string.h>
#include<errno.h>
 
int main()
{
	FILE* pf= fopen("test.txt", "w+");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//输入一个字符
	fputc('a', pf);
	//用完关闭文件
	fclose(pf);
	pf = NULL;
 
	return 0;
}
