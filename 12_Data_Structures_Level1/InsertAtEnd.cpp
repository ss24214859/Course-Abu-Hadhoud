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
Node* Find(Node* Head, int NodeValue)
{
    while(Head!=NULL)
    {
        if(Head->Number==NodeValue)
        return Head;

        Head=Head->Next;
    }
    return NULL;
}

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
void InsertAfter(Node* &PrevNode,int NewNodeValue)
{
    Node* NewNode= new Node;

    NewNode->Number=NewNodeValue;
    NewNode->Next=PrevNode->Next;

    PrevNode->Next=NewNode;
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
    PrintNode(Head);
    cout<<"---------------"<<endl;
    InsertAtEnd(Head,0);
    PrintNode(Head);
}