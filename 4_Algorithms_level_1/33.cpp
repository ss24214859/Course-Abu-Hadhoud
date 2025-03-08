#include<iostream>
#include<string>
#include<cmath>
using namespace std;



float ReadNumberPersent(string massage)
{
    float number;
    do
    {
    cout<<massage<<endl;
    cin>>number;
    }while(number<0 || number>100);
    return number;
}

char ChackMark(float Number)
{
if (Number>=50)
{
 return 'E';
 
}
else if (Number>=60)
{
 return 'D';
 
}
else if (Number>=70)
{
 return 'C';
 
}
else if (Number>=80)
{
 return 'B';
 
}
else if (Number>=90&&Number<=100)
{
 return 'A';
 
}
else 
{
 return 'F';
 
}


}


void printresult(char Result )
{
    cout<<Result<<endl;
}
int main()
{

printresult(ChackMark(ReadNumberPersent("Enter Your Persent Mark ? ")));

}