#include <iostream>
#include <string>
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

    int Random=rand()%(To-From+1)+From;
    return Random;
    
}


void FillArrayWithRandomNumbers(int arr[100] ,int Quantity)
{

    for(int i=0;i<Quantity;i++)
    {
         arr[i]=RandomNumber(1,100);
    }
}


void PrintArray(int arr[100],int Quantity)
{
    for(int i=0;i<Quantity;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void copyArray(int arrsource[100],int Quantity,int arrDestination2[100])
{
    for(int i=0;i<Quantity;i++)
        arrDestination2[i]=arrsource[i];
    
}

void sum2ArraysInArray(int Arr1[100],int Arr2[100],int sumArrays[100],int Quantity)
{
    for(int i=0;i<Quantity;i++)
    {
        sumArrays[i]=Arr1[i]+Arr2[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int array1[100],array2[100],array3[100];
    int Quantity=ReadPositiveNumber("enter number ? ");

    FillArrayWithRandomNumbers(array1,Quantity);
    cout<<"\nArray 1 ELements : ";
    PrintArray(array1,Quantity);

    FillArrayWithRandomNumbers(array2,Quantity);
    cout<<"\nArray 2 ELements : ";
    PrintArray(array2,Quantity);

    sum2ArraysInArray(array1,array2,array3,Quantity);
    cout<<"\nSum of array1 and array2 elements : ";
    PrintArray(array3,Quantity);

     
}
