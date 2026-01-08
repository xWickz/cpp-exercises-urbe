#include <iostream>
using namespace std;

/*
 * Crea un programa que comprueba si los paréntesis, llaves y corchetes
 * de una expresión están equilibrados.
 * - Equilibrado significa que estos delimitadores se abren y cieran
 *   en orden y de forma correcta.
 * - Paréntesis, llaves y corchetes son igual de prioritarios.
 *   No hay uno más importante que otro.
 * - Expresión balanceada: { [ a * ( c + d ) ] - 5 }
 * - Expresión no balanceada: { a * ( c + d ) ] - 5 }
 */

int main() {

    string expresion;
    cout << "Ingresa una expresión: ";
    getline(cin, expresion);

    string pila = "";

    for (char c : expresion) {
        if (c == '(' || c == '{' || c == '[') {
            pila += c;
        } else if (c == ')' || c == '}' || c == ']') {

            if (pila.empty()) {
                cout << "La expresión no está balanceada." << endl;
                return 0;
            }   
            char ultimo = pila.back();
            pila.pop_back();
            if ((c == ')' && ultimo != '(') ||
                (c == '}' && ultimo != '{') ||
                (c == ']' && ultimo != '[')) {
                cout << "La expresión no está balanceada." << endl;
                return 0;
            }
        }
    }

    if (pila.empty()) {
        cout << "La expresión está balanceada." << endl;
    } else {
        cout << "La expresión no está balanceada." << endl;
    }

    return 0;    
}