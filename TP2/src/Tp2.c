/*
 ============================================================================
 Name        : Tp2.c
 Author      : Santiago Sbaglia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "biblioteca.h"

#define CANT 4
int main()
{
	setbuf(stdout,NULL);
    eEmpleado empleado [CANT];
    int indice = 0;
    int id = 1;
    inicializar(empleado,CANT);
   int opcion;
   do{
        printf( " 1- ALTA\n" );
        printf( " 2-BAJA\n" );
        printf( " 3-MODIFICAR\n" );
        printf( " 4- MOSTRAR\n" );
        printf( " 5- TOTAL Y PROMEDIO DE EMPLEADOS\n");
        printf( " 6- PARA SALIR\n" );

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            empleado[indice].idEmpleado = id;
            id++;
            indice++;
            alta(empleado,CANT);
            break;
        case 2:
            baja(empleado, CANT);

            break;

        case 3:
            modificacion(empleado, CANT);
            break;

        case 4:
            system("cls");
            ordenar(empleado,CANT);
            system("pause");
            break;
        case 5:
            system("cls");
            totalPromedio(empleado, CANT);
            system("pause");
            break;


        }

    }while(opcion != 6) ;

return EXIT_SUCCESS;

}



