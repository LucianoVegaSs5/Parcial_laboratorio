/*
 * arrayCencista.c
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
#define LENCENCISTA 3

int hardcodearCencista(eCencista* listaCencista)
{
	int retorno = -1;

	if(listaCencista != NULL )
	{
		eCencista listAuxiliar[] =
		{
			{100, "Ana", 34, "1203-2345"},
			{101, "Juan", 24, "4301-54678"},
			{102, "Sol", 47, "5902-37487"}
		};

		listaCencista[0] = listAuxiliar[0];
		listaCencista[1] = listAuxiliar[1];
		listaCencista[2] = listAuxiliar[2];

		retorno = 1;
	}

	return retorno;
}

void mostrarCencista(eCencista cencista)
{
	printf("lejago: %d \t nombre:  %s \t edad: %d \t telefono %s \n",
			cencista.legajoCencista,
			cencista.nombre,
			cencista.edad,
			cencista.telefono);
}

int printCencista(eCencista* lista, int len)
{
	int retorno = -1;
	int i;

	if(lista != NULL && len > 0)
	{
		printf("LISTA CENCISTAS:\n");
		for(i=0; i<len; i++)
		{
			printf("======================================================================\n");
			mostrarCencista(*(lista+i));
			printf("======================================================================\n");
			retorno = 1;
		}
	}

	return retorno;
}
