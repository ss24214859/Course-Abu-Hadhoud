#include <iostream>
using namespace std;

template <class T>
class Claculator
{
private: 
    T _Num1 , _Num2;
public:
    Claculator(T Num1 , T Num2)
    {
        _Num1 = Num1;
        _Num2 = Num2;
    }
    
    T Add()
    {
        return _Num1 + _Num2;
    }
    T Substract()
    {
        return _Num1 - _Num2;
    }
    T Multiply()
    {
        return _Num1 * _Num2;
    }
    T Divide()
    {
        if (_Num2 == 0)
        {
            return 0;  // Handle division by zero
        }
        return _Num1 / _Num2;
    }

    void PrintAllResults()
    {
        cout << "Number : " << _Num1 <<" and Number " << _Num2 <<endl;
        cout << _Num1 << " + " << _Num2 << " = " << Add() << endl;
        cout << _Num1 << " - " << _Num2 << " = " << Substract( ) << endl;
        cout << _Num1 << " * " << _Num2 << " = " << Multiply() << endl;
        cout << _Num1 << " / " << _Num2 << " = " << Divide() << endl;
        cout << "-----------------------------------------------------\n";
    }
};
int main()
{
    cout <<"\nInt Claculator\n";
    cout <<"-----------------------------------------------------\n";
    Claculator<int> intCalc(10, 5);
    intCalc.PrintAllResults();

    cout <<"\nFloat Claculator\n";
    cout <<"-----------------------------------------------------\n";
    Claculator<float> floatCalc(10.5, 2.5);
    floatCalc.PrintAllResults();


    return 0;

}