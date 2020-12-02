#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "alquiler.h"
#include "utn.h"

int inicializarClientes(eCliente clientes[], int tamCliente)
{
	int retorno = 1;

	for(int i=0; i<tamCliente; i++)
		{
			clientes[i].isEmpty = 1;
			retorno = 0;
		}

	return retorno;
}

int imprimirClientes(eCliente clientes[], int tamCliente)
{
	int flag = 0;
	int retorno = 1;

	system("cls");

	printf("-------------- Listado de Clientes ---------------\n");
	printf("  Id     DNI       Nombre      Apellido    Estado\n\n");

	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].isEmpty == 0)
		{
			imprimirCliente(clientes[i], tamCliente);
			retorno = 0;
			flag = 1;
		}
	}
	if(flag==0)
	{
		printf("\n -- No hay clientes que mostrar --\n");
	}

	return retorno;
}

void imprimirCliente(eCliente cliente, int tamCliente)
{
    printf("%4d  %d  %10s%10s  %10s\n", cliente.id, cliente.dni, cliente.nombre, cliente.apellido, cliente.estado);
}

int altaCliente(int idC, eCliente clientes[], int tamCliente)
{
	int retorno = -1;
	int indice = buscarLibreCliente(clientes, tamCliente);
	eCliente auxCliente;

	system("cls");

	printf("-------- Alta Cliente --------\n\n");

	if(indice == -1)
	{
		printf("\n**Sistema completo, no hay lugar disponible**\n");
	}
	else
	{
        auxCliente.id = idC;

        utn_getEntero(&auxCliente.dni, 2, "Ingrese dni: ", "\nError", 1000000, 50000000);
        utn_getCadena(auxCliente.nombre, 19, 2, "Ingrese nombre: ", "\nError. ");
        utn_getCadena(auxCliente.apellido, 19, 2, "Ingrese apellido: ", "\nError.");

        strcpy(auxCliente.estado, "Habilitado");

        auxCliente.isEmpty = 0;

        clientes[indice] = auxCliente;
        retorno = indice;
	}

	return retorno;
}

int buscarLibreCliente(eCliente clientes[], int tamCliente)
{
	int indice = -1;

	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int bajaCliente(eCliente clientes[], int tamCliente)
{
    int retorno = 1;
	int id;
	int indice;
	char respuesta;

	system("cls");

	printf("-------- Baja Cliente --------\n\n");
	imprimirClientes(clientes, tamCliente);
	utn_getEntero(&id, 2, "Ingrese id del cliente: ", "\nError.", 1, 10);

	indice = buscarCliente(id, clientes, tamCliente);

	if(indice == -1 || strcmp(clientes[indice].estado, "Inhabilitado") == 0)
	{
		printf("\n-- No hay ningun cliente con este id o el cliente ya esta deshabilitado --\n");
	}
	else
	{
		printf("Inhabilitar cliente? (s/n): ");
		fflush(stdin);
		scanf("%c", &respuesta);

		if(respuesta == 's')
		{
			strcpy(clientes[indice].estado, "Inhabilitado");
			printf("Se ha realizado la baja con exito marcando el cliente como 'Inhabilitado'\n");
			retorno = 0;
		}
		else
		{
			printf("Se ha cancelado la operacion\n");
		}
	}
	return retorno;
}

int buscarCliente(int id, eCliente clientes[], int tamCliente)
{
	int indice =-1;
	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].id == id && clientes[i].isEmpty == 0)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int menuModificar()
{
	int opcion;
	printf("--- Modificaciones ---\n\n");
	printf("1.Nombre\n2.Apellido\n");

	utn_getEntero(&opcion, 2, "Ingrese opcion: ", "\nError.", 1, 2);

	return opcion;
}

