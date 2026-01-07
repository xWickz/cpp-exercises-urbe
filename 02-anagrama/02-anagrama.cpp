#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

/*
 * Escribe una función que reciba dos palabras (String) y retorne
 * verdadero o falso (Bool) según sean o no anagramas.
 * - Un Anagrama consiste en formar una palabra reordenando TODAS
 *   las letras de otra palabra inicial.
 * - NO hace falta comprobar que ambas palabras existan.
 * - Dos palabras exactamente iguales no son anagrama.
 */

string normalizar(const string& frase) {
    string s = frase;
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return tolower(c);
    });
    sort(s.begin(), s.end());
    return s;
}

int main() {

    string palabra1;
    string palabra2;

    cout << "Ingrese la palabra 1: ";
    cin >> palabra1;

    cout << "Ingrese la palabra 2: ";
    cin >> palabra2;

    if (palabra1 == palabra2) {
        cout << "No son anagramas (son iguales)" << '\n';
        return 0;
    }

    string norm1 = normalizar(palabra1);
    string norm2 = normalizar(palabra2);

    bool esAnagrama = norm1 == norm2;
    cout << (esAnagrama ? "Son anagramas" : "No son anagramas") << '\n';

    return 0;
}

