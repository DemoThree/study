#include <iostream>
using namespace std;
struct Node{
    int data;
   struct Node* next;
}Node;
int main(int argc, char const *argv[])
{
 struct Node* node=(struct Node*)malloc(sizeof(Node));

 struct Node* head=node; 
 cout<<node<<"========"<<head<<endl;
 cout<<&head<<endl;
    /* code */
    return 0;
}
