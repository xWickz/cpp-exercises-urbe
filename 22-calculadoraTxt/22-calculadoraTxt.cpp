#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*
 * Lee el fichero "Challenge21.txt" incluido en el proyecto, calcula su
 * resultado e imprímelo.
 * - El .txt se corresponde con las entradas de una calculadora.
 * - Cada línea tendrá un número o una operación representada por un
 *   símbolo (alternando ambos).
 * - Soporta números enteros y decimales.
 * - Soporta las operaciones suma "+", resta "-", multiplicación "*"
 *   y división "/".
 * - El resultado se muestra al finalizar la lectura de la última
 *   línea (si el .txt es correcto).
 * - Si el formato del .txt no es correcto, se indicará que no se han
 *   podido resolver las operaciones.
*/

int calculadora(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cerr << "No se pudo abrir el archivo: " << filename << "\n";
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();
    cout << content;

    try {
        stringstream ss(content);
        double result = 0.0;
        double current;

        if (!(ss >> result)) {
            throw runtime_error("Formato invalido: falta el primer numero");
        }

        char op;
        while (ss >> op) {

            double value;
            if (!(ss >> value)) {
                throw runtime_error("Formato invalido: falta numero tras operador");
            }

            switch (op) {
                case '+':
                    result += value;
                    break;
                case '-':
                    result -= value;
                    break;
                case '*':
                    result *= value;
                    break;
                case '/':
                    if (value == 0) {
                        throw runtime_error("Division por cero");
                    }
                    result /= value;
                    break;
                default:
                    throw runtime_error("Operacion desconocida");
            }
        }

        cout << "\nResultado: " << result << "\n";
    } catch(const exception& e) {
        cerr << "\nNo se han podido resolver las operaciones: " << e.what() << "\n";
        return 1;
    }

    return 0;

}

int main() {
    calculadora("C:\\Users\\sagu2\\OneDrive\\Escritorio\\Dev\\cpp-exercises\\22-calculadoraTxt\\22-calculadoraTxt.txt");
    return 0;
}