#include "Equipo.h"

Equipo::Equipo(std::string nombre) : nombre(nombre), partidosJugados(0), ganados(0),
    empatados(0), perdidos(0), golesFavor(0), golesContra(0), puntos(0) {}

void Equipo::actualizarEstadisticas(int golesAnotados, int golesRecibidos) {
    partidosJugados++;
    golesFavor += golesAnotados;
    golesContra += golesRecibidos;

    if (golesAnotados > golesRecibidos) {
        ganados++;
        puntos += 3;
    } else if (golesAnotados < golesRecibidos) {
        perdidos++;
    } else {
        empatados++;
        puntos += 1;
    }
}

void Equipo::mostrarEstadisticas() const {
    std::cout << nombre << " - PJ: " << partidosJugados << " G: " << ganados
              << " E: " << empatados << " P: " << perdidos << " GF: " << golesFavor
              << " GC: " << golesContra << " Pts: " << puntos << std::endl;
}

std::string Equipo::getNombre() const {
    return nombre;
}

int Equipo::getPuntos() const {
    return puntos;
}

