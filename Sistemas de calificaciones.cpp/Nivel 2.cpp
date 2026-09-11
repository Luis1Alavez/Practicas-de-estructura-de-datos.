#include <iostream>
#include <string>

using namespace std;

int main() {

    string nombre;
    int edad;
    float calificacion1, calificacion2, calificacion3;
    float promedio;

    cout << "Nombre del estudiante: ";
    cin >> nombre;

    cout << "Edad: ";
    cin >> edad;

    if (edad < 0 || edad > 120) {
        cout << "Edad invalida" << endl;
        return 1;
    }

    cout << "Calificacion 1: ";
    cin >> calificacion1;

    cout << "Calificacion 2: ";
    cin >> calificacion2;

    cout << "Calificacion 3: ";
    cin >> calificacion3;

    if (calificacion1 < 0 || calificacion1 > 10) {
        cout << "Calificacion invalida" << endl;
        return 1;
    }

    if (calificacion2 < 0 || calificacion2 > 10) {
        cout << "Calificacion invalida" << endl;
        return 1;
    }

    if (calificacion3 < 0 || calificacion3 > 10) {
        cout << "Calificacion invalida" << endl;
        return 1;
    }

    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

    if (promedio >= 9) {
        cout << "EXCELENTE" << endl;
    }
    else if (promedio >= 7) {
        cout << "APROBADO" << endl;
    }
    else if (promedio >= 6) {
        cout << "REGULAR (aprobado con lo minimo)" << endl;
    }
    else {
        cout << "REPROBADO" << endl;
    }

    cout << "Promedio: " << promedio << endl;

    return 0;
}
