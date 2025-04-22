#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Vector
{
    using namespace std;

    void PrintVector(vector<string> Vec)
    {
        for (string &str : Vec)
        {
            cout << str << endl;
        }
    }
}