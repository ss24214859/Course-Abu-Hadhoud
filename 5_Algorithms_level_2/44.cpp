// Count Positive Numbers in Array 
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

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
        
         arr[i]=RandomNumber(-100,100);
    }
}

short CountPositiveNumbersInArray(int array1[100],int arrLength1)
{
    int count=0;
    for(int i=0;i<arrLength1;i++)
    {
        if(array1[i]>0)  
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
    cout<<"Positive Numbers count in Array is : "<<CountPositiveNumbersInArray(array,arrLength);


}