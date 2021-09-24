/*
 * utn.c
 *
 *  Created on: 4 sep. 2021
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>


int sumar(int operando1 , int operando2, int* resultado) {
	int retorno = -1;
	*resultado = operando1 + operando2;
	retorno = 0;
	return retorno;
}

int restar (int operando1 , int operando2, int* resultado){
	int retorno = -1;
	*resultado = operando1 - operando2;
	retorno = 0;
	return retorno;
}
int multiplicar (int operando1 , int operando2, int* resultado){
	int retorno = -1;
	*resultado = operando1 * operando2;
	retorno = 0;
	return retorno;
}
int dividir  (int operando1 , int operando2, float* resultado){
	int retorno;
	retorno = -1;
	if(operando2 != 0){
		*resultado = (float)operando1 / operando2;
		retorno = 0;
	}
	return retorno;
}
int sacarFactorial(int operando, int* resultado){
	int acumulador;
	int retorno;
	retorno = -1;
	acumulador = 1;
	for(int i = 1;i <= operando;i++){
		acumulador = acumulador * i;
	}
	*resultado = acumulador;
	retorno = 0;
	return retorno;
}
