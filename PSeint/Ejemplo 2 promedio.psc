// Realizado por Dulce Martìnez #9959-24-4564
Algoritmo Promedio
	
	Definir i,N como Entero
	Definir acum,dato,prom como Reales
	Escribir "Ingrese la cantidad de datos:"
	Leer N
	
	acum<-0
	
	Para i<-1 Hasta n Hacer
		Escribir "Ingrese el dato ",i,":"
		Leer dato
		acum<-acum+dato
	FinPara
	
	prom<-acum/N
	
	Escribir "El promedio es: ",prom
	
FinAlgoritmo