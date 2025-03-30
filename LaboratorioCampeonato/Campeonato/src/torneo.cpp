#include "Torneo.h"
#include <cstdlib>
#include <ctime>

Torneo::Torneo() {
    srand(time(nullptr));  // Inicializar la semilla para la generación de números aleatorios
}

void Torneo::agregarEquipo(const std::string& nombre) {
    equipos.push_back(Equipo(nombre));  // Agregar el equipo a la lista
}

void Torneo::ingresarEquipos() {
    std::cout << "Ingrese los nombres de los " << NUMERO_EQUIPOS << " equipos:" << std::endl;
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        std::string nombre;
        std::cout << "Equipo " << (i + 1) << ": ";
        std::cin >> nombre;
        agregarEquipo(nombre);
    }
}

void Torneo::llenarResultados() {
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = 0; j < NUMERO_EQUIPOS; j++) {
            if (i != j) {
                // Generar resultados aleatorios para los partidos
                int golesIda = rand() % 11;  // Goles aleatorios entre 0 y 10
                int golesVuelta = rand() % 11;  // Goles aleatorios entre 0 y 10

                resultados[i][j][0] = golesIda;  // Goles de ida
                resultados[i][j][1] = golesVuelta;  // Goles de vuelta
                resultados[j][i][0] = golesVuelta;  // Goles de ida para el otro equipo
                resultados[j][i][1] = golesIda;  // Goles de vuelta para el otro equipo
            }
        }
    }
}

void Torneo::calcularEstadisticas() {
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = 0; j < NUMERO_EQUIPOS; j++) {
            if (i != j) {
                // Actualizar partidos jugados
                estadisticas[i][0]++;

                // Actualizar goles a favor y goles en contra
                estadisticas[i][4] += resultados[i][j][0];  // Goles a favor del equipo i
                estadisticas[i][5] += resultados[i][j][1];  // Goles en contra del equipo i

                // Actualizar victorias, empates y derrotas
                if (resultados[i][j][0] > resultados[i][j][1]) {
                    estadisticas[i][1]++;  // Victoria
                    estadisticas[i][6] += 3;  // 3 puntos por victoria
                } else if (resultados[i][j][0] < resultados[i][j][1]) {
                    estadisticas[i][3]++;  // Derrota
                } else {
                    estadisticas[i][2]++;  // Empate
                    estadisticas[i][6] += 1;  // 1 punto por empate
                }
            }
        }
    }
}

void Torneo::mostrarResultadosPartidos() const {
    std::cout << "\nTabla de RESULTADOS de los Partidos:" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "| " << std::setw(12) << std::left << "Equipo"
              << "| " << std::setw(12) << std::left << "Equipo"
              << "| " << std::setw(9) << std::left << "Resultado" << "|" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = i + 1; j < NUMERO_EQUIPOS; j++) {
            std::cout << "| " << std::setw(12) << std::left << equipos[i].getNombre()
                      << "| " << std::setw(12) << std::left << equipos[j].getNombre()
                      << "| " << std::setw(2) << resultados[i][j][0] << "-"
                      << std::setw(6) << std::left << resultados[i][j][1] << "|" << std::endl;
        }
    }
    std::cout << "--------------------------------------------------" << std::endl;
}

void Torneo::mostrarTablaPosiciones() const {
    std::cout << "Tabla de Posiciones:" << std::endl;
    dibujarLinea();  // Llamada para dibujar la línea de la tabla

    std::cout << std::setw(8) << std::left << "Equipo";
    std::cout << std::setw(9) << std::left << "PJ";
    std::cout << std::setw(9) << std::left << "PG";
    std::cout << std::setw(9) << std::left << "PE";
    std::cout << std::setw(9) << "PP";
    std::cout << std::setw(9) << "GF";
    std::cout << std::setw(9) << "GC";
    std::cout << std::setw(9) << "Pts tot" << std::endl;

    dibujarLinea();  // Llamada para dibujar la línea de la tabla

    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        std::cout << std::setw(9) << equipos[i].getNombre();  // Suponiendo que tienes un método getNombre() en la clase Equipo
        for (int j = 0; j < 7; j++) {
            std::cout << std::setw(9) << estadisticas[i][j];  // Imprime las estadísticas de cada equipo
        }
        std::cout << std::endl;
        dibujarLinea();  // Llama a la función para dibujar la línea después de cada equipo
    }
}

// Función para dibujar la línea en la tabla
void Torneo::dibujarLinea() const {
    std::cout << "+--------";
    for (int i = 0; i < 7; i++) {
        std::cout << "+---------";
    }
    std::cout << "+" << std::endl;
}
