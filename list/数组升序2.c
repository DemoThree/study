#include<stdio.h>

void fun (int arr[],int j){
int temp=0;
for (int i = 0; i <j; i++)
{
    if (arr[i]==-1)

    {
        break;
        /* code */
    }
    
    for (int x=i+1; x<j;x++)
    {
    
     if(arr[x]<arr[i]){
        temp=arr[i];
        arr[i]=arr[x];
        arr[x]=temp;
     }
        /* code */
    }
}





}
int main(){
static int arr[30]={0},x=0,j=0;
for (int i = 0; i < 30; i++)
{
    /* code */
arr[i]=-1;
}

for (j = 0; j < 20; j++)
{
scanf("%d",&x);
if (x==-1)
{
    /* code */

    break;
}
arr[j]=x;
    /* code */
}
x=0;
for (; j <30; j++)
{
    scanf("%d",&x);
    if (x==-1)
{
    /* code */
    break;
}
arr[j]=x;

}








// fun(arr,j);
for (int i = 0; i < 30; i++)
{
    printf("%d",arr[i]);
}





}