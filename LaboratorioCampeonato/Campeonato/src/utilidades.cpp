#include "Utilidades.h"
#include <cstdlib>
#include <ctime>

int generarAleatorio(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}
