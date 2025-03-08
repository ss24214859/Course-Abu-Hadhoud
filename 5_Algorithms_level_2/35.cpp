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
    cout<<endl;
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
void printResultOfSearch(bool NumberIsFound)
{
    if(NumberIsFound)
    cout<<"Yes,the number is found :-) ";
    else
    cout<<"No,the number is not found :-( ";
}
void printResultOfSearchOnPosition(int arr[100],int Quantity,int position)
{
    if(position!=-1)
    {
        cout<<"the number found at position : "<<position<<endl;
        cout<<"the number found it's order : "<<position+1<<endl;
    }
    else
    {
        cout<<"the number is not found :-("<<endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int Quantity= ReadPositiveNumber("enter number of elements ? ");
    ReadArray(arr,Quantity);
    cout<<"Array [1] : "<<endl;
    PrintArray(arr,Quantity);
    
    cout<<endl<<"enter search Number ? ";
    int SearchNumber=ReadPositiveNumber("Enter Number to Search For ? ");
    cout<<"Number you are loking for : "<<SearchNumber<<endl;
    
    printResultOfSearch(IsNumberInArray(arr,Quantity,SearchNumber));
    
    //short position=FindNumberpositionInArray(arr,Quantity,SearchNumber);
    
    //printResultOfSearchOnPosition(arr,Quantity,position);
    


}



        

    