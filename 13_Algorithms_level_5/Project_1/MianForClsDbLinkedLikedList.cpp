//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include "DS/ClsDblLinkedList.h"

using namespace std;


int main()
{

    ClsDblLinkedList <int> MydblLinkedList;

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);
   
    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();
    cout<<"\nNumber Of items In the Linked List = "<<MydblLinkedList.Size()<<endl;

       MydblLinkedList.DeleteFirstNode();
    cout << "\nAfter Deleting First Node:\n";
    MydblLinkedList.PrintList();
    cout<<"\nNumber Of items In the Linked List = "<<MydblLinkedList.Size()<<endl;

    cout << "\nAfter Deleting Last Node:\n";
    MydblLinkedList.DeleteLastNode();
    MydblLinkedList.PrintList();
    cout<<"\nNumber Of items In the Linked List = "<<MydblLinkedList.Size()<<endl;

}