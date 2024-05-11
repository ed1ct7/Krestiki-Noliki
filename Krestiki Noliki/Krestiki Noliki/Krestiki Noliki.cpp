#include <iostream>
#include <string>
#include "windows.h"
#include <ctime> 

using namespace std;

class krestici_noliki {
public:
    krestici_noliki(bool first_move) {
        this->move_rigth = first_move;
        if (first_move) {
            Player = 1;
        }
        else {
            Player = 2;
        }
        
        cout << "place your sign";
        cout << "0 - left_up" << endl;
        cout << "1 - center_up" << endl;
        cout << "2 - right_up" << endl;
        cout << "3 - left_middle" << endl;
        cout << "4 - center_middle" << endl;
        cout << "5 - right_middle" << endl;
        cout << "6 - left_bottom" << endl;
        cout << "7 - center_bottom" << endl;
        cout << "8 - right_bottom" << endl;

    }

    void player_move() {
        while (move_rigth) {
            cin >> position;
            if (pfield[position] == 0) {
                pfield[position] = Player;
                move_rigth = false;
                break;
            }
            else {
                cout << "pole_zanayto";
                move_rigth = true;
                break;
            }
        }
    }
    
    void output() {
        int temp_field[9];
        string str_field;

        for (size_t i = 0; i < 9; i++)
        {
            temp_field[i] = pfield[i];
        }

        for (size_t i = 0; i < 9; i++)
        {
            if (temp_field[i] == 1) {
                str_field += 'X';
            }
            if (temp_field[i] == 2) {
                str_field += 'O';
            }
            if (temp_field[i] == 0) {
                str_field += ' ';
            }
        }
            cout << " | " << str_field[0] << " | " << str_field[1] << " | " << str_field[2] << " | " << endl;
            cout << " | " << str_field[3] << " | " << str_field[4] << " | " << str_field[5] << " | " << endl;
            cout << " | " << str_field[6] << " | " << str_field[7] << " | " << str_field[8] << " | " << endl;
    }

    void bot_move() {
        if (Player == 1) {
            Bot = 2;
        }
        else {
            Bot = 1;
        }
        while (!move_rigth) {
            
            srand((unsigned)time(0));
            int ran = (rand() % 9);
            position = ran;
            if (pfield[position] == 0) {
                pfield[position] = Bot;
                move_rigth = true;
                break;
            }
            else {
                cout << "pole_zanayto";
                move_rigth = false;
                break;
            }
        }
    }

    void bot_analizer() {

    }

    void game_over_checker() {
        
        int temp_field[9];
        int temp_matrix[3][3];

        for (size_t i = 0; i < 9; i++)
        {
            temp_field[i] = pfield[i];
        }
        ///////////////////////////////
        for (int x = 0; x < 3; ++x)
        {
            for (int k = 0; k < 3; ++k) {
                temp_matrix[x][k] = temp_field[3 * x + k];
            }
        }
        ///////////////////////////////
        for (int i = 0; i < 3; i++)
        {

            if ((temp_matrix[i][0] == temp_matrix[i][1] == temp_matrix[i][2])||
                (temp_matrix[0][i] == temp_matrix[1][i] == temp_matrix[2][i])||
                (temp_matrix[0][0] && temp_matrix[1][1] && temp_matrix[2][2])||
                (temp_matrix[2][2] && temp_matrix[1][1] && temp_matrix[0][0]))
            {
                    

            } 
        }
    }

    void game() {
        while (!gameOver) {
            player_move();
            output();
            system("cls");
            bot_move();
            output();
            game_over_checker();
        }
    }

private:
    
    int field[9]{0,0,0,0,0,0,0,0,0};
    int* pfield = field;

    int best_move_analizer[9]{ 1,0,1,0,2,0,1,0,1 };

    bool move_rigth;

    int position = 0;

    int Player = 0;
    int Bot;

    bool gameOver = false;
};

int main()
{
    krestici_noliki One(true);

    One.game();

    return 0;
}
