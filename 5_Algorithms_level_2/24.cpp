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

int MaxNumberInArray(int array[100],int Quantity)
{
    int Max=0;
    for(int i=0;i<Quantity;i++)
    {
      if(Max<array[i])
      Max=array[i];
    }
    return Max;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int Number=ReadPositiveNumber("enter number ? ");
    ReadArray(arr,Number);
    cout<<"\nArray ELements : ";
    
    PrintArray(arr,Number);
    
    cout<<"\n\nthe beggest Number in Elements : "<< MaxNumberInArray(arr,Number);
     


}






    