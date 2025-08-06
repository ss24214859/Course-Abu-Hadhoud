#pragma once
#include <iostream>
#include "ClsMyStackArr.h"
using namespace std;

class ClsMyString
{
private:
    string _Value="";
    ClsMyStackArr <string> _Undo;
    ClsMyStackArr <string> _Redo;
public:
    void SetValue(string Value)
    {
        if(!_Redo.IsEmpty())
            _Redo.Clear();
            
        _Undo.push(_Value);
        _Value=Value;
    }
    string GetValue()
    {
        return _Value;
    }

    void Undo()
    {
        if(!_Undo.IsEmpty())
        {
            _Redo.push(_Value);
            _Value=_Undo.Top();
            _Undo.pop();
        }
    }

    void Redo()
    {
        if(!_Redo.IsEmpty())
        {   
            _Undo.push(_Value);
            _Value=_Redo.Top();
            _Redo.pop();
        }
    }
    
    
    
};
