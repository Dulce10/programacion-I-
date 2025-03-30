//Programa que permite jugar Piedra - Papel o Tijera
//Programador: daguilae
//Marzo 2025
//Curso de Programaciòn I
#include <iostream>

using namespace std;

main()
{
    int jugador = 0;
    int jugador2 = 2;
    cout << "Piedra - Papel y Tijera" << endl;
    cout << "Elije: 1 para Piedra, 2 para Papel y 3 para Tijera" << endl;
    cin >> jugador;
    if (jugador == 1)
        cout << "Elegiste: Piedra" << endl;
    else if (jugador == 2 )
        cout << "Elegiste: Papel" << endl;
    else if (jugador == 3)
        cout << "elegiste: Tijera" << endl;
    else
        cout << "No elegiste adecuadamente" << endl;
    switch (jugador2)
    {
    case 1:
        cout << "El otro jugador eligio Piedra" << endl;
        break;
    case 2:
        cout << "El otro jugador eligio Papel" << endl;
        break;
    case 3:
        cout << "El otro jugador eligio Tijera" << endl;
        break;
    default:
        cout << "El otro jugador No eligio adecuadamente" << endl;
    }
    if (jugador == jugador2)
        cout << "EMPATASTES" << endl;
    else if (jugador == 1 && jugador2 == 3)
        cout << "GANASTES" << endl;
    else if (jugador == 2 && jugador2 == 1)
        cout << "GANASTES" << endl;
    else if (jugador == 3 && jugador2 == 2)
        cout << "GANASTES" << endl;
    else
        cout << "PERDISTES" << endl;
    return 0;
}
