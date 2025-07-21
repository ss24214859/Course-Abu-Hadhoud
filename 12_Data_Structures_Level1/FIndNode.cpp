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

    Node* node1= Find(Head,6);
    Node* node2= Find(Head,5);

    if(node1!=NULL)
    cout<<"Node1 is Found :-)"<<endl;
    else
    cout<<"Node1 Not Found :-( "<<endl;

    if(node2!=NULL)
    cout<<"Node2 is Found :-)"<<endl;
    else
    cout<<"Node2 Not Found :-( "<<endl;

}
