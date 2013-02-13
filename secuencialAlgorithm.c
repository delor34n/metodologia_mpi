#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void printMatrix ( int **matrix , int col , int row );
void fillMatrix ( int **matrix , int col , int row );
void multMatrix ( int **matrix1 , int col1 , int rows1 , int **matrix2 , int col2 , int rows2 , int **finalMatrix );

int main ( void ) {

	int rows1 = 0, col1 = 0, rows2 = 0, col2 = 0;
	int i = 0;

	int **matrix1, **matrix2, **finalMatrix;

	scanf ( "%d" , &rows1 );
	scanf ( "%d" , &col1 );

	scanf ( "%d" , &rows2 );
	scanf ( "%d" , &col2 );

	if ( col1 != rows2 ) {

		printf ( "\nEsto no es matematicamente posible!\n" );
		return 1;

	}

	matrix1 = ( int ** ) malloc ( rows1 * sizeof ( int * ) );
	matrix2 = ( int ** ) malloc ( rows2 * sizeof ( int * ) );

	fillMatrix ( matrix1 , col1 , rows1 );
	fillMatrix ( matrix2 , col2 , rows2 );

	printMatrix ( matrix1 , col1 , rows1 );
	printMatrix ( matrix2 , col2 , rows2 );

	finalMatrix = ( int ** ) malloc ( rows1 * sizeof ( int * ) );

	for ( i = 0 ; i < col2 ; i++ ) {

		finalMatrix [ i ] = ( int * ) malloc ( col2 * sizeof ( int ) );

	}

	multMatrix ( matrix1 , col1 , rows1 , matrix2 , col2 , rows2 , finalMatrix );
	printMatrix ( finalMatrix , col2 , rows1 );

	return 0;
}

void multMatrix ( int **matrix1 , int col1 , int rows1 , int **matrix2 , int col2 , int rows2 , int **finalMatrix ) {

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

void fillMatrix ( int **matrix , int col , int row ) {

	int i , j;

	if ( matrix == NULL ) {

		printf ( "\n Error en la asignacion de memoria\n" );
		exit ( 0 );

	}

	for ( i = 0 ; i < row ; i++ ) {

		matrix [ i ] = ( int * ) malloc ( col * sizeof ( int ) );

		for ( j = 0 ; j < col ; j++ ) {

			scanf ( "%d" , &matrix [ i ] [ j ] );
		}

	}

}

void printMatrix ( int **matrix , int col , int row ) {

	int i , j;

	for ( i = 0 ; i < row ; i++ ) {

		for ( j = 0 ; j < col ; j++ ) {

			printf( "%d\t " , matrix [ i ] [ j ] );
		}

		printf ( "\n" );

	}

	printf ( "\n" );

}
