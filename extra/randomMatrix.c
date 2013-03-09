/*
*
*   UNIVERSIDAD DE SANTIAGO DE CHILE
*   FACULTAD DE CIENCIA
*   DEPARTAMENTO DE MATEMÁTICA Y CIENCIA DE LA COMPUTACIÓN
*   LICENCIATURA EN CIENCIA DE LA COMPUTACIÓN
*   
*
*   NOMBRE: NICOLE OLIVARES
*   PROFESOR: RUBÉN CARVAJAL SCHIAFFINO
*
*
*   DESCRIPCIÓN: ESTE ALGORITMO CREA INPUT PARA QUE SEAN PROBADAS EN LOS ALGORITMOS.
*
*   COMPILACIÓN: 'gcc -o outputRand randomMatrix.c'
*
*   EJECUCIÓN:  './outputRand {numberColumnsA} {numberRowsA} {numberColumnsB} {numberRowsB} > input{numberInput}'
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createMatrix ( int numberRows , int numberColumns );

int main ( int argc , char *argv [ ] ) {

	/*
	*	VALIDAMOS LOS ARGUMENTOS PASADOS AL SCRIPT
	*/
	if ( argc >= 5 ) {

		/*
		*	Creamos una semilla (seed) y dos contadores(i,j) para los ciclos for
		*	Además creamos las variables para la cantidad de Filas y Columnas
		*/
		float seed = ( float ) time ( NULL );
		int numberRowsA , numberColumnsA;
		int numberRowsB , numberColumnsB;

		numberRowsA = atoi ( argv [ 1 ] );
		numberColumnsA = atoi ( argv [ 2 ] );

		numberRowsB = atoi ( argv [ 3 ] );
		numberColumnsB = atoi ( argv [ 4 ] );

		printf ( "%d\n" , numberRowsA );
		printf ( "%d\n" , numberColumnsA );

		printf ( "%d\n" , numberRowsB );
		printf ( "%d\n" , numberColumnsB );

		/*
		*	Iniciamos la semilla (seed)
		*/
		srand ( seed );

		createMatrix ( numberRowsA , numberColumnsA );
		createMatrix ( numberRowsB , numberColumnsB );
		
	} else {

		printf ( "\n\n ********* ERROR DE LOS ARGUMENTOS EN LA EJECUCIÓN********* \n\n" );
		printf ( "LA EJECUCIÓN ES DE LA SIGUIENTE MANERA: ./outputRand {numberColumnsA} {numberRowsA} {numberColumnsB} {numberRowsB} > input{numberInput}" );
		printf ( "\n\n ********* VUELVA A EJECUTAR EL SCRIPT CORRECTAMENTE ********* \n" );

	}

	return 0;

}

void createMatrix ( int numberRows , int numberColumns ) {

	/*
	*	Dos contadores(i,j) para los ciclos for
	*/
	int i , j;

	/*
	*	Creamos la matriz
	*/
	for ( i = 0 ; i < numberRows ; i++ ) {

		for ( j = 0 ; j < numberColumns ; j++ ) {

			printf ( "%f " , rand ( ) / 2.3 );

		}

		printf ( "\n" );

	}

}
