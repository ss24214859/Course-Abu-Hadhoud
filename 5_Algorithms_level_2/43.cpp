// Count even Numbers in Array 
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enOodOrEven{ood=1,even=2};

int ReadNumber(string Massage)                 
{
    int num;
    cout<<Massage;
    cin>>num;   
    return num;
}

enOodOrEven ChackOodOrEven(int Number)
{
    if(Number%2==0)
    {
        return enOodOrEven::even;
    }
    else
    {
        return enOodOrEven::ood;
    }
}

int RandomNumber(int From,int To)
{
    int Random=rand()%(To-From+1)+From;
    return Random;
    
}


void FillArrayWithRandomNumber(int arr[100] ,int Quantity)
{
    for(int i=0;i<Quantity;i++)
    {
        
         arr[i]=RandomNumber(1,100);
    }
}

short CountEvenNumbersInArray(int array1[100],int arrLength1)
{
    int count=0;
    for(int i=0;i<arrLength1;i++)
    {
        if(ChackOodOrEven(array1[i])==enOodOrEven::even)  //or ood=(array[i]%2 == 0) 
        count++;
    }
    return count;
}

void PrintArray(int arr[100],int Quantity)
{
    for(int i=0;i<Quantity;i++)
    {
        cout<<"Array["<<i+1<<"] : "<<arr[i]<<endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int array[100];
    int arrLength=ReadNumber("enter number ? ");


    FillArrayWithRandomNumber(array,arrLength);
   
    cout<<"\nArray 1 ELements : \n";
    PrintArray(array,arrLength);
    cout<<"even Numbers count in Array is : "<<CountEvenNumbersInArray(array,arrLength);


}