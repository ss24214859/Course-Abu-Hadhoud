#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int RandomNumberInRang(int from,int to)
{
    int num=rand()% (to-from+1)+from;
    return num;
}

void FillTDArrWithRandomNumber(int Arr[3] [3],int Rows,int Cols)
{
    for(int i=0 ; i<Rows; i++)
    {
        for(int j=0; j<Cols; j++)
        {
            Arr[i] [j]=RandomNumberInRang(1,100);
        }
    }
    
}

void PrintTDArr(int arr[3] [3] ,int Rows,int Cols)
{
    for(int i=0 ; i<Rows; i++)
    {
        for(int j=0; j<Cols; j++)
        {
            cout<<setw(3)<< arr [i] [j] <<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    
    int Matrix[3] [3];
    int Rows = 3;
    int Cols = 3;
    FillTDArrWithRandomNumber(Matrix,Rows,Cols);
    cout<<"The Following is a 3x3 Random Matrix :"<<endl;
    PrintTDArr(Matrix,Rows,Cols);
    system("pause>0");
    
}