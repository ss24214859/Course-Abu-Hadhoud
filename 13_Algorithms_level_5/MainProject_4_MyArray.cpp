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

    MyArray.InsertAt(3,800);
    cout<<"\nArray Items After Insert 800 At 3 : "<<endl;
    cout<<"Array Size : "<<MyArray.Size()<<endl;
    MyArray.PrintList();

}