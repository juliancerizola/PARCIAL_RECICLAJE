//////////////////////////////////////////////////////////////
#include "informes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////



void msj(int idMensaje)
{
    if(idMensaje<0) //Si el idMensaje es negativo entonces se trata de un error
    {
        printf("\a");   // Por eso hacemos un ruidito
    }
    switch(idMensaje) // Negativos para errores
    {
        case 1:
            printf(" Hecho!\n");
            break;
        case -1: // Sin entes 1 dados de alta
            printf("\n ERROR - No hay ningun cliente dado de alta (opcion 1)\n");
            break;
        case -2: // Sin entes 2 dados de alta
            printf("\n ERROR - No hay ningun pedido dado de alta o procesado (opciones 4 y 5)\n");
            break;
        case -3: // Accion no valida
            printf("\n ERROR - Opcion invalida (entre 1 y 21)\n");
            break;
        case -5: // No existe id
            printf("\n ERROR - No existe este ID\n");
            break;
        case -999: // Error desconocido o generico
            printf("\n ERROR - Algo salio mal!\n");
            break;
        default:   // Si se ingresa un idMensaje inexistente se da un salto de linea
            printf("\n");
    }
    printf("=========================================================\n\n");
}




//////////////////////////////////////////////////////////////
int clienteMasPedidosxEstado(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido, int estado)
{
	int i;

	int axContPedidos=0;

	int CteMasPedidosId;
	int contMaxPedidos=0;
	int flag=0;

	if(arrayPedido!=NULL && lengthPedido>0 && arrayCliente!=NULL && lengthCliente>0)
	{
		for(i=0;i<lengthCliente;i++)
		{
			if(arrayCliente[i].isEmpty==0)
			{
				axContPedidos=0;
				cantidadPedidosEstadoxIdCliente(estado,arrayCliente[i].id,arrayPedido,lengthPedido,&axContPedidos);

				if(flag==0)
				{
					CteMasPedidosId = arrayCliente[i].id;
					contMaxPedidos = axContPedidos;
					flag=1;
				}
				else if(axContPedidos>contMaxPedidos)
				{
					CteMasPedidosId = arrayCliente[i].id;
					contMaxPedidos = axContPedidos;
				}
			}
		}
	}

	if(estado==0)
	{
        printf("\n El cliente con mas pedidos pendientes es:");
	}
	else if(estado==1)
	{
        printf("\n El cliente con mas pedidos completados es:");
	}

	imprimirCliente(arrayCliente,lengthCliente,CteMasPedidosId-1);
	return 0;
}

int cantidadPedidosEstadoxIdCliente(int estado, int idCliente, ePedido array[], int length, int *contador)
{
	int i;
	int auxContador=0;

	if(array!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(array[i].idCliente == idCliente && array[i].estado == estado)
			{
				auxContador++;
			}
		}
	}
    *contador=auxContador;
    return 0;
}
//////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////
int clienteMasPedidos(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido)
{
	int i;

	int axContPedidos=0;

	int CteMasPedidosId;
	int contMaxPedidos=0;
	int flag=0;

	if(arrayPedido!=NULL && lengthPedido>0 && arrayCliente!=NULL && lengthCliente>0)
	{
		for(i=0;i<lengthCliente;i++)
		{
			if(arrayCliente[i].isEmpty==0)
			{
				axContPedidos=0;

				cantidadPedidosxIdCliente(arrayCliente[i].id,arrayPedido,lengthPedido,&axContPedidos);


				if(flag==0)
				{
					CteMasPedidosId = arrayCliente[i].id;
					contMaxPedidos = axContPedidos;
					flag=1;
				}
				else if(axContPedidos>contMaxPedidos)
				{
					CteMasPedidosId = arrayCliente[i].id;
					contMaxPedidos = axContPedidos;
				}

			}
		}
	}
    printf("\n El cliente con mas pedidos es:");
	imprimirCliente(arrayCliente,lengthCliente,CteMasPedidosId-1);

	return 0;
}

int cantidadPedidosxIdCliente(int idCliente, ePedido array[], int length, int *contador)
{
	int i;
	int auxContador=0;

	if(array!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(array[i].idCliente == idCliente)
			{
				auxContador++;
			}
		}

	}

*contador=auxContador;


