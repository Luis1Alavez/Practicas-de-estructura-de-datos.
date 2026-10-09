
#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion;

    do {
        cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver informacion del programa" << endl;
        cout << "3. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        while (opcion < 1 || opcion > 3) {
            cout << "Opcion invalida. Ingresa una opcion del 1 al 3: ";
            cin >> opcion;
        }

        cin.ignore();

        switch (opcion) {
            case 1: {
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

                cout << "\n--- Registro de Estudiante ---" << endl;
                cout << "Nombre del estudiante: ";
                getline(cin, nombre);

                do {
                    cout << "Edad: ";
                    cin >> edad;

                    if (edad < 0 || edad > 120) {
                        cout << "Edad invalida. Intenta de nuevo." << endl;
                    }
                } while (edad < 0 || edad > 120);

                do {
                    cout << "Cuantas calificaciones deseas registrar?: ";
                    cin >> cantidadCalifs;

                    if (cantidadCalifs <= 0) {
                        cout << "Cantidad invalida. Intenta de nuevo." << endl;
                    }
                } while (cantidadCalifs <= 0);

                for (int i = 1; i <= cantidadCalifs; i++) {
                    do {
                        cout << "Calificacion " << i << ": ";
                        cin >> calificacion;

                        if (calificacion < 0 || calificacion > 10) {
                            cout << "Calificacion invalida. Ingresa una nota entre 0 y 10." << endl;
                        }
                    } while (calificacion < 0 || calificacion > 10);

                    suma = suma + calificacion;

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

                promedio = suma / cantidadCalifs;

                cout << "\n--- Resultados ---" << endl;
                cout << "Estudiante: " << nombre << endl;
                cout << "Promedio: " << promedio << endl;
                cout << "Calificacion mas alta: " << notaAlta << endl;
                cout << "Calificacion mas baja: " << notaBaja << endl;
                cout << "Calificaciones aprobatorias: " << aprobadas << endl;
                cout << "Calificaciones reprobatorias: " << reprobadas << endl;

                if (promedio >= 9) {
                    cout << "Clasificacion: EXCELENTE" << endl;
                } else if (promedio >= 7) {
                    cout << "Clasificacion: APROBADO" << endl;
                } else if (promedio >= 6) {
                    cout << "Clasificacion: REGULAR (aprobado con lo minimo)" << endl;
                } else {
                    cout << "Clasificacion: REPROBADO" << endl;
                }

                break;
            }

            case 2:
                cout << "\n--- Informacion del Programa ---" << endl;
                cout << "Este programa permite registrar estudiantes, validar sus" << endl;
                cout << "edades y calificaciones (escala de 0 a 10), calcular" << endl;
                cout << "su promedio, ver la nota mas alta/baja y contar cuantas" << endl;
                cout << "materias pasaron y reprobaron." << endl;
                break;

            case 3:
                cout << "\nSaliendo del sistema. Hasta luego!" << endl;
                break;
        }

    } while (opcion != 3);

    return 0;
}

