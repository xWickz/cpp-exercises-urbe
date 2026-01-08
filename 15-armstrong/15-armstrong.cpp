#include <iostream>
#include <cmath>
using namespace std;

/*
 * Escribe una función que calcule si un número dado es un número de Armstrong
 * (o también llamado narcisista).
 * Si no conoces qué es un número de Armstrong, debes buscar información
 * al respecto.
*/

bool armstrong(int numero) {

    int suma = 0;
    int n = to_string(numero).length();
    string numeros = to_string(numero);
    for (int i = 0; i < n; i++)
        suma += pow(numeros[i] - '0', n);

    return (suma == numero ? true : false);

}

int main() {

    int numero;
    cout << "Ingresa el numero: ";
    cin >> numero;

    if(armstrong(numero)) {
        cout << numero << " es un numero de Armstrong\n";
    } else {
        cout << numero << " no es un numero de Armstrong\n";
    }

    return 0;
}
