#include <iostream>
#include <unordered_map>
using namespace std;

/*
 * Crea un función, que dado un año, indique el elemento 
 * y animal correspondiente en el ciclo sexagenario del zodíaco chino.
 * - Info: https://www.travelchinaguide.com/intro/astrology/60year-cycle.htm
 * - El ciclo sexagenario se corresponde con la combinación de los elementos
 *   madera, fuego, tierra, metal, agua y los animales rata, buey, tigre,
 *   conejo, dragón, serpiente, caballo, oveja, mono, gallo, perro, cerdo
 *   (en este orden).
 * - Cada elemento se repite dos años seguidos.
 * - El último ciclo sexagenario comenzó en 1984 (Madera Rata).
*/

string chineseZodiac(const int& year) {

    string elements[] = {"Madera", "Fuego", "Tierra", "Metal", "Agua"};
    string animals[] = {
        "Rata", "Buey", "Tigre", "Conejo", "Dragón", "Serpiente",
        "Caballo", "Oveja", "Mono", "Gallo", "Perro", "Cerdo"
    };

    if (year < 604) {
        return "El ciclo sexagenario comienza en el año 604 d.C.";
    }

    int sexagenaryYear = (year - 4) % 60;
    string element = elements[(sexagenaryYear % 10) / 2];
    string animal = animals[sexagenaryYear % 12];

    return to_string(year) + ": " + element + " " + animal;
}

int main() {

    cout << chineseZodiac(2021) << endl;
    cout << chineseZodiac(1996) << endl;
    cout << chineseZodiac(1984) << endl;
    cout << chineseZodiac(2024) << endl;

    return 0;
}