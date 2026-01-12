#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Crea una función que reciba dos array, un booleano y retorne un array.
 * - Si el booleano es verdadero buscará y retornará los elementos comunes
 *   de los dos array.
 * - Si el booleano es falso buscará y retornará los elementos no comunes
 *   de los dos array.
 * - No se pueden utilizar operaciones del lenguaje que
 *   lo resuelvan directamente.
*/

string calculateSet(const vector<string>& setA, const vector<string>& setB, bool common) {

    vector<string> result;

    // funcion auxiliar
    auto contains = [](const vector<string>& v, const string& s) {
        for (const auto& x : v) if (x == s) return true;
        return false;
    };

    if (common) {
        for (const auto& a : setA) {
            if (contains(setB, a) && !contains(result, a)) {
                result.push_back(a);
            }
        }
    } else {
        // Elementos en A que no están en B
        for (const auto& a : setA) {
            if (!contains(setB, a) && !contains(result, a)) {
                result.push_back(a);
            }
        }
        // Elementos en B que no están en A
        for (const auto& b : setB) {
            if (!contains(setA, b) && !contains(result, b)) {
                result.push_back(b);
            }
        }
    }

    // Construir la cadena de resultado
    string resultStr = "{";

    for (size_t i = 0; i < result.size(); ++i) {
        resultStr += "\"" + result[i] + "\"";
        if (i < result.size() - 1) {
            resultStr += ", ";
        }
    }
    
    resultStr += "}";

    return resultStr;
}
int main() {

    cout << calculateSet({"1", "2", "3"}, {"2", "3", "4"}, true) << "\n";  // 2, 3
    cout << calculateSet({"1", "2", "3"}, {"2", "3", "4"}, false) << "\n"; // 1, 4
    
    return 0;
}