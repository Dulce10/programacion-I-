//Realizado por Dulce Mart�nez #9959-24-4564
Algoritmo Cadenas
	Definir frase,vocales Como Caracter
	Definir i,j,cantVocales Como Entero
	
	// el usuario ingresa una frase, vamos a contar cuantas vocales tiene
	Escribir "Ingrese una frase"
	Leer frase
	// pasamos toda la frase a minusculas para no tener que preguntar 2 veces por cada vocal
	frase<-Minusculas(frase)
	
	// lista de letras que vamos a buscar
	Vocales<-"aeiou������"
	cantvocales<-0
	
	// comparar todas las letras de frase con las de vocales y contar coincidencias
	Para i<-1 hasta Longitud(frase) Hacer
		Para j<-1 hasta Longitud(vocales) Hacer
			Si Subcadena(frase,i,i)=Subcadena(vocales,j,j) Entonces
				cantVocales<-cantVocales+1
			FinSi
		FinPara
	FinPara
	
	Escribir "La frase contiene ",cantVocales," vocales."
	
	
	
FinAlgoritmo
