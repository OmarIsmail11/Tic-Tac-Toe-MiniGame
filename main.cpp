#include <iostream>

using namespace std;

void GetInitials(string &Player1Name, string &Player2Name, char &Player1Symbol, char &Player2Symbol, int DiceRoll)
{
    
    srand(time(NULL));
    DiceRoll = 1 + (rand() % 2);
    cout << "Player 1 please enter your name : ";
    cin >> Player1Name;
    cout << "Player 2 please enter your name : ";
    cin >> Player2Name;
    cout << "A dice has been rolled and accordingly player " << DiceRoll << " will start.\n";
    if (DiceRoll == 1)
    {
        cout << Player1Name << " please choose your symbol to play with (X/O) : ";
        cin >> Player1Symbol;
        while (Player1Symbol != 'X' && Player1Symbol != 'O')
        {
            cout << "Invalid symbol ! Please re-enter your symbol (X/O) : ";
            cin >> Player1Symbol;
        }
        if (Player1Symbol == 'X')
        {
            Player2Symbol = 'O';
        }
        else
        {
            Player2Symbol = 'X';
        }
    }
    else
    {
        cout << Player2Name << " please choose your symbol to play with (X/O) : ";
        cin >> Player2Symbol;
        while (Player2Symbol != 'X' && Player2Symbol != 'O')
        {
            cout << "Invalid symbol ! Please re-enter your symbol (X/O) : ";
            cin >> Player2Symbol;
        }
        if (Player2Symbol == 'X')
        {
            Player1Symbol = 'O';
        }
        else
        {
            Player1Symbol = 'X';
        }
    }
    cout << Player1Name << " plays with symbol " << Player1Symbol << endl;
    cout << Player2Name << " plays with symbol " << Player2Symbol << endl;
}

void DisplayGrid(char Board[][3])
{
    cout << "   |   |  " << endl;
    cout << " " << Board[0][0] << " | " << Board[0][1] << " | " << Board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |  " << endl;
    cout << " " << Board[1][0] << " | " << Board[1][1] << " | " << Board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |  " << endl;
    cout << " " << Board[2][0] << " | " << Board[2][1] << " | " << Board[2][2] << endl;
    cout << "   |   |   " << endl;
}

int CheckForWin(char Board[][3],char Player1Symbol, char Player2Symbol)
{
    if (Board[0][0] = Player1Symbol && Board[0][1] == Player1Symbol && Board[0][2] == Player1Symbol)
    {
        return 1;
    }
    if (Board[0][0] = Player1Symbol && Board[1][0] == Player1Symbol && Board[2][0] == Player1Symbol)
    {
        return 1;
    }
    if (Board[0][0] = Player1Symbol && Board[0][1] == Player1Symbol && Board[0][2] == Player1Symbol)
    {
        return 1;
    }
}
int main()
{
    char Board[3][3] = {'1','2','3','4','5','6','7','8','9'};
    int PlayerToStart;
    char Player1Symbol, Player2Symbol;
    string Player1Name, Player2Name;
    int DiceRoll;
    int OccupiedCells = 0;
    GetInitials(Player1Name,Player2Name,Player1Symbol,Player2Symbol, DiceRoll);
    DisplayGrid(Board);
}