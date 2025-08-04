#include <iostream>
#include "DS/ClsMyDynamicArray.h"
using namespace std;

int main()
{
    ClsMyDynamicArray <int> MyArray(5);

    MyArray.SetItem(0,10);
    MyArray.SetItem(1,20);
    MyArray.SetItem(2,30);
    MyArray.SetItem(3,40);
    MyArray.SetItem(4,50);

    cout<<"\nArray Size : "<<MyArray.Size()<<endl;
    cout<<"IsEmpty  :" << MyArray.IsEmpty()<<endl;
    cout<<"Array Items: "<<endl;
    MyArray.PrintList();

    cout<<"\n Item(2): "<<MyArray.GetItem(2)<<endl;

    MyArray.Reverse();
    cout<<"\nArray Items After Reverse: "<<endl;
    MyArray.PrintList();

    MyArray.Clear();
    cout<<"\nArray Items After Clear: "<<endl;
    MyArray.PrintList();
}