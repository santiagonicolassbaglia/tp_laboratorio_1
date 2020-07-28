/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: admin
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

 int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)

{
	int retorno = -1;

	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)

	{
		do

		{
			printf("%s",mensaje);

			scanf("%d",&bufferInt);
				fflush(stdin);
			if(bufferInt >= minimo && bufferInt <= maximo)

			{

				*pResultado = bufferInt;

				retorno = 0;

				break;

			}

			else

			{
				printf("%s",mensajeError);

				reintentos--;
			}

		}while(reintentos >= 0);
	}

	return retorno;
}






 int dividir (float* pResultado,int operador1, int operador2)
 {
 	float resultado;
 	int retorno = -1;
 	if(pResultado != NULL &&operador2 != 0)
 	{
 		resultado = (float) operador1 / operador2;
 		*pResultado = resultado;
 		retorno = 0;
 	}
 	return retorno;
 }







 int sumar(int operador1,int operador2) // prototipo
 {
 	int resultado; // variable local de la funcion

 	resultado=operador1 + operador2;


 	return resultado;
 }




 int restar(int operador1,int operador2) // prototipo
 {
 	int resultado; // variable local de la funcion

 	resultado=operador1 - operador2;

 	// retornar valor
 	return resultado;
 }


 int multiplicar(int operador1,int operador2) // prototipo
 {
 	int resultado; // variable local de la funcion

 	resultado= operador1 * operador2;

 	return resultado;
 }



 int factorial(int numero)
    {
  int i ;
  int resultado=1 ;




    for (i=numero; i>0 ; i--)
    {
        resultado= resultado*i ;
    }


    return resultado;

    }










void swichFunciones(int opciones, int numero, int numeroDos)

 {


	    int suma;
	    int res;
		int multiplicacion;
		float resultado;
		int respuesta;
		int factoriales;
		int factorialesDos;



	  printf("----CALCULOS---- \n");

	          	       printf ("1-Suma\n");
	          	       printf ("2-Resta\n");
	          	       printf ("3-Multiplicacion\n");
	          	       printf ("4-Division\n");
	          	       printf ("5-Factorial\n");
	          	       printf ("6-Resultados\n");

	          	     scanf("%d", &opciones);



	          	           	   	   switch(opciones)
	          	           	   	   {

	          	           	   	   case 1:
	          	           	   		   suma = sumar(numero,numeroDos);
	          	           	   		   	   printf("la suma es %d\n",suma);

	          	           	   		   	   	   break;


	          	           	   	   	   case 2:
	          	           	   	   		   res= restar(numero,numeroDos);
	          	           	   	   		   printf(" El resultado de la resta es :%d \n", res);

	          	           	   	   		   break;


	          	           	   	   	   case 3:
	          	           	   	   		   multiplicacion = multiplicar(numero,numeroDos);
	          	           	   	   		   printf("la multiplicacion es %d\n",multiplicacion);

	          	           	   	   		   break;

	          	           	   	   	   	  case 4:

	          	           	   	   	   		  respuesta = dividir(&resultado,numero,numeroDos);
	          	           	   	   	   		  if(respuesta == 0)
	          	           	   	   	   		  {
	          	           	   	   	   			  printf("El resultado es: %f\n",resultado);
	          	           	   	   	   		  }
	          	           	   	   	   		  else
	          	           	   	   	   		  {
	          	           	   	   	   			  printf("No es posible dividir por cero\n");
	          	           	   	   	   		  }

	          	           	   	   	   		  break;




	          	           	   	   	   	  case 5:
	          	           	   	   	   		  factoriales=factorial(numero) ;
	          	           	   	   	   		  printf(" el resultado factoriado del primer numero  es : %d \n\n", factoriales);

	          	           	   	   	   		  factorialesDos=factorial(numeroDos) ;
	          	           	   	   		      printf(" el resultado factoriado del segundo numero  es : %d \n\n", factorialesDos);

	          	           	   	   	   		  break;
	                                      }





 }








