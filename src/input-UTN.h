/*
 * input-UTN.h
 *
 *  Created on: 22 may. 2022
 *      Author: Luciano
 */

#ifndef INPUT_UTN_H_
#define INPUT_UTN_H_



#endif /* INPUT_UTN_H_ */

/**
 * @brief Recibe una cadena de pedir nombre para que las primeras letras de las palabras que hayan sean convertidas
 * en mayusculas y el resto en minusculas
 *
 * @param nombre (char [])
 */
void ponerMayusculas(char* nombre);

/**
 * @brief pide un nombre por consola y verifica que el array Nombre no tenga numeros y hace un buqle con la variable retorno
 * hasta que se escriba bien el nombre
 *
 * @param nombre (char [])
 * @param mensaje (char [])
 * @param mensajeError (char [])
 * @return retorna 1 si salio todo bien
 */
int pedirString(char* nombre, char* mensaje, char* mensajeError);

/**
 * @brief recibe un array y verifica si hay almenos una letra si es asi devuelve -1, sino devuelve 1
 *
 * @param cadena
 * @return 1 si no hay letras, sino devuelve -1
 */
int validarCadenaDeNumeros(char* cadena);

/**
 * @brief pide un numero como array y verifica que todos sean numeros, si es asi lo transforma a int y compara que este entre los rangos
 * pedidos, el bucle se hace con la variable retorno
 *
 * @param numero (int*) puntero en el que se guarda la variable
 * @param mensaje  (char  *) mensaje para pedir el dato
 * @param mensajeError (char* ) mensaje usado para indicar el error si no se ingreso numeros
 * @param mensajeError2 (char *) mensaje de error utilizado para indicar que este entre los rangos el numero pedido
 * @param maximo (int)
 * @param minimo (int )
 * @return
 */
int pedirNumeros(int* numero, char* mensaje, char* mensajeError, char* mensajeError2, int maximo, int minimo);

/**
 * @brief pide un numero por consola y valida que el numero este entre los parametros indicados
 *
 * @param numero (int*) punteros donde se guarda el valor ingresado
 * @param mensaje (char *) mensaje para la pedida de datos
 * @param mensajeError (char *) mensaje que indica si el valor no esta entre los parametros indicados
 * @param max (int)
 * @param min (int)
 */
void getNumeroValidarMaxMin(int* numero, char mensaje[],char mensajeError[], int max, int min);
