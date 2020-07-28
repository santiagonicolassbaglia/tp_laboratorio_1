/*
 ============================================================================
 Name        : eclipse.c
 Author      : Santiago Sbaglia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"





int main(void)
{
	setbuf(stdout,NULL); // SIEMPRE!!!

    int num1;
    int num2;
    int suma;
    int res;
    int multiplicacion;
    int respuesta;
    float resultado;
    int fac;
    int fac2;

    char opciones;

    int seguir;





    while (seguir != 5)
      {


      printf ("-----------------------------------------------------\n");
      printf ("--------------------M-E-N-U--------------------------\n");
      printf ("-----------------------------------------------------\n\n\n\n");


       printf ("1-Escribe el primer numero\n");
       printf ("2-Escribe el segundo numero\n");
       printf ("3-Calculos\n");
       printf ("4-imprimir calculos\n");
       printf ("5-salir");

      scanf("%c", &opciones);
      fflush(stdin);



      switch (opciones)
    {
       case '1':
				   printf("Escribe el primer numero: \n");
			   scanf("%d", &num1);

			   break;


       case '2':

			   printf("Escribe el segundo numero: \n");
				   scanf("%d", &num2);

				   break;


      case '3':


                  swichFunciones(opciones,num1,num2);


    	  	  	  break;

        case '4':
        	suma = sumar(num1, num2);
        	printf("la suma es %d\n", suma);

        	 res= restar(num1, num2);
        	 printf(" El resultado de la resta es :%d \n", res);

        	 multiplicacion = multiplicar(num1, num2);
             printf("la multiplicacion es %d\n",multiplicacion);

             respuesta = dividir(&resultado,num1, num2);
             printf("la division es %d\n",respuesta);

              fac= factorial(num1);
              printf("lel factorial es %d\n",fac);

              fac2= factorial(num2);
               printf("el factorial es %d\n",fac2);



       	         	 break;


                   case '5':
                	   	   seguir = 5;
                         printf("salir");


                    break;


      	  	  }



      }
}





