int modificarCliente(eCliente clientes[], int tamCliente)
{
    int retorno = 1;
    int idC;
    system("cls");

    printf("-------- Modificar Cliente --------\n\n");

    imprimirClientes(clientes, tamCliente);
    utn_getEntero(&idC, 2, "Ingrese id del cliente a modificar: ", "\nError.", 1, 10);

	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].id == idC)
		{
			system("cls");
			switch(menuModificar())
			{
			case 1:
			    utn_getCadena(clientes[i].nombre, 19, 2, "Ingrese nuevo nombre: ", "\nError.");
				break;
			case 2:
			    utn_getCadena(clientes[i].apellido, 19, 2, "Ingrese nuevo apellido: ", "\nError.");
				break;
			}
			retorno = 0;
		}
	}
    return retorno;
}

int altaAlquiler(int idA, eCliente clientes[], int tamCliente, eAlquiler alquileres[], int tamAlquiler, eEquipo equipos[], int tamEquipo, eOperador operadores[], int tamOperador)
{
	int retorno = -1;
	int indice = buscarLibreAlquiler(alquileres, tamAlquiler);
	eAlquiler aux;

	system("cls");

	printf("--------Alta Alquiler-------\n\n");

	if(indice == -1)
	{
		printf("\n**Sistema completo, no hay lugar disponible**\n");
	}
	else
	{
        aux.idAlquiler = idA;

        imprimirClientes(clientes, tamCliente);

        utn_getEntero(&aux.idCliente, 2, "Ingrese id del cliente: ", "\nError.", 1, 10);

        if(buscarCliente(aux.idCliente, clientes, tamCliente) >= 0)
        {
            listarEquipos(equipos, tamEquipo);
            utn_getEntero(&aux.idEquipo, 2, "Ingrese id del equipo:", "\nError.", 1, 3);
            utn_getEntero(&aux.tiempoEstimado, 2, "Ingrese el tiempo estimado de uso (en horas): ", "\nError.", 1, 200);

            aux.tiempoReal = 0;

            listarOperadores(operadores, tamOperador);
            utn_getEntero(&aux.idOperador, 2, "Ingrese id del operador: ", "\nError.", 1 , 3);

            strcpy(aux.estado, "Alquilado");

            aux.isEmpty = 0;

            alquileres[indice] = aux;
            retorno = indice;
        }
        else
        {
            printf("\n**No hay un cliente con ese id**\n");
        }
	}
	return retorno;
}

