#include <iostream>

using namespace std;

void GetInitials(string &Player1Name, string &Player2Name, char &Player1Symbol, char &Player2Symbol)
{
    cout << "Player 1 please enter your name : ";
    cin >> Player1Name;
    cout << "Player 2 please enter your name : ";
    cin >> Player2Name;
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
    cout << "   |   |   " << endl << endl;
}

int CheckForWin(char Board[][3],char Player1Symbol, char Player2Symbol)
{
    if (Board[0][0] == Player1Symbol && Board[0][1] == Player1Symbol && Board[0][2] == Player1Symbol)
    {
        return 1;
    }
    if (Board[1][0] == Player1Symbol && Board[1][1] == Player1Symbol && Board[1][2] == Player1Symbol)
    {
        return 1;
    }
    if (Board[2][0] == Player1Symbol && Board[2][1] == Player1Symbol && Board[2][2] == Player1Symbol)
    {
        return 1;
    }
    if (Board[0][0] == Player1Symbol && Board[1][0] == Player1Symbol && Board[2][0] == Player1Symbol)
    {
        return 1;
    }
    if (Board[0][1] == Player1Symbol && Board[1][1] == Player1Symbol && Board[2][1] == Player1Symbol)
    {
        return 1;
    }
    if (Board[0][2] == Player1Symbol && Board[1][2] == Player1Symbol && Board[2][2] == Player1Symbol)
    {
        return 1;
    }
    if (Board[0][0] == Player1Symbol && Board[1][1] == Player1Symbol && Board[2][2] == Player1Symbol)
    {
        return 1;
    }
    if (Board[2][0] == Player1Symbol && Board[1][1] == Player1Symbol && Board[0][2] == Player1Symbol)
    {
        return 1;
    }
    //Other Player
    if (Board[0][0] == Player2Symbol && Board[0][1] == Player2Symbol && Board[0][2] == Player2Symbol)
    {
        return 2;
    }
    if (Board[1][0] == Player2Symbol && Board[1][1] == Player2Symbol && Board[1][2] == Player2Symbol)
    {
        return 2;
    }
    if (Board[2][0] == Player2Symbol && Board[2][1] == Player2Symbol && Board[2][2] == Player2Symbol)
    {
        return 2;
    }
    if (Board[0][0] == Player2Symbol && Board[1][0] == Player2Symbol && Board[2][0] == Player2Symbol)
    {
        return 2;
    }
    if (Board[0][1] == Player2Symbol && Board[1][1] == Player2Symbol && Board[2][1] == Player2Symbol)
    {
        return 2;
    }
    if (Board[0][2] == Player2Symbol && Board[1][2] == Player2Symbol && Board[2][2] == Player2Symbol)
    {
        return 2;
    }
    if (Board[0][0] == Player2Symbol && Board[1][1] == Player2Symbol && Board[2][2] == Player2Symbol)
    {
        return 2;
    }
    if (Board[2][0] == Player2Symbol && Board[1][1] == Player2Symbol && Board[0][2] == Player2Symbol)
    {
        return 2;
    }
    return 0;
}

void GameManager(char Board[][3],string Player1Name, string Player2Name, char Player1Symbol, char Player2Symbol)
{
    int Occupied = 0;
    int CellNumber;
    int Win;
    for (int i=0; i < 6; i++)
    {
        Win = CheckForWin(Board, Player1Symbol, Player2Symbol);
        if (Win == 1)
        {
            cout << Player1Name << " wins !\n";
            break;
        }
        else if (Win == 2)
        {
            cout << Player2Name << " wins !\n";
            break;
        }
        cout << Player1Name << "'s turn.\nPlease enter the cell number you want to play : ";
        cin >> CellNumber;
        while (CellNumber < 0 || CellNumber > 9)
        {
            cout << "Invalid choice ! Please re-enter the cell number you want to play : ";
            cin >> CellNumber;
        }
        switch (CellNumber)
        {
            case 1:
                Board[0][0] = Player1Symbol;
                break;
            case 2:
                Board[0][1] = Player1Symbol;
                break;
            case 3:
                Board[0][2] = Player1Symbol;
                break;
            case 4:
                Board[1][0] = Player1Symbol;
                break;
            case 5:
                Board[1][1] = Player1Symbol;
                break;
            case 6:
                Board[1][2] = Player1Symbol;
                break;
            case 7:
                Board[2][0] = Player1Symbol;
                break;
            case 8:
                Board[2][1] = Player1Symbol;
                break;
            case 9:
                Board[2][2] = Player1Symbol;
                break;
            }
            DisplayGrid(Board);
            Occupied++;
            if (Occupied == 9)
            {
                break;
            }
            Win = CheckForWin(Board, Player1Symbol, Player2Symbol);
            if (Win == 1)
            {
                DisplayGrid(Board);
                cout << Player1Name << " wins !\n";
                break;
            }
            else if (Win == 2)
            {
                DisplayGrid(Board);
                cout << Player2Name << " wins !\n";
                break;
            }
            cout << Player2Name << "'s turn.\nPlease enter the cell number you want to play : ";
            cin >> CellNumber;
            while (CellNumber < 0 || CellNumber > 9)
            {
                cout << "Invalid choice ! Please re-enter the cell number you want to play : ";
                cin >> CellNumber;
            }
            switch (CellNumber)
            {
                case 1:
                    Board[0][0] = Player2Symbol;
                    break;
                case 2:
                    Board[0][1] = Player2Symbol;
                    break;
                case 3:
                    Board[0][2] = Player2Symbol;
                    break;
                case 4:
                    Board[1][0] = Player2Symbol;
                    break;
                case 5:
                    Board[1][1] = Player2Symbol;
                    break;
                case 6:
                    Board[1][2] = Player2Symbol;
                    break;
                case 7:
                    Board[2][0] = Player2Symbol;
                    break;
                case 8:
                    Board[2][1] = Player2Symbol;
                    break;
                case 9:
                    Board[2][2] = Player2Symbol;
                    break;
            }
            DisplayGrid(Board);
            Occupied++;
            if (Occupied == 9)
            {
                break;
            }
        }
        if (Win == 0 && Occupied == 9)
        {
            cout << "Draw !\n";
        }
}

int main()
{
    char Board[3][3] = {'1','2','3','4','5','6','7','8','9'};
    char Player1Symbol, Player2Symbol;
    string Player1Name, Player2Name;
    GetInitials(Player1Name,Player2Name,Player1Symbol,Player2Symbol);
    DisplayGrid(Board);
    GameManager(Board,Player1Name,Player2Name,Player1Symbol,Player2Symbol);
    return 0;
}