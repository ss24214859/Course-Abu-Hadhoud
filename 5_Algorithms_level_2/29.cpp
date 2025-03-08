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
    if(Quantity==0)
        cout<<"Nothing";
}

bool isPrimeNumber(int number)
{
    for(int i=2;i<=number/2;i++)
    {
        if(number%i==0)
        {
            return false;
        }
        

    }
       return true;
}

void copyPrimeNumbersInArray(int arr1[100],int Quantity1,int arr2[100],int &Quantity2)
{
    Quantity2=0;
    for(int i=0;i<Quantity1;i++)
    {
        if(isPrimeNumber(arr1[i]))
        {
            arr2[Quantity2]=arr1[i];
            Quantity2++;
        }
    }   
    Quantity2--;
}
/*void PrintPrimeNumbersInArray(int arr[100],int Quantity)
{
    int countPrimeNumbers=0;
    for(int i=0;i<Quantity;i++)
    {
        if(isPrimeNumber(arr[i]))
        {    cout<<arr[i]<<" ";
            countPrimeNumbers++;
        }    
    }
    if(countPrimeNumbers==0)
    cout<<" nothing Prime Numbers in Array ";
    
}*/

int main()
{
    srand((unsigned)time(NULL));
    int array1[100],array2[100];
    int Quantity1=ReadPositiveNumber("enter number ? ");
    int Quantity2;

    ReadArray(array1,Quantity1);

    cout<<"\nArray 1 ELements : ";
    PrintArray(array1,Quantity1);

    copyPrimeNumbersInArray(array1,Quantity1,array2,Quantity2);

    cout<<"\nPrime Numbers In Array 2 : ";
    PrintArray(array2,Quantity2);
     
}
