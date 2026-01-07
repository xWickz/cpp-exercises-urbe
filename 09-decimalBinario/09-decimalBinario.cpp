#include <iostream>
using namespace std;

/*
 * Crea un programa se encargue de transformar un número
 * decimal a binario sin utilizar funciones propias del lenguaje que lo hagan directamente.
 */

int main() {
    int numero = 0;
    cout << "Ingresa el numero decimal: ";
    cin >> numero;

    string binario = "";
    while (numero > 0) {
        if (numero % 2 == 0) { // entero
            binario = "0" + binario;
        } else {
            binario = "1" + binario;
        }
        numero = numero / 2;
    }

    if (binario == "") binario = "0";

    cout << "El numero en binario es: " << binario;
}