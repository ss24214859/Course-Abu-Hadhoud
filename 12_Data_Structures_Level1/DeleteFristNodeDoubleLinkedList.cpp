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

    if(Head!=NULL)    // this mean if this is Not First Node In Linked List 
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

void InsertAtEnd(Node* &Head ,int NewNodeValue)
{
    Node* NewNode=new Node;
    NewNode->Number=NewNodeValue;
    NewNode->Next=NULL;
    NewNode->Prev=NULL;


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
    NewNode->Prev=LastNode;
    return;
}

 void DeleteNode(Node* &Head , Node* NodeToDelete)
 {
    if(Head==NULL||NodeToDelete==NULL)
    return;

    if(Head==NodeToDelete)
    Head=Head->Next;
    
    if(NodeToDelete->Prev!=NULL)
    NodeToDelete->Prev->Next=NodeToDelete->Next;
    
    if(NodeToDelete->Next!=NULL)
    NodeToDelete->Next->Prev=NodeToDelete->Prev;


    delete NodeToDelete;
 }

 void DeleteFirstNode(Node * &Head)
 {
    if(Head==NULL)
    return;
    Node* FirstNode=Head;

    Head=Head->Next;

    if(Head!=NULL)
    Head->Prev=NULL;

    delete FirstNode;
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
    cout<<"__________________________________\n\n";
    cout<<"Prev <--> Value <--> Next "<<endl;
    cout<<"__________________________________\n";
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

    PrintList(Head);
    cout<<"___________________"<<endl;
    Node* NodeToDelete= Find(Head,5);
    DeleteFirstNode(Head);
    PrintList(Head);
    PrintListDetials(Head);

}