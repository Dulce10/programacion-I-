Algoritmo calculadora
	Definir a, b, total Como Real
	Definir opcion como Entero
	Escribir 'Ingrese un n�mero'
	leer a 
	Escribir 'Ingrese otro n�mero'
	leer b
	Escribir 'Seleccione una opci�n'
	Escribir '1. Suma'
	Escribir '2. Resta'
	Escribir '3. Multiplicaci�n'
	Escribir '4. Divisi�n'
	leer opcion
	Segun opcion Hacer
		1:
			total<- a+b
			Escribir 'Total: ', total
		2:
			total<- a-b
			Escribir 'Total: ', total 
		3:
			total<- a*b
			Escribir 'Total: ', total
		4:
			total<- a/b
			Escribir 'Total: ', total
		De Otro Modo:
			Escribir 'Fin del programa'
	Fin Segun
	
FinAlgoritmo
