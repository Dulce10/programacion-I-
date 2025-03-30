#ifndef EQUIPO_H
#define EQUIPO_H
#include <string>
#include <iostream>

class Equipo {
private:
    std::string nombre;
    int partidosJugados;
    int ganados;
    int empatados;
    int perdidos;
    int golesFavor;
    int golesContra;
    int puntos;

public:
    Equipo(std::string nombre);
    void actualizarEstadisticas(int golesAnotados, int golesRecibidos);
    void mostrarEstadisticas() const;
    std::string getNombre() const;
    int getPuntos() const;
};

#endif
