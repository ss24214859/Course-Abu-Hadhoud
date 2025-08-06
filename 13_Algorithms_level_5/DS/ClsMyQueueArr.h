#pragma once
#include <iostream>
#include "ClsMyDynamicArray.h"
using namespace std;

template <class T>
class ClsMyQueueArr
{
protected:
    
    
public:
    ClsMyDynamicArray<T> _Queue;

    void push(T Value)
    {
        _Queue.InsertAtEnd(Value);
    }
    void pop()
    {
        _Queue.DeleteFirstItem();
    }

    void DeleteItem(int Index)
    {
        _Queue.DeleteItemAt(Index);
    }

    int size()
    {
        return _Queue.Size();
    }

    bool IsEmpty()
    {
        return _Queue.IsEmpty();
    }

    T front()
    {
        return _Queue.GetItem(0);
    }

    T back()
    {
        return _Queue.GetItem(size()-1);
    }

    T GetItem(int Index)
    {
        return _Queue.GetItem(Index);
    }

    
    void Reverse()
    {
        _Queue.Reverse();
    }
    
    bool UpdateItem(int Index,T Value)
    {
        return _Queue.SetItem(Index,Value);
    }
    
    void InsertAfter(int Index, T Value)
    {
        _Queue.InsertAfter(Index, Value);
    }
    
    void InsertAtFront(T Value)
    {
        _Queue.InsertAtBeginning(Value);
    }
    
    void InsertAtBack(T Value)
    {
        _Queue.InsertAtEnd(Value);
    }
    
    void Clear()
    {
        _Queue.Clear();
    }
    
    void Print()
    {
        _Queue.PrintList();
    }

};