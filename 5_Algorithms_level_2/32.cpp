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


void ReadArray(int arr[100] ,int Quantity)
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

void CopyArrayInReverse(int arrsource[100],int Quantity,int arrDestination2[100])
{

    for(int i=0;i<Quantity;i++)
        arrDestination2[i]=arrsource[Quantity-1-i];
}

int main()
{
    srand((unsigned)time(NULL));
    int array1[100],array2[100];
    int Number=ReadPositiveNumber("enter number ? ");

    ReadArray(array1,Number);

    cout<<"\nArray 1 ELements : ";
    PrintArray(array1,Number);

    CopyArrayInReverse(array1,Number,array2);

    cout<<"\nArray 2 ELements : ";
    PrintArray(array2,Number);

    

     
}