int buscarLibreAlquiler(eAlquiler alquileres[], int tamAlquiler)
{
	int indice =-1;

	for(int i=0; i<tamAlquiler; i++)
	{
		if(alquileres[i].isEmpty)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

void listarEquipos(eEquipo equipos[], int tamEquipo)
{
		printf("\n-- EQUIPOS --\n");
		printf(" Id       Tipo\n");

		for(int i=0; i<tamEquipo; i++)
		{
			printf(" %d%                    10s \n", equipos[i].idEquipo, equipos[i].descripcion);
		}
}

void listarOperadores(eOperador operadores[], int tamOperador)
{
		printf("\n-- OPERADORES --\n");
		printf(" Id       Tipo\n");

		for(int i=0; i<tamOperador; i++)
		{
			printf("%d%10s %10s \n", operadores[i].id, operadores[i].nombre, operadores[i].apellido);
		}
}

int finalizarAlquiler(eCliente clientes[], int tamCliente, eAlquiler alquileres[], int tamAlquiler, eEquipo equipos[], int tamEquipo, eOperador operadores[], int tamOperador)
{
    int flag = 0;
    int retorno = 1;
    int idAlquiler;
    int indiceAlquiler;
    char respuesta;

    printf("-------- Finalizar alquiler --------\n\n");
    imprimirAlquileres(alquileres, tamAlquiler, equipos, tamEquipo);
    utn_getEntero(&idAlquiler, 2, "Ingrese id del alquiler a finalizar: ", "\nError.", 1, 30);

    for(int i=0; i<tamCliente; i++)
	{
		if(alquileres[i].idAlquiler== idAlquiler && (strcmp(alquileres[i].estado, "Alquilado") == 0))
		{
			flag = 1;
		}
	}

	if(!flag)
    {
        printf("\n**Este alquiler ya esta finalizado**\n");
    }
    else
    {

        indiceAlquiler = buscarAlquiler(idAlquiler, alquileres, tamAlquiler);

        printf("Confima cambio de estado a 'Finalizado'? (s/n)\n");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            utn_getEntero(&alquileres[indiceAlquiler].tiempoReal, 2, "Ingrese el tiempo real de alquilado: ", "\nError.", 1, 400);
            strcpy(alquileres[indiceAlquiler].estado, "Finalizado");
            printf("Se ha realizado el cambio con exito\n");
            retorno = 0;
        }
        else
        {
            printf("Se ha cancelado la operacion\n");
        }
    }
    return retorno;
}

int imprimirAlquileres(eAlquiler alquileres[], int tamAlquiler, eEquipo equipos[], int tamEquipo)
{
	int retorno = 1;

	system("cls");

	printf("-------------- Listado de Alquileres ---------------\n");
	printf("Id-Alquiler | Id-Cliente |  Equipo  | Tiempo Estimado  | Tiempo Real  |  Estado  \n\n");

	for(int i=0; i<tamAlquiler; i++)
	{
        if(alquileres[i].isEmpty == 0)
        {
            imprimirAlquiler(alquileres[i], tamAlquiler, equipos, tamEquipo);
        }
	}

	return retorno;
}

void imprimirAlquiler(eAlquiler alquiler, int tamAlquiler, eEquipo equipos[], int tamEquipo)
{
    char equipo[20];

    cargarDescripcionEquipo(equipo, alquiler.idEquipo, equipos, tamEquipo);

    printf("%d            %d           %s           %d          %d            %s\n", alquiler.idAlquiler, alquiler.idCliente, equipo, alquiler.tiempoEstimado, alquiler.tiempoReal, alquiler.estado);

}

int cargarDescripcionEquipo(char descripcion[], int idEquipo, eEquipo equipos[], int tamEquipo)
{
	int retorno =1;

	for(int i=0; i<tamEquipo; i++)
	{
		if(equipos[i].idEquipo == idEquipo)
		{
			strcpy(descripcion, equipos[i].descripcion);
			retorno =0;
		}
	}
	return retorno;
}

int inicializarAlquileres(eAlquiler alquileres[], int tamAlquiler)
{
	int retorno = 1;

	for(int i=0; i<tamAlquiler; i++)
		{
			alquileres[i].isEmpty = 1;
			retorno = 0;
		}

	return retorno;
}

int buscarAlquiler(int idAlquiler, eAlquiler alquileres[], int tamAlquiler)
{
	int indice =-1;
	for(int i=0; i<tamAlquiler; i++)
	{
		if(alquileres[i].idAlquiler == idAlquiler && alquileres[i].isEmpty == 0)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int menuInformes()
{
	int opcion;

	system("cls");

	printf("-------- INFORMES --------\n");
	printf("1) Nombre y apellido del cliente con mas alquileres.\n");
	printf("2) Equipo mas alquilado.\n");
	printf("3) Promedio tiempo real de alquiler de equipos.\n");
	printf("4) Listar todos los clientes con sus alquileres.\n");
	printf("5) Salir.\n");

	utn_getEntero(&opcion, 2, "\nIngrese una opcion : ", "\nError.\n", 1, 5);

	return opcion;
}

void informarEquipoMasAlquilado(eAlquiler alquileres[], int tamAlquiler, eEquipo equipos[], int tamEquipo)
{
    int auxMax=-1;
    int flagEquipos[3]={0,0,0};

    for(int i=0;i<tamAlquiler;i++)
    {
        if(alquileres[i].isEmpty == 0)
        {
            if(alquileres[i].idEquipo==1)
            {
                flagEquipos[0]++;
            }
            if(alquileres[i].idEquipo==2)
            {
                flagEquipos[1]++;
            }
            if(alquileres[i].idEquipo==3)
            {
                flagEquipos[2]++;
            }
        }
    }

    for(int i=0;i<tamEquipo;i++)
    {
        if(flagEquipos[i]>auxMax)
        {
            auxMax=flagEquipos[i];
        }
    }
    printf("\nEl/los equipos con mas alquileres: ");
    printf("\n\n  Id              Equipo    Cantidad\n");
    for(int i=0;i<3;i++)
    {
        if(flagEquipos[i]==auxMax)
        {
            printf("%4d%20s     %d\n",equipos[i].idEquipo,equipos[i].descripcion, auxMax);
        }
    }
    printf("\n");
}

void informarTiempoEquipos(eEquipo equipos[], int tamEquipo, eAlquiler alquileres[], int tamAlquiler)
{
	int idEquipo;
	int suma = 0;
	int alquileresCant = 0;
	int total = 0;
	int flag = 0;
	char equipo[20];

	system("cls");

	printf("-- Tiempo de alquiler de equipos --\n");

	listarEquipos(equipos, tamEquipo);
	utn_getEntero(&idEquipo, 2, "\nIngrese id del equipo: ", "\nError.\n", 1, 3);

	for(int s=0; s<tamAlquiler; s++)
	{
		if(alquileres[s].isEmpty == 0 && alquileres[s].idEquipo == idEquipo && strcmp(alquileres[s].estado, "Finalizado")==0)
		{
            suma += alquileres[s].tiempoReal;
            alquileresCant++;
            flag = 1;
		}
	}

	if(!flag)
    {
        printf("**No hay alquileres finalizados para promediar sus tiempos reales de alquilado\n**");
    }
    else
    {
        total = suma/alquileresCant;
        cargarDescripcionEquipo(equipo, idEquipo, equipos, tamEquipo);
        printf("\nEl promedio de tiempo real alquilado del equipo '%s' es:  %.2d.\n\n", equipo, total);
    }
}

int imprimirClientesAlquileres(eCliente clientes[], int tamCliente, eAlquiler alquileres[], int tamAlquiler, eEquipo equipos[], int tamEquipo)
{
	int flag = 0;
	int retorno = 1;

	system("cls");

	printf("--------- Listado de Clientes con sus Alquileres ----------\n");

	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].isEmpty == 0)
		{
		    printf("\n----------------- CLIENTE -----------------\n");
            printf("  Id     DNI       Nombre      Apellido    Estado  \n\n");

			imprimirCliente(clientes[i], tamCliente);
			retorno = 0;

			printf("----------------- ALQUILERES -----------------\n");
			printf("Id-Alquiler | Equipo  | Tiempo Estimado  | Tiempo Real  |  Estado  \n\n");

			for(int a=0; a<tamAlquiler; a++)
            {
                if(alquileres[a].idCliente == clientes[i].id)
                {
                    imprimirAlquiler(alquileres[a], tamAlquiler, equipos, tamEquipo);
                    printf("\n----------------------------------------------------\n");
                    flag = 1;
                }
            }

		}
	}
	if(flag==0)
	{
		printf("\n**No hay alquileres que mostrar**\n");
	}

	return retorno;
}

