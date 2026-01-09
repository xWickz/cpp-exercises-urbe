#include <iostream>
using namespace std;

/*
 * Crea una función que reciba días, horas, minutos y segundos (como enteros)
 * y retorne su resultado en milisegundos.
*/

int convertirAMilisegundos(int dias, int horas, int minutos, int segundos) {
    const int MILISEGUNDOS_POR_SEGUNDO = 1000;
    const int SEGUNDOS_POR_MINUTO = 60;
    const int MINUTOS_POR_HORA = 60;
    const int HORAS_POR_DIA = 24;

    int totalMilisegundos = 0;

    totalMilisegundos += dias * HORAS_POR_DIA * MINUTOS_POR_HORA * SEGUNDOS_POR_MINUTO * MILISEGUNDOS_POR_SEGUNDO;
    totalMilisegundos += horas * MINUTOS_POR_HORA * SEGUNDOS_POR_MINUTO * MILISEGUNDOS_POR_SEGUNDO;
    totalMilisegundos += minutos * SEGUNDOS_POR_MINUTO * MILISEGUNDOS_POR_SEGUNDO;
    totalMilisegundos += segundos * MILISEGUNDOS_POR_SEGUNDO;
    return totalMilisegundos;
}

int main() {

    int dias, horas, minutos, segundos;
    cout << "Ingresa días, horas, minutos y segundos separados por espacios: ";
    cin >> dias >> horas >> minutos >> segundos;
    int resultado = convertirAMilisegundos(dias, horas, minutos, segundos);
    cout << "Total en milisegundos: " << resultado << "\n";
    
    return 0;
}

