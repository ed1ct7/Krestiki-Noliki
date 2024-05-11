#include <iostream>
#include <string>
#include "windows.h"
#include <ctime> 

using namespace std;

class krestici_noliki {
public:
    krestici_noliki(bool first_move) {
        this->your_move = first_move;
        if (first_move) {
            Pkr_or_nl = 1;
        }
        else {
            Pkr_or_nl = 2;
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
        while (your_move) {
            cin >> position;
            if (polEEE[position] == 0) {
                polEEE[position] = Pkr_or_nl;
                your_move = false;
                break;
            }
            else {
                cout << "pole_zanayto";
                your_move = true;
                break;
            }
        }
    }
    
    void output() {
        int tempPole[9];
        string pOle;

        for (size_t i = 0; i < 9; i++)
        {
            tempPole[i] = polEEE[i];
        }

        for (size_t i = 0; i < 9; i++)
        {
            if (tempPole[i] == 1) {
                pOle += 'X';
            }
            if (tempPole[i] == 2) {
                pOle += 'O';
            }
            if (tempPole[i] == 0) {
                pOle += ' ';
            }
        }
            cout << " | " << pOle[0] << " | " << pOle[1] << " | " << pOle[2] << " | " << endl;
            cout << " | " << pOle[3] << " | " << pOle[4] << " | " << pOle[5] << " | " << endl;
            cout << " | " << pOle[6] << " | " << pOle[7] << " | " << pOle[8] << " | " << endl;    
    }

    void bot_move() {
        if (Pkr_or_nl == 1) {
            Bkr_or_nl = 2;
        }
        else {
            Bkr_or_nl = 1;
        }
        while (!your_move) {
            srand((unsigned)time(0));
            int ran = (rand() % 9);
            position = ran;
            if (polEEE[position] == 0) {
                polEEE[position] = Bkr_or_nl;
                your_move = true;
                break;
            }
            else {
                cout << "pole_zanayto";
                your_move = false;
                break;
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
        }
    }

    int pole[9]{ 0,0,0,0,0,0,0,0,0 };
    int* polEEE = pole;

    int position_analizer = 0;

    bool your_move;
    int position = 0;
    int Pkr_or_nl = 0;
    int Bkr_or_nl;

    bool gameOver = false;

    void analizer() {

    }
};

int main()
{
    krestici_noliki One(true);

    One.game();

    return 0;
}
