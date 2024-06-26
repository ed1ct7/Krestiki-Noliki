﻿#include <iostream>
#include <string>  

using namespace std;

int arr_symbols_count(int begin, int arr[], int symbol, int* loc, int modifier) {
    int symbol_count = 0;
    int pupupu = begin;
    for (size_t i = 0; i < 3; i++)
    {
        if (arr[pupupu] == symbol)
        {
            symbol_count++;
            *loc = pupupu;
        }
        pupupu = pupupu + modifier;
    }
    return symbol_count;
}

int arr_symbols_count(int begin, int end, int arr[], int symbol) {
    int symbol_count = 0;
    for (size_t i = begin; i < end; i++)
    {
        if (arr[i] == symbol)
        {
            symbol_count++;
        }
    }
    return symbol_count;
}

int arr_symbols_count(int begin, int arr[], int symbol, int modifier) {
    int symbol_count = 0;
    int pupupu = begin;
    for (size_t i = 0; i < 3; i++)
    {
        if (arr[pupupu] == symbol)
        {
            symbol_count++;

        }
        pupupu = pupupu + modifier;
    }
    return symbol_count;
}

class krestici_noliki {
public:
    krestici_noliki() {
        int first_move = 0;
        cout << "First to move?" << endl;
        cout << "0 - no" << endl;
        cout << "1 - yes" << endl << endl;
        cin >> first_move;
        cout << endl;

        this->move_rigth = first_move;
        if (first_move) {
            this->Player = 1;
            this->Bot = 2;
            this->best_move_analizer[4] = 3;
        }
        else {
            this->Player = 2;
            this->Bot = 1;
        }
    }

    void player_move() {
        while (this->move_rigth) {
            cin >> position;
            if (position > 8 || position < 0) {
                cout << "ne_dostupno" << endl;
                this->move_rigth = true;
                continue;
            }
            else if (this->pfield[position] == 0) {
                this->pfield[position] = this->Player;
                this->move_rigth = false;

                this->best_move_analizer[position] = -1;

                this->best_move = -1;
                continue;
            }
            else {
                cout << "pole_zanayto" << endl;
                this->move_rigth = true;
                continue;
            }
        }
    }
    
    void output() {

        cout << "place your sign" << endl;
        cout << "0 - left_up" << endl;
        cout << "1 - center_up" << endl;
        cout << "2 - right_up" << endl;
        cout << "3 - left_middle" << endl;
        cout << "4 - center_middle" << endl;
        cout << "5 - right_middle" << endl;
        cout << "6 - left_bottom" << endl;
        cout << "7 - center_bottom" << endl;
        cout << "8 - right_bottom" << endl;

        string str_field;

        for (size_t i = 0; i < 9; i++)
        {
            if (this->pfield[i] == 1) {
                str_field += 'X';
            }
            if (this->pfield[i] == 2) {
                str_field += 'O';
            }
            if (this->pfield[i] == 0) {
                str_field += ' ';
            }
        }
            cout << " | " << str_field[0] << " | " << str_field[1] << " | " << str_field[2] << " | " << endl;
            cout << " | " << str_field[3] << " | " << str_field[4] << " | " << str_field[5] << " | " << endl;
            cout << " | " << str_field[6] << " | " << str_field[7] << " | " << str_field[8] << " | " << endl;
    }

