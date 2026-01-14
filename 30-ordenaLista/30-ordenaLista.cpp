#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Crea una función que ordene y retorne una matriz de números.
 * - La función recibirá un listado (por ejemplo [2, 4, 6, 8, 9]) y un parámetro
 *   adicional "Asc" o "Desc" para indicar si debe ordenarse de menor a mayor
 *   o de mayor a menor.
 * - No se pueden utilizar funciones propias del lenguaje que lo resuelvan
 *   automáticamente.
*/

vector<int> sorting(vector<int> arr, const string& order) {
   
    const int n = static_cast<int>(arr.size());

    if (order == "Asc") {
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    } else if (order == "Desc") {
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    } else {
        return arr; // Si el orden no es válido, retorna la lista sin cambios
    }

    return arr;
}

int main() {

    vector<int> sorted_list = sorting({5, 3, 8, 6, 2}, "Asc");
    vector<int> unsorted_list = sorting({5, 3, 8, 6, 2}, "Desc"); 
    vector<int> list = sorting({5, 3, 8, 6, 2}, "zzz"); // orden no válido

    for (int num : sorted_list) {
        cout << num << " ";
    }
    cout << endl;

    for (int num : unsorted_list) {
        cout << num << " ";
    }

    cout << endl;

    for (int num : list) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}