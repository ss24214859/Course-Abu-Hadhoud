#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "C:\CoursesMohamedAbuHadoud\MyLiberary\MyLib.h"
using namespace std;

struct stPlayerInFo
{
    string Name = "";
    int Whopen = 0;
    int Won = 0;
    int Losse = 0;
    int Draw = 0;
};

enum enWhopen
{
    rock = 1,
    pepper = 2,
    scissor = 3
};
enum enWiner
{
    NoWiner = 0,
    Player1 = 1,
    Player2 = 2,
};

void GetPlayersChoice(stPlayerInFo &Player1, stPlayerInFo &Player2)
{
    Player1.Whopen = (enWhopen)Random::RandomNumber(1, 3);
    Player2.Whopen = (enWhopen)IO::ReadIntNumberBetween(1, 3, "enter your choice? rock:[1],Pepper[2],scissor[3]?");
}

string PrintPlayerChoice(stPlayerInFo Player)
{

    string Print = "";
    if (Player.Whopen == enWhopen::rock)
    {
        Print = Player.Name + " Choice : Rock \n";
        return Print;
    }
    else if (Player.Whopen == enWhopen::pepper)
    {
        Print = Player.Name + " Choice : pepper \n";
        return Print;
    }
    else if (Player.Whopen == enWhopen::scissor)
    {

        Print = Player.Name + " Choice : scissor \n";
        return Print;
    }
    else
    {
        return "wrong Number";
    }
}

enWiner RoundWiner(stPlayerInFo &Player1, stPlayerInFo &Player2)
{

    if (Player1.Whopen == enWhopen::rock)
    {
        if (Player2.Whopen == enWhopen::rock)
            return enWiner::NoWiner;
        else if (Player2.Whopen == enWhopen::pepper)
            return enWiner::Player2;
        else if (Player2.Whopen == enWhopen::scissor)
            return enWiner::Player1;
    }

    else if (Player1.Whopen == enWhopen::pepper)
    {
        if (Player2.Whopen == enWhopen::rock)
            return enWiner::Player1;
        else if (Player2.Whopen == enWhopen::pepper)
            return enWiner::NoWiner;
        else if (Player2.Whopen == enWhopen::scissor)
            return enWiner::Player2;
    }

    else if (Player1.Whopen == enWhopen::scissor)
    {
        if (Player2.Whopen == enWhopen::rock)
            return enWiner::Player2;
        else if (Player2.Whopen == enWhopen::pepper)
            return enWiner::Player1;
        else if (Player2.Whopen == enWhopen::scissor)
            return enWiner::NoWiner;
    }
    return enWiner::NoWiner;
}

void CalculationPlayersPointsOfRound(stPlayerInFo &Player1, stPlayerInFo &Player2, enWiner RoundWiner)
{
    if (RoundWiner == enWiner::Player1)
    {
        Player1.Won++;
        Player2.Losse++;
    }
    else if (RoundWiner == enWiner::Player2)
    {
        Player2.Won++;
        Player1.Losse++;
    }
    else
    {
        Player1.Draw++;
        Player2.Draw++;
    }
}

string WinerName(stPlayerInFo Player1, stPlayerInFo Player2, enWiner Winer)
{
    if (Winer == enWiner::Player1)
        return Player1.Name;

    else if (Winer == enWiner::Player2)
        return Player2.Name;
    else
        return "No Winer";
}

void screenColorOfRounResult(enWiner Winer)
{
    if (Winer == enWiner::Player1)
    {
        system("color 4F");
        cout << "\a";
    }
    else if (Winer == enWiner::Player2)
        system("color 2F");
    else if (Winer == enWiner::NoWiner)
        system("color 6F");
}

void PrintResultOfRound(stPlayerInFo Player1, stPlayerInFo Player2)
{
    enWiner Winer = RoundWiner(Player1, Player2);
    cout << PrintPlayerChoice(Player1);
    cout << PrintPlayerChoice(Player2);
    cout << "Round Winer : (" << WinerName(Player1, Player2, Winer) << " ) \n";

    screenColorOfRounResult(Winer);
}

void Round(stPlayerInFo &Player1, stPlayerInFo &Player2, short RoundNumber)
{

    cout << "Round [" << RoundNumber << "] Begins\n";
    GetPlayersChoice(Player1, Player2);

    cout << "___________Round [" << RoundNumber << "] ____________\n";
    PrintResultOfRound(Player1, Player2);
    cout << "\n_________________________________________________\n";

    CalculationPlayersPointsOfRound(Player1, Player2, RoundWiner(Player1, Player2));
}

string NameOfFinalWiner(stPlayerInFo Player1, stPlayerInFo Player2)
{
    if (Player1.Won > Player2.Won)
        return Player1.Name;
    else if (Player1.Won < Player2.Won)
        return Player2.Name;
    else if (Player1.Won == Player2.Won)
        return "No Winer";

    return 0;
}

void GameOvermenu(stPlayerInFo Player1, stPlayerInFo Player2)
{
    string t = "            ";

    cout << t << "_________________________________________________\n\n";

    cout << t << "             *** G A M E  O V E R ***\n";
    cout << t << "_________________________________________________\n\n";

    cout << t << "_________________[ Game Result ]_________________\n\n";

    cout << t << "Game Rounds        : " << Player1.Won + Player2.Won + Player1.Draw << "\n";
    cout << t << Player1.Name << " Won Times : " << Player1.Won << "\n";
    cout << t << Player2.Name << " Won Times      : " << Player2.Won << "\n";
    cout << t << "Draw Times         : " << Player1.Draw << "\n";
    cout << t << "Final Winner       : " << NameOfFinalWiner(Player1, Player2) << "\n\n";
    cout << t << "_________________________________________________\n\n";
}

bool ReadYesOrNo(string massage)
{
    char c = 'h';
    while (c != 'y' || c != 'n' || c != 'Y' || c != 'N')
    {
        cout << massage;
        cin >> c;

        if (c == 'y' || c == 'Y')
            return true;
        else if (c == 'n' || c == 'N')
            return false;
    }
    return 0;
}

void ClearData(stPlayerInFo &Player1, stPlayerInFo &Player2)
{
    Player1.Won = 0;
    Player1.Losse = 0;
    Player1.Draw = 0;
    Player2.Won = 0;
    Player2.Losse = 0;
    Player2.Draw = 0;
}

void startGame(stPlayerInFo &Player1, stPlayerInFo &Player2)
{
    system("CLS");
    system("color 0F");
    int NumberOfRounds = IO::ReadIntNumberBetween(1, 10, "How Many Rounds [1] To [10] ?");

    for (int i = 0; i < NumberOfRounds; i++)
    {
        Round(Player1, Player2, i + 1);
    }

    GameOvermenu(Player1, Player2);
    ClearData(Player1, Player2);
}

void Game()
{
    srand((unsigned)time(NULL));
    stPlayerInFo Player1, Player2;

    Player1.Name = "Computer";
    Player2.Name = "You";

    bool Again = true;

    while (Again)
    {
        startGame(Player1, Player2);
        Again = ReadYesOrNo("Do You Want Play Again? y/n?");
    }
}

int main()

{
    // Game();
}
