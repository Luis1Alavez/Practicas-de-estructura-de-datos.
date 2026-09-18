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
                int cantidadCalifs;
                float calificacion;
                float suma = 0;
                float promedio;
                
                // Variables para la calificación más alta y más baja
                float notaAlta = -1;
                float notaBaja = 11;

                // Contadores para aprobadas y reprobatorias (suponiendo que se aprueba con 6 o más)
                int aprobadas = 0;
                int reprobadas = 0;

                cout << "\n--- Registro de Estudiante ---" << endl;
                cout << "Nombre del estudiante: ";
                getline(cin, nombre); // Usamos getline para nombres compuestos

                cout << "Edad: ";
                cin >> edad;

                if (edad < 0 || edad > 120) {
                    cout << "Edad invalida" << endl;
                    break; // Sale del case actual y regresa al menú
                }

                // Preguntar cuántas calificaciones desea registrar
                cout << "Cuantas calificaciones deseas registrar?: ";
                cin >> cantidadCalifs;

                if (cantidadCalifs <= 0) {
                    cout << "Cantidad invalida." << endl;
                    break;
                }

                // Ciclo for para pedir las "n" calificaciones una por una
                for (int i = 1; i <= cantidadCalifs; i++) {
                    cout << "Calificacion " << i << ": ";
                    cin >> calificacion;

                    // Validar que esté entre 0 y 10
                    if (calificacion < 0 || calificacion > 10) {
                        cout << "Calificacion invalida. Intentalo de nuevo para esta nota." << endl;
                        i--; // Repite la vuelta si la nota no es válida
                        continue;
                    }

                    // Acumular la suma
                    suma = suma + calificacion;

                    // Contar aprobadas y reprobatorias (aprobada >= 6)
                    if (calificacion >= 6) {
                        aprobadas++;
                    } else {
                        reprobadas++;
                    }

                    // Encontrar la más alta sin usar arreglos
                    if (calificacion > notaAlta) {
                        notaAlta = calificacion;
                    }

                    // Encontrar la más baja sin usar arreglos
                    if (calificacion < notaBaja) {
                        notaBaja = calificacion;
                    }
                }

                // Calcular el promedio
                promedio = suma / cantidadCalifs;

                // Mostrar resultados
                cout << "\n--- Resultados ---" << endl;
                cout << "Estudiante: " << nombre << endl;
                cout << "Promedio: " << promedio << endl;
                cout << "Calificacion mas alta: " << notaAlta << endl;
                cout << "Calificacion mas baja: " << notaBaja << endl;
                cout << "Calificaciones aprobatorias: " << aprobadas << endl;
                cout << "Calificaciones reprobatorias: " << reprobadas << endl;

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
                cout << "su promedio, ver la nota mas alta/baja y contar cuantas" << endl;
                cout << "materias pasaron y reprobaron." << endl;
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
