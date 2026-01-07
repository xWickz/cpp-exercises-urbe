#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <sstream>
#include <regex>
using namespace std;

/*
 * Crea un programa que cuente cuantas veces se repite cada palabra
 * y que muestre el recuento final de todas ellas.
 * - Los signos de puntuación no forman parte de la palabra.
 * - Una palabra es la misma aunque aparezca en mayúsculas y minúsculas.
 * - No se pueden utilizar funciones propias del lenguaje que
 *   lo resuelvan automáticamente.
 */

int main() {    
    string texto;
    cout << "Ingresa tu texto/oracion: ";
    getline(cin, texto);

    regex puntuaction("[[:punct:]]");
    string manipulated = regex_replace(texto, puntuaction, ""); // quitar puntuacion
    transform(manipulated.begin(), manipulated.end(), manipulated.begin(), [](unsigned char c) { // para mnisciulas todos
        return tolower(c);
    });

    unordered_map<string, int> contador;
    istringstream flujo(manipulated); // separa string a palabras
    string palabra; 

    while (flujo >> palabra) 
        contador[palabra]++;
    
    cout << "Recuento de palabras: ";
    for (const auto& par : contador) 
        cout << par.first << ": " << par.second << "\n";
    

    return 0;
}