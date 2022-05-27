/*
 * arrayVivienda.h
 *
 *  Created on: 22 may. 2022
 *      Author: Luciano
 */

#include "arrayCencista.h"

#ifndef ARRAYVIVIENDA_H_
#define ARRAYVIVIENDA_H_

struct
{
  int idVivienda;
  char calle[NOMBRE];
  int cantidadPersonas;
  int cantidadHabitaciones;
  int tipoVivienda;
  eCencista legajoCencista;
}typedef eVivienda;


#endif /* ARRAYVIVIENDA_H_ */

/**
 * @brief inicializa el array de viviendas con los id en -1, para indicar que estan vacios
 *
 * @param lista (eVivienda) array de viviendas
 * @param len (int) cantidadDeViviendas
 * @return 1 si salio todo bien y -1 de caso contrario
 */
int inicializadorVivienda(eVivienda* lista, int len);

/**
 * @brief se le ingresa el array de viviendas y busca la primera pocision que tenga como valor de idVivienda en -1, como desocupado
 *
 * @param lista (eVivienda) array de viviendas
 * @param len (int) largo del array
 * @return retorna la pocision vacia o -1 si algo salio mal
 */
int buscarPocisionVacia(eVivienda* lista, int len);

/**
 * @brief Se le ingresan los valores pedidos en el alta para cargarlos al array en la pocision vacia encontrada
 *  en la funcion buscarPocisionVacia
 *
 * @param lista (eVivienda) array de viviendas
 * @param len (int) largo de viviendas
 * @param idVivienda (int)
 * @param calle (char array[])
 * @param cantidadPersonas (int )
 * @param cantidadHabitaciones (int)
 * @param tipoVivienda (int)
 * @param legajoCencista (eCensista (int))
 * @return retorna 1 si salio todo bien o -1 de caso contrairo
 */
int agregarVivienda(eVivienda* lista, int len, int idVivienda, char* calle, int cantidadPersonas,
		int cantidadHabitaciones, int tipoVivienda, int legajoCencista);

/**
 * @brief Ordena el array por calle en descendente y si son iguales los ordena por cantidad de personas
 *
 * @param list (eVivivenda) array de viviendas
 * @param len (int) cantidad de viviendas
 * @return
 */
int ordenarViviendaPorCalle(eVivienda* list, int len);

/**
 * @brief recibe una vivivienda y muestra todos su campos
 *
 * @param vivienda (eVivienda)
 */
void mostrarVivienda(eVivienda vivienda);

/**
 * @brief analiza que las viviendas que tengan un id != de -1 sean mostradas por la funcion mostrarVivienda
 *
 * @param lista (eVivienda) array de viviendas
 * @param len (int) largo del array
 * @param flagIngreso (int* )
 * @return 1 si salio todo bien p -1 de caso contrario
 */
int printVivienda(eVivienda* lista, int len, int* flagIngreso);


/**
 * @brief Se ingresa la lista, el largo y ademas el id que se quiere encontrar, la funcion lo compara con todas las pocisiones
 *	y retonar la pocicion encontrada sino existe el id retorna -1
 *
 * @param list (eVivienda) array de viviendas
 * @param len (int ) largo del array
 * @param idVivienda (int ) id de vivienda
 * @return la pocision encontrada del id sino retorna -1
 */
int encontratViviendaPorId(eVivienda* list, int len, int idVivienda);

/**
 * @brief pide los datos necesarios para cargar la vivienda y todos sus campos, habilita con el flag ingreso que se pueda acceder a las otras opciones
 * y elije al cencsista segun el tipo de vivienda de la vivienda ingresada.
 *
 * @param listaVivienda (eVivienda *) array de viviendas
 * @param len (int ) largo del array de viviendas
 * @param ids (int* ) puntero con el que va haciendo un inremento del id
 * @param flagIngreso (int* ) puntero con el cual se habilita las demas opciones
 * @param listaCencista (int* ) lista de los cencistas para designar a cada casa
 */
void altaVivienda(eVivienda* listaVivienda, int len,int* ids,int* flagIngreso, eCencista* listaCencista);

/**
 * @brief pregunta que campo de vivienda se decea modificar y pide los datos para actualizarlos segun la opcion elegida,
 * validando el id ingresado y el flag de carga para poder acceder a la opcion cuando almenos se halla ingresado una funcion
 *
 * @param lista (eVivienda* ) array de viviendas
 * @param len (int ) largo del array
 * @param flagCarga (int *) flag que habilita la opcion
 * @param listaCencista (eCencista* )
 */
void modificarVivienda(eVivienda* lista, int len, int* flagCarga, eCencista* listaCencista);


/**
 * @brief recibe una pocision del array viviendas y cambia el id a -1, haciando que la pocision ahora este vacia
 * ocasionado una baja logica
 *
 * @param lista (eVivien*) array de viviendas
 * @param len (int) largo del array
 * @param pocisionIdBorrar (int) id que se desea borrar
 * @return
 */
int bajaLogica(eVivienda* lista, int len, int pocisionIdBorrar);

/**
 * @brief pregunta el id de vivienda que sea desea borrar para lugao despues de la confirmacion llamar a la funciona que
 * hace la baja logica
 *
 * @param lista (eVvivienda* )Array de viviendas
 * @param len (int) largo del array
 * @param flagCarga (int)
 */
void bajaVivienda(eVivienda* lista, int len, int* flagCarga);

void informarDatosCencista(eVivienda* listaVivienda, int lenVivienda, eCencista*  listaCencista,  int lenCencista, int* contadorPrimerCencista, int* contadorSegundoCencista, int* contadorTercerCencista);

