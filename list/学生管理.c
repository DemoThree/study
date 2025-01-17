//fscanf的案例示范
//通过读取格式化文件中的内容到程序中,文件内容为学生成绩的信息。
#include<stdio.h>
#define SIZE 20

typedef struct Stu
{
	char name[SIZE];
	int age;
	float score;
}Student;

void print_struct(Student* temp)
{
	for (int i = 0; i < 3; i++)
	{	   /* code */
			printf("%s %d %.2f\n",temp[i].name,temp[i].age,temp[i].score);
	}
}
int main()
{
	Student stu[3] = { 0 };
	//打开文件
	FILE* pf = fopen("结构体属组fwrite.txt","r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	  //exit(EXIT_FAILURE);包含在stdlib.h头文件中
	}

	//读文c

    for (int i = 0; i < 3; i++)
	{
    fscanf(pf,"%s%d%f",stu[i].name,&stu[i].age,&stu[i].score);
		/* code */
	}
	
   print_struct(stu);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

