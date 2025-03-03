#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithOrderNumbers(int arr[3][3], short Rows, short Cols)
{
    int OrderNumber=0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            OrderNumber++;
            arr[i][j] = OrderNumber;
        }
    }
}

void TransposeMatrix(int arr[3][3], int arrTranspos[3] [3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            
            arrTranspos[j] [i] =arr[i][j];
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int RowsSum(int arr[3][3],short RowNumber, short Cols)
{
    int Sum = 0;
    for (short j = 0; j <= Cols - 1; j++)
    {
        Sum += arr[RowNumber][j];
    }
    return Sum;
}
void SumMatrixRowsInArry(int arr[3][3], int arrSum[3], short Rows,short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        arrSum[i] = RowsSum(arr, i, Cols);
    }
}

void PrintRowsSumArray(int arr[3], short Rows)
{
    cout << "\nThe the following are the sum of each Row in the matrix:\n";
    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
    }
}


int ColsSum(int arr[3][3],short Row, short ColNumber)
{
    int Sum = 0;
    for (short j = 0; j <= Row - 1; j++)
    {
        Sum += arr[j][ColNumber];
    }
    return Sum;
}

void SumMatrixColsInArry(int arr[3][3], int arrSum[3], short Rows,short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        arrSum[i] = ColsSum(arr,Rows , i);
    }
}

void PrintColsSumArray(int arr[3], short Cols)
{
    cout << "\nThe the following are the sum of each Col in the matrix:\n";
    for (short i = 0; i < Cols; i++)
    {
        cout << " Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main()
{

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    short Rows=3;
    short Cols=3;
    int arr[Rows][3];
    int arrTranspos[Rows] [3];
    int RowsSum[Rows];
    int ColsSum[3];
    FillMatrixWithOrderNumbers(arr, Rows, Cols);
    cout << "\nThe following is a 3x3  matrix:\n";
    PrintMatrix(arr, Rows, Cols);
    SumMatrixRowsInArry(arr, RowsSum, Rows,Cols);
    PrintRowsSumArray(RowsSum, Rows);
    
    
    SumMatrixColsInArry(arr, ColsSum, Rows,Cols);
    PrintColsSumArray(ColsSum, Cols);
    
    TransposeMatrix(arr,arrTranspos, Rows, Cols);
    
    cout << "\nThe following is a 3x3 Trnspose matrix:\n";
    PrintMatrix(arrTranspos, Rows, Cols);
    SumMatrixRowsInArry(arrTranspos, RowsSum, Rows,Cols);
    PrintRowsSumArray(RowsSum, Rows);
    
    
    SumMatrixColsInArry(arrTranspos, ColsSum, Rows,Cols);
    PrintColsSumArray(ColsSum, Cols);
}    