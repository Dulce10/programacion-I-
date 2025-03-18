#include <iostream>
#include "calculador.h"
using namespace std;

int main() {
    calculador miCalc("Sin cálculo aún");
    double num1, num2, resultado;
    char operacion;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        cout << "Ingrese primer numero: ";
        cin >> num1;

        cout << "Ingrese operacion (+, -, *, /): ";
        cin >> operacion;

        cout << "Ingrese segundo numero: ";
        cin >> num2;

        switch (operacion) {
            case '+':
                cout << "Resultado: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Resultado: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Resultado: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "Error" << endl;
                } else {
                    cout << "Resultado: " << num1 / num2 << endl;
                }
                break;
            default:
                cout << "Operación no válida." << endl;
        }

        cout << "\n¿Deseas hacer otra operacion? (s/n): ";
        cin >> continuar;
    }

    cout << "\n¡Gracias por usar la calculadora!\n";
    return 0;
}
