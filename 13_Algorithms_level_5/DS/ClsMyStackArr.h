#pragma once
#include <iostream>
#include "ClsMyQueueArr.h"

using namespace std;

template <class T>
class ClsMyStackArr : public ClsMyQueueArr <T>
{
public:
    void push(T Value)
    {
        
        ClsMyQueueArr<T>:: _Queue.InsertAtBeginning(Value);    // TO Use Varibale Or Methods in Base Class You Can Use This Way 
        //this->_Queue.InsertAtBeginning(Value);        // OR You Can This Way 

    }
    T Top()
    {
        return ClsMyQueueArr <T>::front();
    }
    T Bottom()
    {
        return ClsMyQueueArr <T>::back();
    }

};