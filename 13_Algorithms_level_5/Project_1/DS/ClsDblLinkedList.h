#pragma once
#include <iostream>
using namespace std;

template <class T>
class ClsDblLinkedList
{
public:
    class Node
    {
    public:
        T Value;
        Node *Prev;
        Node *Next;
    };

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
    }

    void DeleteLastNode()
    {
        if (Head == NULL)
            return;
        if (Head->Next == NULL)
        {
            delete Head;
            Head = NULL;
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
    }


};