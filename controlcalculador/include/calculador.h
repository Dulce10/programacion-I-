#ifndef CALCULADOR_H
#define CALCULADOR_H

#include <iostream>
using namespace std;

class calculador {
private:
    string calculoRealizado;

public:
    calculador(string calculoRealizado); // Constructor
    virtual ~calculador();               // Destructor

    double sumar(double a, double b);
    double restar(double a, double b);
    double multiplicar(double a, double b);
    double dividir(double a, double b);

    void mostrarCalculo(); // Mostrar el cálculo realizado
};

#endif // CALCULADOR_H
