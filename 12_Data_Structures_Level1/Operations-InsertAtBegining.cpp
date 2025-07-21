#include <iostream>
using namespace std;

class Node 
{
public:
    int Number;
    Node * Next;
};

void InsertAtBegining(Node * &Head , int Value)
{
    Node * NewNode = new Node;

    NewNode->Number = Value;
    NewNode->Next=Head;

    Head = NewNode;

}

void PrintNode(Node* Head)
{
    while(Head!=NULL)
    {
        cout<< Head->Number<<endl;

        Head = Head->Next;
    }
}

int main()
{
    Node* Head=NULL;
    InsertAtBegining(Head,1);
    InsertAtBegining(Head,2);
    InsertAtBegining(Head,3);
    InsertAtBegining(Head,4);
    InsertAtBegining(Head,5);

    PrintNode(Head);
}
