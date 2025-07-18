#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> q)
{
    cout << "Content: " <<endl;
    while(!q.empty())
    {
        cout<< q.front() << endl;
        q.pop();
    }
}
int main()
{
    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);

    queue<int> q2;
    q2.push(40);
    q2.push(50);
    q2.push(60);
    q2.push(70);
    
    q2.swap(q1);

    cout << "Queue1 Size: "<<q1.size()<<endl;
    printQueue(q1);
    cout << "Queue2 Size: "<<q2.size()<<endl;
    printQueue(q2);
    
}