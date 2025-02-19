#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
//Bibliotecas

using namespace std;

//constante
const int NUM_EQUIPOS = 6;
const int MAX_GOLES = 10;

struct Equipo {
    string nombre;
    int partidos_jugados = 0;
    int ganados = 0;
    int perdidos = 0;
    int empatados = 0;
    int puntos = 0;
};

void generarResultados(int matriz[NUM_EQUIPOS][NUM_EQUIPOS]) {
    srand(time(0));
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        for (int j = 0; j < NUM_EQUIPOS; j++) {
            if (i != j) {
                matriz[i][j] = rand() % (MAX_GOLES + 1);
                matriz[j][i] = rand() % (MAX_GOLES + 1);
            } else {
                matriz[i][j] = -1; // Sin enfrentamiento
            }
        }
    }
}

void calcularTabla(int matriz[NUM_EQUIPOS][NUM_EQUIPOS], vector<Equipo> &equipos) {
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        for (int j = 0; j < NUM_EQUIPOS; j++) {
            if (i != j) {
                equipos[i].partidos_jugados++;
                if (matriz[i][j] > matriz[j][i]) {
                    equipos[i].ganados++;
                    equipos[i].puntos += 3;
                    equipos[j].perdidos++;
                } else if (matriz[i][j] < matriz[j][i]) {
                    equipos[j].ganados++;
                    equipos[j].puntos += 3;
                    equipos[i].perdidos++;
                } else {
                    equipos[i].empatados++;
                    equipos[j].empatados++;
                    equipos[i].puntos += 1;
                    equipos[j].puntos += 1;
                }
            }
        }
    }
}

void mostrarTabla(const vector<Equipo> &equipos) {
    cout << "\nTabla de Posiciones:" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Equipo\tPJ\tG\tE\tP\tPuntos" << endl;
    for (const auto &equipo : equipos) {
        cout << equipo.nombre << "\t" << equipo.partidos_jugados << "\t" << equipo.ganados
             << "\t" << equipo.empatados << "\t" << equipo.perdidos << "\t" << equipo.puntos << endl;
    }
}

void determinarGanadorYDescenso(const vector<Equipo> &equipos) {
    int maxPuntos = -1, minPuntos = 1000;
    string ganador, descendido;

    for (const auto &equipo : equipos) {
        if (equipo.puntos > maxPuntos) {
            maxPuntos = equipo.puntos;
            ganador = equipo.nombre;
        }
        if (equipo.puntos < minPuntos) {
            minPuntos = equipo.puntos;
            descendido = equipo.nombre;
        }
    }
    cout << "\nEl equipo ganador del campeonato es: " << ganador << endl;
    cout << "El equipo que desciende es: " << descendido << endl;
}

int main() {
    vector<Equipo> equipos(NUM_EQUIPOS);
    int matriz[NUM_EQUIPOS][NUM_EQUIPOS];
    char opcion;

    do {
        cout << "Ingrese los nombres de los 6 equipos:" << endl;
        for (int i = 0; i < NUM_EQUIPOS; i++) {
            cout << "Equipo " << i + 1 << ": ";
            cin >> equipos[i].nombre;
        }

        generarResultados(matriz);
        calcularTabla(matriz, equipos);
        mostrarTabla(equipos);
        determinarGanadorYDescenso(equipos);

        cout << "\nDesea generar otro campeonato? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
