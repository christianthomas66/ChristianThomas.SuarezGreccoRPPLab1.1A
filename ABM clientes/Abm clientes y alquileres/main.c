#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"
#include "utn.h"

#define TAM_CLIENTE 5
#define TAM_ALQUILER 30
#define TAM_EQUIPO 3
#define TAM_OPERADOR 3

int menu();

int main()
{
    int seguir = 0;
    int seguir2 = 0;
	int idClientes = 1;
	int idAlquileres = 1;
	int flag = 0;
	int flag2 = 0;
	char aux;

	eCliente clientes[TAM_CLIENTE];
	eAlquiler alquileres[TAM_ALQUILER];

	eEquipo equipos[TAM_EQUIPO] = {{1, "Amoladora"}, {2, "Mezcladora"}, {3, "Taladro"}};
    eOperador operadores[TAM_OPERADOR] = {{1, "Raul", "Gonzalez"}, {2, "Ramon", "Diaz"}, {3, "Maria", "Lopez"}};

	inicializarClientes(clientes, TAM_CLIENTE);
	inicializarAlquileres(alquileres, TAM_ALQUILER);

    do
	{
		switch(menu())
		{
		case 1:
            if(!(altaCliente(idClientes, clientes, TAM_CLIENTE)))
			{
				idClientes++;
				flag = 1;
			}
			break;

		case 2:
            if(flag)
            {
                modificarCliente(clientes, TAM_CLIENTE);
            }
            else
            {
                printf("\n-- Debe dar de alta un cliente primero --\n");
            }
			break;

		case 3:
            if(flag)
            {
                bajaCliente(clientes, TAM_CLIENTE);
            }
            else
            {
                printf("\n-- Debe dar de alta un cliente primero --\n");
            }
			break;

		case 4:
            if(flag)
            {
                if(!altaAlquiler(idAlquileres, clientes, TAM_CLIENTE, alquileres, TAM_ALQUILER, equipos, TAM_EQUIPO, operadores, TAM_OPERADOR))
                {
                    idAlquileres++;
                    flag2 = 1;
                }
            }
            else
            {
                printf("\n-- Debe dar de alta un cliente primero --\n");
            }
			break;

		case 5:
            if(flag2)
            {
                finalizarAlquiler(clientes, TAM_CLIENTE, alquileres, TAM_ALQUILER, equipos, TAM_EQUIPO, operadores, TAM_OPERADOR);
            }
            else
            {
                printf("\n-- Debe dar de alta un alquiler primero --\n");
            }
			break;

		case 6:
		    if(flag2)
            {
                do
                {
                    switch(menuInformes())
                    {
                        case 1:
                            informarClienteMasAlquilados(clientes, TAM_CLIENTE, alquileres, TAM_ALQUILER);
                            break;
                        case 2:
                            informarEquipoMasAlquilado(alquileres, TAM_ALQUILER, equipos, TAM_EQUIPO);
                            break;
                        case 3:
                            informarTiempoEquipos(equipos, TAM_EQUIPO, alquileres, TAM_ALQUILER);
                            break;
                        case 4:
                            imprimirClientesAlquileres(clientes, TAM_CLIENTE, alquileres, TAM_ALQUILER, equipos, TAM_EQUIPO);
                            break;
                        case 5:
                            seguir2 = 1;
                            break;
                    }
                    system("pause");
                }while(seguir2 == 0);
            }
            else
            {
                printf("\n-- Debe dar de alta un alquiler primero --\n");
            }
			break;

		case 7:
            printf("Desea salir???\n");
                fflush(stdin);
                scanf("%c", &aux);
                while(aux != 's' && aux != 'n')
                    {
                        printf("Opcion incorrecta. Reingrese 's'(si) o 'n'(no)");
                        printf(" s/n : \n");
                        fflush(stdin);
                        scanf("%c", &aux);
                    }

                if(aux == 's')
                    {
                        printf("Gracias. Vuelva pronto!!!\n");
                        return 0;
                    }
                break;
			}
			system("pause");
		}while(seguir == 0);

    return 0;
}

int menu()
{
	system("cls");
	int opcion;

	printf("-------- MENU --------\n");
	printf("1) Alta cliente\n");
	printf("2) Modificar cliente\n");
	printf("3) Baja cliente\n");
	printf("4) Nuevo alquiler\n");
	printf("5) Fin del alquiler\n");
	printf("6) Informar\n");
	printf("7) Salir\n");

	utn_getEntero(&opcion, 2, "\nIngrese una opcion : ", "\nError.\n", 1, 7);

	return opcion;
}

