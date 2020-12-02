#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct
{
	int id;
	int dni;
	char nombre[20];
	char apellido[20];
	char estado[20];
	int isEmpty;

}eCliente;



typedef struct
{
	int id;
	char nombre[20];
	char apellido[20];

}eOperador;

typedef struct
{
    int idAlquiler;
	int idCliente;
	int idEquipo;
	int tiempoEstimado;
	int tiempoReal;
	int idOperador;
	char estado[20];
	int isEmpty;

}eAlquiler;

typedef struct
{
	int idEquipo;
	char descripcion[20];
}eEquipo;


/** \brief Indica que todas las posiciones en el array estan vacias,
* pone la bandera (isEmpty) en TRUE(1) en todas las posiciones del array.
* \param eCliente clientes[]
* \param int tamCliente
* \return int
*/
int inicializarClientes(eCliente clientes[], int tamCliente);

/** \brief Imprime el array de forma encolumnada.
* \param eCliente clientes[]
* \param int tamCliente
* \return no devuelve nada
*/
int imprimirClientes(eCliente clientes[], int tamCliente);

/** \brief Imprime una posicion del array
* \param eCliente cliente
* \param int tamCliente
* \return no devuelve nada
*/
void imprimirCliente(eCliente cliente, int tamCliente);

/** \brief Agrega un cliente
* \param int idC
* \param eCliente clientes[]
* \param int tamCliente
* \return 1 en caso de error, 0 en caso de exito
*/
int altaCliente(int idC, eCliente clientes[], int tamCliente);

/** \brief Busca una posicion libre
* \param eCliente clientes[]
* \param int tamCliente
* \return devuelve el indice libre o -1 si hay error
*/
int buscarLibreCliente(eCliente clientes[], int tamCliente);

/** \brief Inhabilita un cliente
* \param eCliente clientes[]
* \param nt tamCliente
* \return no devuelve nada
*/
int bajaCliente(eCliente clientes[], int tamCliente);

/** \brief Busca un cliente recibiendo como parámetro de búsqueda su Id.
* \param int id
* \param eCliente clientes[]
* \param int tamCliente
* \return devuelve el indice del cliente o -1 si hay error
*/
int buscarCliente(int id, eCliente clientes[], int tamCliente);

/** \brief Imprime el menu de modificaciones
 * \return int opcion
 */
int menuModificar();

/** \brief Modifica nombre o apellido de un cliente
* \param eCliente clientes[]
* \param int tamCliente
* \return int
*/
int modificarCliente(eCliente clientes[], int tamCliente);

/** \brief Busca una posicion libre
* \param eAlquiler alquileres[]
* \param int tamAlquiler
* \return devuelve el indice libre o -1 si hay error
*/
int buscarLibreAlquiler(eAlquiler alquileres[], int tamAlquiler);

/** \brief Agrega un alquiler
* \param int idA
* \param eCliente clientes[]
* \param int tamCliente
* \param eAlquiler alquileres[]
* \param int tamAlquiler
* \param eEquipo equipos[]
* \param int tamEquipo
* \param eOperador operadores[]
* \param int tamOperador
* \return 1 en caso de error, 0 en caso de exito
*/
int altaAlquiler(int idA, eCliente clientes[], int tamCliente, eAlquiler alquileres[], int tamAlquiler, eEquipo equipos[], int tamEquipo, eOperador operadores[], int tamOperador);

/** \brief Imprime el array de equipos de forma encolumnada.
* \param eEquipo equipos[]
* \param int tamEquipo
* \return no devuelve nada
*/
void listarEquipos(eEquipo equipos[], int tamEquipo);

/** \brief Imprime el array de operadores de forma encolumnada.
* \param eOperador operadores[]
* \param int tamOperador
* \return no devuelve nada
*/
void listarOperadores(eOperador operadores[], int tamOperador);

