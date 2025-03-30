#include <iostream>
#include "Torneo.h"

int main() {
    Torneo torneo;

    // Agregar equipos (puedes ingresar los nombres como antes)
    torneo.ingresarEquipos();

    // Llenar resultados y calcular estad�sticas
    torneo.llenarResultados();
    torneo.calcularEstadisticas();

    // Mostrar los resultados de los partidos
    torneo.mostrarResultadosPartidos();

    // Mostrar la tabla de posiciones con la l�nea dibujada
    torneo.mostrarTablaPosiciones();

    return 0;
}

