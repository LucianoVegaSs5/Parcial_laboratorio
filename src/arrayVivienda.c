/*
 * arrayVivienda.c
 *
 *  Created on: 22 may. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input-UTN.h"
#include "arrayVivienda.h"
#include "arrayCencista.h"
#include "printearMenues.h"


int inicializadorVivienda(eVivienda lista[], int len)
{
    int retorno = -1;
    int i;
    if(lista != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            (lista+i)->idVivienda = -1; // Declaramos vacias todas las pocisiones
        }

        retorno = 1;
    }

    return retorno;
}

int buscarPocisionVacia(eVivienda* lista, int len)
{
	int pocisionVacia;
	int i;

	if(lista != NULL && len > 0)
	{
		for(i = 0; i < len ; i++)
		{
			if((lista+i)->idVivienda == -1)
			{
				pocisionVacia = i;
				break;
			}
		}
	}

	return pocisionVacia;
}

int agregarVivienda(eVivienda* lista, int len, int idVivienda, char* calle, int cantidadPersonas,
		int cantidadHabitaciones, int tipoVivienda, int legajoCencista)
{
    int retorno = -1;
    int pocisionVacia;

    pocisionVacia = buscarPocisionVacia(lista, len);
    if(pocisionVacia > -1)
    {
    	if(lista != NULL && len > 0)
        {
			(lista+pocisionVacia)->idVivienda = idVivienda;
			strcpy((lista+pocisionVacia)->calle, calle);
			(lista+pocisionVacia)->cantidadPersonas = cantidadPersonas;
			(lista+pocisionVacia)->cantidadHabitaciones = cantidadHabitaciones;
			(lista+pocisionVacia)->tipoVivienda = tipoVivienda;
			(lista+pocisionVacia)->legajoCencista.legajoCencista = legajoCencista;

	        retorno = 1;
	    }
	}

   return retorno;
}

int ordenarViviendaPorCalle(eVivienda* list, int len)
{
    int i;
    int j;
    int diferencia;
    eVivienda guardar;
    int retorno = -1;

    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len-1; j++)
            {
            	if((list+i)->idVivienda > 2000 && (list+j)->idVivienda > 2000)
            	{
            		diferencia = strcmp((list+i)->calle,(list+j)->calle );

            		if(diferencia > 0)
            		{
            			guardar = *(list+j);
            			*(list+j) = *(list+i);
            			*(list+i) = guardar;
            		}
            		else
            		{
            			if(diferencia == 0)
            			{
            				if((list+i)->cantidadPersonas <= (list+j)->cantidadPersonas)
            				{
            					guardar = *(list+j);
            					*(list+j) = *(list+i);
            					*(list+i) = guardar;
            				}
            			}
            		}
            	}
            }
        }
    }

    return retorno;

}

void mostrarVivienda(eVivienda vivienda)
{
	char tipoDeVivienda[25];

	switch(vivienda.tipoVivienda)
		{
			case 1:
				strcpy(tipoDeVivienda,"Casa");
				break;
			case 2:
				strcpy(tipoDeVivienda,"Departamento");
				break;
			case 3:
				strcpy(tipoDeVivienda,"Casillaasa");
				break;
			case 4:
				strcpy(tipoDeVivienda,"Rancho");
				break;
		}

	printf(" id: %d\t Calle: %s\t  %d Personas/s\t Habitaciones: %d\t tipo:  %s\t legajo del Cencista: %d\n",
    vivienda.idVivienda,
	vivienda.calle,
	vivienda.cantidadPersonas,
	vivienda.cantidadHabitaciones,
	tipoDeVivienda,
	vivienda.legajoCencista.legajoCencista);



}

int printVivienda(eVivienda* lista, int len, int* flagIngreso)
{
	int retorno = -1;
	int i;

	if(*flagIngreso == 1)
	{
		if(lista != NULL && len > 0)
		{
			printf("LISTADO DE CASAS:\n");
			for(i = 0; i < len; i++)
			{
				if((lista+i)->idVivienda != -1)
				{
					printf("==========================================================================================================================\n");
					mostrarVivienda(*(lista+i));
					printf("==========================================================================================================================\n");
					retorno = 0;
				}
			}
		}
	}
	else
	{
		printf("Necesita ingresar datos primero\n");
	}
	return retorno;
}

int encontratViviendaPorId(eVivienda* list, int len, int idVivienda)
{
    int retorno = -1;
    int i;

    if(list != NULL && len > 0)
    {
        for(i=0; i< len; i++)
        {
            if((list+i)->idVivienda == idVivienda)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int bajaLogica(eVivienda* lista, int len, int pocisionIdBorrar)
{
	int retorno = -1;
	if(lista!=NULL && len > 0)
	{
		(lista+pocisionIdBorrar)->idVivienda = -1;
		retorno = 1;
	}
	return retorno;
}

void altaVivienda(eVivienda* listaVivienda, int len,int* ids,int* flagIngreso, eCencista* listaCencista)
{
	eVivienda viviendaAux;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;

	int validarIngreso;

	if(listaVivienda != NULL && len > 0)
	{
		printf("\n========== ALTA ==========\n");

		viviendaAux.idVivienda = *ids;
		(*ids)++;

		pedirString(calle, "Ingrese el nombre de la calle donde se encuetra su vivienda: ", "Error, no debe agregar puntos ni numeros\n");

		pedirNumeros(&cantidadPersonas, "Ingrese la cantidad de personas que viven en la vivienda: ", "Error, debe ingresar solo numeros enteros\n",
				"Error el numero es muy grande o muy pequeño\n", 15, 1);
		pedirNumeros(&cantidadHabitaciones, "Ingrese la cantidad de habitaciones que hay en la vivienda: ", "Error, debe ingresar solo numero esteros\n",
				"Error, el numero es muy grande o muy pequeño\n", 15, 1);

		pedirNumeros(&tipoVivienda, "El tipo de vivienda en la que usted vive es: \n"
				"1- Casa\n"
				"2- Departamento\n"
				"3- Casilla\n"
				"4- Rancho\n"
				"Porfavor ingrese la opcion correspondiente a su vivienda: ", "Error, debe ingresar solo numeros", "Error, elija una de las opcines indicadas: ", 4,1);

		strcpy(viviendaAux.calle, calle);
		viviendaAux.cantidadPersonas = cantidadPersonas;
		viviendaAux.cantidadHabitaciones = cantidadHabitaciones;
		viviendaAux.tipoVivienda = tipoVivienda;

		switch(tipoVivienda)
		{
			case 1:
				viviendaAux.legajoCencista.legajoCencista = listaCencista[2].legajoCencista;
				strcpy(viviendaAux.legajoCencista.nombre,listaCencista[2].nombre);
				break;
			case 2:
				viviendaAux.legajoCencista.legajoCencista = listaCencista[0].legajoCencista;
				strcpy(viviendaAux.legajoCencista.nombre,listaCencista[0].nombre);
				break;
			case 3:
			case 4:
				viviendaAux.legajoCencista.legajoCencista = listaCencista[1].legajoCencista;
				strcpy(viviendaAux.legajoCencista.nombre,listaCencista[1].nombre);
				break;
		}

		validarIngreso = agregarVivienda(listaVivienda, len, viviendaAux.idVivienda, viviendaAux.calle, viviendaAux.cantidadPersonas, viviendaAux.cantidadHabitaciones,
				viviendaAux.tipoVivienda, viviendaAux.legajoCencista.legajoCencista);

		if(validarIngreso == 1)
		{
			printf("\nLa vivienda se ha cargado correctamente\n");
			printf("Su id de vivienda es %d, con el podra modificar datos o borrarlos de ser necesarios. \n"
					"El cencista encargado de su casa es %s - legajo %d.\n", viviendaAux.idVivienda, viviendaAux.legajoCencista.nombre, viviendaAux.legajoCencista.legajoCencista);
			*flagIngreso = 1;
		}
		else
		{
			printf("No hay espacio suficiente.\n");
		}
	}

}

void modificarVivienda(eVivienda* lista, int len, int* flagCarga, eCencista* listaCencista)
{
	int idModificar;
	int opcionModificar;
	int pocisionId;
	int confirmar;

	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;

	if(*flagCarga == 1)
	{
		if(lista != NULL && listaCencista != NULL && len > 0)
		{
			printf("\n========== MODIFICAR ==========\n");

			pedirNumeros(&idModificar, "Ingrese el id de la vivienda que desea modificar: ", "Error, debe ingresar solo el numero de id\n", "Error, numero de id invalido\n",2100 , 2000);

			pocisionId = encontratViviendaPorId(lista, len, idModificar);

			if(pocisionId != -1)
			{
				mostrarVivienda(*(lista+pocisionId));
				mostrarMenuModificacion(&opcionModificar);

				switch(opcionModificar)
				{
					case 1:
						pedirString(calle, "Ingrese el nuevo nombre de la calle: ", "Error, no debe ingresar numeros\n");
						guardarCambios(&confirmar);
						if(confirmar == 1)
						{
							strcpy((lista+pocisionId)->calle, calle);
							printf("Cambios guardados.\n");
							mostrarVivienda(*(lista+pocisionId));
						}
						else
						{
							printf("No se ha realizado ningun cambio\n");
							mostrarVivienda(*(lista+pocisionId));
						}
						break;
					case 2:
						pedirNumeros(&cantidadPersonas, "Ingrese la cantidad de personas que viven en la vivienda: ", "Error, debe ingresar solo numeros enteros\n",
									"Error el numero es muy grande o muy pequeño\n", 15, 1);
						guardarCambios(&confirmar);
						if(confirmar == 1)
						{
							(lista+pocisionId)->cantidadPersonas = cantidadPersonas;
							printf("Cambios guardados.\n");
							mostrarVivienda(*(lista+pocisionId));
						}
						else
						{
							printf("No se ha realizado ningun cambio\n");
							mostrarVivienda(*(lista+pocisionId));
						}
						break;
					case 3:
						pedirNumeros(&cantidadHabitaciones, "Ingrese la cantidad de habitaciones que hay en la vivienda: ", "Error, debe ingresar solo numero esteros\n",
									"Error, el numero es muy grande o muy pequeño\n", 15, 1);
						guardarCambios(&confirmar);
						if(confirmar == 1)
						{
							(lista+pocisionId)->cantidadHabitaciones = cantidadHabitaciones;
							printf("Cambios guardados.\n");
							mostrarVivienda(*(lista+pocisionId));
						}
						else
						{
							printf("No se ha realizado ningun cambio\n");
							mostrarVivienda(*(lista+pocisionId));
						}
						break;
					case 4:
						pedirNumeros(&tipoVivienda, "El tipo de vivienda en la que usted vive es: \n"
									"1- Casa\n"
									"2- Departamento\n"
									"3- Casilla\n"
									"4- Rancho\n"
									"Porfavor ingrese la opcion correspondiente a su vivienda: ", "Error, debe ingresar solo numeros", "Error, elija una de las opcines indicadas: ", 4,1);
						guardarCambios(&confirmar);

						if(confirmar == 1)
						{
							(lista+pocisionId)->tipoVivienda = tipoVivienda;
							printf("Cambios guardados.\n");
							mostrarVivienda(*(lista+pocisionId));
						}
						else
						{
							printf("No se ha realizado ningun cambio\n");
							mostrarVivienda(*(lista+pocisionId));
						}
						break;
				}

			}
			else
			{
				printf("El id de la vivienda ingresado es incorrecto.\n");
			}
		}
	}
	else
	{
		printf("Necesita cargar datos primero\n");
	}
}

void bajaVivienda(eVivienda* lista, int len, int* flagCarga)
{
	int pocisionId;
	int idBorrar;
	int validarBaja;
	int confirmar;

	if(*flagCarga == 1)
	{
		if(lista != NULL && len > 0)
		{
			printf("\n========== BAJA ==========\n");

			pedirNumeros(&idBorrar, "Ingrese el id de la vivienda que desea borrar: ", "Error, debe ingresar solo el numero de id\n", "Error, numero de id invalido\n",2100 , 2000);
			pocisionId = encontratViviendaPorId(lista, len, idBorrar);

			if(pocisionId != -1)
			{
				mostrarVivienda(*(lista+pocisionId));
				pedirNumeros(&confirmar, "¿Esta seguro de borrar los datos de la vivienda?\n"
								"1- Si\n"
								"2- No\n"
									"Elija una opcion: ", "Error, debe elejir una opcion valida", "Error, debe elejir una opcion valida", 2, 1);
				if(confirmar == 1)
				{
					validarBaja = bajaLogica(lista, len, pocisionId);

					if(validarBaja == 1)
					{
						printf("La operacion se ha completado con exito\n");
					}
					else
					{
						printf("Ocurrio un error inesperado\n");
					}
				}
				else
				{
					printf("La operacion ha sido cancelada.\n");
				}
			}
			else
			{
				printf("El id de la vivienda ingresado es incorrecto.\n");
			}
		}
		printf("Algo salio mal\n");

	}
	else
	{
		printf("Necesita cargar datos primero\n");
	}
}

