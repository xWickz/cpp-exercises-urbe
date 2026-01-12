#include <iostream>
using namespace std;

/*
 * Quiero contar del 1 al 100 de uno en uno (imprimiendo cada uno).
 * ¿De cuántas maneras eres capaz de hacerlo?
 * Crea el código para cada una de ellas.
*/

int main() {
    
    int contador = 0;

    // primera forma bucles : 20
    for (int i = 0; i < 20; i++) {
        cout << contador << "\n";
        contador++;   
    }

    // segunda forma : 40
    int iterador = 0;
    while (iterador < 20) {
        cout << contador << "\n";
        contador++;
        iterador++;
    }

    // tercera forma : 60
    iterador = 0;
    do {
        cout << contador << "\n";
        contador++;
        iterador++;
    } while (iterador < 20);

    // cuarta forma : 100
    iterador = 0;
    for (;;) {
        if (iterador >= 40) break;
        cout << contador << "\n";
        contador++;
        iterador++;
    }

    return 0;

}