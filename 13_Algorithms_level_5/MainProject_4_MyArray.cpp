#include <iostream>
#include "DS/ClsMyDynamicArray.h"
using namespace std;

int main()
{
    ClsMyDynamicArray <int> MyArray(5);

    MyArray.SetItem(0,5);
    MyArray.SetItem(1,10);
    MyArray.SetItem(2,50);

    cout<<"\nArray Size : "<<MyArray.Size()<<endl;
    cout<<"IsEmpty  :" << MyArray.IsEmpty()<<endl;
    cout<<"Array Items: "<<endl;
    MyArray.PrintList();


}