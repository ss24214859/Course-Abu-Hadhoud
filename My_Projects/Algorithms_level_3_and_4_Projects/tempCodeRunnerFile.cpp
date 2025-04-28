#include <iostream>
#include <locale> // هذه المكتبة ضرورية
using namespace std;

int main()
{
    setlocale(LC_ALL, "ar_EG.UTF-8"); // تعيين اللغة للعربية
    cout << "السلام عليكم!" << endl;  // ستعمل إذا كان المحرر يدعم UTF-8
    system("pause>0");
    return 0;
}