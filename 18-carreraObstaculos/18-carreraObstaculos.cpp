#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Crea una función que evalúe si un/a atleta ha superado correctamente una
 * carrera de obstáculos.
 * - La función recibirá dos parámetros:
 *      - Un array que sólo puede contener String con las palabras
 *        "run" o "jump"
 *      - Un String que represente la pista y sólo puede contener "_" (suelo)
 *        o "|" (valla)
 * - La función imprimirá cómo ha finalizado la carrera:
 *      - Si el/a atleta hace "run" en "_" (suelo) y "jump" en "|" (valla)
 *        será correcto y no variará el símbolo de esa parte de la pista.
 *      - Si hace "jump" en "_" (suelo), se variará la pista por "x".
 *      - Si hace "run" en "|" (valla), se variará la pista por "/".
 * - La función retornará un Boolean que indique si ha superado la carrera.
 * Para ello tiene que realizar la opción correcta en cada tramo de la pista.
*/

bool carreraObstaculos(const vector<string>& acciones, string pista) {

    for(int i = 0; i < pista.length(); i++) {
        if (pista[i] == '_') {
            if (acciones[i] == "run") {
                // normal
            } else if (acciones[i] == "jump") {
                pista[i] = 'x';
            } else {
                // ño
                return false;
            }
        } else if (pista[i] == '|') {
            if (acciones[i] == "jump") {
                // normal
            } else if (acciones[i] == "run") {
                pista[i] = '/';
            } else {
                // ño
                return false;
            }
        } else {
            // bs
            return false;
        }
    }

    return true; // o false según corresponda
}

int main() {

    vector<string> acciones = {"run", "jump", "run", "run", "jump"};
    
    string pista = "_|__|";

    bool resultado = carreraObstaculos(acciones, pista);

    cout << "Resultado de la carrera: " << (resultado ? "Superada" : "No superada") << endl;
    cout << "Pista final: " << pista << endl;

    return 0;
}