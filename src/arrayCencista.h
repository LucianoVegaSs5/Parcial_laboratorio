/*
 * arrayCencista.h
 *
 *  Created on: 22 may. 2022
 *      Author: Luciano
 */

#define NOMBRE 25

#ifndef ARRAYCENCISTA_H_

struct
{
	int legajoCencista;
	char nombre[NOMBRE];
	int edad;
	char telefono[20];
}typedef eCencista;

#define ARRAYCENCISTA_H_



#endif /* ARRAYCENCISTA_H_ */

/***
 * @brief hardcodea los campos de la entidad eCencista que fueron establecidos con antereoridad
 *
 * @param listaCencista (eCencista) array de cencistas
 * @return retorna 1 si salio todo bien y -1 de caso contrario
 */
int hardcodearCencista(eCencista* listCensista);

/**
 * @brief muestra todos los campos del cencista que recibe de la funcion printCencista
 *
 * @param cencista (eCencista)
 */
void mostrarCencista(eCencista cencista);

/**
 * @brief recibe una lista y el largo y llama a la funcion mostrarCencista para mostrar cada pocision del array
 * que tenga el id != -1
 *
 * @param lista (eCencista) array de cencista
 * @param len (int) largo del array
 * @return
 */
int printCencista(eCencista* lista, int len);

void cencistaMasCencos(int primerCencista, int segundoCencista, int tercerCencista, eCencista* listaCencista);
