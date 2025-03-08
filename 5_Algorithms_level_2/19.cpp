#include <iostream>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string massge)
{
    int num=0;
    do
    {
        cout<<massge;
        cin>>num;
    }while(num<1);
    return num;
}

int RandomNumber(int From,int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
int main()
{
    srand((unsigned)time(NULL));
    int From=ReadPositiveNumber("Random Number From ? ");
    int To=ReadPositiveNumber("To ? ");
    
    cout<<RandomNumber(From,To)<<endl;
    cout<<RandomNumber(From,To)<<endl;
    cout<<RandomNumber(From,To)<<endl;
    cout<<RandomNumber(From,To)<<endl;

}