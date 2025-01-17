#include <stdio.h>
int* fun(int arr[],int arr2[]){
    static  int arr3[31]={-1},j=0;
      for (int  i = 0; i < 20; i++)
      {
        if (arr[i]<arr2[j])
        {
          arr3[i]=arr[j]; 
        }else{
          if(arr2[j]!=-1){
          arr3[i]=arr2[j];
          j++;
          }
        }
        
        
      }
      
      return arr3;


}
int main(int argc, char const *argv[])
{   
   int arr[20]={-1},i,j=0;
   int arr2[10]={-1};
   int *arr3;
   while (i!=-1&&j<19)
   {
    
    scanf("%d",&i);
    if (i!=-1){
    arr[j]=i;
    j++;
   }
    
   }
   i=j=0;
   while (i!=-1&&j<10)
   {
    /* code */
    scanf("%i",&i);
    if (i!=-1)
    {
        arr2[j]=i;
        j++;
        /* code */
    }
    
   }
   
  arr3=fun(arr,arr2);
   
   for (int  i = 0; i <sizeof(arr)/sizeof(arr[0]); i++)
   {
    /* code */
    printf("%d",arr3[i]);
   }
   
   

    return 0;
}
