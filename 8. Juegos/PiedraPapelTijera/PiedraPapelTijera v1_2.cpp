//Programa que permite jugar Piedra - Papel o Tijera
//Programador: daguilae
//Marzo 2025
//Curso de Programaciòn I
#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()

using namespace std;
string eleccionJugador(int jugador);
int aleatorio();
main()
{
    srand(time(0));
    int jugador = 0;
    int pc = 0;
    int perdidas = 0;
    int ganancias = 0;
    while (ganancias < 3 && perdidas < 3)
    {
        cout << "Piedra - Papel y Tijera" << endl;
        cout << "Elije: 1 para Piedra, 2 para Papel y 3 para Tijera" << endl;
        cin >> jugador;
        cout << "Tu " << eleccionJugador(jugador) <<endl;
        pc = aleatorio();
        cout << "PC " << eleccionJugador(pc) << endl;
        if (jugador == pc){
            cout << "EMPATASTES" << endl;
        }
        else if ((jugador == 1 && pc == 3) || (jugador == 2 && pc == 1) || (jugador == 3 && pc == 2)) {
            cout << "GANASTES" << endl;
            ganancias = ganancias + 1;
        }
        else {
            cout << "PERDISTES" << endl;
            perdidas = perdidas +1;
        }
    }
    cout << "Resultados: Ganastes " << ganancias << " Perdistes " << perdidas << endl;

    return 0;
}
int aleatorio()
{
    int resultado = 0;

    resultado = ((rand() % 4));
    if (resultado == 0)
        resultado = 1;
    return resultado;

}

string eleccionJugador(int jugador)
{
    if (jugador == 1)
        return "Elegiste: Piedra";
    else if (jugador == 2 )
        return "Elegiste: Papel";
    else if (jugador == 3)
        return "Elegiste: Tijera";
    else
        return "No elegiste adecuadamente";
}
