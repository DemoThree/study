#include<stdio.h>
int fun(int i){
  int arr[6]={0},z=0,j=0,i2=0;
  for (int y = 0; y < 6; y++)
  {
    arr[y]=-1;
    /* code */
  }
  
  
    i2=i*i;
while (i>0){
        arr[j]=i%10;
        i/=10;
        j++;
    }

while(i2>0){

 if (arr[z]==-1)
  {
    return 1;
  }

if (i2%10==arr[z])
{
  
  i2=i2/10;
 
  z++;
}else{
return 0;
}
}
return 0;
}
int main(int argc, char const *argv[])
{
   for ( int i = 1; i < 100; i++)
   {
    if (fun(i))
   {
    printf("i:%d-%d\n",i,i*i);
    /* code */
   }
   }
    return 0;
}
