#include <iostream>
#include "clsLoginScreen.h"
#include "clsCurrenciesListScreen.h"
using namespace std;

int main()
{

    while(true)
    {
       if(!clsLoginScreen::ShowLoginScreen())
       {
            break;
       }
    }

}