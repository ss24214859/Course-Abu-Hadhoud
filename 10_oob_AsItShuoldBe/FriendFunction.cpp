
// ProgrammingAdvices.com
// Mohammed Abu-Hadhoud
#include <iostream>
using namespace std;

class clsA
{
private:
    int _Var1;

protected:
    int _Var3;

public:
    int Var2;

    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
        _Var3 = 30;
    }

    friend int MySum(clsA A1); // friend function
    friend class clsB;         // friend class
};

// this function is normal function and not a member of any class
int MySum(clsA A1)
{
    return A1._Var1 + A1.Var2 + A1._Var3;
}

// int Fun2(clsA A1)
//{
//     return A1._Var1 + A1.Var2 + A1._Var3;
// }

class clsB
{

public:
    int sum(clsA A)
    {
        return A.Var2 + A._Var1 + A._Var3;
    }
};
int main()
{
    clsA A1;
    clsB B1;
    cout << MySum(A1) << endl;
    cout << B1.sum(A1) << endl;
    system("pause>0");

    return 0;
};