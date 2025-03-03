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

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(0,10);
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

void MultiplyMatrix(int arr1[3][3],int arr2[3][3],int arrSum[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            
            arrSum[i] [j] =arr1[i][j] * arr2[i][j];
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
           printf("%3d    ",arr[i][j]);
            
           
            
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
int SumOfMatrix(int arr[3][3], short Rows,short Cols)
{
    int SumOfMatrix=0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
           SumOfMatrix+=arr[i][j];
        }
    }
    return SumOfMatrix;
}

bool IsTowMtricesIsEqual(int arr1[3][3], int arr2[3][3],short Rows,short Cols)
{
    return SumOfMatrix(arr1,Rows,Cols)==SumOfMatrix(arr2,Rows,Cols);
}
bool IsTowMtricesIsTypical(int arr1[3][3], int arr2[3][3],short Rows,short Cols)
{
    
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(arr1[i][j]!=arr2[i][j])
                return false;
        }
    }
    return true;
}

bool IsMatrixIsIdentity(int arr[3][3], short Rows,short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(i==j&&arr[i][j]!=1)
                return false;
            else if(i!=j&&arr[i] [j]!=0)
                return false;
        }
    }
        
    return true;
}

bool IsMatrixIsScalar(int arr[3][3], short Rows,short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            
            if(i==j&&arr[i][j]!=arr[0][0])
                return false;
            else if(i!=j&&arr[i] [j]!=0)
                return false;
        }
    }
    return true;
}


short CountNumberInMatrix(int arr[3][3], short Rows,short Cols,int Number)
{
    short counter=0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(arr[i][j]==Number)
            counter++;
        }
    }
    return counter;
}

bool IsMatrixIsSparce(int arr[3][3], short Rows,short Cols)
{
    return CountNumberInMatrix(arr,Rows,Cols,0)>(Rows*Cols)/2;
}

bool IsNumberIsExistsInMatrix(int arr[3][3], short Rows,short Cols,int Number)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(arr[i][j]==Number)
            return true;
        }
    }
    return false;
}

void PrintInterestedNumbersInTowMatrices(int arr1[3][3],int arr2[3][3], short Rows,short Cols)
{
    cout<<"Interested Numbers are : ";
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(IsNumberIsExistsInMatrix(arr2,Rows, Cols,arr1[i][j]))
            cout<<setw(3)<<arr1[i][j]<<" ";
        }
    }
    cout<<endl;
}



int MinimumNumberInMatrix(int arr[3][3], short Rows,short Cols)
{
    int Mini=arr[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(arr[i][j]<Mini)
            Mini=arr[i][j];
        }
    }
    return Mini;
}

int MaximumNumberInMatrix(int arr[3][3], short Rows,short Cols)
{
    int Max=arr[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(arr[i][j]>Max)
            Max=arr[i][j];
        }
    }
    return Max;
}



bool IsMatrixIsPalindrome(int arr[3][3], short Rows,short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols/2; j++) 
        {
            if(arr[j][i]!=arr[j][Cols-1-i])
                return false;
        }
    }
    return true;
}

int main()
{

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    short Rows=3;
    short Cols=3;
    int arr1[3][3]={{1,2,1},{3,4,3},{5,3,5}};
    int arr2[3][3]{{1,2,10},{3,4,3},{5,3,57}};
    int arrMul[Rows] [3];
    int RowsSum[Rows];
    int ColsSum[3];
    //FillMatrixWithRandomNumbers(arr1, Rows , Cols);
    
    //FillMatrixWithRandomNumbers(arr2, Rows , Cols);
    MultiplyMatrix(arr1,arr2,arrMul,Rows,Cols);
    
    cout << "\nMatrix 1:\n";
    PrintMatrix(arr1, Rows, Cols);
    cout << "\nMatrix 2:\n";
    PrintMatrix(arr2, Rows, Cols);
    cout << "\nMultiply Matrix:\n";
    PrintMatrix(arrMul, Rows, Cols);
    cout<<"\nSum Of Matrix 1 is :"<<SumOfMatrix(arr1,Rows, Cols)<<endl;
    cout<<"Sum Of Matrix 2 is :"<<SumOfMatrix(arr2,Rows, Cols)<<endl;
    if(IsTowMtricesIsEqual(arr1,arr2,Rows,Cols))
    cout<<"Yes: Matrices Are equal."<<endl;
    else
    cout<<"No: Matrices Are Not equal."<<endl;
    
    if(IsTowMtricesIsTypical(arr1,arr2,Rows,Cols))
    cout<<"Yes: Matrices Are Typical."<<endl;
    else
    cout<<"No: Matrices Are Not Typical."<<endl;
    
    
   
    
    if(IsMatrixIsIdentity(arr1,Rows, Cols))
        cout<<"this matrix is identity. \n";
    else
        cout<<"this matrix isn't identity. \n";
        
    if(IsMatrixIsIdentity(arr2,Rows, Cols))
        cout<<"\nYes : this matrix is identity. \n";
    else
        cout<<"\nNo :this matrix isn't identity. \n";
    
    if(IsMatrixIsScalar(arr1,Rows, Cols))
        cout<<"\nYes :this matrix is scalar . \n";
    else
        cout<<"\nNo : this matrix is Not scalar . \n";
        
    if(IsMatrixIsScalar(arr2,Rows, Cols))
        cout<<"\nYes :this matrix is scalar . \n";
    else
        cout<<"\nNo : this matrix is Not scalar . \n";
        
        
        
    int Number=0;    
    cout<<"enter the Number to Count in Matrix ? ";
    cin>>Number;
    
    cout<<"Number "<<Number<<" count in matrix is : ";
    cout<<CountNumberInMatrix(arr2,Rows, Cols,Number)<<"\n";
    
    
    
    
    
    //17
    if(IsNumberIsExistsInMatrix(arr1,Rows, Cols,Number))
        cout<<"\nYes :is exists . \n";
    else
        cout<<"\nNo :is Not exists . \n";
        
    if(IsNumberIsExistsInMatrix(arr2,Rows, Cols,Number))
        cout<<"\nYes :is exists . \n";
    else
        cout<<"\nNo :is Not exists . \n";
        
        
    
    
    //16
    if(IsMatrixIsSparce(arr2,Rows, Cols))
        cout<<"\nYes :this matrix is a sparce . \n";
    else
        cout<<"\nNo : this matrix is Not a sparce . \n";
        
        
    //18 
    
    PrintInterestedNumbersInTowMatrices(arr1,arr2,Rows, Cols);
    
    
    //19 
    cout<<"\n\nMinimum Number in Matrix1 : "<<MinimumNumberInMatrix(arr1,Rows, Cols)<<endl;
    cout<<"\nMaximum Number in Matrix1 : "<<MaximumNumberInMatrix(arr1,Rows, Cols)<<endl;
    
    
    
    
    //20
    if(IsMatrixIsPalindrome(arr1,Rows, Cols))
        cout<<"\nYes :is Palindrom . \n";
    else
        cout<<"\nNo :is Not Palindrom . \n";
        
    if(IsMatrixIsPalindrome(arr2,Rows, Cols))
        cout<<"\nYes :is Palindrom . \n";
    else
        cout<<"\nNo :is Not Palindrom . \n";
        
}   