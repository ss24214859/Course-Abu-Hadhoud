//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include "DS/ClsDblLinkedList.h"

using namespace std;


int main()
{

    ClsDblLinkedList <int> MydblLinkedList;
    
    if(MydblLinkedList.IsEmpty())
    cout<<"Yes List Is Empty."<<endl;
    else
    cout<<"No List Is Not Empty."<<endl;

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);
   
    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();
    cout<<"\nNumber Of items In the Linked List = "<<MydblLinkedList.Size()<<endl;

    ClsDblLinkedList <int> ::Node* N1;
    N1=MydblLinkedList.GetNode(0);
    cout<<"N1 Value = "<<N1->Value<<endl;
}