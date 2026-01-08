#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

/*
 * Crea un programa que sea capaz de transformar texto natural a código
 * morse y viceversa.
 * - Debe detectar automáticamente de qué tipo se trata y realizar
 *   la conversión.
 * - En morse se soporta raya "—", punto ".", un espacio " " entre letras
 *   o símbolos y dos espacios entre palabras "  ".
 * - El alfabeto morse soportado será el mostrado en
 *   https://es.wikipedia.org/wiki/Código_morse.
 */

int main() {

    unordered_map<char, string> morse = {
        {'a', ".-"},   {'b', "-..."}, {'c', "-.-."}, {'d', "-.."},
        {'e', "."},    {'f', "..-."}, {'g', "--."},  {'h', "...."},
        {'i', ".."},   {'j', ".---"}, {'k', "-.-"},  {'l', ".-.."},
        {'m', "--"},   {'n', "-."},   {'o', "---"},  {'p', ".--."},
        {'q', "--.-"}, {'r', ".-."},  {'s', "..."},  {'t', "-"},
        {'u', "..-"},  {'v', "...-"}, {'w', ".--"},  {'x', "-..-"},
        {'y', "-.--"}, {'z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
        {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
        {'8', "---.."}, {'9', "----."}
    };

    string texto;
    cout << "Ingresa un texto para ser convertido a morse: ";
    getline(cin, texto);

    for (char c : texto) {
        c = tolower(c);
        if (c == ' ') {
            cout << "/";
        } else if (morse.count(c)) {
            cout << morse[c] << " ";
        }
    }
    
    return 0;
}