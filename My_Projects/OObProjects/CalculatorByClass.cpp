#include <iostream>
using namespace std;

class clsCalculator
{

private:
    double _Result = 0;
    double _PreviousResult = 0;
    double _Number = 0;

    string _OperationName = "Clear";

    void GetPreviousValues()
    {
        _PreviousResult = _Result;
    }

public:
    void Clear()
    {
        GetPreviousValues();
        _OperationName = "Clear";
        _Result = 0;
    }

    void Add(double Num)
    {

        GetPreviousValues();
        _OperationName = "Adding";
        _Number = Num;
        _Result += Num;
    }

    void Subtract(double Num)
    {
        GetPreviousValues();
        _OperationName = "Subtracting";
        _Number = Num;
        _Result -= Num;
    }

    void Divide(double Num)
    {
        Num = (Num == 0) ? 1 : Num;
        GetPreviousValues();
        _OperationName = "Dividing";
        _Number = Num;
        _Result /= Num;
    }

    void Multiply(double Num)
    {
        GetPreviousValues();
        _OperationName = "Multiplying";
        _Number = Num;
        _Result *= Num;
    }

    double GetFinal_Result()
    {
        return _Result;
    }

    void Print_Result()
    {
        if (_OperationName == "Clear" || _OperationName == "Canceling Last Operarion")
            cout << "Result After " << _OperationName << " is " << _Result << endl;
        else
            cout << "Result After " << _OperationName << " " << _Number << " is " << _Result << endl;
    }
    void CancelLastOperation()
    {
        _Result = _PreviousResult;
        _Number = 0;
        _OperationName = "Canceling Last Operarion";
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
}