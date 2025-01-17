#include <iostream> 
using namespace std; 

int main() 
{ 
    int *p[4]; //p是一个指针数组，每一个指针都指向一个int型数据 
    int a=1,b=2,c=3,d=4;
    int i;
    p[0]=&a;
    p[1]=&b;
    p[2]=&c;
    p[3]=&d;
    int (*q)[4],(*z)[4];//q是一个指针，指向int[4]数组 
    //q[0]=&a;//error   q是指向int[4]数组的指针，而&a是一个int型指针,所以不能赋值 
    int aa[][4]={{0,1,2,5},{0,3,4,6},{0,5,6,7},{0,5,7,8}};

    q=aa;
    cout << "p的值:" << p << endl; //注意，p不等于p[0] 
    cout << "p[0]的值:" << p[0] << "  a的地址:" << &a << endl;

    cout << "p[0]地址保存的值:" << *(p[0]) << "  a的值:" << a << endl;
    cout << "p[1]地址保存的值:" << *(p[1]) << "  b的值:" << b << endl;
    cout << "p[2]地址保存的值:" << *(p[2]) << "  c的值:" << c << endl;
    cout << "p[3]地址保存的值:" << *(p[3]) << "  d的值:" << d << endl;


    cout << "q的值:" << q << "  aa的地址:" << &aa << endl;

    cout << "q[i]的地址:" << endl;
    for(i = 0; i < 4; ++i)
    cout <<aa[i]<<"|aa--q|"<< q[i] << endl;//q[0] 与 q的值相同 

    cout << "q指向int[4]的所有值:" << endl;
    for(i = 0; i < 4; i++)
    cout << q[1][i] << ' ';
    cout << endl;

    int zz[4]={0,1,2,5};

    z=&zz;
    cout << "z的值:" << z << "  zz的地址:" << &zz << endl;

    cout << "z[i]的地址:" << endl;
    for(i = 0; i < 4; ++i)
    cout <<zz[i]<<"|zz[i]--z|"<< z << endl;//q[0] 与 q的值相同 

    cout << "z指向int[4]的所有值:" << endl;
    for(i = 0; i < 4; i++)
    cout << z[i] << ' ';
    cout << endl;
    //cout<<*(p[0])<<*(q[0])<<endl;
    return 0; 
} 
