#include <stdio.h>
#include<stdlib.h>//缺stdlib.h
#define N 10
struct stud_type 
{char name[10];int num;float score;};
int main()
{
int i;struct stud_type stu[N];float s=0;FILE*fp;//改int
if((fp=fopen("student.txt", "r"))==NULL)//改if // 3.w->r
{printf("Cannotopen\nPressanykeytoexit!");
getchar();exit(1);//gai 0->1
}
for(i=0;i<N;i++){
fscanf(fp,"%s%d%f",&stu[i].name,&stu[i].num,&stu[i].score);
s=s+stu[i].score;//改stu[i].score
}
for(i=0;i<N;i++)printf("%8s%5d%8.2f\n",stu[i].name,stu[i].num,stu[i].score);
printf("平均分 =%8.2f\n",s/N);
fclose(fp);//改（fp）
}