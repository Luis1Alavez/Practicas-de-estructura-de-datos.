#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion;

    do {
        // Mostrar el menú principal
        cout << "\n=== SISTEMA DE CALIFICACIONES ===" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver informacion del programa" << endl;
        cout << "3. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        // Limpiar el buffer de entrada para evitar conflictos con futuros cin/getline
        cin.ignore();

        switch (opcion) {
            case 1: {
                string nombre;
                int edad;
                float calificacion1, calificacion2, calificacion3;
                float promedio;

                cout << "\n--- Registro de Estudiante ---" << endl;
                cout << "Nombre del estudiante: ";
                getline(cin, nombre); // Usamos getline para nombres compuestos

                cout << "Edad: ";
                cin >> edad;

                if (edad < 0 || edad > 120) {
                    cout << "Edad invalida" << endl;
                    break; // Sale del case actual y regresa al menú
                }

                cout << "Calificacion 1: ";
                cin >> calificacion1;
                if (calificacion1 < 0 || calificacion1 > 10) {
                    cout << "Calificacion invalida" << endl;
                    break;
                }

                cout << "Calificacion 2: ";
                cin >> calificacion2;
                if (calificacion2 < 0 || calificacion2 > 10) {
                    cout << "Calificacion invalida" << endl;
                    break;
                }

                cout << "Calificacion 3: ";
                cin >> calificacion3;
                if (calificacion3 < 0 || calificacion3 > 10) {
                    cout << "Calificacion invalida" << endl;
                    break;
                }

                promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

                cout << "\n--- Resultados ---" << endl;
                cout << "Estudiante: " << nombre << endl;
                cout << "Promedio: " << promedio << endl;

                if (promedio >= 9) {
                    cout << "Clasificacion: EXCELENTE" << endl;
                }
                else if (promedio >= 7) {
                    cout << "Clasificacion: APROBADO" << endl;
                }
                else if (promedio >= 6) {
                    cout << "Clasificacion: REGULAR (aprobado con lo minimo)" << endl;
                }
                else {
                    cout << "Clasificacion: REPROBADO" << endl;
                }
                break;
            }

            case 2:
                cout << "\n--- Información del Programa ---" << endl;
                cout << "Este programa permite registrar estudiantes, validar sus" << endl;
                cout << "edades y calificaciones (escala de 0 a 10), calcular" << endl;
                cout << "su promedio y obtener una clasificacion automatica." << endl;
                break;

            case 3:
                cout << "\nSaliendo del sistema. ¡Hasta luego!" << endl;
                break;

            default:
                cout << "\nOpción invalida. Por favor, intente de nuevo." << endl;
                break;
        }

    } while (opcion != 3); // El programa se repite hasta que el usuario elija salir (3)

    return 0;
}
