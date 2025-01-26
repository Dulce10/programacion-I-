//Realizado por Dulce Martínez #9959-24-4564
Funcion resultado <- Potencia (base, exponente)
    Definir resultado como Entero
    Si exponente=0 Entonces
        resultado <- 1;
    sino 
        resultado <- base*Potencia(base,exponente-1); 
    FinSi
FinFuncion

Algoritmo Potencias
    Definir exponente como Entero
    Definir base como Entero
    Escribir "Ingrese Base"
    Leer base
    Escribir "Ingrese Exponente"
    Leer exponente
    Escribir "El resultado es ",Potencia(base,exponente)
FinAlgoritmo