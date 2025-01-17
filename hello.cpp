// Created on iPad.
// 5. 编写一个程序，要求用户（按任意次序）输入 1~16 的所有整数，
//然后用 4×4 矩阵的形式将它们显示出来，再计算出每行、每列和每条对角线上的和：
// Enter the numbers from 1 to 16 in any order:
// Row sums: 34 34 34 34
// Column sums: 34 34 34 34
// Diagonal sums: 34 34
#include <stdio.h>

int main() {

int arr[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},Row[4]={0},Column[4]={0},j=0;
printf("%d|%d\n",sizeof(arr),Row[0]);


for (int i=0;i<=sizeof(arr)/4;i++){

if(i%4==0&&i!=0){
printf("\tColumn sums:%-2d|%-2d|%-2d|%-2d|Row->%-2d|%-2d\n",Column[0],Column[1],Column[2],Column[3],Row[j-1],i/4);
j=i/4;
}

Row[j]+=arr[i];

Column[i%4]+=arr[i];
printf("%-3d->Row:%d+",arr[i],Row[j-1]);
}
      return 0;
}