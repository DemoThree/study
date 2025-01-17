#include <stdio.h>
int find(long a,long b){
long num=a*b,i=0;
int arr[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
if (a==0||b==0)
{
    return 0;
    /* code */
}

while (a>0)
{
    if (i==10)
    {return 0;
        /* code */
    }
    arr[i]=a%10;
    a=a/10;
    i++;
    /* code */
}
while (b>0)
{
    if (i==10)
    {return 0;
        /* code */
    }
    arr[i]=b%10;
    b=b/10;
    i++;
    /* code */
}
while (num>0)
{
    if (i==10)
    {return 0;
        /* code */
    }
    arr[i]=num%10;
    num=num/10;
    i++;
    /* code */
}
if (i<10)
{
 return 0;   /* code */
}

for (int j = 0; j < 10; j++)
{  
    for (int n = 1; n < 10; n++)
    {
        if (arr[j]==arr[n]&&j!=n)
        {
            /* code */
            return 0;
        }
        
        /* code */
    }
    /* code */
}


return 1;
}


int main(int argc, char const *argv[])
{
int total=0;
for (long i = 0; i < 100; i++)
{
    for (long j = 100; j < 10000; j++)
    {
        if (i>j)
        {
            continue;  
        }
        
    if (find(i,j))
    {
        total++;
        printf("%ld-%ld-%ld\n",i,j,i*j);
        /* code */
    }
    
        /* code */
    }
    
    /* code */
}
printf("total:%d",total);
    /* code */
    return 0;
}
