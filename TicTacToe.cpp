#include <iostream>
using namespace std;

char board[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char currentPlayer = 'X';

void displayBoard()
{
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWinner()
{
    // Rows
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return true;
    }

    // Columns
    for(int i=0;i<3;i++)
    {
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return true;

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return true;

    return false;
}

int main()
{
    int choice;
    int moves = 0;

    cout << "===== TIC TAC TOE =====\n";

    while(true)
    {
        displayBoard();

        cout << "\nPlayer " << currentPlayer << ", enter position (1-9): ";
        cin >> choice;

        bool validMove = true;

        switch(choice)
        {
            case 1:
                if(board[0][0]=='1') board[0][0]=currentPlayer;
                else validMove=false;
                break;

            case 2:
                if(board[0][1]=='2') board[0][1]=currentPlayer;
                else validMove=false;
                break;

            case 3:
                if(board[0][2]=='3') board[0][2]=currentPlayer;
                else validMove=false;
                break;

            case 4:
                if(board[1][0]=='4') board[1][0]=currentPlayer;
                else validMove=false;
                break;

            case 5:
                if(board[1][1]=='5') board[1][1]=currentPlayer;
                else validMove=false;
                break;

            case 6:
                if(board[1][2]=='6') board[1][2]=currentPlayer;
                else validMove=false;
                break;

            case 7:
                if(board[2][0]=='7') board[2][0]=currentPlayer;
                else validMove=false;
                break;

            case 8:
                if(board[2][1]=='8') board[2][1]=currentPlayer;
                else validMove=false;
                break;

            case 9:
                if(board[2][2]=='9') board[2][2]=currentPlayer;
                else validMove=false;
                break;

            default:
                validMove=false;
        }

        if(!validMove)
        {
            cout << "\nInvalid Move! Try Again.\n";
            continue;
        }

        moves++;

        if(checkWinner())
        {
            displayBoard();
            cout << "\n🎉 Player " << currentPlayer << " Wins!\n";
            break;
        }

        if(moves==9)
        {
            displayBoard();
            cout << "\n🤝 Match Draw!\n";
            break;
        }

        if(currentPlayer=='X')
            currentPlayer='O';
        else
            currentPlayer='X';
    }

    cout << "\nThanks for playing!\n";

    return 0;
}