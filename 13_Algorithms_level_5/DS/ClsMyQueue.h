#pragma once
#include <iostream>
#include "ClsDblLinkedList.h"

template <class T>
class ClsMyQueue
{
protected:
    ClsDblLinkedList <T> _Queue;
    
public:
    void push(T Value)
    {
        _Queue.InsertAtEnd(Value);
    }
    void pop()
    {
        _Queue.DeleteFirstNode();
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

    void PrintList()
    {
        _Queue.PrintList();
    }

};