#pragma once
#include <iostream>
#include "ClsMyQueue.h"

using namespace std;

template <class T>
class ClsMyStack : public ClsMyQueue <T>
{
public:
    void push(T Value)
    {
        
        ClsMyQueue<T>:: _Queue.InsertAtBeginning(Value);    // TO Use Varibale Or Methods in Base Class You Can Use This Way 
        //this->_Queue.InsertAtBeginning(Value);        // OR You Can This Way 

    }
    T Top()
    {
        return ClsMyQueue <T>::front();
    }
    T Bottom()
    {
        return ClsMyQueue <T>::back();
    }

};