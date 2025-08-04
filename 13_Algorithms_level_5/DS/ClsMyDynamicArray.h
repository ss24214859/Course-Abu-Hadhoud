#pragma once
#include <iostream>
using namespace std;

template <class T>
class ClsMyDynamicArray
{
protected:
    int _Size;

public:
    T* OriginalArray;

    ClsMyDynamicArray(int Size)
    {
        if(Size<0)
            _Size=0;
    
        _Size=Size;

        OriginalArray= new T [_Size];
    }
    ~ClsMyDynamicArray()
    {
        delete[] OriginalArray;
    }

    bool SetItem(int Index,T Value)
    {
        if(Index < _Size && (Index>=0))
        {
            OriginalArray[Index]=Value;
            return true;
        }
        else
        return false;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return _Size==0;
    }

    void PrintList()
    {
        for(int i=0;i<_Size;i++)
        {
            cout<<OriginalArray[i]<<" ";
        }
        cout<<"\n";
    }
    
    
};