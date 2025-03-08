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
void swap(int &num1,int &num2)
{
    int temp=num1;
    num1=num2;
    num2=temp;
}
int RandomNumber(int From,int To)
{

    int Random=rand()%(To-From+1)+From;
    return Random;
    
}


void FillArrayFrom1ToN(int arr[100] ,int Quantity)
{
    for(int i=0;i<Quantity;i++)
    {
         arr[i]=i+1;
    }
}


void PrintArray(int arr[100],int Quantity)
{
    for(int i=0;i<Quantity;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void ShuffleArray(int arr[100],int Quantity)
{
    for(int i=0;i<Quantity;i++)
        swap(arr[RandomNumber(1,Quantity)-1],arr[RandomNumber(1,Quantity)-1]);
}

int main()
{
    srand((unsigned)time(NULL));
    int array1[100];
    int Quantity=ReadPositiveNumber("enter number ? ");

    FillArrayFrom1ToN(array1,Quantity);
    cout<<"\nArray 1 ELements : ";
    PrintArray(array1,Quantity);

    ShuffleArray(array1,Quantity);
    cout<<"\nArray 1 After Shuffle : ";
    PrintArray(array1,Quantity);

}
