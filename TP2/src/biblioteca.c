/*
 * biblioteca.c
 *
 *  Created on: 18 may. 2020
 *      Author: admin
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "validaciones.h"

void inicializar( eEmpleado empleado[], int cantidad)
{

    int i ;

    for ( i=0 ; i< cantidad ; i++ )
    {
        empleado[i].isEmpty = 0;

    }

}


int buscarLibre ( eEmpleado empleado[], int cantidad)
{
    int retorno = -1;
    int i ;

    for ( i =0 ; i< cantidad ; i++)

    {

        if (empleado[i].isEmpty ==0)
        {
            retorno = i;
            break;
        }

    }
    return retorno;
}

int BuscarPorId ( eEmpleado empleado[], int cantidad, int auxId)
{
    int retorno = -1;// no se encontro el dato
    int i ;

    for ( i=0 ; i<cantidad ; i++)
    {
        if ( empleado [i].isEmpty == 1 && empleado[i].idEmpleado == auxId)
        {
            retorno = i;// te devuelve el indice de la posicion dond esta el auxid
            break;

        }
    }
    return retorno;
}

void imprimir(eEmpleado empleado[], int cantidad)
{

    int i;

    for( i = 0; i<cantidad; i++)
    {
        if(empleado[i].isEmpty == 1)
        {
            printf("%s %s %.2f %d %d\n", empleado[i].nombre, empleado[i].apellido, empleado[i].salary, empleado[i].sector, empleado[i].idEmpleado);
        }

    }
}

void alta ( eEmpleado empleado[], int cantidad )
{
    char auxNombre [51];
    char auxApellido [51];
    float auxSalary;
    int auxSector;
    int auxBuscarEspacioLibre;

    system("cls");
    printf("\nALTA EMPLEADO\n\n");

    auxBuscarEspacioLibre= buscarLibre(empleado,cantidad);

    if( auxBuscarEspacioLibre== -1)
    {
        printf("No hay mas espacio Libre");
    }
    else
    {
        getValidString( " Ingrese el nombre del empleado:\n", "ingrese solo letras:", auxNombre);
        getValidString( "Ingrese el Apellido\n", "ingrese solo letras\n", auxApellido);
        auxSalary = getValidFloat( "Ingrese el salario\n\n", "ingrese solo numeros:\n");
        auxSector = getValidInt("Ingrese el Sector\n", "ingrese solo Numeros\n",1,10000);

        strcpy(empleado[auxBuscarEspacioLibre].nombre, auxNombre);

        strcpy(empleado[auxBuscarEspacioLibre].apellido, auxApellido);

        empleado[auxBuscarEspacioLibre].salary=auxSalary;

        empleado[auxBuscarEspacioLibre].sector=auxSector;

        empleado[auxBuscarEspacioLibre].isEmpty = 1 ; // le digo que esta lleno

    }

    system("pause");

}

void modificacion( eEmpleado empleado[], int cantidad )
{
    char auxNombre [51];
    char auxApellido [51];
    int auxId;
    float auxSalary;
    int auxSector;
    int auxBusquedaId;

    system( "cls");

    printf( " MODIFICACION EMPLEADO\n\n");

    auxId = getValidInt("Ingrese el id a modificar: \n", "ingrese solo numeros\n", 1, 1000);

    auxBusquedaId=BuscarPorId(empleado,cantidad,auxId);

    if(auxBusquedaId == -1)
    {
        printf("El id no existe.\n");
    }
    else
    {
        getValidString( " Reingrese el nombre del empleado:\n", "ingrese solo letras:", auxNombre);
        getValidString( "Reingrese el Apellido\n", "ingrese solo letras\n", auxApellido);
        auxSalary = getValidFloat( "Reigrese el salario\n\n", "ingrese solo numeros:\n");
        auxSector = getValidInt("Reingrese el Sector\n", "ingrese solo Numeros\n",1,10000);

        strcpy(empleado[auxBusquedaId].nombre, auxNombre);

        strcpy(empleado[auxBusquedaId].apellido, auxApellido);

        empleado[auxBusquedaId].salary=auxSalary;

        empleado[auxBusquedaId].sector=auxSector;

        empleado[auxBusquedaId].isEmpty = 1 ; // le digo que esta lleno
    }
    system("pause");

}

void baja( eEmpleado empleado[], int cantidad )
{

    int auxId;
    int auxBusquedaId;

    system( "cls");

    printf( " BAJA EMPLEADO\n\n");

    auxId = getValidInt("Ingrese el id a dar de baja: \n", "ingrese solo numeros\n", 1, 1000);

    auxBusquedaId=BuscarPorId(empleado,cantidad,auxId);

    if(auxBusquedaId == -1)
    {
        printf("El id no existe.\n");
    }
    else
    {

        empleado[auxBusquedaId].isEmpty = 0 ; // para dar de baja es lo mismo que modificar pero cambio este -1 a 0
    }
    system("pause");

}

void ordenar (eEmpleado empleado [], int cantidad)
{

    eEmpleado auxEmpleado;
    int i ;
    int j ;
    system("cls");

    for (i=0; i<cantidad-1; i++)
    {
        if ( empleado[i].isEmpty == 0  )
        {
            continue;
        }
        for ( j=i+1; j<cantidad; j++)
        {
            if( empleado[j].isEmpty==0)
            {
                continue;
            }
            if ( strcmp(empleado[i].apellido, empleado[j].apellido)>0)
            {
                auxEmpleado = empleado[i];
                empleado[i]= empleado[j];
                empleado[j]= auxEmpleado;
            }
            if (strcmp(empleado[i].apellido,empleado[j].apellido)==0)
            {

                if (empleado[i].sector>empleado[j].sector)
                {
                    auxEmpleado = empleado[i];
                    empleado[i]= empleado[j];
                    empleado[j]= auxEmpleado;

                }

            }
        }

    }

    imprimir(empleado, cantidad);

    system("pause");

}

void totalPromedio( eEmpleado empleado[], int cantidad )

{
    float total=0 ;
    int contador=0;
    int i;
    float promedio;


    for( i=0 ; i<cantidad ; i++ )
    {
        if ( empleado[i].isEmpty==1)
        {
            total+=empleado[i].salary;
            contador++;

        }
    }

    promedio = total / contador ;

    printf("El total de salario es: %.2f.\n", total);
    printf("El promedio de salario es %.2f.\n", promedio);

    for(i=0; i<cantidad; i++)
    {
        if(empleado[i].salary > promedio && empleado[i].isEmpty == 1)
        {
            printf("Empleados por encima del promedio: %s\t%.2f\n", empleado[i].nombre, empleado[i].salary);
        }

    }

}

