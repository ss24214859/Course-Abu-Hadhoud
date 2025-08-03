#include <iostream>
#include "DS/ClsMyQueue.h"
using namespace std;

int main()
{
    ClsMyQueue <int> MyQueue;
    MyQueue.push(1);
    MyQueue.push(2);
    MyQueue.push(3);
    MyQueue.push(4);

    MyQueue.PrintList();

    cout<<"Queue size = "<<MyQueue.size()<<endl;
    cout<<"Queue front= "<<MyQueue.front()<<endl;
    cout<<"Queue back = "<<MyQueue.back()<<endl;

    cout<<"\nAfter use Pop:"<<endl;
    MyQueue.pop();
    MyQueue.PrintList();

}