/*
 * printearMenues.h
 *
 *  Created on: 24 may. 2022
 *      Author: Luciano
 */

#ifndef PRINTEARMENUES_H_
#define PRINTEARMENUES_H_



#endif /* PRINTEARMENUES_H_ */

/**
 * @brief muestra el menu principal y llama a una funcion para pedir el dato para el case
 *
 * @param opcion (char* )
 */
void mostrarMenuPrincipal(char* opcion);

/**
 * @brief muestra todas las opciones a modificar y pide la opcion para validarla
 *
 * @param opcion
 */
void mostrarMenuModificacion(int* opcion);

/**
 * @brief pregunta si se quiere guardar los cambios 1-si, 2-no pidiendo la opcion al usuario y validandola
 *
 * @param confirmar
 */
void guardarCambios(int* confirmar);

/**
 * @brief Si se escoge la opcion salir pide la confirmacion con 1 para si y 2 para no
 *
 * @param salir
 */
void mostrarMenuSalida(int *salir);
