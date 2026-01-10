#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

/*
 * Crea una función que sume 2 números y retorne su resultado pasados
 * unos segundos.
 * - Recibirá por parámetros los 2 números a sumar y los segundos que
 *   debe tardar en finalizar su ejecución.
 * - Si el lenguaje lo soporta, deberá retornar el resultado de forma
 *   asíncrona, es decir, sin detener la ejecución del programa principal.
 *   Se podría ejecutar varias veces al mismo tiempo.
*/

int asyncSum(const int& n1, const int& n2, const int& timer) {
    this_thread::sleep_for(chrono::seconds(timer));
    return (n1 + n2);
}

int main() {

    int n1, n2, time;
    cout << "Ingrese el numero 1: ";
    cin >> n1;
    cout << "Ingrese el numero 2: ";
    cin >> n2;
    cout << "Ingresa el tiempo que debe tardar en finalizar su ejecucion: ";
    cin >> time;

    cout << asyncSum(n1, n2, time);
    return 0;
}