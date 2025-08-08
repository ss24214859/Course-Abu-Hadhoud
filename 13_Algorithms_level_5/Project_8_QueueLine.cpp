#include <iostream>
#include "Ds/clsQueueLine.h"
using namespace std;

int main()
{
    clsQueueLine PayBillsQueue("A0",10);
    clsQueueLine SubscribtionsQueue("B0",5);

    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();

    
    cout<<"Pay Bills Info :\n"<<endl;
    PayBillsQueue.PrintInfo();

    PayBillsQueue.PrintTicketsLineRTL();
    PayBillsQueue.PrintTicketsLineLTR();

    PayBillsQueue.PrintAllTickets();

    PayBillsQueue._ServeNextclient();

    cout<<"Pay Bills Queue After Serving one Clinet.\n"<<endl;
    PayBillsQueue.PrintInfo();


    SubscribtionsQueue.IssueTicket();
    SubscribtionsQueue.IssueTicket();
    SubscribtionsQueue.IssueTicket();

    cout<<"Subscribtions Info :\n"<<endl;
    SubscribtionsQueue.PrintInfo();

    SubscribtionsQueue.PrintTicketsLineRTL();
    SubscribtionsQueue.PrintTicketsLineLTR();

    SubscribtionsQueue.PrintAllTickets();

    SubscribtionsQueue._ServeNextclient();

    cout<<"Subsucibtions Queue After Serving one Clinet.\n"<<endl;
    SubscribtionsQueue.PrintInfo();





    system("pause>0");
}