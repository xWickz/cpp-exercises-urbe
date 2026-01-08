#include <iostream>
using namespace std;

/*
 * Crea una función que reciba dos cadenas como parámetro (str1, str2)
 * e imprima otras dos cadenas como salida (out1, out2).
 * - out1 contendrá todos los caracteres presentes en la str1 pero NO
 *   estén presentes en str2.
 * - out2 contendrá todos los caracteres presentes en la str2 pero NO
 *   estén presentes en str1.
 */

string eliminarChars(const string& str1, const string& str2) {
    string resultado;
    for (char c : str1) {
        if (str2.find(c) == string::npos) {
            resultado += c;
        }
    }
    return resultado;
}


int main() {
    string str1, str2;
    cout << "Ingresa la primera cadena: ";
    getline(cin, str1);
    cout << "Ingresa la segunda cadena: ";
    getline(cin, str2);
    string out1 = eliminarChars(str1, str2);
    string out2 = eliminarChars(str2, str1);
    cout << "Cadena 1 sin caracteres de cadena 2: " << out1 << endl;
    cout << "Cadena 2 sin caracteres de cadena 1: " << out2 << endl;
    
    return 0;
}