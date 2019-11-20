#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void indexes(){
    cout << "0 1 2\n3 4 5\n6 7 8\n";
}

int clear_board(int *board) {
    for (int i = 0; i < 9; i++) {
        board[i] = 0;
    }
    return *board;
}

void show_board(int *board) {
    int n = 0;
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[n] == 0) {
                cout << "-" << ' ';
            }
            else if (board[n] == 1) {
                cout << "X" << ' ';
            }
            else if (board[n] == 2) {
                cout << "O" << ' ';
            }
            n++;
        }
        cout << endl;
    }
}

void player(int num, int *board){
    int x;
    cout << "Player " << num << " choose field you want to mark: ";
    do {
        cin >> x;
        if (x > 8 || x < 0) {
            x = -1;
        }
        if (board[x] != 0) {
            cout << "This field is already marked. Try different: ";
        }
    }while(board[x] != 0 && x == -1);
    board[x] = num;
    show_board(board);
}

bool win(int *b) {
    // horizontal check
    if (b[0] == b[1] && b[1] == b[2] && b[0] != 0) {
        cout << "Player " << b[0] << " wins.";
        return true;
    }
    if (b[3] == b[4] && b[4] == b[5] && b[3] != 0) {
        cout << "Player " << b[3] << " wins.";
        return true;
    }
    if (b[6] == b[7] && b[7] == b[8] && b[6] != 0) {
        cout << "Player " << b[6] << " wins.";
        return true;
    }
    // vertical check
    if (b[0] == b[3] && b[3] == b[6] && b[0] != 0) {
        cout << "Player " << b[0] << " wins.";
        return true;
    }
    if (b[1] == b[4] && b[4] == b[7] && b[1] != 0) {
        cout << "Player " << b[1] << " wins.";
        return true;
    }
    if (b[2] == b[5] && b[5] == b[8] && b[2] != 0) {
        cout << "Player " << b[2] << " wins.";
        return true;
    }
    // diagonal check
    if (b[0] == b[4] && b[4] == b[8] && b[0] != 0) {
        cout << "Player " << b[0] << " wins.";
        return true;
    }
    if (b[2] == b[4] && b[4] == b[6] && b[2] != 0) {
        cout << "Player " << b[2] << " wins.";
        return true;
    }
    return false;
}
void game(int *board) {
    for (int i = 0; i < 9; i++) {
        system("CLS");
        indexes();
        show_board(board);
        if(i % 2 == 0) {
            player(1,board);
        }
        else if(i % 2 == 1) {
            player(2,board);
        }
        if (win(board)) {
            break;
        }
        else if (i == 8) {
            cout << "It's a draw.";
        }
    }
}

int main()
{
    int board[9];
    indexes();
    clear_board(board);
    show_board(board);
    game(board);
    return 0;
}
