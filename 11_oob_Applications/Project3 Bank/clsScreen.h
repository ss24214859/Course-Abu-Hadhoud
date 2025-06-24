#pragma once
#include <iostream>
#include "../../MyClasss/clsUtil.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t" << clsUtil::PrintLineByChar(45) << endl;
        cout << "\n\t\t\t\t\t" << Title << endl;
        if (SubTitle != "")
            cout << "\t\t\t\t\t" << SubTitle << endl;

        cout << "\t\t\t\t\t" << clsUtil::PrintLineByChar(45) << endl;
    }
};