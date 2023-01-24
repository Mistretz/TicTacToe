#include <iostream>
#include <vector>
using namespace std;



// Shows the grid while playing.
void show_table(vector<char> position) {


cout << "\n " << position[0] << " " << "|" << " " << position[1] << " " << "|" << " " << position[2] << " \n";
cout << " " << position[3] << " " << "|" << " " << position[4] << " " << "|" << " " << position[5] << " \n";
cout << " " << position[6] << " " << "|" << " " << position[7] << " " << "|" << " " << position[8] << " \n"; 

}

// Shows the grid, with numbers for the positions, so the player knows which number is which position.
void show_positions() {


    cout << "\n " << "1" << " " << "|" << " " << "2" << " " << "|" << " " << "3" << " \n";
    cout << " " << "4" << " " << "|" << " " << "5" << " " << "|" << " " << "6" << " \n";
    cout << " " << "7" << " " << "|" << " " << "8" << " " << "|" << " " << "9" << " \n";

}

//Greeting dialogue.
void greet(){

    cout << "\nHello and welcome to Tic-Tac-Toe!\n";
    cout << "Player One gets the X and Player Two gets the O.\n";
    cout << "Choose where to place your symbol by writing a number from 1 to 9!\n";
    cout << "Below you can see the positions on the game table and their corresponding numbers!\n";
    cout << "GLHF!\n";
}

//Shows the result at the end of the game.
void result(bool victory1, bool victory2) {

    if (victory1 == true)
    {
        cout << "\nVictory Player 1!\n";
    }
    else if (victory2 == true)
    {
        cout << "\nVictory Player 2!\n";
    }
    else {
        cout << "\nIt's a draw!\n";
    }

}

//The actual playing mechanisms for taking user input, checking if one of the players won, making sure one cannot write on top of the other.
void play(bool victory1, bool victory2, int turns, int choice, vector<char> position) {
    while (victory1 == false && victory2 == false && turns < 9) {

        if (turns % 2 == 0) {

            cout << "\nPlayer 1, it's your turn!\n";
            cin >> choice;
            while (position[choice - 1] != '-') {

                cout << "\nThat space is already taken! Please try again!\n";
                cin >> choice;
            }

            position[choice - 1] = 'X';

        }
        else {
            cout << "\nPlayer 2, it's your turn!\n";
            cin >> choice;
            while (position[choice - 1] != '-') {

                cout << "\nThat space is already taken! Please try again!\n";
                cin >> choice;
            }
            position[choice - 1] = 'O';
        }



        if ((position[0] == 'X' && position[1] == 'X' && position[2] == 'X') ||
            (position[3] == 'X' && position[4] == 'X' && position[5] == 'X') ||
            (position[6] == 'X' && position[7] == 'X' && position[8] == 'X') ||
            (position[0] == 'X' && position[3] == 'X' && position[6] == 'X') ||
            (position[1] == 'X' && position[4] == 'X' && position[7] == 'X') ||
            (position[2] == 'X' && position[5] == 'X' && position[8] == 'X') ||
            (position[0] == 'X' && position[4] == 'X' && position[8] == 'X') ||
            (position[2] == 'X' && position[4] == 'X' && position[6] == 'X'))
        {

            victory1 = true;
        }

        if ((position[0] == 'O' && position[1] == 'O' && position[2] == 'O') ||
            (position[3] == 'O' && position[4] == 'O' && position[5] == 'O') ||
            (position[6] == 'O' && position[7] == 'O' && position[8] == 'O') ||
            (position[0] == 'O' && position[3] == 'O' && position[6] == 'O') ||
            (position[1] == 'O' && position[4] == 'O' && position[7] == 'O') ||
            (position[2] == 'O' && position[5] == 'O' && position[8] == 'O') ||
            (position[0] == 'O' && position[4] == 'O' && position[8] == 'O') ||
            (position[2] == 'O' && position[4] == 'O' && position[6] == 'O'))
        {

            victory2 = true;
        }

        show_table(position);

        turns = turns + 1;

        
    }
    result(victory1, victory2);
}
