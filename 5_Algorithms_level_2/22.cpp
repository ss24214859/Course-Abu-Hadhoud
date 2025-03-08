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

void ReadArray(int Array[100], int &lengthOArray)
{
    lengthOArray=ReadPositiveNumber("enter Length Of Array ? ");

    cout<<"\nenter Array Elements : \n";

    for(int i=0; i<lengthOArray;i++)
    {
        cout<<"enter Element[ "<<i+1<<" ] : ";
        Array[i]=ReadPositiveNumber("");
    }
}

int RepeatedNumberIArray(int Array[100],int LengthOfArray,int ChackNumber)
{
    int Repeats=0;
    for(int i=0;i<LengthOfArray;i++)
    {
        if(ChackNumber==Array[i])
        {
            Repeats++;
        }

    }
    return Repeats;
}

void PrintArray(int Array[100],int length)
{
    for(int i=0;i<length;i++)
    cout<<Array[i]<<" ";
}

void printResult(int Array[100],int lengthOfArray,int ChackNumber)
{
    cout<<"\nOraginal Array : ";
    PrintArray(Array,lengthOfArray);
    cout<<endl<<endl<<ChackNumber<<" is Repeated "<<RepeatedNumberIArray(Array,lengthOfArray,ChackNumber)<<" Time(S)"<<endl;
}
int main()
{
    int arr[100],lengthOfArr,ChackNumber;
    ReadArray(arr,lengthOfArr);
    ChackNumber=ReadPositiveNumber("\nenter the Number you want to Chack: ");
    printResult(arr,lengthOfArr,ChackNumber);

}