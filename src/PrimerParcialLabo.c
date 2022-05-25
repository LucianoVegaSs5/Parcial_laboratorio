/*
 ============================================================================
Vega Luna Luciano Rafael
Division 1D
Parcial Laboratorio
 ============================================================================
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

#define NOMBRE 25
#define LEN 100 //LARGO
#define LENCENCISTAS 3 // CANCTIDAD CENCISTAS

int main(void) {
	setbuf(stdout, NULL);

	eVivienda listaVivienda[LEN];
    eCencista listaCencista[LENCENCISTAS];

	int iDSVivienda = 2000;
	int salir;
	char opcionLetra;
	int flagIngreso = 0;

	if(inicializadorVivienda(listaVivienda, LEN) == 1 && hardcodearCencista(listaCencista) == 1)
	{
		do
		{
			mostrarMenuPrincipal(&opcionLetra);

			switch(opcionLetra)
			{
				case 'A':
					altaVivienda(listaVivienda, LEN, &iDSVivienda, &flagIngreso, listaCencista);
					break;
				case 'B':
					modificarVivienda(listaVivienda, LEN, &flagIngreso, listaCencista);
					break;
				case 'C':
					bajaVivienda(listaVivienda, LEN, &flagIngreso);
					break;
				case 'D':
					ordenarViviendaPorCalle(listaVivienda, LEN);
					printVivienda(listaVivienda, LEN, &flagIngreso);
					break;
				case 'E':
					printCencista(listaCencista, LENCENCISTAS);
					break;
				case 'F':
					mostrarMenuSalida(&salir);
					break;
				default:
					printf("Elija porfavor una opcion valida.\n");
					break;

			}

		}while(salir != 1);

	}
	else
	{
		printf("ERROR EN LA INICIALIZACION\n");
	}

}



