#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <random>

using namespace std;

/*
 * Crea una función que analice una matriz 3x3 compuesta por "X" y "O"
 * y retorne lo siguiente:
 * - "X" si han ganado las "X"
 * - "O" si han ganado los "O"
 * - "Empate" si ha habido un empate
 * - "Nulo" si la proporción de "X", de "O", o de la matriz no es correcta.
 *   O si han ganado los 2.
 * Nota: La matriz puede no estar totalmente cubierta.
 * Se podría representar con un vacío "", por ejemplo.
 */

unordered_map<char, string> moves = {
        {'x', "X"},
        {'o', "O"},
        {' ', ""}
};

void fillRandomBoard(string board[3][3]) {
    static random_device rd;
    static mt19937 gen(rd());
    static array<char, 3> keys = {'x', 'o', ' '};
    uniform_int_distribution<int> dist(0, static_cast<int>(keys.size()) - 1);

    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            char k = keys[dist(gen)];
            board[r][c] = moves[k];
        }
    }
}

void printBoard(const string board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        cout << (board[i][0].empty() ? "." : board[i][0])
            << (board[i][1].empty() ? "." : board[i][1])
            << (board[i][2].empty() ? "." : board[i][2]) << "\n";
    }
}

string checkWinner(const string board[3][3]) {
    
    for (int i = 0; i < 3; ++i) {
        // FILA
        if (!board[i][0].empty() && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        // COLUMNA
        if (!board[0][i].empty() && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // DIAGONAL
    if (!board[0][0].empty() && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (!board[0][2].empty() && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    /* pending: empate */
    
    return "Nulo"; // Placeholder
}

int main() {

    string board[3][3];
    fillRandomBoard(board);
    printBoard(board);
    cout << "\n" << checkWinner(board);
    return 0;

}