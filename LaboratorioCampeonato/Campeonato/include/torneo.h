#ifndef TORNEO_H
#define TORNEO_H

#include "Equipo.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#define NUMERO_EQUIPOS 6  // Constante de número de equipos

class Torneo {
private:
    std::vector<Equipo> equipos;    // Lista de equipos
    int resultados[NUMERO_EQUIPOS][NUMERO_EQUIPOS][2];  // Resultados partidos
    int estadisticas[NUMERO_EQUIPOS][7];  // Estadísticas de los equipos

public:
    Torneo();
    void agregarEquipo(const std::string& nombre);
    void ingresarEquipos();
    void llenarResultados();
    void calcularEstadisticas();
    void mostrarResultadosPartidos() const;
    void mostrarTablaPosiciones() const;

    // Función para dibujar la línea en la tabla
    void dibujarLinea() const;
};

#endif
