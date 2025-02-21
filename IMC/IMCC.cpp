#include <iostream>
#include <iomanip> // Para manejar la precisión decimal

using namespace std;

int main() {
    double peso, altura, imc;
    int categoria;

    // Solicitar al usuario el peso en kilogramos
    cout << "Ingrese su peso en kg: ";
    cin >> peso;

    // Solicitar al usuario la altura en metros
    cout << "Ingrese su altura en centimetros: ";
    cin >> altura;

    // Verificar que la altura no sea cero o negativa
    if (altura <= 0) {
        cout << "Error: La altura debe ser un valor positivo mayor que cero." << endl;
        return 1;
    }

    // Mostrar valores ingresados
    cout << "Peso ingresado: " << peso << " kg" << endl;
    cout << "Altura ingresada: " << altura << " cm" << endl;
    cout << "Altura al cuadrado: " << (altura * altura) << endl;

    // Calcular el IMC usando casting explícito
    imc = static_cast<double>(peso) / (static_cast<double>(altura) * static_cast<double>(altura));

    // Mostrar el resultado con dos decimales
    cout << fixed << setprecision(2);
    cout << "Su IMC es: " << imc << endl;

    // Determinar la categoría del IMC
    if (imc < 18.5) {
        categoria = 1;
    } else if (imc < 24.9) {
        categoria = 2;
    } else if (imc < 29.9) {
        categoria = 3;
    } else {
        categoria = 4;
    }

    // Clasificación del IMC con switch
    switch (categoria) {
        case 1:
            cout << "Clasificación: Bajo peso" << endl;
            break;
        case 2:
            cout << "Clasificación: Peso normal" << endl;
            break;
        case 3:
            cout << "Clasificación: Sobrepeso" << endl;
            break;
        case 4:
            cout << "Clasificación: Obesidad" << endl;
            break;
        default:
            cout << "Error en la clasificación" << endl;
            break;
    }

    return 0;
}
