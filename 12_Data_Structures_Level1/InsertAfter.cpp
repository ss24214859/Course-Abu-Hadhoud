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
    InsertAtBegining(Head,4);
    InsertAtBegining(Head,5);

    PrintNode(Head);

    Node* node1= Find(Head,3);

    if(node1!=NULL)
    cout<<"Node1 is Found :-)"<<endl;
    else
    cout<<"Node1 Not Found :-( "<<endl;

    InsertAfter(node1,600);

    PrintNode(Head);

    


}
