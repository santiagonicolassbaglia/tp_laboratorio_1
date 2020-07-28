#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this= malloc(sizeof(LinkedList));

    if (this!= NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if (this!= NULL)
        {
    	  returnAux= this->size;

        }



    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxiliarNodo=NULL;
	int indice;


	if (this!= NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		auxiliarNodo= this->pFirstNode;
		indice=0;

	do{


		if ( indice == nodeIndex)
		{
			return auxiliarNodo;
		}
		else{
			   auxiliarNodo = auxiliarNodo->pNextNode; // pasa al sig nodo hasta que encuentre el que esta buscando
			indice++;									// y lo devuelve

		   }
	 }while(auxiliarNodo != NULL);

	}

 return NULL;


}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 *
 *
 *
 *  1 - crear el nodo
    	 * 2- cargar el elemento en el nodo
    	 * 3- incrementar el size

 *principio
 *
 * crear el nodo
    	// crear el empleado
    	//cargar el elemento al nodo
    	3- incrementar el size
		4-next node a null
		5-escribir el pfrirst node con la dire de nuevo nodo
 *
 * MEDIO


		1-next node al siguiente del que esta en nodeIndex ahora get node (nodeIndex), tiene que agarrar al ultimo antes que al anterior
    	 2- obtener el nodo anterior a este ( get_node(nodeIndex-1)) y escribirle la direc del nuevo nodo



    	 * 1- next node a pFirst
    	 * 2- obtener el nodo anterior a este ( get_node(nodeIndex-1)) y escribirle la direc del nuevo nodo
    	 */





static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nodoNew = NULL;
    Node* nodoAux = NULL;
    if( this != NULL && nodeIndex >= 0 )//Verifica que el puntero a la lista no sea NULL y que el index sea coherente.
    {
    	nodoNew = (Node*) malloc(sizeof(Node));//Asigna un espacio en la memoria a nodoNew.
    	if( nodoNew != NULL )//Verifica que el nodoNew se haya creado correctamente.
    	{
    		nodoNew->pElement = pElement;//Le asigna al nodo el elemento
			if( nodeIndex == 0 )//si es el primero
			{
				nodoNew->pNextNode = this->pFirstNode;//hace que este nodo nuevo, apunte a la direccion de memoria que apuntaba la lista.
				this->pFirstNode = nodoNew;//Hace que la lista apunte al nodo nuevo.
			}
			else//Si no es el primer nodo.
			{
				nodoAux = getNode(this,nodeIndex-1); //obtener el nodo anterior a este ( get_node(nodeIndex-1)) y escribirle la direc del nuevo nodo
				nodoNew->pNextNode = nodoAux->pNextNode;//Hago que el nodo nuevo, apunte a la direccion de memoria que estaba apuntando el nodo anterior. (Puede ser otro nodo o NULL).
				nodoAux->pNextNode = nodoNew;//Hago que el nodo anterior, apunte a el nodo nuevo.
			}
			this->size++;//Incrementa el tama�o de la lista.
			returnAux = 0;
		}
    }
    return returnAux;
}



