#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/** \brief Valida que una cadena ingresada contenga solo caracteres no numericos
* \param char *pAux : puntero donde se guarda la cadena
* \param int limit : el limite de caracteres que puede contener la cadena
* \param int retry : la cantidad de reintentos que se le da al usuario
* \param char* msg : el mensaje que se le muestra al usuario
* \param char* msgError : el mensaje que se le muestra al usuario en caso de error
* \return -1 en caso de error (puntero vacio, limite o reintentos negativos, o caracteres numericos en la cadena) retorna 0 en caso de exito
*/
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);

/** \brief Captura una cadena del usuario que no supere el limite ingresado
* \param char* pAux : el puntero donde se guardara la cadena
* \param int limit : el limite que la cadena no puede superar
* \return -1 en caso de error(punteros vacios o cadena mas larga que el limite) retorna 0 en caso de exito
*/
int getCadena(char* pAux, int limit);

/**   \brief Valida que una cadena ingresada no contenga caracteres numericos
*   \param char str[]: cadena a validar
*   \return -1 en caso de ser una cadena con caracteres numericos, retorna 0 en caso de exito
*/
int isChar(char str[]);

/**  \brief Valida que lo ingresado por el usuario sea un numero entero o flotante
*  \param float* pFloat; puntero donde se guarda el numero
*  \param int retry: la cantidad de veces que el usuario puede intentar ingresar datos
*  \param char* msg: el mensaje que se le mostrara al usuario
*  \param char*msgError : el mensaje que se le mostrara al usuario en caso de error (punteros vacios,supero la cantidad de intentos, o caracteres no numericos)
*  \param float min: el limite inferior del numero a ingresar
*  \param float max: el limite superior del numero a ingresar
*  \return -1 en caso de error(puntero vacio,intentos agotados, caracter no numerico) retorna 0 en caso de exito
*/
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

/**  \brief Tranforma una cadena de caracteres a numero flotante
*  \param float*pAux: el puntero a la cadena donde se va a guardar el numero flotante
*  \return -1 en caso de error(cadena demasiado grande, caracteres no numericos en la cadena) o 0 en caso de exito
*/
int getFloat(float*pAux);

/**   \brief Valida que una cadena ingresada sea un numero entero o flotante
*   \param char* pAux: puntero de la cadena a validar
*   \return -1 en caso de ser una cadena con caracteres no numericos o con mas de un punto ('.'), retorna 0 en caso de exito
*/
int isFloat(char* pAux);

/** \brief Valida que lo ingresado por el usuario sea un numero entero
* \param int* pEntero: el puntero donde se guardara el numero en caso de exito
* \param int retry: la cantidad de veces que el usuario puede intentar ingresar el dato
* \param char* msg: el mensaje que se le mostrara al usuario
* \param char*msgError: el mensaje que se le mostrara al usuario en caso de error
* \param int min: el limite inferior del numero a ingresar
* \param int max: el limite superior del numero a ingresar
* \return -1 en caso de error(puntero vacio,intentos agotados, caracter no numerico) retorna 0 en caso de exito
*/
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

/**  \brief Captura un numero ingresado por el usuario
*  \param int* pAux: el puntero donde se  guardara el numero
*  \return -1 en caso de error (lo ingresado no es un numero) o en caso de exito, retorna 0
*/
int getInt(int* pAux);

/** \brief Valida que la cadema que recibe la funcion no contenga caracteres no numericos dentro
* \param char *pAux: la cadena a validar
* \return -1 en caso de error (caracteres no numericos dentro de la cadena)
*/
int isInt(char *pAux);

/** \brief Pone una cadena en minuscula
* \param char* str: la cadena a validar
* \return -1 en caso de error, 0 en caso de exito
*/
int strLwr(char* str);

/** \brief Pone mauyuscula en la primera letra de la/s palabra/s y minuscula en el resto
* \param char* str: la cadena a validar
* \return -1 en caso de error, 0 en caso de exito
*/
int normalizeStr(char* str);

#endif // UTN_H_INCLUDED


