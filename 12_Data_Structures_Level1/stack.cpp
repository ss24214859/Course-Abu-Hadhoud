#include <iostream>
#include <stack>
using namespace std;

void PrintStack(stack<int> &s)
{
    cout<< "content: "<<endl;
    while(!s.empty())
    {
        cout << s.top() <<endl;
        s.pop();
    }
}
int main()
{
    stack <int> s1;
    s1.push(10);
    s1.push(20);
    stack <int> s2;
    s2.push(30);
    s2.push(40);
    s2.push(50);
    
    s1.swap(s2);

    cout<< "Stack 1: " << endl;
    cout<< "size: " << s1.size()<<endl;
    PrintStack(s1);

    cout<< "stack 2: " << endl;
    cout<< "size: " << s2.size()<<endl;
    PrintStack(s2);
}