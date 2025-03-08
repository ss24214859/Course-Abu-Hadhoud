//Copy Prime Numbers in Array
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enPrimeOrNot{Prime=1,NotPrime=2};
enPrimeOrNot ChackPrimeNumber(int number)
{
    for(int i=2;i<=number/2;i++)  //if (i>=Number/2) loop will stop than Number will be Prime
    {
        if(number%i==0)           
        {
            return enPrimeOrNot::NotPrime;
        }
        

    }
       return enPrimeOrNot::Prime;
}

int ReadNumber(string Massage)                 
{
    int num;
    cout<<Massage;
    cin>>num;   
    return num;
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

void AddArrayElement(int Number,int arr[100],int &arrLength)
{
    arr[arrLength]=Number;
    arrLength++;  //to Add new empty element
}

void CopyPrimeNumbersInArray(int array1[100],int array2[100],int arrLength1,int &arrLength2)
{
    for(int i=0;i<arrLength1;i++)
    {
        if(ChackPrimeNumber(array1[i])==enPrimeOrNot::Prime)  
        AddArrayElement(array1[i],array2,arrLength2);
    }
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
    int array1[100],array2[100];
    int arrLength1=ReadNumber("enter number Of Elements ? "),
    arrLength2=0;

    FillArrayWithRandomNumber(array1,arrLength1);

    CopyPrimeNumbersInArray(array1,array2,arrLength1,arrLength2);
   
    cout<<"\nArray 1 ELements : \n";
    PrintArray(array1,arrLength1);

    cout<<"\nArray 2 ELements : \n";
    PrintArray(array2,arrLength2);
}