/** \brief Imprime el array de forma encolumnada.
* \param eAlquiler alquileres[]
* \param int tamEquipo int tamAlquiler
* \param eEquipo equipos[]
* \param int tamEquipo
* \return no devuelve nada
*/
int imprimirAlquileres(eAlquiler alquileres[], int tamAlquiler, eEquipo equipos[], int tamEquipo);

/** \brief Indica que todas las posiciones en el array estan vacias,
* pone la bandera (isEmpty) en TRUE(1) en todas las posiciones del array.
* \param eAlquiler alquileres[]
* \param int tamAlquiler
* \return int
*/
int inicializarAlquileres(eAlquiler alquileres[], int tamAlquiler);

/** \brief Imprime una posicion del array
* \param eAlquiler alquiler
* \param int tamAlquiler
* \param eEquipo equipos[]
* \param int tamEquipo
* \return no devuelve nada
*/
void imprimirAlquiler(eAlquiler alquiler, int tamAlquiler, eEquipo equipos[], int tamEquipo);

/** \brief Carga la descripcion del tipo de equipo
* \param char descripcion[]
* \param int idEquipo
* \param eEquipo equipos[]
* \param int tamEquipo
* \return 1 en caso de error, 0 en caso de exito
*/
int cargarDescripcionEquipo(char descripcion[], int idEquipo, eEquipo equipos[], int tamEquipo);

/** \brief Busca un alquiler recibiendo como parámetro de búsqueda su Id.
* \param int id
* \param eAlquiler alquileres[]
* \param int tamAlquiler
* \return devuelve el indice de la mascota o -1 si hay error
*/
int buscarAlquiler(int idAlquiler, eAlquiler alquileres[], int tamAlquiler);

/** \brief Finaliza un alquiler
* \param eCliente clientes[]
* \param int tamCliente
* \param eAlquiler alquileres[]
* \param int tamAlquiler
* \param eEquipo equipos[]
* \param int tamEquipo
* \param eOperador operadores[]
* \param int tamOperador
* \return int
*/
int finalizarAlquiler(eCliente clientes[], int tamCliente, eAlquiler alquileres[], int tamAlquiler, eEquipo equipos[], int tamEquipo, eOperador operadores[], int tamOperador);

/** \brief Imprime el menu de informes
 * \return int opcion
 */
int menuInformes();

/** \brief Informa el equipo mas alquilado
 * \param eAlquiler alquileres[]
 * \param int tamAlquiler
 * \param eEquipo equipos[]
 * \param int tamEquipo
 * \return void
 */
void informarEquipoMasAlquilado(eAlquiler alquileres[], int tamAlquiler, eEquipo equipos[], int tamEquipo);

/** \brief Informa el promedio de tiempo real del equipo elegido
 * \param eEquipo equipos[]
 * \param int tamEquipo
 * \param eAlquiler alquileres[]
 * \param int tamAlquiler
 * \return void
 */
void informarTiempoEquipos(eEquipo equipos[], int tamEquipo, eAlquiler alquileres[], int tamAlquiler);

/** \brief Imprime todos los clientes con todos sus alquieres
 * \param eCliente clientes[]
 * \param int tamCliente
 * \param eAlquiler alquileres[]
 * \param int tamAlquiler
 * \param eEquipo equipos[]
 * \param int tamEquipo
 * \return int
 */
int imprimirClientesAlquileres(eCliente clientes[], int tamCliente, eAlquiler alquileres[], int tamAlquiler, eEquipo equipos[], int tamEquipo);

/** \brief Informa el cliente con mas equipos alquilados
 * \param eCliente clientes[]
 * \param int tamCliente
 * \param eAlquiler alquileres[]
 * \param int tamAlquiler
 * \return void
 */
void informarClienteMasAlquilados(eCliente clientes[], int tamCliente, eAlquiler alquileres[], int tamAlquiler);

#endif // ALQUILER_H_INCLUDED
