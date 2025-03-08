#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool ReadBoolen(string Massge)
{

    cout<<Massge<<endl;
    bool b=0;
    cin>>b;
    return b;
}

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

void AddArrayElement(int Number,int arr[100],int &arrLength)
{
    arr[arrLength]=Number;
    arrLength++;  //to Add new empty element
}
void ReadArrayByUser(int arr[100] ,int &Quantity)
{
    bool Add=1;
    
    while (Add)
    {
        AddArrayElement(ReadPositiveNumber("Enter a Number ? "),arr,Quantity);

        Add=ReadBoolen("Do you want to add More Numbers ? [0]:No,[1]:yes ?");
       
    }

}

void PrintArrayElements(int arr[100],int Quantity)
{
    for(int i=0;i<Quantity;i++)  // (i<Quantity) == (i<=Quantity-1)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    
    int arr[100];
    int Quantity=0;
    ReadArrayByUser(arr,Quantity);
    cout<<"Array length : "<<Quantity<<endl;
    cout<<"Array Elements : ";
    PrintArrayElements(arr,Quantity);
    
  
    


}



        

    