    void bot_analizer() {

        int ploc = 0;

        ///////////////////Compl tactics/////////////////////

        if (this->move_count == 2 && this->move_rigth == false)
        {
            if (arr_symbols_count(2, this->pfield, this->Bot, 2) == 1 && arr_symbols_count(2, this->pfield, 0, &ploc, 2) >= 1 && arr_symbols_count(2, this->pfield, this->Player, 2) == 1) {
                this->best_move_analizer[ploc + 1] += 3;
            }
            if (arr_symbols_count(0, this->pfield, this->Bot, 4) == 1 && arr_symbols_count(0, this->pfield, 0, &ploc, 4) >= 1 && arr_symbols_count(0, this->pfield, this->Bot, 4) == 1) {
                this->best_move_analizer[ploc] += 3;
            }
            if (this->pfield[4] == 0) {
                this->best_move_analizer[4] += 4;
            }
        }

        if (this->move_count == 3 && this->move_rigth == false)
        {
            if (arr_symbols_count(2, this->pfield, this->Player, 2) == 2 && arr_symbols_count(2, this->pfield, 1, &ploc, 2) >= 1) {
                this->best_move_analizer[1] += 2;
            }
            if (arr_symbols_count(0, this->pfield, this->Player, 4) == 2 && arr_symbols_count(0, this->pfield, 1, &ploc, 4) >= 1) {
                this->best_move_analizer[1] += 2;
            }
        }

        if (this->move_count == 4 && this->move_rigth == false)
        {
            for (size_t i = 0; i < 3; i++ )
        {
            if ((arr_symbols_count(i * 3, this->pfield, this->Bot, 1) == 1 && arr_symbols_count(i * 3, this->pfield, this->Player, 1) == 1) && arr_symbols_count(i * 3, this->pfield, 0, &ploc, 1) == 1) {
                this->best_move_analizer[ploc] -= 2;
            }
            else if ((arr_symbols_count(i, this->pfield, this->Bot, 3) == 1 && arr_symbols_count(i, this->pfield, this->Player, 3) == 1) && arr_symbols_count(i, this->pfield, 0, &ploc, 3) == 1) {
                this->best_move_analizer[ploc] -= 2;
            }
        }
        }

        ///////////////////Compl tactics/////////////////////
       

        for (size_t i = 0; i < 3; i++ )
        {
            if ((arr_symbols_count(i * 3, this->pfield, this->Bot, 1) == 2 || arr_symbols_count(i * 3, this->pfield, this->Player, 1) == 2) && arr_symbols_count(i * 3, this->pfield, 0, &ploc, 1) == 1) {
                this->best_move_analizer[ploc] += 4;
            }
            else if ((arr_symbols_count(i, this->pfield, this->Bot, 3) == 2 || arr_symbols_count(i, this->pfield, this->Player, 3) == 2) && arr_symbols_count(i, this->pfield, 0, &ploc, 3) == 1) {
                this->best_move_analizer[ploc] += 4;
            }
        }

        if ((arr_symbols_count(0, this->pfield, this->Bot, 4) == 2 || arr_symbols_count(0, this->pfield, this->Player, 4) == 2) && arr_symbols_count(0, this->pfield, 0, &ploc, 4) == 1) {
                this->best_move_analizer[ploc] += 4;
        }
        if ((arr_symbols_count(2, this->pfield, this->Bot, 2) == 2 || arr_symbols_count(2, this->pfield, this->Player, 2) == 2) && arr_symbols_count(2, this->pfield, 0, &ploc, 2) == 1) {
                this->best_move_analizer[ploc] += 4;
        }

        /////////////////////////////////////////////////////////////////////////////

        for (int i = 0; i < 9; ++i) {
            if (this->best_move_analizer[i] > this->best_move) {
                this->best_move = this->best_move_analizer[i];
                best_move_position = i;
            }
        }
    }

    void bot_move() {
            if (!this->move_rigth) {
                this->pfield[best_move_position] = Bot;
                this->best_move_analizer[best_move_position] = -1;
                best_move_position = 0;
                this->best_move = -1;
                this->move_rigth = true;
            }
            else {
                this->move_rigth = false;
            }
    }

    void game_over_checker() {

        if (arr_symbols_count(0,8, this->pfield,0) == 0) {
            gameOver = true;
            this->who_won = 3;
        }

        for (size_t i = 0; i < 3; i++)
        {
            if (arr_symbols_count(i * 3, this->pfield, this->Bot, 1) == 3 || arr_symbols_count(i, this->pfield, this->Bot, 3) == 3) {
                who_won = 2;
                gameOver = true;
            }else if (arr_symbols_count(i * 3, this->pfield, this->Player, 1) == 3 || arr_symbols_count(i, this->pfield, this->Player, 3) == 3) {
                who_won = 1;
                gameOver = true;
            }
        }

        if (arr_symbols_count(0, this->pfield, this->Bot, 4) == 3 || arr_symbols_count(2, this->pfield, this->Bot, 2) == 3) {
            who_won = 2;
            gameOver = true;
        }
        else if (arr_symbols_count(0, this->pfield, this->Player, 4) == 3 || arr_symbols_count(2, this->pfield, this->Player,  2) == 3) {
            who_won = 1;
            gameOver = true;
        }
    }

    void game() {
        while(!this->gameOver) {  
            output();
            bot_analizer();
            if (this->move_rigth) {
                player_move();
                this->move_count++;
            }
            else {
                bot_move();
                this->move_count++;
            }
            game_over_checker();
            system("cls");
        }
        output();
        switch (this->who_won) {
        case 1:
            cout << "You won";
            break;
        case 2:
            cout << "You lost";
            break;
        case 3:
            cout << "Draw";
            break;
        }
    }

private: 
    int pfield[9]{ 0,0,0,0,0,0,0,0,0 };
    int position = 0;

    int best_move = 0;
    int best_move_position=4;
    int best_move_analizer[9]{ 2,0,2,0,1,0,2,0,2 };
    
    int Player = 0;
    int Bot;

    int who_won = 0;
    bool gameOver = false;
    bool move_rigth;

    int move_count = 0;
};

int main()
{
    krestici_noliki One;
    One.game();

    return 0;
}
