#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


short DigitCounter(long int Number)
{
    short counter = 0;
    while (Number != 0)
    {
        Number /= 10;
        counter++;
    }
    return counter;
}

string TextOfNumber(long int Number)
{
    string Singles[19] = { "one", "two", "three", "four", "five", "six", "seven", "eight",
        "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
         "seventeen", "eighteen", "nineteen" };

    string tens[8] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    short NumberOfDigits = DigitCounter(Number) - 1;


    string SinglesOf = "";
    /*for(int i=1.1;i<20;i++)                    //test Arr
        cout<<Singles[i-1]<<endl;*/

    string Text = "";

    if (Number == 0)
        Text = "Zero";
    else if (Number > 0 && Number <= 19)
    {
        return Singles[Number - 1];     
    }
    else if (Number >= 20 && Number <= 90)
    {
        Text = tens[(Number / 10) - 2];
        
    }
    else if (Number >= 100 && Number <= 900)
    {
        SinglesOf = Singles[(Number / 100) - 1];
        Text = SinglesOf + ((SinglesOf == "one") ? " Hunderd" : " Hunderds");
    }
    else if (Number >= 1000 && Number <= 900000)
    {
        string NumberOfThousand = TextOfNumber(Number / 1000);

        Text = NumberOfThousand + ((NumberOfThousand == "one") ? " Thousand" : " Thousands");
        NumberOfDigits = DigitCounter(Number) -DigitCounter(Number/1000);
    }
    else if (Number >= 1000000 && Number <= 900000000)
    {
        string NumberOfMilion = TextOfNumber(Number / 1000000);

        Text = NumberOfMilion + ((NumberOfMilion == "one") ? " Milion" : " Milions");
        NumberOfDigits = DigitCounter(Number) - DigitCounter(Number/1000000);
    }
    else if (Number >= 1000000000 && Number <= 900000000000)
    {
        string NumberOfBilion = TextOfNumber(Number / 1000000000);

        Text = NumberOfBilion + ((NumberOfBilion == "one") ? " Bilion" : " Bilions");
        NumberOfDigits = DigitCounter(Number) - DigitCounter(Number/1000000000);
    }




    if (NumberOfDigits == 0)      //shutdown recergine.
        return Text;

    long int PowerOf10WithDigit = long (pow(10, NumberOfDigits));

    Number/*=855*/ %= PowerOf10WithDigit; //to remove first Number on the left.example:{ Number =855 after-> =55 } 

    return Text + " " + TextOfNumber(Number/*=55*/);
}

int main()
{
    cout << TextOfNumber(8476362741);
}