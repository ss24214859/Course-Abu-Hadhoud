#pragma once
#include <iostream>
using namespace std;

template <class T>
class ClsDblLinkedList
{

protected:    
    int  _Size=0;

public:
    class Node
    {
    public:
        T Value;
        Node *Prev;
        Node *Next;
    };

private:
    void _Swap(Node *&N1,Node *&N2)
    {
        Node *temp=N1;
        N1=N2;
        N2=temp;
    }
    
public:
    Node *Head=NULL;

    void InsertAtBeginning(T Value)
    {
        Node *NewNode = new Node;

        NewNode->Value = Value;
        NewNode->Next = Head;
        NewNode->Prev = NULL;

        if (Head != NULL) // this mean if this is Not First Node In Linked List
            Head->Prev = NewNode;

        Head = NewNode;
        _Size++;
    }

    Node *Find(T NodeValue)
    {
        Node *CurrentNode=Head;
        while (CurrentNode != NULL)
        {
            if (CurrentNode->Value == NodeValue)
                return CurrentNode;

            CurrentNode = CurrentNode->Next;
        }
        return NULL;
    }

    void InsertAfter(Node *&CurrentNode, T NewNodeValue)
    {
        Node *NewNode = new Node;

        NewNode->Value = NewNodeValue;
        NewNode->Next = CurrentNode->Next;
        NewNode->Prev = CurrentNode;

        if (CurrentNode->Next != NULL)
            NewNode->Next->Prev = NewNode;

        CurrentNode->Next = NewNode;
        _Size++;
    }

    void InsertAtEnd(T NewNodeValue)
    {
        Node *NewNode = new Node;
        NewNode->Value = NewNodeValue;
        NewNode->Next = NULL;
        NewNode->Prev = NULL;

        if (Head == NULL)
        {
            Head = NewNode;
            return;
        }

        Node *LastNode = Head;
        while (LastNode->Next != NULL)
        {
            LastNode = LastNode->Next;
        }
        LastNode->Next = NewNode;
        NewNode->Prev = LastNode;
        _Size++;
        return;
    }

    void DeleteNode(Node *NodeToDelete)
    {
        if (Head == NULL || NodeToDelete == NULL)
            return;

        if (Head == NodeToDelete)
            Head = Head->Next;

        if (NodeToDelete->Prev != NULL)
            NodeToDelete->Prev->Next = NodeToDelete->Next;

        if (NodeToDelete->Next != NULL)
            NodeToDelete->Next->Prev = NodeToDelete->Prev;

        delete NodeToDelete;
        _Size--;
    }

    void DeleteFirstNode()
    {
        if (Head == NULL)
            return;
        Node *FirstNode = Head;

        Head = Head->Next;

        if (Head != NULL)
            Head->Prev = NULL;

        delete FirstNode;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (Head == NULL)
            return;
        if (Head->Next == NULL)
        {
            delete Head;
            Head = NULL;
            _Size--;
            return;
        }

        Node *NodeBeforeLastNode = Head;

        while (NodeBeforeLastNode->Next->Next != NULL)
        {
            NodeBeforeLastNode = NodeBeforeLastNode->Next;
        }

        Node *Temp = NodeBeforeLastNode->Next;
        NodeBeforeLastNode->Next = NULL;
        delete Temp;
        _Size--;
    }



    void PrintList()
    {
        Node *CurrentNode=Head;
        cout << "Linked List Contenet: " << endl;
        while (CurrentNode != NULL)
        {
            cout << CurrentNode->Value << " ";

            CurrentNode = CurrentNode->Next;
        }
        cout<<endl;
    }

    int Size() { return _Size; }

    bool IsEmpty()
    {
        return _Size==0;
    }

    void Clear()
    {
        /*               --This is The Hard Way
        if(Head==NULL)
        return;

        while(Head->Next!=NULL)
        {
            Head=Head->Next;
            delete Head->Prev;
        }
        delete Head;
        Head=NULL;
        _Size*/ 

        // This is the Ture Way

        while(Size!=0)
        {
            DeleteFirstNode();
        }

    }

    void Reverse()
    {
        Node *Current=NULL;
        while(Head!=NULL)
        {
            Current=Head;
            Head=Head->Next;
            _Swap(Current->Next,Current->Prev);
        }
        Head=Current;
    }
};
