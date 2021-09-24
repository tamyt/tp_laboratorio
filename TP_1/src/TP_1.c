/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "menu.h"

int main(void) {
	setbuf(stdout,NULL);
	int rta;
	int num1;
	int num2;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultipl;
	float resultadoDiv;
	int resultadoFactorial1;
	int resultadoFactorial2;
	int retornoMenu;
	int retornoSum;
	int retornoRes;
	int retornoMul;
	int retornoDiv;
	int retornoFac1;
	int retornoFac2;
	int flag;
	int flag1;
	int flag2;
	num1 = 0;
	num2 = 0;
	flag = 0;
	flag1 = 0;
	flag2 = 0;

	do{
		retornoMenu = muestraMenu(num1,num2,&rta);
		if(retornoMenu == 0){
			switch(rta)
			{
				case 1:
					printf("Ingresá el número ");
					scanf("%d",&num1);
					flag = 1;
					break;
				case 2:
					if(flag == 1){
						printf("Ingresá el número ");
						scanf("%d",&num2);
						flag1 = 1;
					}
					else{
						printf("Error, ingrese el primer operando");
					}
					break;
				case 3:
					if(flag == 1 && flag1 == 1){
						retornoSum = sumar(num1,num2,&resultadoSuma);
						retornoRes = restar(num1,num2,&resultadoResta);
						retornoMul = multiplicar(num1,num2,&resultadoMultipl);
						retornoDiv = dividir(num1,num2,&resultadoDiv);
						retornoFac1 = sacarFactorial(num1,&resultadoFactorial1);
						retornoFac2 = sacarFactorial(num2,&resultadoFactorial2);
						flag2 = 1;
					}
					else{
						printf("Error, ingrese ambos operandos");
					}
					break;
				case 4:
					if(flag == 1 && flag1 == 1 && flag2 == 1){
						if(retornoSum == 0){
							printf("El resultado de %d + %d es : %d \n", num1, num2,resultadoSuma);
						}
						else{
							printf("No se pudo hacer la suma ");
						}
						if(retornoRes == 0){
							printf("El resultado de %d - %d es : %d \n", num1, num2,resultadoResta);
						}
						else{
							printf("No se pudo hacer la resta ");
						}
						if(retornoDiv == 0){
							printf("El resultado de %d / %d es : %.2f \n", num1, num2,resultadoDiv);
						}
						else{
							printf("No es posible dividir por 0");
						}
						if(retornoMul == 0){
							printf("El resultado de %d * %d es : %d \n", num1, num2,resultadoMultipl);
						}
						else{
							printf("No se pudo hacer la multiplicación ");
						}
						if(retornoFac1 == 0){
							printf("El factorial de %d es %d y ",num1,resultadoFactorial1);
						}
						else{
							printf("No se pudo sacar el factorial ");
						}
						if(retornoFac2 == 0){
							printf("El factorial de %d es %d \n",num2,resultadoFactorial2);
						}
						else{
							printf("No se pudo sacar el factorial ");
						}
					}
					else{
						printf("Error, para poder mostrar los resultados falta ingresar los resultados o hacer las cuentas");
					}
					break;
				 default:
					printf("Adios!\n");
					break;

			}
		}
		else{
			printf("Error, no se pudo mostrar el menu");
		}
	}
	while(rta != 5);
	// fflush(stdin);

	return EXIT_SUCCESS;
}
