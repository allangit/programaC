/*comentarios 
en la linea */

#include <stdio.h>
#include <stdlib.h>

typedef struct snodolista {
  int valor;
  struct snodolista *siguiente;
} nodolista;

typedef struct slista {
  nodolista *primero;
  long tam; // cantidad de elementos de la lista
} lista;

int agregar_valor(lista *l, int valor);
int agregarfinal(lista *plista, int valor);
void limpiar_lista(lista *l);

int main()
{
  lista l;

  l.primero = NULL;
  l.tam = 0;

  agregar_valor(&l, 2);
  agregar_valor(&l, -7);
  agregar_valor(&l, 10);
  agregar_valor(&l, 14);
  agregarfinal(&l,5);
  agregarfinal(&l,1);
  // actual: el nodo a imprimir
  nodolista *actual = l.primero;

  // Mientras haya nodos en la lista
  while (actual != NULL)
  {
    printf("%d\n", actual->valor);
    actual = actual->siguiente;
  }

  limpiar_lista(&l);
  
  return 0;
}

int agregar_valor(lista *l, int valor)
{
  // Primero, asignamos memoria al nodo
  nodolista *nuevo = (nodolista *) malloc(sizeof(nodolista));

  if (nuevo != NULL)
  {
    // Una vez que ya tenemos memoria asignada,  insertamos el nodo en la posición requerida.
    // En este caso, será al inicio de la lista

    nuevo->valor = valor;

    // Si está vacía
    if (l->primero == NULL)
    {
      l->primero = nuevo;
      nuevo->siguiente = NULL;
      
    }
    else
    {
      nuevo->siguiente = l->primero;
      l->primero = nuevo;
    }
    
    l->tam++;

    return 1;
  }

  return 0;
}

void limpiar_lista(lista *l)
{
  // Libera la memoria asignada a cada uno de los nodos
  // actual: el nodo cuya memoria se va a liberar
  nodolista *actual = l->primero;

  while (actual != NULL)
  {
    l->primero = l->primero->siguiente;
    free(actual);
    actual = l->primero;
  }

  l->tam = 0;
}

int agregarfinal(lista *plista, int valor)
{
	nodolista *nuevo = (nodolista *) malloc(sizeof(nodolista));
	
	if (nuevo != NULL)
	{
    // Una vez que ya tenemos memoria asignada,  insertamos el nodo en la posición requerida.
    // En este caso, será al inicio de la lista

		nuevo->valor = valor;
		
		if (plista->primero == NULL) 
		{
			plista->primero = nuevo;
			nuevo->siguiente = NULL;
      
        }
		else
		{
			nodolista *ultimo=plista->primero;
			
			while (ultimo->siguiente!=NULL){
				
				ultimo=ultimo->siguiente;
			}
			ultimo->siguiente=nuevo;
			nuevo->siguiente=NULL;
		}
		
		plista->tam++;
		
		return 1;
	}
	
	return 0;
}

