#pragma once
#include <iostream>
#include "../../MyClasss/clsTime.h"
#include "../../MyClasss/clsDate.h"
#include <queue>
#include <stack>
using namespace std;

class clsQueueLine
{

private:
    class clsTicket
    {
        string _Prefix;
        short _Number;
        string _TicketDateTime;
        short _WatingClients;
        short _AverageServeTime;
        string _ExpectedServeTime;

    public:
        clsTicket(string Prefix, short Number, short WatingClients, short AvreageServeTime)
        {
            _Prefix = Prefix;
            _Number = Number;
            _TicketDateTime = clsDate::GetSystemDateTimeString();
            _WatingClients = WatingClients;
            _AverageServeTime = AvreageServeTime;
            _ExpectedServeTime = clsTime::TimeFromMinutesTostring(AvreageServeTime * _WatingClients);
        }

        string GetPrefix() const
        {
            return _Prefix;
        }

        short GetNumber() const
        {
            return _Number;
        }

        clsDate GetTicketDateTime() const
        {
            return _TicketDateTime;
        }

        short GetWatingClients() const
        {
            return _WatingClients;
        }

        short GetAvreageServeTime() const
        {
            return _AverageServeTime;
        }

        string GetExpectedServeTime() const
        {
            return _ExpectedServeTime;
        }

        string FullNumber()
        {
            return _Prefix + to_string(_Number);
        }

        void Print()
        {
            cout <<     "\n\t\t\t\t______________________________\n\n";
            cout << "\t\t\t\t"<<"             "<<FullNumber()<<"\n\n";
            cout << "\t\t\t\t"<<" "<<_TicketDateTime<<endl;
            cout << "\t\t\t\t"<<" Wating Clients = "<<_WatingClients<<endl;
            cout << "\t\t\t\t"<<"    Serve Time In "<<endl;
            cout << "\t\t\t\t"<<"   "<<_ExpectedServeTime<<"."<<endl;
            cout <<       "\t\t\t\t______________________________\n"<<endl;
        }

    };

    string _Prefix="";
    int _AverageServeTime=0;
    short _TotalTickets=0;

public:
    queue <clsTicket> QueueLine;

    clsQueueLine(string Prefix, int AverageServeTime)
    {
        _Prefix = Prefix;
        _AverageServeTime = AverageServeTime;
    }

    void IssueTicket()
    {
        _TotalTickets++;
        QueueLine.push(clsTicket(_Prefix,_TotalTickets,WatingClients(),_AverageServeTime));
    }

    short WatingClients()
    {
        return QueueLine.size();
    }

    short ServedClients()
    {
        return _TotalTickets - WatingClients(); 
    }

    string WhoIsNext()
    {
        if(QueueLine.empty())
        return "No Clients Left.";
        else
        return QueueLine.front().FullNumber();
    }

    void PrintInfo()
    {

        cout << "\t\t\t\t__________________________________\n"
             << endl;
        cout << "\t\t\t\t            Queue Info            " << endl;
        cout << "\t\t\t\t__________________________________\n"
             << endl;
        cout << "\t\t\t\t" << "Prefix = " << _Prefix << endl;
        cout << "\t\t\t\t" << "Total Tickets = " << _TotalTickets << endl;
        cout << "\t\t\t\t" << "Served Clients = " << ServedClients() << endl;
        cout << "\t\t\t\t" << "Wating Clients = " << WatingClients() << endl;
        cout << "\t\t\t\t__________________________________\n"
             << endl;
    }

    void PrintTicketsLineRTL()
    {
        cout << "\t\tTickets :  ";

        if(QueueLine.empty())
        {
            cout<<"No Clients Left."<<endl;
            return;
        }

        queue<clsTicket> _tempTotalTickets = QueueLine;
        while (!_tempTotalTickets.empty())
        {
            cout << _tempTotalTickets.front().FullNumber() << " <-- ";
            _tempTotalTickets.pop();
        }
        cout << endl;
    }

    void PrintTicketsLineLTR()
    {
        cout << "\t\tTickets :  ";

        if(QueueLine.empty())
        {
            cout<<"No Clients Left."<<endl;
            return;
        }

        queue<clsTicket> _tempTotalTickets = QueueLine;
        string ToPrint="";
        while (!_tempTotalTickets.empty())
        {
            ToPrint= _tempTotalTickets.front().FullNumber() + " --> " + ToPrint;     // Print  Queue In Reverse Without use stack.  
            _tempTotalTickets.pop();
        }
        cout<<ToPrint<<endl;
    }

    void PrintAllTickets()
    {
        queue<clsTicket> Temp = QueueLine;

        cout << "\n\t\t\t\t" << "         --Tickets-- ";

        if(Temp.empty())
        {
            cout<<": No Tickets."<<endl;
            return;
        }
        
        while (!Temp.empty())
        {
            Temp.front().Print();
            Temp.pop();
        }
    }

    bool _ServeNextclient()
    {
        if(QueueLine.empty())
            return false;

        QueueLine.pop();
        return true;
    }
};