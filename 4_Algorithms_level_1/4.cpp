#include <iostream>
using namespace std;

struct stInFo
{
    int Age;
    bool HasDraivingLicense; 
};

stInFo ReadInFo()
{
    stInFo InFo;
    cout<<"enter your Age? ";
    cin>>InFo.Age;
    cout<<"do you have driver License? (yes=1 , no=0) ";
    cin>>InFo.HasDraivingLicense;

    return InFo;
}
bool IsAccapted(stInFo InFo)
{
    return (InFo.Age >21 && InFo.HasDraivingLicense);
}
void PrintResult(stInFo InFo)
{
    if(IsAccapted(InFo))
    {
        cout<<"\n\"Hired\""<<endl;
    }
    else
    {
        cout<<"\n\"Rejected\""<<endl;
    }
}

int main()
{
PrintResult(ReadInFo());
}