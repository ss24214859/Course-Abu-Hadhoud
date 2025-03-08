//Copy distinct Numbers in Array
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RepeatedNumberIArray(int Array[100],int LengthOfArray,int ChackNumber)
{
    int Repeats=0;
    for(int i=0;i<LengthOfArray;i++)
    {
        if(ChackNumber==Array[i])
        {
            Repeats++;
        }

    }
    return Repeats;
}

void AddArrayElement(int Number,int arr[100],int &arrLength)
{
    arr[arrLength]=Number;
    arrLength++;  //to Add new empty element
}

short FindNumberpositionInArray(int arr[100],int Quantity,int Number)
{
    
    for(short i=0;i<=Quantity;i++)
    {
        if(arr[i]==Number)
        return i;
    }
    return -1;
}

bool IsNumberInArray(int arr[100],int Quantity,int SearchNumber)
{
   return -1!=FindNumberpositionInArray(arr,Quantity,SearchNumber);
}

/*void CopyDistinctNumbersInArrayUsingRepeatedNumberInArray(int array1[100],int array2[100],int arrLength1,int &arrLength2)
{
    for(int i=0;i<arrLength1;i++)
    {
        if(RepeatedNumberIArray(array2,arrLength2,array1[i])==0)  
        AddArrayElement(array1[i],array2,arrLength2);
    }
}*/
void CopyDistinctNumbersInArray(int array1[100],int array2[100],int arrLength1,int &arrLength2)
{
    for(int i=0;i<arrLength1;i++)
    {
        if(!IsNumberInArray(array2,arrLength2,array1[i]))  //if(! in Array)
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
    
    int array1[100];
    array1[0]=10,array1[1]=10,array1[2]=10,array1[3]=50,array1[4]=50,array1[5]=70,array1[6]=70,
    array1[7]=70,array1[8]=70,array1[9]=90;
    int arrLength1=10;

    int array2[100];
    int arrLength2=0;
    

    CopyDistinctNumbersInArray(array1,array2,arrLength1,arrLength2);
    //CopyDistinctNumbersInArrayUsingRepeatedNumberInArray(array1,array2,arrLength1,arrLength2);
    cout<<"\nArray 1 ELements : \n";
    PrintArray(array1,arrLength1);

    cout<<"\nArray 2 ELements : \n";
    PrintArray(array2,arrLength2);
}


