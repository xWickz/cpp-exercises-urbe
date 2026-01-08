#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype>
using namespace std;

/*
 * Crea una función que reciba un String de cualquier tipo y se encargue de
 * poner en mayúscula la primera letra de cada palabra.
 * - No se pueden utilizar operaciones del lenguaje que
 *   lo resuelvan directamente.
*/


int main() {

    string str;
    size_t pos = 0;
    cout << "Ingresa tu texto: ";
    getline(cin, str);

    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ')  { // indicamos que hay un espacio, verificamos
            pos = i+1;
            if (pos < str.size()) {
                str[pos] = static_cast<char>(
                    toupper(static_cast<unsigned char>(str[pos]))
                );
            }
        }
    }

    cout << str;
    return 0;
}
