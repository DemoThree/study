#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char *str[]={"gain","much","stronger","point"};
    char **pc[]={str+2,str,str+3,str+1};
    char ***ppc=pc;
    cout<<"*pc[2]---"<<*pc[2]<<"---"<<pc+2<<"pc+2|pc[2]"<< pc[2]<<endl;


    
    return 0;
}