return 0;

}
//////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////
int clienteMasKgReciclados(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido)
{
	int i;

	float axacumKgReciclados=0;

	int CteMasPedidosId;
	float acumKgReciclados=0;
	int flag=0;

	if(arrayPedido!=NULL && lengthPedido>0 && arrayCliente!=NULL && lengthCliente>0)
	{
		for(i=0;i<lengthCliente;i++)
		{
			if(arrayCliente[i].isEmpty==0)
			{
				axacumKgReciclados=0;
				cantidadKgRecicladosxIdCliente(arrayCliente[i].id,arrayPedido,lengthPedido,&axacumKgReciclados);
				if(flag==0)
				{
					CteMasPedidosId = arrayCliente[i].id;
					acumKgReciclados = axacumKgReciclados;
					flag=1;
				}
				else if(axacumKgReciclados>acumKgReciclados)
				{
					CteMasPedidosId = arrayCliente[i].id;
					acumKgReciclados = axacumKgReciclados;
				}
			}
		}
	}
    printf("\n El cliente que reciclo mas kilos es:");
	imprimirCliente(arrayCliente,lengthCliente,CteMasPedidosId-1);
	return 0;
}


int clienteMenosKgReciclados(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido)
{
	int i;

	float axacumKgReciclados=0;

	int CteMasPedidosId;
	float acumKgReciclados=0;
	int flag=0;

	if(arrayPedido!=NULL && lengthPedido>0 && arrayCliente!=NULL && lengthCliente>0)
	{
		for(i=0;i<lengthCliente;i++)
		{
			if(arrayCliente[i].isEmpty==0)
			{
				axacumKgReciclados=0;

				cantidadKgRecicladosxIdCliente(arrayCliente[i].id,arrayPedido,lengthPedido,&axacumKgReciclados);


				if(flag==0)
				{
					CteMasPedidosId = arrayCliente[i].id;
					acumKgReciclados = axacumKgReciclados;
					flag=1;
				}
				else if(axacumKgReciclados<acumKgReciclados && axacumKgReciclados>0)
				{
					CteMasPedidosId = arrayCliente[i].id;
					acumKgReciclados = axacumKgReciclados;
				}

			}
		}
	}
    printf("\n El cliente que reciclo menos kilos es:");

	imprimirCliente(arrayCliente,lengthCliente,CteMasPedidosId-1);

	return 0;
}


int cantidadKgRecicladosxIdCliente(int idCliente, ePedido array[], int length, float *acumulador)
{
	int i;
	float auxAcumulador=0;

	if(array!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(array[i].idCliente == idCliente && array[i].estado==1 && array[i].isEmpty==0)
			{
				auxAcumulador = array[i].kilosHDPE + array[i].kilosLDPE + array[i].kilosPP;
			}
		}

	}

    *acumulador=auxAcumulador;
    return 0;
}
//////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////
int porcentajePlasticoReciclado(ePedido array[], int length, int id)
{
    int kilosReciclados;
    int porcentajeKilosReciclados;

    kilosReciclados = array[id].kilosHDPE + array[id].kilosLDPE + array[id].kilosPP;
    porcentajeKilosReciclados=(kilosReciclados*100)/array[id].kilos;

    return porcentajeKilosReciclados;
}
//////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////
int clientesMas1000kg(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente,int lengthPedido)
{
	int i;

	float auxAcumuladorKgReciclados=0;
	int contCtesMayor1k=0;


	if(arrayPedido!=NULL && lengthPedido>0 && arrayCliente!=NULL && lengthCliente>0)
	{
		for(i=0;i<lengthCliente;i++)
		{
			if(arrayCliente[i].isEmpty==0)
			{
				auxAcumuladorKgReciclados=0;
				cantidadKgRecicladosxIdCliente(arrayCliente[i].id,arrayPedido,lengthPedido,&auxAcumuladorKgReciclados);
				if(auxAcumuladorKgReciclados>1000)
				{
					contCtesMayor1k++;
				}
			}
		}
	}
		printf("\n La cantidad de clientes que reciclaron mas de 1000kg es : %d\n",contCtesMayor1k);


	return 0;
}

int clientesMenos100kg(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente,int lengthPedido)
{
	int i;

	float auxAcumuladorKgReciclados=0;
	int contCtesMenos100=0;


	if(arrayPedido!=NULL && lengthPedido>0 && arrayCliente!=NULL && lengthCliente>0)
	{
		for(i=0;i<lengthCliente;i++)
		{
			if(arrayCliente[i].isEmpty==0)
			{
				auxAcumuladorKgReciclados=0;

				cantidadKgRecicladosxIdCliente(arrayCliente[i].id,arrayPedido,lengthPedido,&auxAcumuladorKgReciclados);

				if(auxAcumuladorKgReciclados<100 && auxAcumuladorKgReciclados>0)
				{
					contCtesMenos100++;
				}
			}
		}
	}
		printf("\n La cantidad de clientes que reciclaron menos de 100kg es : %d\n",contCtesMenos100);


	return 0;
}
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
int obtenerPedidoxLocalidad(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido)
{
    char bufferLocalidad[TEXT_SIZE];

    int i;
    int auxContPedidos=0;
    int contPedidos=0;
    int len;

    char localidadBuscada[TEXT_SIZE];
    utn_getTexto("\n Ingrese localidad: "," ERROR",1,TEXT_SIZE,2,localidadBuscada);

    len = strlen(localidadBuscada);
    strncpy(bufferLocalidad,localidadBuscada,strlen(localidadBuscada));
    len = (strlen(localidadBuscada)-1);

    if(arrayPedido!=NULL && arrayPedido>0 && arrayCliente!=NULL && lengthCliente>0)
        {
            for(i=0;i<lengthCliente;i++)
            {
                if(arrayCliente[i].isEmpty==0)
                {
                    if(strncmp(bufferLocalidad, arrayCliente[i].localidad,len)==0)
                    {
                        cantidadPedidosEstadoxIdCliente(0,arrayCliente[i].id,arrayPedido, arrayPedido, &auxContPedidos);
                        contPedidos = contPedidos+auxContPedidos;
                    }
                }
            }

        }
    printf("\n La localidad %s cuenta con %d pedidos\n",bufferLocalidad, contPedidos);

    return 0;
}

