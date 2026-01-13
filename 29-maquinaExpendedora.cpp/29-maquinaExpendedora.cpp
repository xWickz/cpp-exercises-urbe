#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Simula el funcionamiento de una máquina expendedora creando una operación
 * que reciba dinero (array de monedas) y un número que indique la selección
 * del producto.
 * - El programa retornará el nombre del producto y un array con el dinero
 *   de vuelta (con el menor número de monedas).
 * - Si el dinero es insuficiente o el número de producto no existe,
 *   deberá indicarse con un mensaje y retornar todas las monedas.
 * - Si no hay dinero de vuelta, el array se retornará vacío.
 * - Para que resulte más simple, trabajaremos en céntimos con monedas
 *   de 5, 10, 50, 100 y 200.
 * - Debemos controlar que las monedas enviadas estén dentro de las soportadas.
*/

enum class Money : int {
    FIVE = 5,
    TEN = 10,
    FIFTY = 50,
    ONEHUNDRED = 100,
    TWOHUNDRED = 200
};

string buy(const int& code, const vector<Money>& money) {
    
    unordered_map<int, pair<string, int>> products = {
        {1, {"Agua", 100}},
        {2, {"Refresco", 150}},
        {3, {"Snack", 200}}
    };

    // Sumamos el dinero
    int total_money = 0;
    for (Money m : money) {
        total_money += static_cast<int>(m);
    }

    if (products.find(code) == products.end()) {
        return "El código de producto " + to_string(code) + " no existe.";
    }

    // Producto seleccionado
    auto [prod_name, prod_price] = products[code];

    // no dinero
    if (prod_price > total_money)
        return "Dinero insuficiente. Se retornan todas las monedas. \nDispones de: " + to_string(total_money) + " monedas. \nMientras que el producto cuesta: " + to_string(prod_price) + " monedas.\n";

    // si dinero 
    int change = total_money - prod_price;
    if (change == 0) {
        return "Has comprado: " + prod_name + ". No hay cambio.\n";
    } else {
        return "Has comprado: " + prod_name + ". Tu cambio es: " + to_string(change) + " monedas.\n";
    }

    return "El código de producto " + to_string(code) + " no existe.";
}

int main() {

    // parecido al git
    cout << buy(1, {Money::FIVE, Money::FIVE, Money::TEN, Money::TEN, Money::TEN, Money::FIVE, Money::TWOHUNDRED}) << endl;
    cout << buy(3, {Money::FIVE, Money::FIVE, Money::TEN, Money::TEN, Money::TEN, Money::FIVE}) << endl;
    cout << buy(1, {Money::FIVE, Money::FIVE, Money::TEN, Money::TEN, Money::TEN, Money::FIVE, Money::FIFTY}) << endl;
    cout << buy(1, {Money::TWOHUNDRED}) << endl;

    return 0;
}