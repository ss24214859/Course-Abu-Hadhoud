#include <iostream>
#include "../MyClasss/clsInputValidate.h"
#include "../MyClasss/clsDate.h"
#include "../MyClasss/clsPeriod.h"

int main()

{
    cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(9, 12, 2022), clsDate(8, 12, 2022), clsDate(31, 12, 2022)) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(9, 12, 2022), clsDate(31, 12, 2022), clsDate(8, 12, 2022))
         << endl;

    int x = clsInputValidate::ReadIntNumber("\nPlease Enter a Number:\n", "Invalid Number, Enter again:\n");
    cout << "x=" << x;

    int y = clsInputValidate::ReadIntNumberBetween(1, 5, "\nPlease Enter a Number between 1 and 5:\n", "Number is not within range, enter again:\n");
    cout << "y=" << y;

    double a = clsInputValidate::ReadDblNumber("\nPlease Enter a Double Number:\n", "Invalid Number, Enter again:\n");
    cout << "a=" << a;

    cout << "\nPlease Enter a Double Number between 1 and 5:\n";
    double b = clsInputValidate::ReadDblNumberBetween(1, 5, "\nPlease Enter a Double Number between 1 and 5:\n", "Number is not within range, enter again:\n");
    cout << "b=" << b;

    cout << endl
         << clsInputValidate::IsValideDate(clsDate(35, 12, 2022)) << endl;

    system("pause>0");

    return 0;
}