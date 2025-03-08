
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int RandomNumber(int From,int To)
{
    int Random=rand()%(To-From+1)+From;
    return Random;
    
}

void FillArrayWithRandomNumber(int arr[100] ,int &Quantity)
{

    cout<<"enter number of elements ? ";
    cin>>Quantity;
    
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
int main()
{
    srand((unsigned)time(NULL));
    
    int arr[100], Number;
    
    FillArrayWithRandomNumber(arr,Number);
    cout<<"\nArray ELements : ";
    PrintArray(arr,Number);


}






    