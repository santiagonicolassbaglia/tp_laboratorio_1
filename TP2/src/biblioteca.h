/*
 * biblioteca.h
 *
 *  Created on: 19 may. 2020
 *      Author: admin
 */

typedef struct{
 int idEmpleado;
 int isEmpty;
 char nombre[51];
 char apellido[51];
 float salary;
 int sector;

}eEmpleado;

void inicializar( eEmpleado empleado[], int cantidad);
int buscarLibre ( eEmpleado empleado[], int cantidad);
int BuscarPorId ( eEmpleado empleado[], int cantidad , int auxId);

void imprimir(eEmpleado empleado[], int cantidad);

void alta ( eEmpleado empleado[], int cantidad );
void modificacion( eEmpleado empleado[], int cantidad );
void baja( eEmpleado empleado[], int cantidad );

void ordenar (eEmpleado empleado [], int cantidad);
void totalPromedio( eEmpleado empleado[], int cantidad );




