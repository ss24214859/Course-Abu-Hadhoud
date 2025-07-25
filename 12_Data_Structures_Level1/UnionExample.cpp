#include <iostream>

union MyUnion {
    int intValue;
    float floatValue;
    char charValue;
};

int main() {
    MyUnion myUnion;

    myUnion.intValue = 42;
    std::cout << "Integer value: " << myUnion.intValue << std::endl;

    myUnion.floatValue = 3.14f;
    std::cout << "Float value: " << myUnion.floatValue << std::endl;

    myUnion.charValue = 'A';
    std::cout << "Char value: " << myUnion.charValue << std::endl;

    //std::cout<<"\n"<<myUnion.floatValue<<std::endl;    :: this Do error Becuse In Last Operation Stored CharValue Not Float.

    //std::cout << "\nInteger value: " << myUnion.intValue << std::endl;   :: this Do error Becuse In Last Operation Stored CharValue Not Int.



    return 0;
} 