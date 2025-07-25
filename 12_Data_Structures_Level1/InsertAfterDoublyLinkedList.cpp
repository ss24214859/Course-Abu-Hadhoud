#include <iostream>
using namespace std;

class Node 
{
public:
    int Number;
    Node * Next;
    Node * Prev;
};

void InsertAtBegining(Node * &Head , int Value)
{
    Node * NewNode = new Node;

    NewNode->Number = Value;
    NewNode->Next=Head;
    NewNode->Prev=NULL;

    if(Head!=NULL) // this mean if this is Not First Node In Linked List 
    Head->Prev=NewNode;

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
    NewNode->Prev=PrevNode;

    if(PrevNode->Next!=NULL)
    PrevNode->Next->Prev=NewNode;

    PrevNode->Next=NewNode;
}


void PrintNodeDetials(Node* Node)
{
    if(Node->Prev!=NULL)
    cout<<Node->Prev->Number;
    else
    cout<<"NULL";

    cout<<" <--> "<<Node->Number<<" <--> ";

    if(Node->Next!=NULL)
    cout<<Node->Next->Number;
    else
    cout<<"NULL";

    cout<<endl;


}

void PrintListDetials(Node* Head)
{
    while(Head!=NULL)
    {
        PrintNodeDetials(Head);
        Head=Head->Next;
    }
}

void PrintList(Node* Head)
{
    cout<<"Linked List Content: "<<endl;
    while(Head!=NULL)
    {
        cout<< Head->Number<<" <--> ";

        Head = Head->Next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node* Head=NULL;
    InsertAtBegining(Head,1);
    InsertAtBegining(Head,2);
    InsertAtBegining(Head,3);
    InsertAtBegining(Head,4);
    InsertAtBegining(Head,5);


    Node* node1= Find(Head,1);

    if(node1!=NULL)
    cout<<"Node1 is Found :-)"<<endl;
    else
    cout<<"Node1 Not Found :-( "<<endl;

    InsertAfter(node1,600);

    PrintList(Head);
    cout<<endl;
    PrintListDetials(Head);

}