void informarClienteMasAlquilados(eCliente clientes[], int tamCliente, eAlquiler alquileres[], int tamAlquiler)
{
    int auxMax=-1;
    int flagClientes[5]={0,0,0,0,0};

    for(int i=0;i<tamAlquiler;i++)
    {
        if(alquileres[i].isEmpty == 0)
        {
            if(alquileres[i].idCliente==1)
            {
                flagClientes[0]++;
            }
            if(alquileres[i].idCliente==2)
            {
                flagClientes[1]++;
            }
            if(alquileres[i].idCliente==3)
            {
                flagClientes[2]++;
            }
            if(alquileres[i].idCliente==4)
            {
                flagClientes[3]++;
            }
            if(alquileres[i].idCliente==5)
            {
                flagClientes[4]++;
            }
        }
    }

    for(int i=0;i<5;i++)
    {
        if(flagClientes[i]>auxMax)
        {
            auxMax=flagClientes[i];
        }
    }
    printf("\nEl/los clientes con mas alquileres: ");
    printf("\n\n  Id        Nombre     Cantidad\n");
    for(int i=0;i<5;i++)
    {
        if(flagClientes[i]==auxMax)
        {
            printf("%4d%20s     %d\n", clientes[i].id, clientes[i].nombre, auxMax);
        }
    }
    printf("\n");
}
