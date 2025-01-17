#include <stdio.h>
float *search(float(*point)[4],int n){
    for(int i=0;i<4;i++){
        if (n==i+1){
return point[i];
        }
        
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    static float score[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    float* searchs(float(*point)[4],int n),*p;
    
    p=search(score,2);
    for (int i = 0; i < 4; i++)
    {
        /* code */
        printf("%5.2f\t",*(p+i));
    }
    
    return 0;
}
