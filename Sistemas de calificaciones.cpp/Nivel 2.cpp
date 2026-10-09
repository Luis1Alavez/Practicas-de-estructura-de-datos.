
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void mostrarMenu();
int leerEntero(string mensaje, int min, int max);
float leerCalificacion(int numero);
float calcularPromedio(float suma, int n);
string obtenerEstado(float promedio);
void registrarEstudiante();

int main() {
    int opcion;

    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ", 1, 3);

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;

            case 2:
                cout << "\n--- Informacion del Programa ---" << endl;
                cout << "Este programa permite registrar estudiantes," << endl;
                cout << "validar edades y calificaciones de 0 a 10," << endl;
                cout << "calcular promedios, encontrar la calificacion" << endl;
                cout << "mas alta y mas baja, y contar aprobadas y reprobadas."
                     << endl;
                break;

            case 3:
                cout << "\nSaliendo del sistema. Hasta luego!" << endl;
                break;
        }

    } while (opcion != 3);

    return 0;
}

void mostrarMenu() {
    cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Ver informacion del programa" << endl;
    cout << "3. Salir" << endl;
}

int leerEntero(string mensaje, int min, int max) {
    int valor;

    do {
        cout << mensaje;

        if (cin >> valor) {
            if (valor >= min && valor <= max) {
                return valor;
            }

            cout << "Valor invalido. Ingresa un numero entre "
                 << min << " y " << max << "." << endl;
        } else {
            cout << "Entrada invalida. Ingresa un numero entero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (true);
}

float leerCalificacion(int numero) {
    float calificacion;

    do {
        cout << "Calificacion " << numero << ": ";

        if (cin >> calificacion) {
            if (calificacion >= 0 && calificacion <= 10) {
                return calificacion;
            }

            cout << "Calificacion invalida. Ingresa una nota entre 0 y 10."
                 << endl;
        } else {
            cout << "Entrada invalida. Ingresa un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (true);
}

float calcularPromedio(float suma, int n) {
    return suma / n;
}

string obtenerEstado(float promedio) {
    if (promedio >= 9) {
        return "EXCELENTE";
    } else if (promedio >= 7) {
        return "APROBADO";
    } else if (promedio >= 6) {
        return "REGULAR (aprobado con lo minimo)";
    } else {
        return "REPROBADO";
    }
}

void registrarEstudiante() {
    string nombre;
    int edad;
    int cantidadCalifs;
    float calificacion;
    float suma = 0;
    float promedio;
    float notaAlta = -1;
    float notaBaja = 11;
    int aprobadas = 0;
    int reprobadas = 0;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n--- Registro de Estudiante ---" << endl;
    cout << "Nombre del estudiante: ";
    getline(cin, nombre);

    edad = leerEntero("Edad: ", 0, 120);

    cantidadCalifs = leerEntero(
        "Cuantas calificaciones deseas registrar?: ", 1, 100
    );

    for (int i = 1; i <= cantidadCalifs; i++) {
        calificacion = leerCalificacion(i);

        suma += calificacion;

        if (calificacion >= 6) {
            aprobadas++;
        } else {
            reprobadas++;
        }

        if (calificacion > notaAlta) {
            notaAlta = calificacion;
        }

        if (calificacion < notaBaja) {
            notaBaja = calificacion;
        }
    }

    promedio = calcularPromedio(suma, cantidadCalifs);

    cout << "\n--- Resultados ---" << endl;
    cout << "Estudiante: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Calificacion mas alta: " << notaAlta << endl;
    cout << "Calificacion mas baja: " << notaBaja << endl;
    cout << "Calificaciones aprobatorias: " << aprobadas << endl;
    cout << "Calificaciones reprobatorias: " << reprobadas << endl;
    cout << "Clasificacion: " << obtenerEstado(promedio) << endl;
}
