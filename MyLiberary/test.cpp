/*#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    bitset<64> commandBits;
    cout << "Enter binary command (e.g., 101010): ";
    cin >> commandBits;

    int command = commandBits.to_ulong();

    cout << "\nBinary command: " << commandBits << endl;
    cout << "Integer value: " << command << endl;

    cout << "Enter int command;" << endl;
    cin >> command;
    bitset<64> binaryCommand(command);
    cout << "Binary: " << binaryCommand << endl; // Output: 101010

    return 0;
}
*/

#include <iostream>
#include <bitset>
#include <string>
#include "ReadLip.h"
using namespace std;

// Function to display active devices
void showDevices(int command)
{
    if (command & (1 << 0))
        cout << "✅ Light is ON\n";
    if (command & (1 << 1))
        cout << "✅ Fan is ON\n";
    if (command & (1 << 2))
        cout << "✅ AC is ON\n";
    if (command & (1 << 3))
        cout << "✅ Washing Machine is ON\n";
    if (command & (1 << 4))
        cout << "✅ Door is OPEN\n";
    if (command & (1 << 5))
        cout << "✅ Alarm is ON\n";
}
/*
int main()
{
    bool input;
    bool i1 = 0, i2 = 1, i3 = 0, i4 = 1, i5 = 0, i6 = 1;

    // Convert string to 6-bit binary number
    bitset<6> /*commandBits((to_string(i1) + to_string(i2)));
    cout << commandBits << endl;*/
/*
commandBits = i1 & i2 & i3 & i4 & i5 & i6;
cout << commandBits << endl;

int command = commandBits.to_ulong(); // Convert to unsigned long (integer)
cout << "\ncommand = " << command << endl
<< endl;
cout << "\n🔎 Device Status:\n";
showDevices(command);

return 0;
}
*/

int main()
{
    /* bitset<2> command;
     command |= (Read::ReadYesOrNo("Light is ON\n") << 0);
     command |= (Read::ReadYesOrNo("Fan is ON\n") << 1);

     cout << endl
          << (command.to_ulong() & (1 << 0)) << endl;*/
}
