#include <iostream>
using namespace std;

void ReadNumbers(int num[3])                 
{
    
    for(int i=0; i<=3-1; i++)
    {
    cout<<"Please enter Number "<<i+1<<"?";
    cin>>num[i];   
    }


}
int sumNumbers(int num[3])
{
    int sum=0;
    for(int i=0; i<=3-1; i++)
    {
        sum=num[i]+sum;
    }
    return sum;

}

float AvrageNumbers(int num[3])
{
    return (float) sumNumbers(num)/3;
}
void PrintResult(float result)
{
    cout<<"\nThe Avrage is = "<<result<<endl;
   

}

int main()
{
int Numbers[3];
ReadNumbers(Numbers);
PrintResult(AvrageNumbers(Numbers));
}