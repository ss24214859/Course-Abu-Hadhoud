// Chack Array is Palndrom Or no
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool IsArrayPalndrom(int arr[100],int length)
{
    //int r=length-1;

    for(int i=0;i<length;i++)
    {
        if(arr[i]!=arr[/* r */length-1-i])
        return false;
        /* else
        r--; */
    }
    return true;
}

void PrintArray(int arr[100],int Quantity)
{
    for(int i=0;i<Quantity;i++)
    {
        cout<<"Array["<<i+1<<"] : "<<arr[i]<<endl;
    }
}


void PrintResult(int arr[100],int Quantity)
{
    cout<<endl;
    if(IsArrayPalndrom(arr,Quantity))
    cout<<"yes Array is Plandrom\n";
    else
    cout<<"No Array is not Plandrom\n";
}

int main()
{
    
    int array1[100];
    array1[0]=10,array1[1]=20,array1[2]=30,array1[3]=30,array1[4]=20,array1[5]=10,array1[6]=70,
    array1[7]=70,array1[8]=70,array1[9]=90;
    int arrLength1=6;

    cout<<"\nArray 1 ELements : \n";
    PrintArray(array1,arrLength1);

    PrintResult(array1,arrLength1);

}
