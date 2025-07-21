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

void DeleteNode(Node* &Head,int Value)
{
    Node* Current=Head;
    Node* Prev=Head;

    if(Current->Number==Value)
    {
        Head=Head->Next;
        delete Current; //to Free Memory
        return;
    }
    
    while(Current!=NULL&&Current->Number!=Value)
    {
        Prev=Current;
        Current=Current->Next;
    }

    if(Current==NULL)
        return;

    Prev->Next=Current->Next;
    delete Current;
    return;
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
    cout<<"___________________"<<endl;
    DeleteNode(Head,3);
    PrintNode(Head);

}
