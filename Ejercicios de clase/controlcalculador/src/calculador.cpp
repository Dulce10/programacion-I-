#include "calculador.h"

calculador::calculador(string calculoRealizado) { //constructor
    this->calculoRealizado = calculoRealizado;
}

calculador::~calculador() { //destructor
    // Puedes dejarlo vacío si no necesitas liberar recursos
}

double calculador::sumar(double a, double b) {
    return a + b;
}

double calculador::restar(double a, double b) {
    return a - b;
}

double calculador::multiplicar(double a, double b) {
    return a * b;
}

double calculador::dividir(double a, double b) {
    if (b == 0) {
        return 0; // Manejo simple
    }
}
