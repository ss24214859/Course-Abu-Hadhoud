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
        struct TicketInfo
        {
            string PrefixNumber;
            clsTime TicketTime;
            clsDate TicketDate;
            short WatingClients;
            string ServeTime;
        };
        string _Taps="\t\t\t\t\t";

        string _Prefix;
        int _ServeTime;
        queue<TicketInfo> _TotalTickets;
        short _ServedClients=0;
        short _WatingClients=0;
protected:
        template <typename T>
        stack <T> _ConvertFromQueueToStack(queue<T> queue)
        {
            stack <T> stack;
            while(!queue.empty())
            {
                stack.push(queue.front());
                queue.pop();
            }
            return stack;
        }

        string _TimeFromMinutesTostring(int Minutes)
        {
            if(Minutes<60)
            return to_string(Minutes)+" Minutes";

            short hours=0;
            while(Minutes>=60)
            {
                hours++;
                Minutes-=60;
            }
            if(Minutes==0)
            return to_string(hours)+" Hours";
            else
            return to_string(hours)+" Hours And " + to_string(Minutes)+" Minutes";
        }
public:
        clsQueueLine(string Prefix , int ServeTime)
        {
            _Prefix=Prefix;
            _ServeTime=ServeTime;
        }

        void IssueTicket()
        {
            TicketInfo NewTicket;
            NewTicket.PrefixNumber=_Prefix + to_string(_TotalTickets.size()+1);
            NewTicket.TicketDate.GetSystemDate();
            NewTicket.TicketTime.GetSystemTime();
            NewTicket.WatingClients=_WatingClients;
            NewTicket.ServeTime=_TimeFromMinutesTostring(_ServeTime*NewTicket.WatingClients);
            _TotalTickets.push(NewTicket);
            _WatingClients++;

        }
        
        void PrintInfo()
        {
            
            cout<<"\t\t\t\t__________________________________\n"<<endl;
            cout<<"\t\t\t\t            Queue Info            "<<endl;
            cout<<"\t\t\t\t__________________________________\n"<<endl;
            cout<<_Taps<<"Prefix = "<<_Prefix<<endl;
            cout<<_Taps<<"Total Tickets = "<<_TotalTickets.size()<<endl;
            cout<<_Taps<<"Served Clients = "<<_ServedClients<<endl;
            cout<<_Taps<<"Wating Clients = "<<_WatingClients<<endl;
            cout<<"\t\t\t\t__________________________________\n"<<endl;
        }

        void PrintTicketsLineRTL()
        {
            cout<<"\t\tTickets :  ";
            queue<TicketInfo> _tempTotalTickets=_TotalTickets;
            while(!_tempTotalTickets.empty())
            {
                cout<<_tempTotalTickets.front().PrefixNumber<<" <-- ";
                _tempTotalTickets.pop();
            }
            cout<<endl;
        }

        void PrintTicketsLineLTR()
        {
            cout<<"\t\tTickets :  ";
            stack<TicketInfo> _StackTotalTickets=_ConvertFromQueueToStack(_TotalTickets);
            while(!_StackTotalTickets.empty())
            {
                cout<<_StackTotalTickets.top().PrefixNumber<<" --> ";
                _StackTotalTickets.pop();
            }
            cout<<endl;
        }

        void PrintAllTickets()
        {
            queue<TicketInfo> Temp=_TotalTickets;

            cout<<_Taps<<"      --Tickets--"<<endl;

            while(!Temp.empty())
            {
                cout<<"\t\t\t\t___________________________________\n"<<endl;
                cout<<_Taps<<"\t"<<Temp.front().PrefixNumber<<endl; 
                cout<<"\n"<<_Taps;
                Temp.front().TicketDate.Print();  //Date
                cout<<" - "<<Temp.front().TicketTime.TimeToString()<<endl;  //time
                cout<<_Taps<<"Wating Clients = "<<Temp.front().WatingClients<<endl;
                cout<<_Taps<<"  Serve Time In "<<endl;
                cout<<_Taps<<"  "<<Temp.front().ServeTime<<"."<<endl;
                cout<<"\t\t\t\t___________________________________\n"<<endl;
                
                Temp.pop();
            }
        }

        void _ServeNextclient()
        {
            _ServedClients++;
            _WatingClients--;
        }
};