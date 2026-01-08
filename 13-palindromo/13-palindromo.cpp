#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Escribe una función que reciba un texto y retorne verdadero o
 * falso (Boolean) según sean o no palíndromos.
 * Un Palíndromo es una palabra o expresión que es igual si se lee
  * de izquierda a derecha que de derecha a izquierda.
 * NO se tienen en cuenta los espacios, signos de puntuación y tildes.
 * Ejemplo: Ana lleva al oso la avellana.
 */

bool esPalindromo(const string& texto) {

    string replica = texto;

    // eliminar espacios y signos de puntuación, y convertir a minúsculas
    replica.erase(remove_if(replica.begin(), replica.end(),
        [](char c) { return !isalnum(c); }), replica.end());
    transform(replica.begin(), replica.end(), replica.begin(),
        [](unsigned char c) { return tolower(c); });

    string invertido = replica;
    reverse(invertido.begin(), invertido.end());
    if (replica == invertido) {
        return true;
    }

    return false;
}

int main() {

    string texto;
    cout << "Ingresa un texto: ";
    getline(cin, texto);

    if (esPalindromo(texto)) {
        cout << texto << " es un palíndromo\n";
    } else {
        cout << texto << " no es un palíndromo\n";
    }

    return 0;
}