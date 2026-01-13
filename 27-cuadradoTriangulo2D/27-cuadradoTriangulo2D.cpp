#include <iostream>
#include <string>
using namespace std;

/*
 * Crea un programa que dibuje un cuadrado o un triángulo con asteriscos "*".
 * - Indicaremos el tamaño del lado y si la figura a dibujar es una u otra.
 * - EXTRA: ¿Eres capaz de dibujar más figuras?
*/

int main() {

    string resultado;
    const int size = 5;

    // cuadrado
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size-1 || j == 0 || j == size-1) {
                resultado += "*";
            } else {
                resultado += " ";
            }
        }
        resultado += "\n";
    }

    // triangulo
    string resultadoTriangulo;
    for (int i = 1; i <= size; i++) {

        for (int j = 1; j <= size-i; j++) 
            resultadoTriangulo += " ";

            for (int k = 1; k <= 2*i-1; k++) {
                resultadoTriangulo += "*";
                
            }

            resultadoTriangulo += "\n";
    }

    cout << resultado << "\n";
    cout << resultadoTriangulo << "\n";

    return 0;
}