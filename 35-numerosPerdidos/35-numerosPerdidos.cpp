#include <iostream>
#include <vector>
using namespace std;

/*
 * Dado un array de enteros ordenado y sin repetidos,
 * crea una función que calcule y retorne todos los que faltan entre
 * el mayor y el menor.
 * - Lanza un error si el array de entrada no es correcto.
*/

vector<int> faltantes(const vector<int>& arr) {

    if (arr.size() < 2) 
        throw invalid_argument("Al menos 2 elementos requeridos");
    
    for (size_t i = 0; i < arr.size() - 1; i++) {
        if (arr[i] >= arr[i + 1])
            throw invalid_argument("Debe estar ordenado y sin repetidos");
    }

    vector<int> resultados;

    for (size_t i = 0; i < arr.size() - 1; i++) {
        int diff = arr[i + 1] - arr[i];

        if (diff > 1) {
            for (int n = arr[i] + 1; n < arr[i + 1]; n++) 
                resultados.push_back(n);
        }
    }

    return resultados;
}

int main() {

    vector<int> v = {2, 3, 6, 8};

    vector<int> f = faltantes(v);

    cout << "Faltantes: ";
    for (size_t i = 0; i < f.size(); i++) {
        cout << f[i] << " ";
    }
    cout << endl;

    return 0;
}