#include <iostream>
using namespace std;

/*
 * Crea un programa que calcule quien gana más partidas al piedra,
 * papel, tijera.
 * - El resultado puede ser: "Player 1", "Player 2", "Tie" (empate)
 * - La función recibe un listado que contiene pares, representando cada jugada.
 * - El par puede contener combinaciones de "R" (piedra), "P" (papel)
 *   o "S" (tijera).
 * - Ejemplo. Entrada: [("R","S"), ("S","R"), ("P","S")]. Resultado: "Player 2".
*/

string piedraPapelTijeras(const pair<string, string> plays[], int size) {

    int score1 = 0;
    int score2 = 0;

    for (int i = 0; i < size; i++) {
        const string& p1 = plays[i].first;
        const string& p2 = plays[i].second;

        if (p1 == p2) {
            continue;
        } 
        else if (
            (p1 == "R" && p2 == "S") ||
            (p1 == "S" && p2 == "P") ||
            (p1 == "P" && p2 == "R")
        ) {
            score1++;
        } 
        else {
            score2++;
        }
    }

    if (score1 > score2) {
        return "Player 1";
    } 
    else if (score2 > score1) {
        return "Player 2";
    } 
    else {
        return "Tie";
    }
}

int main() {
    pair<string, string> plays1[] = {{"R","S"}, {"S","R"}, {"P","S"}};
    cout << piedraPapelTijeras(plays1, 3) << "\n"; // Player 2

    pair<string, string> plays2[] = {{"R","S"}, {"S","S"}, {"P","R"}};
    cout << piedraPapelTijeras(plays2, 3) << "\n"; // Player 1

    pair<string, string> plays3[] = {{"R","R"}, {"S","S"}, {"P","P"}};
    cout << piedraPapelTijeras(plays3, 3) << "\n"; // Tie

    return 0;
}
