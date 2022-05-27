/*
 * printearMenues.c
 *
 *  Created on: 24 may. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input-UTN.h"

void mostrarMenuPrincipal(char* opcion)
{
	pedirString(opcion, "\n\n========= MENU =========\n"
							"A)ALTA VIVIENDA\n"
							"B)MODIFICAR VIVIENDA\n"
							"C)BAJA VIVIENDA\n"
							"D)LISTAR VIVIENDAS\n"
							"E)LISTAR CENCISTAS\n"
							"F)INFORMAR CENCISTA\n"
							"G)SENCISTA MAS CENSOS\n"
							"H)SALIR\n", "Error, Elija una opcion valida.\n");
}

void mostrarMenuModificacion(int* opcion)
{
	pedirNumeros(opcion, "Modificar: \n"
				"1- Calle\n"
				"2- Cantidad de Personas\n"
				"3- Cantidad de Habitaciones\n"
				"4- Tipo de Vivienda\n"
				"Ingrese la opcion que busca modificar: ", "Error, debe de ingresar la opcion a modificar", "Error, elija una opcion valida", 4 , 1);
}

void guardarCambios(int* confirmar)
{
	pedirNumeros(confirmar, "¿Desea guardar los cambios?\n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)", "Error, escoga una opcion valida", 2, 1);
}

void mostrarMenuSalida(int *salir)
{
	pedirNumeros(salir, "\n¿ESTA SEGURO DE SALIR?\n"
	    		"1) CONFIRMAR\n"
	 			"2) CANCELAR\n",
				"Error, ingrese una de las opciones (1-2)","Error, ingrese una de las opciones (1-2)", 2,1);
}
