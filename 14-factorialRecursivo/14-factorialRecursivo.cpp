#include <iostream>
using namespace std;

/*
 * Escribe una función que calcule y retorne el factorial de un número dado
 * de forma recursiva.
 */

int factorial(int n) {
    if (n <= 1) 
        return 1;
    
    return n * factorial(n - 1);
}

int main() {
    int numero;
    cout << "ingresa un numero para calcular su factorial: ";
    cin >> numero;

    if (numero < 0) {
        cout << "no se puede\n";
    } else {
        cout << "El factorial de " << numero << " es " << factorial(numero) << endl;
    }

    return 0;
}