#include <iostream>
#include <cmath>
using namespace std;

/*
 * Crea una única función (importante que sólo sea una) que sea capaz
 * de calcular y retornar el área de un polígono.
 * - La función recibirá por parámetro sólo UN polígono a la vez.
 * - Los polígonos soportados serán Triángulo, Cuadrado y Rectángulo.
 * - Imprime el cálculo del área de un polígono de cada tipo.
 */

double poligono(float base, float altura, int type) { 
    switch(type) {
        case 1: 
        { // triangle
            return (base * altura) / 2;
            break;
        }
        case 2:
        { // square
            return base * base; // base stands for lado
            break;
        }
        case 3:
        { // rectangle
            return base * altura; 
            break;
        }
        default:
            return 0.0;
            break;
    }

}
int main() {

    float base, altura;
    int choice = 0;
    cout << "Calculate the area of a polygon! Please select\n1 - triangle\n2 - square\n3 - rectangle\nChoose: ";
    cin >> choice;


    if (choice == 1 || choice == 2 || choice == 3) cout << "Lets calculate the area of a " << (choice == 1 ? "triangle" : (choice == 2) ? "square" : "rectangle") << "!\n";

    switch(choice) {
        case 1: 
        { // triangle

            base = 0;
            altura = 0;

            cout << "Base: ";
            cin >> base;

            cout << "Height: ";
            cin >> altura;

            cout << "Area from a " << base << "x" << altura << " triangle is " << poligono(base, altura, 1) << "\n";
            break;
        }
        case 2:
        { // square
            base = 0;
            altura = 0;

            cout << "Base: ";
            cin >> base;

            cout << "Area from a " << base << "x" << base << " square is " << poligono(base, 0, 2);
            break;
        }
        case 3: 
        { // rectangle
            base = 0;
            altura = 0;

            cout << "Base: ";
            cin >> base;

            cout << "Height: ";
            cin >> altura;

            cout << "Area from a " << base << "x" << altura << " rectangle is " << poligono(base, altura, 3);
            break;
        }
        default: 
            cout << "No valid option.\n";
            break;
    }

}