int cantidadPPpromedioxCliente(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido)
{
    int contCtes;
    int j;
    float acumPP=0;
    float promPPTotal=0;

    if(arrayPedido!=NULL && lengthPedido>0 && arrayCliente!=NULL && lengthCliente>0)
    {
        contarClientesPedidoCompletado(arrayPedido,arrayCliente,lengthCliente,lengthPedido,&contCtes);
        for(j=0;j<lengthPedido;j++)
        {
            if(arrayPedido[j].isEmpty==0 && arrayPedido[j].estado==1)
            {
                acumPP = acumPP + arrayPedido[j].kilosPP;
            }
        }
        if(acumPP!=0 && contCtes!=0)
        {
            promPPTotal = (acumPP/contCtes);
        }
    }
    printf("\n El promedio de polipropileno reciclado por cliente es de: %.2f\n", promPPTotal);
	return 0;
}

int contarClientesPedidoCompletado(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido, int *cantidadPedidosProcesados)
{
	int i,j;
	int contadorPedidosProcesados=0;

	if(arrayPedido!=NULL && lengthPedido>0 && arrayCliente!=NULL && lengthCliente>0)
	{
		for(i=0;i<lengthCliente;i++)
		{
			if(arrayCliente[i].isEmpty==0)
			{
				for(j=0;j<lengthPedido;j++)
				{
					if(arrayPedido[i].isEmpty==0)
					{
						if(arrayPedido[i].estado==1)
						{
							contadorPedidosProcesados++;
							break;
						}
					}
				}
			}
		}
		*cantidadPedidosProcesados=contadorPedidosProcesados;
	}


	return 0;
}
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
int cantidadPlasticoRecicladoxCuit(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido)
{
	int i,j;
	char cuit[15];
	int opcion;
	int len;
	float acumPlastico=0;

		utn_getTexto(" Ingrese cuit: "," ERROR - Cuit invalido\n",1,15,1,cuit);

		printf("\n Ingrese un tipo de plastico");
		printf("\n 1) Polietileno de baja densidad (LDPE)");
		printf("\n 2) Polietileno de alta densidad (HDPE)");
		printf("\n 3) Polipropileno (PP)");

        utn_getUnsignedInt("-Ingrese el numero de la accion que desea realizar: "," ERROR - Opcion invalida (entre 1 y 3)\n",0,3,1,100,1,&opcion);


	len = (strlen(cuit)-1);

	if(arrayPedido!=NULL && lengthPedido>0 && arrayCliente!=NULL && lengthCliente>0)
		{

			for(i=0;i<lengthCliente;i++)
			{
				if(arrayCliente[i].isEmpty==0)
				{
					if(strncmp(cuit, arrayCliente[i].cuit,len)==0)
					{
						for(j=0;j<lengthPedido;j++)
						{
							if(arrayPedido[j].isEmpty==0 && arrayPedido[j].estado==1 && arrayPedido[j].idCliente == arrayCliente[i].id)
							{
								switch(opcion)
								{
								case 1:
									acumPlastico += arrayPedido[j].kilosLDPE;

									break;
								case 2:
									acumPlastico += arrayPedido[j].kilosHDPE;
									break;
								case 3:
									acumPlastico += arrayPedido[j].kilosPP;
									break;
								default:
									break;
								}

							}
						}
					}
				}
			}
			switch(opcion)
			{
			case 1:
				printf(" El cliente %s ingreso %.2f de polietileno de baja densidad (LDPE)\n",cuit, acumPlastico);
				break;
			case 2:
				printf(" El cliente %s ingreso %.2f de polietileno de alta densidad (HDPE)\n",cuit, acumPlastico);
				break;
			case 3:
				printf(" El cliente %s ingreso %.2f de polipropileno (PP)\n",cuit, acumPlastico);
				break;
			default:
				break;
			}
		}

	return 0;
}
//////////////////////////////////////////////////////////////
