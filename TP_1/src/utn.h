/*
 * utn.h
 *
 *  Created on: 4 sep. 2021
 *      Author: Maru
 */

#ifndef UTN_H_
#define UTN_H_
/**
 * \brief suma operando1 y operando2
 * \param int* resultado, puntero al espacio de memoria donde se dejara  el valor obtenido.
 * \param int operando1,primer operando.
 * \param int operando2,segundo operando.
 * \return (-1) Error / (0) Ok
 */
int sumar(int operando1, int operando2, int* resultado);
/**
 * \brief resta operando1 y operando2
 * \param int* resultado, puntero al espacio de memoria donde se dejara  el valor obtenido.
 * \param int operando1,primer operando.
 * \param int operando2,segundo operando.
 * \return (-1) Error / (0) Ok
 */
int restar(int operando1, int operando2, int* resultado);
/**
 * \brief multiplica operando1 por operando2
 * \param int* resultado, puntero al espacio de memoria donde se dejara  el valor obtenido.
 * \param int operando1,primer operando.
 * \param int operando2,segundo operando.
 * \return (-1) Error / (0) Ok
 */
int multiplicar(int operando1, int operando2, int* resultado);
/**
 * \brief divide operando1 con operando2
 * \param int* resultado, puntero al espacio de memoria donde se dejara  el valor obtenido.
 * \param int operando1,primer operando.
 * \param int operando2,segundo operando.
 * \return (-1) Error / (0) Ok
 */
int dividir(int operando1, int operando2, float* resultado);
/**
 * \brief saca el factorial de operando
 * \param int* resultado, puntero al espacio de memoria donde se dejara  el valor obtenido.
 * \param int operando,operando del que sacamos el factorial.
 * \return (-1) Error / (0) Ok
 */
int sacarFactorial(int operando, int* resultado);


#endif /* UTN_H_ */
