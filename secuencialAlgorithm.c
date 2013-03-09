/*
*
*	UNIVERSIDAD DE SANTIAGO DE CHILE
*	FACULTAD DE CIENCIA
*	DEPARTAMENTO DE MATEMÁTICA Y CIENCIA DE LA COMPUTACIÓN
*	LICENCIATURA EN CIENCIA DE LA COMPUTACIÓN
*	
*
*	NOMBRE: NICOLE OLIVARES
*	PROFESOR: RUBÉN CARVAJAL SCHIAFFINO
*
*
*	DESCRIPCIÓN: ESTE ALGORITMO REALIZA UNA MULTIPLICACIÓN DE DOS MATRICES (AxB=C) SENCUENCIALMENTE.
*
*	COMPILACIÓN: 'gcc -o outputSecuencial secuencialAlgorithm.c'
*
*	EJECUCIÓN:	'./outputSecuencial < input{number} > outputSecuencial{numberInput}'
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib/time.h"

void printMatrix ( double **matrix , int col , int row );
void fillMatrix ( double **matrix , int col , int row );
void multMatrix ( double **matrix1 , int col1 , int rows1 , double **matrix2 , int col2 , int rows2 , double **finalMatrix );

/*
*
*	MAIN FUNCTION
*
*/
int main ( void ) {

	/*
	*	Variables tstart, tend, Esec y Etime son para medir el tiempo de la ejecución
	*	El resto sólo son variables contadoras.
	*/
	time_586 tstart , tend;
	double Esec, Etime;

	int rows1 = 0, col1 = 0, rows2 = 0, col2 = 0;
	int i = 0;

	double **matrix1, **matrix2, **finalMatrix;

	scanf ( "%d" , &rows1 );
	scanf ( "%d" , &col1 );

	scanf ( "%d" , &rows2 );
	scanf ( "%d" , &col2 );

	if ( col1 != rows2 ) {

		printf ( "\nEsto no es matematicamente posible!\n" );
		return 1;

	}

	matrix1 = ( double ** ) malloc ( rows1 * sizeof ( double * ) );
	matrix2 = ( double ** ) malloc ( rows2 * sizeof ( double * ) );

	fillMatrix ( matrix1 , col1 , rows1 );
	fillMatrix ( matrix2 , col2 , rows2 );

	printMatrix ( matrix1 , col1 , rows1 );
	printMatrix ( matrix2 , col2 , rows2 );

	finalMatrix = ( double ** ) malloc ( rows1 * sizeof ( double * ) );

	for ( i = 0 ; i < col2 ; i++ ) {

		finalMatrix [ i ] = ( double * ) malloc ( col2 * sizeof ( double ) );

	}

	time ( tstart );
	multMatrix ( matrix1 , col1 , rows1 , matrix2 , col2 , rows2 , finalMatrix );
	time ( tend );

	Etime = time_diff ( tend , tstart );
	Esec = Etime / 1000000;
	printf( "%f\n" , Esec );

	//printMatrix ( finalMatrix , col2 , rows1 );

	return 0;
}

/*
*
*	MULTMATRIX FUNCTION
*
*/
void multMatrix ( double **matrix1 , int col1 , int rows1 , double **matrix2 , int col2 , int rows2 , double **finalMatrix ) {

	int i = 0 , j = 0 , k = 0;

	for ( i = 0 ; i < rows1 ; i++ ) {

		for ( j = 0 ; j < col2 ; j++ ) {

			finalMatrix [ i ] [ j ] = 0;

			for ( k = 0 ; k < rows2 ; k++ ) {

				finalMatrix [ i ] [ j ] = finalMatrix [ i ] [ j ] + ( matrix1 [ i ] [ k ] * matrix2 [ k ] [ j ] );

			}

		}

	}

}

/*
*
*	FILLMATRIX FUNCTION
*
*/
void fillMatrix ( double **matrix , int col , int row ) {

	int i , j;

	if ( matrix == NULL ) {

		printf ( "\n Error en la asignacion de memoria\n" );
		exit ( 0 );

	}

	for ( i = 0 ; i < row ; i++ ) {

		matrix [ i ] = ( double * ) malloc ( col * sizeof ( double ) );

		for ( j = 0 ; j < col ; j++ ) {

			scanf ( "%lf" , &matrix [ i ] [ j ] );
		}

	}

}

/*
*
*	PRINTMATRIX FUNCTION
*
*/
void printMatrix ( double **matrix , int col , int row ) {

	int i , j;

	for ( i = 0 ; i < row ; i++ ) {

		for ( j = 0 ; j < col ; j++ ) {

			printf( "%lf\t " , matrix [ i ] [ j ] );
		}

		printf ( "\n" );

	}

	printf ( "\n" );

}
