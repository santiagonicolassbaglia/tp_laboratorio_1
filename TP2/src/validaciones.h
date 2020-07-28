/*
 * validaciones.h
 *
 *  Created on: 19 may. 2020
 *      Author: admin
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
float getValidFloat(char requestMessage[],char errorMessage[]);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

#endif /* VALIDACIONES_H_ */
