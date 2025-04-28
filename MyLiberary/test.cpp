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

int main()
{
    string input;
    cout << "Enter command code (example: 101010): ";
    cin >> input;

    // Convert string to 6-bit binary number
    bitset<6> commandBits(input);
    int command = commandBits.to_ulong(); // Convert to unsigned long (integer)
    cout << "\ncommand = " << command << endl
         << endl;
    cout << "\n🔎 Device Status:\n";
    showDevices(command);

    return 0;
}
