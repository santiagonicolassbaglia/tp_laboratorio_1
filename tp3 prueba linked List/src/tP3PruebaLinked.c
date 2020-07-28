#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main(void)
{
	setbuf(stdout, NULL);
    int opcion;
    LinkedList* listaEmpleados = ll_newLinkedList();//Crea una lista dinamica.
    LinkedList* listaFiltrada=NULL;
    int listaContadora=0;

	do
	{
		if( !utn_getNumero(&opcion, "Por favor, ingrese una opción: "
											 "\n\t 1. Cargar los datos de los empleados desde el archivo data.csv. "
											 "\n\t 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
											 "\n\t 3. Alta de empleado."
											 "\n\t 4. Modificar datos de empleado."
											 "\n\t 5. Baja de empleado."
											 "\n\t 6. Listar empleados."
											 "\n\t 7. Ordenar empleados."
											 "\n\t 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
											 "\n\t 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
											"\n\t 10. (filter)lista filtrada, el empleado trabaja mas de 200."
											"\n\t 11.(Cout)listar personas que ganan menos de 8000 ."
				"\n\t 13. Salir.\n","La opción ingresada es invalida.\n",1,13,2))
		{
				switch(opcion)
				{
					case 1:

						if( !controller_loadFromText("data.csv",listaEmpleados) )//Carga los datos desde un archivo en modo texto.
						{
							printf("Carga realizada con exito!.\n\n");
						}
						else
						{
							printf("No se pudo cargar el archivo!.\n\n");
						}
						break;

					case 2:

						if( !controller_loadFromBinary("data.dat",listaEmpleados) )//Carga los datos desde un archivo en modo binario.
						{
							printf("Lista binario cargada con exito!.\n\n");
						}
						else
						{
							printf("No se pudo cargar la lista binaria!.\n\n");
						}
						break;

					case 3:

						if( !controller_addEmployee(listaEmpleados) )//Agrega un empleado a la lista dinamica.
						{
							printf("Alta de empleado exitosa!.\n\n");
						}
						else
						{
							printf("No se pudo dar de alta el empleado!.\n\n");
						}
						break;

					case 4:

						if( !controller_editEmployee(listaEmpleados) )//Modifica un empleado de la lista dinamica.
						{
							printf("Modificacion de empleado exitosa!.\n\n");
						}
						else
						{
							printf("No se pudo modificar el empleado!.\n\n");
						}
						break;

					case 5:

						if( !controller_removeEmployee(listaEmpleados) )//Elimina un empleado de la lista dinamica.
						{
							printf("Baja de empleado exitosa!.\n\n");
						}
						else
						{
							printf("No se pudo dar de baja el empleado!.\n\n");
						}
						break;

					case 6:

						if( !controller_ListEmployee2(listaEmpleados) )//Lista la informacion de todos los empleados de la lista dinamica.
						{
							printf("Lista impresa con exito!.\n\n");
						}
						else
						{
							printf("No se pudo imprimir lista!.\n\n");

						}
						break;

					case 7:

						if( !controller_sortEmployee(listaEmpleados) )//Ordena a los empleados por un criterio.
						{
							printf("Lista ordenada con exito!.\n\n");
						}
						else
						{
							printf("No se pudo ordenar la lista!.\n\n");
						}
						break;

					case 8:

						if( !controller_saveAsText("data2.csv",listaEmpleados) )//Guarda los datos en un archivo en modo texto.
						{
							printf("Lista guardada en archivo con exito!.\n\n");
						}
						else
						{
							printf("No se pudo guardar la lista en el archivo!.\n\n");
						}
						break;

					case 9:

						if( !controller_saveAsBinary("data2.dat",listaEmpleados) )//Guarda los datos en un archivo en modo binario.
						{
							printf("Lista guardada en binario con exito!.\n\n");
						}
						else
						{
							printf("No se pudo guardar la lista en modo binario!.\n\n");
						}
						break;


					case 10:


						listaFiltrada=ll_filter(listaEmpleados,controller_elEmpleadoTrabajaMayora200);
					if( listaFiltrada!=NULL)
					{

					printf("-- lista filtrada. Los empleados que trabajan mas de 200 hs \t\n\n");
						ll_map(listaFiltrada,employee_imprimirEmp);
					}else
					{
						printf("ERROR");
					}
						break;



					case 11:

					listaContadora = ll_count(listaEmpleados,controller_CuantosEmpleadosGananMenosDe17000);

					  printf("-- la cantidad de empleados que ganan menos de 17000:%d\n ", listaContadora);

				break;









				}
		}
	}while(opcion != 13);//Si la opcion es igual a 10, finaliza el programa.
    return EXIT_SUCCESS;
}
