#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

#define RESP_LEN 2

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).

 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile;
	if( path != NULL && pArrayListEmployee != NULL )//Valida que los punteros recibidos en la funcion sean coherentes.
	{
		auxFile = fopen(path,"r");//Abre el archivo en modo lectura.
		if( auxFile != NULL &&
			!parser_EmployeeFromText(auxFile,pArrayListEmployee) )//Llama a la funcion que parsea los datos del archivo.
		{
			retorno = 0;
		}
		fclose(auxFile);
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).

 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile;
	if( path != NULL && pArrayListEmployee != NULL)
	{
		auxFile = fopen(path,"rb");//Abre el archivo en modo lectura binario.
		    if( auxFile != NULL &&//Valida que el archivo que se buscó abrir no sea NULL.
			 !parser_EmployeeFromBinary(auxFile,pArrayListEmployee) )//Llama a la funcion que parsea los datos del archivo binario.
		{
			retorno = 0;
		}
		fclose(auxFile);//Cierra el archivo.
	}
    return retorno;
}

/** \brief Alta de empleados.

 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char auxNombre[NOMBRE_LEN];
	int auxHoras;
	int auxSueldo;
	int auxId;
	Employee* pEmpl = NULL;

	if( pArrayListEmployee != NULL &&
		!controller_findIdMax(pArrayListEmployee,&auxId) &&//Busca el ID maximo  actualmente en la lista.
		!utn_getNombre(auxNombre,NOMBRE_LEN,"Ingrese un nombre: \n","Nombre invalido.\n",2) &&
		!utn_getNumero(&auxHoras,"Ingrese horas trabajadas: \n","Horas invalidas.\n",0,400,2) &&
		!utn_getNumero(&auxSueldo,"Ingrese un sueldo: \n","Sueldo invalido.\n",0,60000,2) )
	{
		pEmpl = employee_newParametros(auxId+1,auxNombre,auxHoras,auxSueldo);// carga los datos obtenidos desde el usuario y al ID maximo le suma 1 y se lo asigna al empleado.
		if( pEmpl != NULL &&
			!ll_add(pArrayListEmployee,pEmpl) )//Agrega el empleado a la lista dinamica.
		{
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Modificacion de empleados.

 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	int idMaximo;
	int indiceEmpl;
	Employee* auxEmpl;
	char newNombre[NOMBRE_LEN];
	int newHoras;
	int newSueldo;
	char respuesta[RESP_LEN];

	if( pArrayListEmployee != NULL &&
		!controller_findIdMax(pArrayListEmployee,&idMaximo) &&//Busca el ID maximo  actualmente en la lista.
		!utn_getNumero(&auxId,"Por favor ingrese el ID del usuario a modificar: \n","ID invalido.\n",0,idMaximo,2) &&
		!controller_findEmployeeById(pArrayListEmployee,auxId,&indiceEmpl) &&
		indiceEmpl > -1)
	{
		auxEmpl = (Employee*) ll_get(pArrayListEmployee,indiceEmpl);//obtiene el puntero al empleado segun el ID.
		if( auxEmpl != NULL &&
			!employee_imprimirEmp(auxEmpl) &&
			!utn_getDescripcion(respuesta,RESP_LEN,"Desea modificar el usuario mostrado? [Ingrese: S/N]","Opcion invalida",2) &&
			!strncmp(respuesta,"S",RESP_LEN) )
		{
			if( !utn_getNombre(newNombre,NOMBRE_LEN,"Ingrese un nombre: \n","Nombre invalido.\n",2) &&
				!utn_getNumero(&newHoras,"Ingrese horas trabajadas: \n","Horas invalidas.\n",0,400,2) &&
				!utn_getNumero(&newSueldo,"Ingrese un sueldo: \n","Sueldo invalido.\n",0,60000,2) &&
				!employee_setNombre(auxEmpl,newNombre) &&
				!employee_setHorasTrabajadas(auxEmpl,newHoras) &&
				!employee_setSueldo(auxEmpl,newSueldo) )
			{
				ll_set(pArrayListEmployee,indiceEmpl,auxEmpl);//Setea los nuevos valores del empleado en la lista dinamica.
				retorno = 0;
			}
		}
	}
    return retorno;
}


/** \brief Baja de empleados.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	int idMaximo;
	int indiceEmpl;
	Employee* auxEmpl;
	char respuesta[RESP_LEN];

	if( pArrayListEmployee != NULL &&

	    !controller_findIdMax(pArrayListEmployee,&idMaximo) &&//Busca el ID maximo  actualmente en la lista.
		!utn_getNumero(&auxId,"Por favor ingrese el ID del usuario a dar de baja: \n","ID invalido.\n",0,idMaximo,2) &&
		!controller_findEmployeeById(pArrayListEmployee,auxId,&indiceEmpl) &&

		indiceEmpl > -1)
	{
		auxEmpl = (Employee*) ll_get(pArrayListEmployee,indiceEmpl);//obtiene el puntero al empleado segun el ID.
		if( auxEmpl != NULL &&
			!employee_imprimirEmp(auxEmpl) &&
			!utn_getDescripcion(respuesta,RESP_LEN,"Desea eliminar el usuario mostrado? [Ingrese: S/N]","ERROR!",2) &&

			!strncmp(respuesta,"S",RESP_LEN) )
		{
			ll_remove(pArrayListEmployee,indiceEmpl);//Elimina al empleado de la lista dinamica.
			employee_delete(auxEmpl);//Borra el espacio de memoria que ocupa el empleado obtenido.
			retorno = 0;
		}
	}
    return retorno;
}




/** \brief Lista todos los empleados.*/

