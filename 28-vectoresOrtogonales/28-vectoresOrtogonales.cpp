#include <iostream>
using namespace std;

/*
 * Crea un programa que determine si dos vectores son ortogonales.
 * - Los dos array deben tener la misma longitud.
 * - Cada vector se podría representar como un array. Ejemplo: [1, -2]
*/

bool areOrthogonal(const int vectorA[], const int vectorB[], int size) {
    int dotProduct = 0;
    for (int i = 0; i < size; i++) {
        dotProduct += vectorA[i] * vectorB[i];
    }
    return dotProduct == 0;
}

int main() {
    int vectorA[] = {1, -2, 3};
    int vectorB[] = {2, 1, 0};

    if (areOrthogonal(vectorA, vectorB, 3)) {
        cout << "Los vectores son ortogonales.\n";
    } else {
        cout << "Los vectores no son ortogonales.\n";
    }

    return 0;
}