#pragma once
#include <iostream>
#include "ClsDblLinkedList.h"

using namespace std;

template <class T>
class ClsMyStack
{
protected:
    ClsDblLinkedList <T> _Stack;
public:
    void push(T Value)
    {
        _Stack.InsertAtBeginning(Value);
    }
    void pop()
    {
        _Stack.DeleteFirstNode();
    }
    int Size()
    {
        return _Stack.Size();
    }
    T Top()
    {
        return _Stack.GetItem(0);
    }
    T Bottom()
    {
        return _Stack.GetItem(Size()-1);
    }

    T GetItem(int Index)
    {
        return _Stack.GetItem(Index);
    }


    void DeleteItem(int Index)
    {
        _Stack.DeleteNode(Index);
    }

    bool IsEmpty()
    {
        return _Stack.IsEmpty();
    }

    void Reverse()
    {
        _Stack.Reverse();
    }
    
    bool UpdateItem(int Index,T Value)
    {
        return _Stack.UpdateItem(Index,Value);
    }
    
    void InsertAfter(int Index, T Value)
    {
        _Stack.InsertAfter(Index, Value);
    }
    
    void InsertAtTop(T Value)
    {
        _Stack.InsertAtBeginning(Value);
    }
    
    void InsertAtBottom(T Value)
    {
        _Stack.InsertAtEnd(Value);
    }
    
    void Clear()
    {
        _Stack.Clear();
    }
    
    void Print()
    {
        _Stack.Print();
    }
};