int controller_ListEmployee2(LinkedList* pArrayListEmployee)
{
    Employee *pEmployee;

    int auxReturn = -1;
    int i;


         int auxId;
             char auxNombre[NOMBRE_LEN];
             int auxHoras;
             int auxSueldo;

    if(pArrayListEmployee != NULL)
    {
        auxReturn = 0;


        for(i=0; i<ll_len(pArrayListEmployee); i++)
          {
                pEmployee = ll_get(pArrayListEmployee, i);
             if (   !employee_getId(pEmployee,&auxId) &&
            		!employee_getNombre(pEmployee,auxNombre) &&
            		!employee_getHorasTrabajadas(pEmployee,&auxHoras) &&
            		!employee_getSueldo(pEmployee,&auxSueldo) )
            {

            	printf("ID: %d - NOMBRE: %s - HORAS: %d - SUELDO: %d\n",auxId,auxNombre,auxHoras,auxSueldo);//Si pasa las validaciones del IF, imprime la informacion del empleado.
            }

           }

    }

    return auxReturn;
}








/** \brief Ordena todos los empleados.

 */


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int orden;

	if( pArrayListEmployee != NULL &&
		!utn_getNumero(&orden,"Por favor ingrese el orden: [0=DESC/1=ASC]\n","Opcion invalida.\n",0,1,2) &&
		!ll_sort(pArrayListEmployee,employee_sortBySueldo,orden) )//Ordena la informacion del usuario segun el criterio de sueldo, pasado en la funcion employee_sortBySueldo.
	 {
		retorno = 0;
	 }
       return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path Puntero al archivo recibido.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \return Retorna 0 en caso de guardar el archivo correctamente; -1 en caso de error.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile = NULL;
	Employee* auxEmpl = NULL;
	int auxId;
	char auxNombre[NOMBRE_LEN];
	int auxHoras;
	int auxSueldo;
	int i;

	if( path != NULL && pArrayListEmployee != NULL )
	{
		auxFile = fopen(path,"w");//Abre el archivo en modo escritura.
		if( auxFile != NULL )
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
			{
				auxEmpl = ll_get(pArrayListEmployee,i);//Obtiene la informacion del empleado en la posicion i.
				if( auxEmpl != NULL &&
					!employee_getId(auxEmpl,&auxId) &&
					!employee_getNombre(auxEmpl,auxNombre) &&
					!employee_getHorasTrabajadas(auxEmpl,&auxHoras) &&
					!employee_getSueldo(auxEmpl,&auxSueldo) )
				{
					fprintf(auxFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
				}
			}
			retorno = 0;
			fclose(auxFile);
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile = NULL;
	Employee* auxEmpl = NULL;
	int i;

	if( path != NULL && pArrayListEmployee != NULL )
	{
		auxFile = fopen(path,"wb");//Abre el archivo en modo escritura binario.
		if( auxFile != NULL )
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
			{
				auxEmpl = ll_get(pArrayListEmployee,i);
				if( auxEmpl != NULL )
				{
					fwrite(auxEmpl,sizeof(Employee),1,auxFile);//escribe el archivo binario con el tamaño de cada Employee.
				}
			}
			retorno = 0;
			fclose(auxFile);//Cierra el archivo.
		}
	}
    return retorno;
}

