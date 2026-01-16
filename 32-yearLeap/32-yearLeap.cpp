#include <iostream>
using namespace std;

/*
 * Crea una función que imprima los 30 próximos años bisiestos
 * siguientes a uno dado.
 * - Utiliza el menor número de líneas para resolver el ejercicio.
*/

void yearLeap(int yearStart) {

    int contador = 0;
    int years = yearStart + 1;

    while (contador < 30) {
        if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0)) {
            cout << years << endl;
            contador++;
        }
        years++;
    }

    // nadas.dasd

}

int main() {
    int year;
    cout << "Introduce un año: ";
    cin >> year;
    yearLeap(year);
    return 0;
}