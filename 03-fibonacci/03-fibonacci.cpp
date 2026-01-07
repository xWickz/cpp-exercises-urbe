#include <iostream>
using namespace std;

/*
 * Escribe un programa que imprima los 50 primeros números de la sucesión
 * de Fibonacci empezando en 0.
 * - La serie Fibonacci se compone por una sucesión de números en
 *   la que el siguiente siempre es la suma de los dos anteriores.
 *   0, 1, 1, 2, 3, 5, 8, 13...
 */

int main() {

    long long t1_fibo = 0;
    long long t2_fibo = 1;
    long long temporal_fibo = 0;

    cout << t1_fibo << ", " << t2_fibo;

    for(int i = 0; i < 48; i++) {
        temporal_fibo = t2_fibo; // 1
        t2_fibo = t1_fibo + t2_fibo; // 0 + 1 
        t1_fibo = temporal_fibo;
        cout << ", " << t2_fibo ;
    }

    return 0;
}