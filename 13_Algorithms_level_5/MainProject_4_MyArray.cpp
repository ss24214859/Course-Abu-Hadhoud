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

    MyArray.InsertAtBeginning(900);
    cout<<"\nArray Items After Insert 900 At Beginning : "<<endl;
    cout<<"Array Size : "<<MyArray.Size()<<endl;
    MyArray.PrintList();
    
    MyArray.InsertBefore(0,500);
    cout<<"\nArray Items After Insert 500 Before 2 : "<<endl;
    cout<<"Array Size : "<<MyArray.Size()<<endl;
    MyArray.PrintList();

    MyArray.InsertAfter(6,800);
    cout<<"\nArray Items After Insert 800 After 2 : "<<endl;
    cout<<"Array Size : "<<MyArray.Size()<<endl;
    MyArray.PrintList();

     MyArray.InsertAtEnd(700);
    cout<<"\nArray Items After Insert 700 At End : "<<endl;
    cout<<"Array Size : "<<MyArray.Size()<<endl;
    MyArray.PrintList();

}