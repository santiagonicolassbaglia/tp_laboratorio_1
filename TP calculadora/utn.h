/*
 * utn.h
 *
 *  Created on: 7 abr. 2020
 *      Author: admin
 */

#ifndef UTN_H_
#define UTN_H_

// prototipos de funciones


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


int sumar(int operador1,int operador2); // prototipo
int restar(int operador1,int operador2);
int multiplicar(int operador1,int operador2);
int dividir (float* pResultado,int operador1, int operador2);
int factorial(int numero);

void swichFunciones(int opciones, int numero, int numeroDos);




#endif /* UTN_H_ */

