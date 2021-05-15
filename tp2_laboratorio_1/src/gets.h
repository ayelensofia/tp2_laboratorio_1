
#ifndef GETS_H_
#define GETS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//GETS

/** \brief Obtiene un numero flotante
 *
 * \param [] char mensaje que pide el ingreso del numero flotante
 * \param char[] dato ingresado
 * \param char[] mensaje de error que pide el reingreso del numero flotante
 * \return int devuelve 1 si el numero es flotante, 0 sino lo es
 *
 */
float GetFloat(char [],char[],char[]);

/** \brief 0btiene una cadena de caracteres que contengan solo letras
 *
 * \param char[] mensaje que pide el ingreso de la cadena
 * \param char[] dato ingresado
 * \param char[] mensaje error que pide el reingreso de la cadena
 * \return int devuelve el dato ingresado convertido en flotante
 *
 */
int GetString(char[],char[],char[]);
/** \brief Obtiene un caracter
 *
 * \param char[] mensaje que pide el ingreso de un caracter
 * \param char dato ingresado
 * \param char[] mensaje error que pide el reingreso del caracter
 * \param char primer caracter valido
 * \param char segundo caracter valido
 * \return char devuelve el caracter ingresado
 *
 */
char GetChar(char[],char, char[],char,char);
/** \brief Obtiene un entero
 *
 * \param char[] mensaje que pide un entero
 * \param char[] dato ingresado
 * \param char[] mensaje de error que pide el reingreso del dato
 * \return int devuelve el dato ingresado convertido en entero
 *
 */
int GetInt(char[],char[],char[]);
/** \brief Obtiene un telefono
 *
 * \param char[] mensaje que pide un telefono
 * \param char[] dato ingresado
 * \param char[] mensaje de error que pide reingreso del dato
 * \return int retorno 1 si es un telefono, 0 sino lo es
 *
 */
int GetTelefono(char[],char[],char[]);
/** \brief Obtiene un dato alfanumerico
 *
 * \param char[] mensaje que pide un dato alfanumerico
 * \param char[] dato ingresado
 * \param char[] mensaje de error que pide el reingreso del dato
 * \return int devuelve 1 si es un alfanumerico, 0 sino lo es
 *
 */
int GetAlfanumerico(char[],char[],char[]);

/** \brief Obtiene un dato numerico con un rango especifico
 *
 * \param char[] mensaje que pide el dato
 * \param char[] dato ingresado
 * \param char[] mensaje de error que pide el reingreso del dato ingresado
 * \param int entero minimo que se puede ingresar
 * \param int entero maximo que se puede ingresar
 * \return int devuelve el dato convertido a entero
 *
 */
int GetEnteroConRango(char[],char[],char[],int,int);

//VALIDACIONES CON MENSAJE DE ERROR

/** \brief  Muestra mensaje de error sino recibe una cadena de solo letras
 *
 * \param char[] mensaje de error que pide el reingreso del dato
 * \param char[] dato ingresado
 * \return int devuelve 1 si es una cadena de solo letras, 0 sino lo es
 *
 */
int Validar_Cadena(char[],char[]);
/** \brief Muestra mensaje de error sino recibe una cadena de solo enteros
 *
 * \param char[] mensaje de error que pide el reingreso del dato ingresado
 * \param char[] dato ingresado
 * \return int devuelve 1 si es una cadena numerica, 0 sino lo es
 *
 */
int Validar_Numerico(char[],char[]);
/** \brief Muestra mensaje de error sino recibe una cadena alfanumerica
 *
 * \param char[] mensaje de error que pide el reingreso del dato ingresado
 * \param char[] dato ingresado
 * \return int devuelve 1 si es una cadena alfanumerica, 0 sino lo es
 *
 */
int Validar_Alfanumerico(char[],char[]);
/** \brief Muestra mensaje de error sino recibe una cadena con punto flotante
 *
 * \param char[] mensaje de error que pide el reingreso del dato ingresado
 * \param char[] dato ingresado
 * \return int devuelve 1 si es una cadena con punto flotante, 0 sino lo es
 *
 */
int Validar_Flotante(char[],char[]);
/** \brief Muestra mensaje de error sino recibe una cadena numerica con un solo guion
 *
 * \param char[] mensaje de error que pide el reingreso del dato ingresado
 * \param char[] dato ingresado
 * \return int devuelve 1 si es una cadena numerica con un solo guion, 0 sino lo es
 *
 */
int ValidarTelefono(char[],char[]);

/** \brief Obtiene un caracter
 *
 * \param char[] mensaje de error que pide el reingreso del dato ingresado
 * \param char dato ingresado
 * \param char primer caracter valido
 * \param char segundo caracter valido
 * \return char devuelve el dato ingresado validado
 *
 */
char Validar_Caracter(char[],char,char,char);

/** \brief Valida que un entero este dentro de un rango determinado
 *
 * \param char[]  mensaje de error que pide el reingreso del dato ingresado
 * \param int dato del tipo entero recibido
 * \param int entero minimo que se puede ingresar
 * \param int entero maximo que se puede ingresar
 * \return int devuelve el dato del tipo entero validado
 *
 */
int ValidarRangoEntero(char[],int,int,int);

//COMPROBACIONES

/** \brief Verifica si el dato recibido es numérico
 *
 * \param char[] dato a ser verificado
 * \return int devuelve 1 si el dato recibido es numerico, 0 sino lo es
 *
 */
int EsNumerico(char[]);
/** \brief Verifica si el dato recibido contiene solo letras
 *
 * \param char[] dato a ser verificado
 * \return int devuelve 1 si el dato recibido contiene solo letras, 0 sino lo es
 *
 */
int EsSoloLetras(char[]);
/** \brief Verifica si el dato recibido es alfanumérico
 *
 * \param char[] dato a ser verificado
 * \return int devuelve 1 si el dato recibido es alfanumerico, 0 sino lo es
 *
 */
int EsAlfanumerico(char[]);
/** \brief Verifica si el dato recibido es un telefono
 *
 * \param char[] dato a ser verificado
 * \return int devuelve 1 si el dato recibido contiene solo numeros y un guion, de lo contrario devolvera 0
 *
 */
int EsTelefono(char[]);
/** \brief Verifica si el dato recibido es flotante
 *
 * \param char[] dato a ser verificado
 * \return int devuelve 1 si es solo numerico y contiene un punto, 0 sino lo es
 *
 */
int EsFlotante(char[]);

/** \brief Muestra un menu de opciones
 *
 * \param char[] mensaje que pide una opcion
 * \param char[] la opcion ingresada
 * \param char[] mensaje de error
 * \return int devuelve la opcion validada
 *
 */
int Menu(char[],char[],char[]);


#endif /* GETS_H_ */
