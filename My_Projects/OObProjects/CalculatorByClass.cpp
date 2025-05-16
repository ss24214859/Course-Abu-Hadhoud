#include <iostream>
using namespace std;

class clsCalculator
{

private:
    double _Result = 0;
    double _PreviousResult = 0;
    double _Number = 0;
    double _PreviousNumber = 0;

    enum _enOption
    {
        _Clear = 0,
        _Add = 1,
        _Sub = 2,
        _Mul = 3,
        _Div = 4
    };

    _enOption _Option = _enOption::_Clear;
    _enOption _PreviousOption = _enOption::_Clear;

    void GetPreviousValues()
    {
        _PreviousOption = _Option;
        _PreviousNumber = _Number;
        _PreviousResult = _Result;
    }
    double _SimpleCalculator(double Number1, double Number2, _enOption OpType)
    {
        switch (OpType)
        {
        case _enOption::_Add:
            return Number1 + Number2;
            break;
        case _enOption::_Sub:
            return Number1 - Number2;
            break;
        case _enOption::_Mul:
            return Number1 * Number2;
            break;
        default:
            return Number1 / Number2; // Div
            break;
        }
    };

public:
    void Clear()
    {
        GetPreviousValues();
        _Option = _enOption::_Clear;
        _Result = 0;
    }

    void Add(double Num)
    {
        GetPreviousValues();
        _Option = _enOption::_Add;
        _Number = Num;
        _Result = _SimpleCalculator(_Result, _Number, _Option);
    }

    void Subtract(double Num)
    {
        GetPreviousValues();
        _Option = _enOption::_Sub;
        _Number = Num;
        _Result = _SimpleCalculator(_Result, _Number, _Option);
    }

    void Divide(double Num)
    {
        GetPreviousValues();
        _Option = _enOption::_Div;
        _Number = (Num <= 0) ? 1 : Num;
        _Result = _SimpleCalculator(_Result, _Number, _Option);
    }

    void Multiply(double Num)
    {
        GetPreviousValues();
        _Option = _enOption::_Mul;
        _Number = Num;
        _Result = _SimpleCalculator(_Result, _Number, _Option);
    }

    double GetFinal_Result()
    {
        return _Result;
    }

    void Print_Result()
    {
        string OptionName[5] = {"Clear", "Adding", "Subtractring", "Multiplying", "Dividing"};
        if (_Option != _enOption::_Clear)
            cout << "Result After " << OptionName[_Option] << " " << _Number << " is " << _Result << endl;
        else
            cout << "Result After " << OptionName[_Option] << " is " << _Result << endl;
    }
    void CancelLastOperation()
    {
        _Option = _PreviousOption;
        _Number = _PreviousNumber;
        _Result = _PreviousResult;
    }
};

int main()
{

    clsCalculator Calculator1;
    Calculator1.Add(200);
    Calculator1.Print_Result();
    Calculator1.Subtract(50);
    Calculator1.Print_Result();
    Calculator1.Multiply(2);
    Calculator1.Print_Result();
    Calculator1.Divide(3);
    Calculator1.Print_Result();
    Calculator1.Clear();
    Calculator1.Print_Result();
    Calculator1.CancelLastOperation();
    Calculator1.Print_Result();
    Calculator1.CancelLastOperation();
    Calculator1.Print_Result();
}