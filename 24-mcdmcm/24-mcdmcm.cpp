#include <iostream>
using namespace std;

/*
 * Crea dos funciones, una que calcule el máximo común divisor (MCD) y otra
 * que calcule el mínimo común múltiplo (mcm) de dos números enteros.
 * - No se pueden utilizar operaciones del lenguaje que
 *   lo resuelvan directamente.
*/

int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mcm(int a, int b) {
    return (a / mcd(a, b)) * b;
}

int main() {

    cout << mcd(48, 18) << "\n"; // 6
    cout << mcm(4, 5) << "\n";   // 20
    
    return 0;
}
