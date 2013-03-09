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

void printMatrix ( float **matrix , int col , int row );
void fillMatrix ( float **matrix , int col , int row );
void multMatrix ( float **matrix1 , int col1 , int rows1 , float **matrix2 , int col2 , int rows2 , float **finalMatrix );

/*
*
*	MAIN FUNCTION
*
*/
int main ( void ) {

	int rows1 = 0, col1 = 0, rows2 = 0, col2 = 0;
	int i = 0;

	float **matrix1, **matrix2, **finalMatrix;

	scanf ( "%d" , &rows1 );
	scanf ( "%d" , &col1 );

	scanf ( "%d" , &rows2 );
	scanf ( "%d" , &col2 );

	if ( col1 != rows2 ) {

		printf ( "\nEsto no es matematicamente posible!\n" );
		return 1;

	}

	matrix1 = ( float ** ) malloc ( rows1 * sizeof ( float * ) );
	matrix2 = ( float ** ) malloc ( rows2 * sizeof ( float * ) );

	fillMatrix ( matrix1 , col1 , rows1 );
	fillMatrix ( matrix2 , col2 , rows2 );

	printMatrix ( matrix1 , col1 , rows1 );
	printMatrix ( matrix2 , col2 , rows2 );

	finalMatrix = ( float ** ) malloc ( rows1 * sizeof ( float * ) );

	for ( i = 0 ; i < col2 ; i++ ) {

		finalMatrix [ i ] = ( float * ) malloc ( col2 * sizeof ( float ) );

	}

	multMatrix ( matrix1 , col1 , rows1 , matrix2 , col2 , rows2 , finalMatrix );
	printMatrix ( finalMatrix , col2 , rows1 );

	return 0;
}

/*
*
*	MULTMATRIX FUNCTION
*
*/
void multMatrix ( float **matrix1 , int col1 , int rows1 , float **matrix2 , int col2 , int rows2 , float **finalMatrix ) {

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
void fillMatrix ( float **matrix , int col , int row ) {

	int i , j;

	if ( matrix == NULL ) {

		printf ( "\n Error en la asignacion de memoria\n" );
		exit ( 0 );

	}

	for ( i = 0 ; i < row ; i++ ) {

		matrix [ i ] = ( float * ) malloc ( col * sizeof ( float ) );

		for ( j = 0 ; j < col ; j++ ) {

			scanf ( "%f" , &matrix [ i ] [ j ] );
		}

	}

}

/*
*
*	PRINTMATRIX FUNCTION
*
*/
void printMatrix ( float **matrix , int col , int row ) {

	int i , j;

	for ( i = 0 ; i < row ; i++ ) {

		for ( j = 0 ; j < col ; j++ ) {

			printf( "%f\t " , matrix [ i ] [ j ] );
		}

		printf ( "\n" );

	}

	printf ( "\n" );

}