/** \brief Busca el ID maximo de los empleados de la lista dinamica
 * \return Retorna 0 en caso de encontrar el ID maximo correctamente; -1 en caso de error.
 *
 */
int controller_findIdMax(LinkedList* pArrayListEmployee, int* id)
{
	int retorno = -1;
	Employee* auxEmpl;
    int i;
    int auxId;
    int auxMaxId;
    int flag = 0;


    if( pArrayListEmployee != NULL )
	{
		     auxMaxId = 0;
		for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
		{
			auxEmpl = (Employee*) ll_get(pArrayListEmployee,i);//Obtiene la informacion del empleado en la posicion i.

			if( auxEmpl != NULL &&
				!employee_getId(auxEmpl,&auxId) )//Obtiene el id del empleado.
			{
				if( flag == 0 || auxId > auxMaxId )
				{
					flag = 1;
					auxMaxId = auxId;//Asigna el valor del id como Id Maximo.
				}
			}
		}
		retorno = 0;
		*id = auxMaxId;//Le asigna al puntero id, el id maximo encontrado.
	}
	return retorno;
}

/** \brief Busca un empleado por el ID.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \param id ID a buscar en la lista dinamica.
 * \param gotIndex Puntero del tipo entero donde se alojará el indice el empleado que coincida con el ID.
 * \return Retorna 0 en caso de encontrar el empleado con el ID brindado; -1 en caso de error.
 *
 */
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id, int* gotIndex)
{
	int retorno = -1;
	int i;
	Employee* auxEmpl;

	if( pArrayListEmployee != NULL && id > 0 )
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
		{
			auxEmpl = (Employee*) ll_get(pArrayListEmployee,i);//Obtiene la informacion del empleado en la posicion i.
			if( auxEmpl != NULL &&
				auxEmpl->id == id )//Valida que el ID pasado por función sea igual que al id del empleado de la lista dinamica.
			{
				retorno = 0;
				*gotIndex = i;// le asigna al puntero gotIndex, el indice del empleado con el ID brindado en la funcion.
			}
		}
	}
	return retorno;
}







// para el FILTERR !
int controller_elEmpleadoTrabajaMayora200(void* pElement)
{
	Employee* pEmployee= (Employee*)pElement;
	int ret=0;
	int horas;

	horas=pEmployee->horasTrabajadas;

	if(horas>=200 )
	{
		ret=1;

	}
	else
	{
		ret=0;
	}


	return ret;
}



int controller_CuantosEmpleadosGananMenosDe17000(void* pElement)
{
	Employee* pEmployee= (Employee*)pElement;
	int ret=0;
	int sueldo;

	sueldo=pEmployee->sueldo;

	if(sueldo <= 17000)
	{
		ret=1;

	}
	else
	{
		ret=0;
	}


	return ret;
}








int employee_imprimirEmp(void* pElement)
{
	int retorno=-1;
	Employee* pEmployee = (Employee*) pElement;

	char auxNombre[NOMBRE_LEN];
	int auxId;
	int auxSueldo;
	int horasTrabajadas;

	if(pEmployee != NULL)
	{
		retorno=0;
		employee_getNombre(pEmployee,auxNombre);
		employee_getId(pEmployee,&auxId);
		employee_getSueldo(pEmployee,&auxSueldo);
		employee_getHorasTrabajadas(pEmployee,&horasTrabajadas);



		printf("ID:%d - NOMBRE: %s - HORAS TRABAJADAS: %d- SUELDO: %d. \n" , auxId, auxNombre, horasTrabajadas, auxSueldo);
	}

	 return retorno ;
}
