#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Declaración de constantes
#define ALUMNOS 5
#define EVALUACIONES 4 // parcial1, parcial2, actividades, final


// Función para ingresar notas
void ingresarNotas(float notas[ALUMNOS][EVALUACIONES]) {
    for (int i = 0; i < ALUMNOS; i++) {
        cout << "Ingrese las notas del alumno " << i + 1 << ":\n";
        cout << "Primer Parcial (20 pts): ";
        cin >> notas[i][0];
        cout << "Segundo Parcial (25 pts): ";
        cin >> notas[i][1];
        cout << "Actividades (20 pts): ";
        cin >> notas[i][2];
        cout << "Examen Final (35 pts): ";
        cin >> notas[i][3];
        cout << endl;
    }
}

// Función para calcular la nota final de cada alumno
void calcularNotasFinales(float notas[ALUMNOS][EVALUACIONES], float notasFinales[ALUMNOS]) {
    for (int i = 0; i < ALUMNOS; i++) {
        notasFinales[i] = notas[i][0] + notas[i][1] + notas[i][2] + notas[i][3];
    }
}

// Función para calcular los porcentajes
void calcularPorcentajes(float notas[ALUMNOS][EVALUACIONES], float porcentajes[ALUMNOS][EVALUACIONES]) {
    for (int i = 0; i < ALUMNOS; i++) {
        for (int j = 0; j < EVALUACIONES; j++) {
            porcentajes[i][j] = (notas[i][j] / ((j == 0) ? 20 : (j == 1) ? 25 : (j == 2) ? 20 : 35)) * 100;
        }
    }
}

//Función para dibujar tabla
void imprimirLinea() {
    cout << "+--------";
    for(int i = 0; i < 5; i++) {
        cout << "+---------";
    }
    cout << "+\n";
}

// Función para mostrar los resultados
void mostrarResultados(float notas[ALUMNOS][EVALUACIONES], float notasFinales[ALUMNOS], float porcentajes[ALUMNOS][EVALUACIONES]) {

    cout << "\nResultados :\n";
    imprimirLinea();
    cout << setw(10) << left << "Alumno";
    cout << setw(10) << left << "P1";
    cout << setw(10) << left << "P2";
    cout << setw(10) << left << "ACT";
    cout << setw(10) << left << "EF";
    cout << setw(10) << left << "Total" << endl;
    imprimirLinea();

    for (int i = 0; i < ALUMNOS; i++) {
        cout << setw(10) << i + 1;
        for (int j = 0; j < EVALUACIONES; j++) {
            cout << setw(10) << notas[i][j];
        }
        cout << setw(10) << notasFinales[i] << endl;
    }

    cout << "\nPorcentajes de cada evaluacion (%):\n";
    imprimirLinea();
    cout << setw(10) << left << "Alumno";
    cout<< setw(10) << left << "P1";
    cout<< setw(10) << left << "P2";
    cout<< setw(10) << left << "ACT";
    cout<< setw(10) << left << "EF" << endl;
    imprimirLinea();

    for (int i = 0; i < ALUMNOS; i++) {
        cout << setw(10) << i + 1;
        for (int j = 0; j < EVALUACIONES; j++) {
            cout << setw(10) << fixed << setprecision(2) << porcentajes[i][j];
        }
        cout << endl;
    }
}

int main() {
    float notas[ALUMNOS][EVALUACIONES];       // Almacena las notas de los alumnos
    float notasFinales[ALUMNOS];              // Almacena las notas finales
    float porcentajes[ALUMNOS][EVALUACIONES]; // Almacena los porcentajes de cada evaluación

    ingresarNotas(notas);
    calcularNotasFinales(notas, notasFinales);
    calcularPorcentajes(notas, porcentajes);
    mostrarResultados(notas, notasFinales, porcentajes);

    return 0;
}
