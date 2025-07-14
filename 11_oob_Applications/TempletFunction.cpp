#include <iostream>
using namespace std;

template <typename T> 
T Add(T a, T b)
{
    return a + b;
}

int main()
{
    int intResult = Add(5, 10);
    double doubleResult = Add(5.5, 10.2);
    string strResult = Add(string("Hello, "), string("World!")  ) ; 

    cout << "Integer Addition: " << intResult << endl;
    cout << "Double Addition: " << doubleResult << endl;
    cout << "String Concatenation: " << strResult << endl;
    cout <<"-----------------------------------------------------\n";
    cout << "Integer Addition: " << Add<int>(5,10) << endl;
    cout << "Double Addition: " << Add<double>(5.5, 10.2)<< endl;
    cout << "String Concatenation: " << Add<string>("Hello","World") << endl;

    return 0;

}