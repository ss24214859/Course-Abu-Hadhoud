#pragma once
#include <iostream>
#include "ClsDblLinkedList.h"

template <class T>
class ClsMyDynamicArray : public ClsDblLinkedList<T>
{


public:
    ClsMyDynamicArray(int size)
    {
        T EmptyValue;
        while(size!=this->_Size)
        {
            this->InsertAtEnd(EmptyValue);
        }
    }

    void SetItem(int Index,T Value)
    {
        this->UpdateItem(Index,Value);
    }
};