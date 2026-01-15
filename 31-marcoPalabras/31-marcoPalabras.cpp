#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

/*
 * Crea una función que reciba un texto y muestre cada palabra en una línea,
 * formando un marco rectangular de asteriscos.
 * - ¿Qué te parece el reto? Se vería así:
 *   **********
 *   * ¿Qué   *
 *   * te     *
 *   * parece *
 *   * el     *
 *   * reto?  *
 *   **********
 * 
*/

// Auxiliar
int findLargest(string str) {
    stringstream ss(str);
    string word;
    int maxLen = 0;
    while (ss >> word) {
        if (word.length() > maxLen) {
            maxLen = word.length();
        }
    }
    return maxLen;
}

string marcoPalabras(const string& texto) {

    string builder;
    int maxLength = findLargest(texto);

    // Tope del marco
    builder += string(maxLength + 4, '*') + '\n';

    // Palabras con marco lateral
    stringstream ss(texto);
    string word;
    while (ss >> word) {
        builder += "* " + word;
        builder += string(maxLength - word.length(), ' ');
        builder += " *\n";
    }

    // Fondo del marco
    builder += string(maxLength + 4, '*') + '\n';

    return builder;
}

int main() {
    string texto = "¿Qué te parece el reto?";
    cout << marcoPalabras(texto);

    string texto2 = "Hola Mundo";
    cout << marcoPalabras(texto2);

    return 0;
}