/*
 * menu.c
 *
 *  Created on: 18 sep. 2021
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>

int muestraMenu(int num1, int num2,int* rta){
	int retorno;
	retorno = -1;
	printf("\nIngrese un nro correspondiente a la accion que quiere ejecutar \n");
	printf("1. Ingresar 1er operando (A = %d) \n",num1);
	printf("2. Ingresar 2do operando (B = %d) \n",num2);
	printf("3. Calcular todas las operaciones \n");
	printf("4. Informar resultados \n");
	printf("5. Salir \n");
	scanf("%d", &(*rta));
	retorno = 0;
	return retorno;
}

/*
 * comentar funciones
 * fijarse los retornos
 * fijarse que los operandos esten ingresados con las flags
 * no se puede dividir por 0
 * cambiartod a float
 */
