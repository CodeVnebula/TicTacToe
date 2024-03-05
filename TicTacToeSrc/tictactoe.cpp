#include <iostream>
using namespace std;

void drawTable(char *spaces);
void getPlayer1(char *spaces, int player1);
void getPlayer2(char *spaces, int player2);
bool determineWinner(char *spaces, int player1, int player2);
bool Tie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1 = 'X', player2 = 'O';
    bool playing = true;

    drawTable(spaces);

    
    while (playing)
    {
        getPlayer1(spaces, player1); system("cls"); drawTable(spaces); 
        if(determineWinner(spaces, player1, player2))
        {
            playing = false; break;
        }
        else if(Tie(spaces))
        {
            playing = false; break;
        }
            
        
        getPlayer2(spaces, player2); system("cls"); drawTable(spaces);
        if(determineWinner(spaces, player1, player2))
        {
            playing = false; break;
        }
        else if(Tie(spaces))
        {
            playing = false; break;
        }
        
    } 

    return 0;
}

void drawTable(char *spaces)
{
    cout << "___________________\n";
    cout << "|     |     |     |\n";
    cout << "|  "<< spaces[0] <<"  |  " << spaces[1] <<"  |  "<< spaces[2] <<"  |\n";
    cout << "|_____|_____|_____|\n";
    cout << "|     |     |     |\n";
    cout << "|  "<< spaces[3] <<"  |  " << spaces[4] <<"  |  "<< spaces[5] <<"  |\n";
    cout << "|_____|_____|_____|\n";
    cout << "|     |     |     |\n";
    cout << "|  "<< spaces[6] <<"  |  " << spaces[7] <<"  |  "<< spaces[8] <<"  |\n";
    cout << "|_____|_____|_____|\n";
}
void getPlayer1(char *spaces,int player1)
{
    int number;
    do
    {
        cout << "Enter spot for(X), 1-9: ";
        cin >> number;
        number -= 1;
        if(spaces[number] == ' ')
        {
            spaces[number] = player1;
            break;
        }
    } while (number < 0 || number > 8 || spaces[number] == 'O');
    
}
void getPlayer2(char *spaces, int player2)
{
    int number;
    do
    {
        cout << "Enter spot for(O), 1-9: ";
        cin >> number;
        number -= 1;
        if(spaces[number] == ' ')
        {
            spaces[number] = player2;
            break;
        }
    } while (number < 0 || number > 8 || spaces[number] == 'X');
}
bool determineWinner(char *spaces, int player1, int player2)
{
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        spaces[0] == player1 ? cout << "player1 win\n" : cout << "player2 win\n";  
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        spaces[3] == player1 ? cout << "player1 win\n" : cout << "player2 win\n";  
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        spaces[6] == player1 ? cout << "player1 win\n" : cout << "player2 win\n";  
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        spaces[0] == player1 ? cout << "player1 win\n" : cout << "player2 win\n";  
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        spaces[1] == player1 ? cout << "player1 win\n" : cout << "player2 win\n";  
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        spaces[2] == player1 ? cout << "player1 win\n" : cout << "player2 win\n";  
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        spaces[0] == player1 ? cout << "player1 win\n" : cout << "player2 win\n";  
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        spaces[2] == player1 ? cout << "player1 win\n" : cout << "player2 win\n";  
    }
    else
    {
       return false; 
    } 
    
    return 1;
}
bool Tie(char *spaces)
{
    for(int i = 0; i < 9; i++)
    {
        if(spaces[i] == ' ')
        {
            return false;
        } 
    }
    cout << "Tie\n";
    return true;
}