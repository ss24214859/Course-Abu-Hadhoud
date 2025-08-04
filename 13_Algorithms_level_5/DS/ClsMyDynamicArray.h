#pragma once
#include <iostream>
using namespace std;

template <class T>
class ClsMyDynamicArray
{
protected:
    int _Size;
    T* _TempArray;

    void Swap(T &Right, T &Left)
    {
        T Temp=Right;
        Right=Left;
        Left=Temp;
    }

public:
    T* _OriginalArray;

    ClsMyDynamicArray(int Size)
    {
        if(Size<0)
            _Size=0;
    
        _Size=Size;

        _OriginalArray= new T [_Size];
    }
    ~ClsMyDynamicArray()
    {
        delete[] _OriginalArray;
    }

    bool SetItem(int Index,T Value)
    {
        if(Index < _Size && (Index>=0))
        {
            _OriginalArray[Index]=Value;
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
            cout<<_OriginalArray[i]<<" ";
        }
        cout<<"\n";
    }


    void Resize(int NewSize)
    {
        if(NewSize<0)
        NewSize=0;

        _TempArray=new T[NewSize];
        
        if(NewSize<_Size)
        _Size=NewSize;

        for(int i=0; i<_Size;i++)
        {
            _TempArray[i]=_OriginalArray[i];
        }
        _Size=NewSize;

        delete[] _OriginalArray;
        _OriginalArray=_TempArray;
        
    }

    T GetItem(int Index)
    {
        return _OriginalArray[Index];
    }

    void Reverse()
    {
        for(int i=0; i<_Size/2; i++)
        {
            Swap(_OriginalArray[i],_OriginalArray[_Size-1-i]);
        }
    }
    
    void Clear()
    {
        _Size=0;
        delete[] _OriginalArray;
        _OriginalArray=new T[_Size];

    }
};