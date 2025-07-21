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
        cout<< Head->Number<<" ";

        Head = Head->Next;
    }
    cout<<endl;
}

void DeleteFirstNode(Node* &Head)
{
    Node* FirstNode=Head;

    if(FirstNode!=NULL)
    {
        Head=FirstNode->Next;
        delete FirstNode; //to Free Memory
        return;
    }
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
    DeleteFirstNode(Head);
    DeleteFirstNode(Head);
    DeleteFirstNode(Head);

    PrintNode(Head);

}
