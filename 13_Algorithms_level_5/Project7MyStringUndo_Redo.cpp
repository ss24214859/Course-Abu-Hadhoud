#include <iostream>
#include "DS/ClsMyString.h"

using namespace std;

int main()
{
   
    cout << "\n\n\t\t\t\t\t\t Undo/Redo Project\n\n";

    ClsMyString S1;

    cout << "\nS1  = " << S1.GetValue() << "\n"; 

    S1.SetValue("Mohammed");
  
    cout << "S1  = " << S1.GetValue() << "\n";

    S1.SetValue("Mohammed2");

    cout << "S1  = " << S1.GetValue() << "\n";

    S1.SetValue("Mohammed3");

    cout << "S1  = " << S1.GetValue() << "\n";

    cout << "\n\nUndo: ";
    cout << "\n__________\n";

    S1.Undo();
    cout << "\nS1  after undo = " << S1.GetValue() << "\n";
    
    S1.Undo();
    cout << "S1  after undo = " << S1.GetValue() << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.GetValue() << "\n";

    cout << "\n\nRedo: ";
    cout << "\n__________\n";

    S1.Redo();
    cout << "\nS1  after Redo = " << S1.GetValue() << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.GetValue() << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.GetValue() << "\n";

    system("pause>0");

    return 0;
}

