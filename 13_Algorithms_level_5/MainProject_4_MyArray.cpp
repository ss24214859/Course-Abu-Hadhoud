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

    int Index= MyArray.Find(20);
    if(Index==-1)
        cout<<"\nItem Was Not Found :-("<<endl;
    else
        cout<<"\n20 Is Found at Index : "<<Index<<endl;

    MyArray.DeleteItem(20);
    cout<<"\nArray Items After Delete Item : "<<endl;
    cout<<"Array Size : "<<MyArray.Size()<<endl;
    MyArray.PrintList();

}