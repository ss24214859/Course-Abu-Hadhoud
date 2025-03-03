#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

enum enChoice{stone=1,peper=2,Scissor};
enum enWinner{Player1=1,computer=2,Draw=3};

struct stRoundInFo
{
    short RoundNumber;
    enChoice Player1Choise;
    enChoice ComputerChoise;
    enWinner RoundWinner;
    string  WinnerName;
};

struct stGameInfo
{
    short GameRounds
    ,Player1WonTimes
    ,ComputerWonTimes
    ,DrawTimes;
    enWinner GameWinner;
    string GameWinnerName;
};


string WinnerName(enWinner Winner)
{
    string WinnerName[3]={"You","Computer","No Winner"};
    return WinnerName[Winner-1];
}

string ChoiseName(enChoice Choise)
{
    string ChoiseName[3]={"Stone","Peper","Scissors"};
    return ChoiseName[Choise-1];
}
enWinner RoundWinner(stRoundInFo RoundInFo)
{
    if(RoundInFo.ComputerChoise==RoundInFo.Player1Choise)
        return enWinner::Draw;

    switch (RoundInFo.Player1Choise)
    {
    case enChoice::stone:
        if(RoundInFo.ComputerChoise==enChoice::peper)
        return enWinner::computer;
        break;
    case enChoice::peper:
        if(RoundInFo.ComputerChoise==enChoice::Scissor)
        return enWinner::computer;
        break;    
    case enChoice::Scissor:
        if(RoundInFo.ComputerChoise==enChoice::stone)
        return enWinner::computer;
        break;
    }

    return enWinner::Player1;
}

short ReadNumberInRang(short from,short to,string massge)
{
    short num=0;
    do
    {
        cout<<massge;
        cin>>num;
    }while(from>num||num>to);
    return num;
}

short RandomNumber(short From,short To)
{
    short Random=rand()%(To-From+1)+From;
    return Random;

}


void SetColorScreenOfWinner(enWinner Winner)
{
    if(Winner==enWinner::computer)
    system("color 4F")&& cout<<"\a"; // Red And Alarm
    else if(Winner==enWinner::Player1)
    system("color 2F");     //Green
    else
    system("color 6F");   //Yallow

}

bool ReadYesOrNo(string massage)
{
    char c='h';
    while(c!='y'||c!='n'||c!='Y' || c!='N')
    {
    cout<<massage;
    cin>>c;

    if(c=='y'||c=='Y')
    return true;
    else if(c=='n'||c=='N')
    {
    return false;
    }
    }
    return 0;
}
string Taps(short Number)
{
    string t="";
    for(short i=1;i<=Number;i++)
    {
        t=t+"\t";
        cout<<t;
    }
    return t;
}

enChoice ReadPlayer1Choise()
{
    return (enChoice) ReadNumberInRang(1,3,"Your Choise : Stone:[1],Peper:[2],Scissor:[3] ? ");
}

enChoice GetComputerChoise()
{
    return (enChoice)RandomNumber(1,3);
}

void PrintRoundResult(stRoundInFo RoundInFO)
{
    cout<<"\n_______________Round["<<RoundInFO.RoundNumber<<"]_______________\n\n";
    cout<<"You Choise : "<<ChoiseName(RoundInFO.Player1Choise)<<endl;
    cout<<"Computer Choise : "<<ChoiseName( RoundInFO.ComputerChoise)<<endl;
    cout<<"Round Winner : ["<<RoundInFO.WinnerName<<"]"<<endl;
    cout<<"__________________________________________"<<endl;
}

enWinner GameWinner(short Player1WinTimes,short ComputerWinTimes)
{
    if(Player1WinTimes>ComputerWinTimes)
        return enWinner::Player1;
    else if(ComputerWinTimes>Player1WinTimes)
        return enWinner::computer;
    else 
        return enWinner::Draw;        
}

stGameInfo FillGameInFo(short HowManyRounds,short ComputerWinTimes,short Player1WinTimes,short DrawTimes)
{
    stGameInfo GameInfo;
    GameInfo.GameRounds=HowManyRounds;
    GameInfo.Player1WonTimes=Player1WinTimes;
    GameInfo.ComputerWonTimes=ComputerWinTimes;
    GameInfo.DrawTimes=DrawTimes;
    GameInfo.GameWinner=GameWinner(Player1WinTimes,ComputerWinTimes);
    GameInfo.GameWinnerName=WinnerName(GameInfo.GameWinner);

    return GameInfo;
}



stGameInfo PlayGame(short HowManyRounds)
{
    stRoundInFo RoundInFo;
    short Player1WinTimes=0, ComputerWinTimes=0, DrawTimes=0;

    for(short GameRound=1;GameRound<=HowManyRounds;GameRound++)
    {
        RoundInFo.RoundNumber=GameRound;
        RoundInFo.Player1Choise=ReadPlayer1Choise();
        RoundInFo.ComputerChoise=GetComputerChoise();
        RoundInFo.RoundWinner=RoundWinner(RoundInFo);
        RoundInFo.WinnerName=WinnerName(RoundInFo.RoundWinner);

        PrintRoundResult(RoundInFo);
        SetColorScreenOfWinner(RoundInFo.RoundWinner);

        //Increse Win/Draw Times
        if(RoundInFo.RoundWinner==enWinner::computer)
        ComputerWinTimes++;
        else if(RoundInFo.RoundWinner==enWinner::Player1)
        Player1WinTimes++;
        else
        DrawTimes++;
    }

    return FillGameInFo(HowManyRounds,ComputerWinTimes,Player1WinTimes,DrawTimes);
}


void ShowGameOverScreen()
{
    cout<<Taps(2)<<"\n_________________________________________________\n\n";

    cout<<Taps(2)<<"             *** G A M E  O V E R ***";
    cout<<Taps(2)<<"\n_________________________________________________\n\n";
}

void ShowFinalGameResult(stGameInfo GameInFo)
{
    cout<<Taps(2)<<"_________________[ Game Result ]_________________\n\n";
    cout<<Taps(2)<<"Game Rounds : "<<GameInFo.GameRounds<<endl;
    cout<<Taps(2)<<"You Won times : "<<GameInFo.Player1WonTimes<<endl;
    cout<<Taps(2)<<"Computer Won times : "<<GameInFo.ComputerWonTimes<<endl;
    cout<<Taps(2)<<"Draw times : "<<GameInFo.DrawTimes<<endl;
    cout<<Taps(2)<<"Final Winner : ["<<GameInFo.GameWinnerName<<"]"<<endl;
    cout<<Taps(2)<<"_________________________________________________\n\n";
    SetColorScreenOfWinner(GameInFo.GameWinner);
}


void ResetScreen()
{
    system("CLS");
    system("Color 0F");
}

void StartGame()
{
    do
    {
        ResetScreen();
        short HowManyPlayRound=ReadNumberInRang(1,10,"How Many Rounds [1] To [10] ?");
        stGameInfo GameInFo=PlayGame(HowManyPlayRound);
        ShowFinalGameResult(GameInFo);

    } while (ReadYesOrNo("Do You Want Play Again ? Y/N ?"));
    
}


int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}