/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)// agrega un nodo llamando addnode y le carga el elemento recivido
{

    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if( this != NULL &&//Verifica que el puntero a la lista no sea NULL.
    	!addNode(this,this->size,pElement) )//Valida que addNode, haya agregado el nodo correctamente.
    {
    	returnAux = 0;//Retorna 0, estan ok las validaciones del IF.
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)// le devuelve lo que esta adentro de getnode ( el puntero)
{
	 void* returnAux = NULL;
	    Node *pNodo = NULL;

	    if ( this != NULL)
	    {
	        if (index >=0 &&  index<=ll_len(this)) // verifica que el indice sea positivo y que la estructura sea menor
	        {
	            pNodo = getNode(this, index);// recorre la lista y te da la posicion de la posicion de memoria del dato buscado

	            if(pNodo != NULL)
	            {
	                returnAux = pNodo->pElement;//devuelve puntero al elemento
	            }
	        }
	    }

	    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)// reemplaza el elemento por este..
                                                      // usa el get para obtener el nodo y reemplazo el elemento
{
    int returnAux = -1;
    Node  *pNodeAux;
    if ( this != NULL)
    {

        if (index >=0 &&  index<=ll_len(this))// verifica si es positivo y menos a cant
        {
            pNodeAux = getNode(this, index);//devuelve pnode->pnextnode

            if(pNodeAux != NULL)
            {
                pNodeAux->pElement = pElement;//copia el elemento al campo elemento de NODE
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_remove(LinkedList* this,int index)// elimina un elemento particular de la lista
{
    int returnAux = -1;
    Node* auxNodo = NULL;
    Node* auxNodo2 = NULL;
    if( this != NULL && index >= 0 && index < this->size )//Verifica que el puntero a la lista no sea NULL y que el indice sea coherente.
    {
    	auxNodo = getNode(this,index);//Obtengo el nodo del indice a eliminar.
    	auxNodo2 = getNode(this,index-1);//Obtengo el nodo del indice anterior a ser eliminado.
    	if( index == 0 )//Valida si es el primer nodo.
    	{
    		this->pFirstNode = auxNodo->pNextNode;//Hace que la lista apunte a la direccion de memoria,
    	}									    //donde apunta el nodo a eliminar (Puede ser otro nodo o NULL).
    	else//Si no es el primer nodo.
    	{
    		auxNodo2->pNextNode = auxNodo->pNextNode;//Hace que el nodo anterior a eliminar,
    	}											//apunte a la direccion de memoria donde apunta el nodo a eliminar (Puede ser otro nodo o NULL).
    	free(auxNodo);//Libera el espacio de memoria del nodo eliminado.
    	this->size--;//Decrementa el size, ya que se elimin� un nodo.
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)// llama al remove un monton de veces para eliminar todos los ementos de la lista
{
	  int returnAux = -1;
	    int i ;

	    if (this != NULL)
	    {

	        for ( i= ll_len( this); i> 0; i--  )// recorre desde el ultimo indice hasta el principio para poder eliminar todo
	        {
	            ll_remove(this, i); //remoueve los datos de un indice determinado

	        }
	        returnAux = 0; //funciona corractamente

	    }

	    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)//borra toda la estrucuta linkedlist
{
	  int returnAux = -1;

	    if(this != NULL)
	    {
	        if(ll_clear(this) == 0)// si clear es 0 borro correctamente todos los elementos
	        {
	            free(this); // libera la direccion de memoria del puntero a linkedlint
	            returnAux = 0;//si borro correctamente devolvera 0
	        }
	    }

	    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)// recorre la lista hasta que algunos de los nodos encuentre el elemento.. si lo encuentra le dice en que posicion esta
{
	int returnAux = -1;
	    Node *pNode;
	    int i ;

	    if ( this !=NULL )
	    {

	        for ( i=0 ; i<ll_len(this); i++ )
	        {
	            pNode= getNode(this,i);//recorre todos los datos
	            if(pNode->pElement == pElement)// busca el nombre o dato que le digamos
	            {
	                returnAux = i; // devuelve el indice si lo encontro
	                break;
	            }
	        }
	    }

	    return returnAux; //devuelve -1 sino lo encuentra
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)// verifica si hay datos en el linkedlist
{int returnAux = -1;

if (this != NULL)
{
    if ( ll_len(this)== 0 )
    {

        returnAux =1 ;

    }
    else

        if ( ll_len( this)>0)
        {
            returnAux = 0;

        }

}

return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */




int ll_push(LinkedList* this, int index, void* pElement)// ponggo el dato en el lugar que quiera
{
    int returnAux = -1;

    if ( this!=NULL)
    {
        if(index >= 0 && index <= ll_len(this))// en addnoce resto-1 al index
        {
            addNode(this, index, pElement);// add solo devuelve -1 y 0 si es correcto
            returnAux = 0;
        }
    }

    return returnAux;
}





/*
int ll_push(LinkedList* this, int index, void* pElement)// pide el nodo con getNode y lo pongo con addNode
{                                                       // pongo el dato en el lugar que quiera
	 int returnAux = -1;

		    Node *pNode;
		    int i ;

		    if ( this !=NULL )
		    {
		    	if(index >= 0 && index <= ll_len(this))
		    	{
		        for ( i=0 ; i<ll_len(this); i++ )
		        {
		        	returnAux = 1;
		            this= getNode(this,i);//recorre todos los datos
		         if(!addNode(this, index, pElement))// busca el nombre o dato que le digamos

		         {
		        	 if ( pElement != NULL)
		        	 {
		                returnAux = 0; // devuelve el indice si lo encontro
		                break;

		        	 }
		        }

		        }
		    }

		    }
		    return returnAux; //devuelve -1 sino lo encuentra


}

*/
/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)// elimina un elemento pero devuelve el puntero
{										// elimina elementos en la posicion que le diga
	void* returnAux = NULL;

	    if (  this != NULL)
	    {
	        if( index>= 0 && index < ll_len(this))// verifica que sea positivo y que sea menor a la estructura
	        {
	            returnAux = ll_get(this, index); // get devuelve puntero a elemento  o devuelve NULL
	            ll_remove(this, index);

	        }
	    }

	    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)//verifica que el elemento que yo ingrese esta en el linkedlist
{
	  int returnAux = -1;

	    if(this != NULL)
	    {
	        if(ll_indexOf(this, pElement)!=-1)// llama a indexof que recorre la lista hasta que algunos de los nodos encuentre el elemento.. si lo encuentra le dice en que posicion esta
	        {
	            returnAux = 1;
	        }
	        else
	        {
	            returnAux = 0;
	        }
	    }

	    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxElement = NULL;
    if (this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for (int i = 0; i < ll_len(this); i++)
        {
            auxElement = ll_get(this2, i);
            if (!ll_contains(this, auxElement))
            {
                returnAux = 0;
                break;
            }        }
    }
    return returnAux;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElementAux = NULL;
    if (this != NULL && from >= 0 && from <= to && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        if (cloneArray != NULL)
        {
            for(int i = from; i < to; i++)
            {
                pElementAux = ll_get(this, i);
                ll_add(cloneArray, pElementAux);            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this) // copia la lista desde 0 hasta size
{
	LinkedList* cloneArray = NULL;

	    if(this != NULL)
	    {
	        cloneArray = ll_subList(this, 0, ll_len(this));
	    }

	    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)// te ordena los elementos de la lista
{
	 int returnAux =-1;

	    void* pElementUno;
	    void* pElementDos;
	    void* pElementAux;
	    int i;
	    int flag;
	    int cantidad;

	    if(this!=NULL)
	    {
	        if (pFunc!= NULL)
	        {
	            if (order == 0 || order == 1)// descendente o ascendente
	            {
	                cantidad = ll_len(this);
	                if(cantidad > 0)
	                {
	                    do
	                    {
	                        flag = 0;
	                        for(i=0; i<cantidad-1; i++)
	                        {
	                            pElementUno = ll_get(this,i);// ll_get devuelve puntero a elemnto
	                            pElementDos = ll_get(this,i+1);

	                            if((pFunc(pElementUno, pElementDos) <0 && order==0) || (pFunc(pElementUno, pElementDos) >0 && order==1))
	                            {
	                                pElementAux = pElementUno;          //aux = p1
	                                ll_set(this,i,pElementDos);         //p1=p2
	                                ll_set(this,i+1,pElementAux);         //p2=aux
	                                flag=1;
	                            }
	                            returnAux=0;
	                        }
	                    }while(flag);
	                }
	            }
	        }
	    }

	    return returnAux;


}
















int ll_map(LinkedList* this, void (*pFunc)(void*))
{
    int retorno = -1;
    void* pElement = NULL;
    int i;
    if(this != NULL && pFunc != NULL)
    {
        for(i=0; i<ll_len(this); i++)//recorre todo el linkedlist
        {
            pElement = ll_get(this, i);// copia los datos de linkedlist a un puntero
            pFunc(pElement);//pfunc = agregar comision y pelement = void* variableA
            retorno = 0;
        }
    }
    return retorno;
}



LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* returnAux;
    int length;
    int i;
    void* pElement;
    if(this != NULL && pFunc != NULL)
    {
        returnAux = ll_newLinkedList();
        length = ll_len(this);
        for(i=0;i<length;i++)
        {
            pElement = ll_get(this, i);
            if(pFunc(pElement) == 1)
            {
                ll_add(returnAux, pElement);
            }
        }
    }
    return returnAux;
}








int ll_count(LinkedList* this, int (*pFunc)(void*))
{
    int contador = 0;
    void* pElement = NULL;
    if (this != NULL && pFunc != NULL)
    {
        for (int i = 0; i < ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            if (pFunc(pElement)==1)
            {
                contador++;
            }
        }
    }
    return contador;}


LinkedList* ll_reduce(LinkedList* this, int (*pFunc) (void*))
{
    int i;
    void* element;

    if (this!=NULL && pFunc!=NULL)
    {
        for (i=0;i<ll_len(this);i++)
        {
            element=ll_get(this,i);
            if (pFunc(element)==1)
            {
                ll_remove(this,i);
            }
        }
    }
    return this;
}
