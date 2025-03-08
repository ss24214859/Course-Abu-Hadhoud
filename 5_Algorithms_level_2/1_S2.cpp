#include <iostream>
#include <string>
using namespace std;

string TheHeaderUsingRang(int from,int to)
{
    for(int i =from;i<=to/3;i++)
    {
        cout<<"\t";
    }
    cout<<"Multipliaction Table From "<<from<<" To "<<to;
    return "\t\n";

}
string TitleTableInRang(int from,int to)
{
    cout<<"\t  ";
    for(int i =from;i<=to;i++)
    {

        cout<<i<<"\t";
    }
    return "\n";
}

string LineOfTitleTableInRang(int from,int to)
{
    for(int i =from;i<=to*9;i++)
    {
        cout<<"_";
    }
    return "\n";
    
}
string MultipliactionTableInRang(int from,int to)
{
    int Result=0;
    for(int series=from;series<=to;series++)
    {
    cout<<" "<<series;
    if(series>0&&series<=9)
    cout<<"   |    ";
    else if(series>=10&&series<=99)
    cout<<"  |    ";
    else  if(series>=100&&series<=999)
    cout<<" |    ";

    for(int Multiplier =from;Multiplier<=to;Multiplier++)
    {
        Result= Multiplier*series;
        cout<<Result<<"\t";
        
    }
    cout<<endl;
    }
    return"\n";
}

void printMultipliactionTableInRang(int from,int to)
{
    cout<<TheHeaderUsingRang(from,to)<<endl;
    cout<<TitleTableInRang(from,to);
    cout<<LineOfTitleTableInRang(from,to);
    cout<<MultipliactionTableInRang(from,to);
}
int main()
{
printMultipliactionTableInRang(1,10);
}
    