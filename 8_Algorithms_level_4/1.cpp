#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int ReadPositiveNumber(string massge)
{
    int num;
    do
    {
    cout<<massge;
    cin>>num;
    } while (num<0);

    return num;
}


string NumberToText(long int Number)
{
    string Singles[20] = { "","one", "two", "three", "four", "five", "six", "seven", "eight",
        "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
         "seventeen", "eighteen", "nineteen" }; 

    if (Number == 0)
    return "";
    else if (Number > 0 && Number <= 19)
    {
        return Singles[Number];     
    }
    else if (Number >= 20 && Number <= 90)
    {
        string tens[10] = { "","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
        return tens[Number / 10] + " " + NumberToText(Number % 10);
    }
    else if (Number >= 100 && Number <= 900)
    {
        string NumberOfHunderds= NumberToText(Number/100);
        return NumberOfHunderds + ((NumberOfHunderds == "one") ? " Hunderd" : " Hunderds,") + NumberToText(Number % 100);
    }
    else if (Number >= 1000 && Number <= 900000)
    {
        string NumberOfThousand = NumberToText(Number / 1000);
        return NumberOfThousand + ((NumberOfThousand == "one") ? " Thousand" : " Thousands,") + NumberToText(Number % 1000);
    }
    else if (Number >= 1000000 && Number <= 900000000)
    {
        string NumberOfMilion = NumberToText(Number / 1000000);

        return NumberOfMilion + ((NumberOfMilion == "one") ? " Milion" : " Milions,")+NumberToText(Number%1000000);
    }
    else if (Number >= 1000000000 && Number <= 900000000000)
    {
        string NumberOfBilion = NumberToText(Number / 1000000000);

        return NumberOfBilion + ((NumberOfBilion == "one") ? " Bilion" : " Bilions,") + NumberToText(Number%1000000000);    
    }
    return "";
}

int main()
{
    
    cout << NumberToText(ReadPositiveNumber("Enter Number ?"));
}