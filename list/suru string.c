#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[100],str2[100];
    scanf("%s",str);
    printf("%s",str);
    for (int i = 0; i < strlen(str); i++)
    {
        
        
            /* code */
        
        
       str2[i%6+2>=6?i+2-6:i+2]=str[i];

        /* code */
    }
    printf("%s",str2);
}
