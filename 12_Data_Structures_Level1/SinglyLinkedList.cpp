#include <iostream>
using namespace std;

class Node 
{
public:
    int Number;
    Node * Next;
};

int main()
{
    Node* Head=NULL;
    Node* Node1=new Node;
    Node* Node2=new Node;
    Node* Node3=new Node;
    //---------------------
    Node1->Number=1;
    Node2->Number=2;
    Node3->Number=3;

    Node1->Next=Node2;
    Node2->Next=Node3;
    Node3->Next=NULL;
    //---------------------
    Head=Node1;
    // Bug False Alogrthim is while(Head->Next != NULL) Output 1 2 . 
    while(Head!=NULL) // this is true to output All Nods 1 2 3 .
    {
        cout<<Head->Number<<endl;
        Head=Head->Next;
    }


}
