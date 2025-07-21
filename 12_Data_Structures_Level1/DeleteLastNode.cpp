#include <iostream>
using namespace std;

class Node 
{
public:
    int Number;
    Node * Next;
};

void InsertAtEnd(Node* &Head ,int NewNodeValue)
{
    Node* NewNode=new Node;
    NewNode->Number=NewNodeValue;
    NewNode->Next=NULL;

    if(Head==NULL)
    {
        Head=NewNode;
        return;
    }
    Node* LastNode=Head;
    while(LastNode->Next!=NULL)
    {
        LastNode=LastNode->Next;
    }
    LastNode->Next=NewNode;
    return;
}

void PrintNode(Node* Head)
{
    while(Head!=NULL)
    {
        cout<< Head->Number<<endl;

        Head = Head->Next;
    }
}


void DeleteLastNode(Node* &Head)
{
    Node* Prev=Head;
    Node* Current=Head;
    
    if(Head==NULL)
    return;

    if(Current->Next==NULL)
    {
        Head=Current->Next;
        delete Current;
        return;
    }

    while(Current!=NULL && Current->Next!=NULL)
    {
        Prev=Current;
        Current=Current->Next;
    }

    Prev->Next=Current->Next;
    delete Current;
    return;
}

int main()
{
    Node* Head=NULL;
    InsertAtEnd(Head,1);
    InsertAtEnd(Head,2);
    InsertAtEnd(Head,3);
    InsertAtEnd(Head,4);
    InsertAtEnd(Head,5);

    PrintNode(Head);
    cout<<"___________________"<<endl;
    DeleteLastNode(Head);
    DeleteLastNode(Head);
    DeleteLastNode(Head);

    PrintNode(Head);

}
