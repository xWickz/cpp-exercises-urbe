#include <iostream>
#include <cmath>
using namespace std;

/*
 * Escribe un programa que se encargue de comprobar si un número es o no primo.
 * Hecho esto, imprime los números primos entre 1 y 100.
 */

bool esPrimo(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int limite = static_cast<int>(sqrt(n));
    for (int d = 3; d <= limite; d += 2) {
        if (n % d == 0) return false;
    }
}

int main() {

    for (int i = 1; i <= 100; ++i) {
        cout << i << (esPrimo(i) ? " es primo" : " no es primo");
    }

    return 0;
}