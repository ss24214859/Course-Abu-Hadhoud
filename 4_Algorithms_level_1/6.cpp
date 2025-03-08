#include <iostream>
using namespace std;

struct stInFo
{
    string FirstName;
    string LastName; 
};

stInFo ReadInFo()
{
    stInFo InFo;
    cout<<"enter your First Name? ";
    cin>>InFo.FirstName;
    cout<<"enter your Last Name?";
    cin>>InFo.LastName;

    return InFo;
}
string GetFullName(stInFo InFo, bool Reversed)
{
    string FullName=" ";
    if(Reversed)
    FullName=InFo.LastName+" "+InFo.FirstName;
    else
    FullName=InFo.FirstName+" "+InFo.LastName;

    return FullName;

}
void PrintFullName(string FullName)           //problem 1
{
    cout<<"\nyour Full Name is: "<<FullName<<endl;
}

int main()
{
    PrintFullName(GetFullName(ReadInFo(),false));
}