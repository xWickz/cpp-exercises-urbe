#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;

/*
 * Crea una función que calcule y retorne cuántos días hay entre dos cadenas
 * de texto que representen fechas.
 * - Una cadena de texto que representa una fecha tiene el formato "dd/MM/yyyy".
 * - La función recibirá dos String y retornará un Int.
 * - La diferencia en días será absoluta (no importa el orden de las fechas).
 * - Si una de las dos cadenas de texto no representa una fecha correcta se
 *   lanzará una excepción.
 */

double diferenciasDias(const string& d1, const string& d2) {

    tm tm1{}; tm tm2{};

    istringstream ss1(d1);
    istringstream ss2(d2);

    ss1 >> get_time(&tm1, "%d/%m/%Y");
    ss2 >> get_time(&tm2, "%d/%m/%Y");
    if (ss1.fail() || ss2.fail()) throw invalid_argument("Fecha inválida");

    time_t time = mktime(&tm1);
    time_t time2 = mktime(&tm2);

    double difference = difftime(time2, time);

    return (difference / 86400);
}

int main() {

    string d1, d2;
    cout << "Ingresa la primera fecha (DD/MM/YYYY): ";
    cin >> d1;

    cout << "Ingresa la segunda fecha (DD/MM/YYYY): ";
    cin >> d2;

    cout << "La diferencia en dias entre ambas fechas es: " << diferenciasDias(d1, d2) << endl;
    return 0;
}
