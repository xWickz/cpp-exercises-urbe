#include <iostream>
using namespace std;

/*
 * Crea un programa que invierta el orden de una cadena de texto
 * sin usar funciones propias del lenguaje que lo hagan de forma automática.
 * - Si le pasamos "Hola mundo" nos retornaría "odnum aloH"
 */

int main() {

    string texto, newtext;
    
    cout << "Ingresa tu texto: ";
    getline(cin, texto);

    for (int i = texto.length(); i >= 0; i--) 
        newtext += texto[i];
    
    cout << "Texto original: " << texto << "\n";
    cout << "Texto invertido: " << newtext << "\n";

    return 0;
}   