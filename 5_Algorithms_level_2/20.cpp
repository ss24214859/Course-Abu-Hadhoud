#include <iostream>
#include <cstdlib>
using namespace std;

enum enTypeChar{SmallLatters=1,CapetalLatters=2,SpecialCharacter=3,Digit=4};

int RandomNumber(int From,int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

char GetRandomCharacter(enTypeChar TypeChar)
{
    switch (TypeChar)
    {
        case enTypeChar::SmallLatters:
            return char(RandomNumber(97,122));
        case enTypeChar::CapetalLatters:
            return char(RandomNumber(65,90));
        case enTypeChar::SpecialCharacter:
            return char(RandomNumber(33,47));
        case enTypeChar::Digit:
            return char(RandomNumber(48,57));
    }
    return 0;
}


int main()
{
    srand((unsigned)time(NULL));

    cout<<GetRandomCharacter(enTypeChar::SmallLatters)<<endl;
    cout<<GetRandomCharacter(enTypeChar::CapetalLatters)<<endl;
    cout<<GetRandomCharacter(enTypeChar::Digit)<<endl;
    cout<<GetRandomCharacter(enTypeChar::SpecialCharacter)<<endl;

}