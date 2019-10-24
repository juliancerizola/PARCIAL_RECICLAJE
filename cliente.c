//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "cliente.h"
#include "pedido.h"
//////////////////////////////////////////////////////////////


/** Inicializa las variables isEmpty,id y cuit*/
int inicializarCliente(eCliente array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        for(;tamanio>0;tamanio--)
        {
            array[tamanio-1].isEmpty=1;
            array[tamanio-1].id=tamanio;
            strncpy(array[tamanio-1].cuit,"",13);
        }
        retorno=0;
    }

    return retorno;
}

/** Hardcodeo de clientes*/
int hardcodeClientes(eCliente array[])
{

		array[0].id = 1;
		strncpy(array[0].nombreEmpresa, "Telefonica", 51);
		strncpy(array[0].direccion, "Lima 1234", 51);
		strncpy(array[0].localidad, "CABA", 51);
		strncpy(array[0].cuit, "30-11223344-5", 13);
		array[0].isEmpty = 0;

		array[1].id = 2;
		strncpy(array[1].nombreEmpresa, "DATASOFT", 51);
		strncpy(array[1].direccion, "Corrientes 2547", 51);
		strncpy(array[1].localidad, "CABA", 51); //origen CABA
		strncpy(array[1].cuit, "30-44556677-6", 13);
		array[1].isEmpty = 0;

		array[2].id = 3;
		strncpy(array[2].nombreEmpresa, "NESTLE", 51);
		strncpy(array[2].cuit, "30-88995521-9", 13);
		strncpy(array[2].localidad, "LANUS", 51);
		strncpy(array[2].direccion, "cucha cucha 555", 51);
		array[2].isEmpty = 0;


		array[3].id = 4;
		strncpy(array[3].nombreEmpresa, "TERRABUSI", 51);
		strncpy(array[3].cuit, "30-56781423-5", 13);
		strncpy(array[3].localidad, "QUILMES", 51);
		strncpy(array[3].direccion, "rocha 784", 51);
		array[3].isEmpty = 0;


		array[4].id = 5;
		strncpy(array[4].nombreEmpresa, "DIA", 51);
		strncpy(array[4].cuit, "31-54581253-3", 13);
		strncpy(array[4].localidad, "AVELLANEDA", 51);
		strncpy(array[4].direccion, "Mitre 750", 51);
		array[4].isEmpty = 0;


		array[5].id = 6;
		strncpy(array[5].nombreEmpresa, "QUILMES", 51);
		strncpy(array[5].cuit, "30-51485759-6", 13);
		strncpy(array[5].localidad, "QUILMES", 51);
		strncpy(array[5].direccion, "rocha 741", 51);
		array[5].isEmpty = 0;

	return 0;
}

/** Busca un cliente por la variable isEmpty y lo devuelve si existe */
int buscarEmptyCliente(eCliente array[], int tamanio, int* posicion, int isEmptyBuscado) /** Si isEmptyBuscado==1 busca isEmpty==1, si isEmptyBuscado==0 busca isEmpty==0 */
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0 && posicion!=NULL)
    {

        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==isEmptyBuscado)
            {
                *posicion=i;
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

/** Busca un cliente por id y lo devuelve si existe*/
int buscarPorIdCliente(eCliente array[], int tamanio, int id, int* posicion)
{
    int retorno=-1;

    if(array!= NULL && tamanio>=0)
    {
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            } else if(array[i].id==id) {
                *posicion=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////

int altaCliente(eCliente array[], int tamanio, int* idRecibido)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        if(buscarEmptyCliente(array,tamanio,idRecibido,1)==-1)
        {
            printf("No hay lugares vacios\n");
        }
        else
        {
            array[*idRecibido].isEmpty=0;

            utn_getTexto(" Ingrese nombre de la empresa: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].nombreEmpresa);
            utn_getTexto(" Ingrese direccion: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].direccion);
            utn_getTexto(" Ingrese localidad: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].localidad);

            utn_getTexto(" Ingrese cuit: "," ERROR - Cuit invalido (13 numeros y dos guiones)\n",1,13,1,&array[*idRecibido].cuit);
            //utn_getUnsignedInt(" Ingrese cuit: "," ERROR - Cuit invalido (11 numeros sin guiones)\n",11,14,0,1,2,&array[*idRecibido].cuit);


            array[*idRecibido].id=*idRecibido+1;
            retorno=0;
        }
    }
    return retorno;
}

int modificarCliente(eCliente array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {

        int posicion;
        int id;
        int accion;

        utn_getUnsignedInt(" ID del Cliente a modificar: "," ERROR\n",1,sizeof(int),1,tamanio,1,&id); // Modificar 'ENTIDAD'
        if(buscarPorIdCliente(array,tamanio,id,&posicion)==-0)
        {
            do
            {
                printf("\n  1) Nombre de la empresa: %s\n",array[posicion].nombreEmpresa);
                printf("  2) Direccion: %s\n",array[posicion].direccion);
                printf("  3) Localidad: %s\n",array[posicion].localidad);
                printf("  4) Cuit: %s\n",array[posicion].cuit);


                printf("\n  9) Volver\n");

                utn_getUnsignedInt("\n-Ingrese el numero de la variable que desea modificar: "," ERROR\n",1,2,1,9,2,&accion);

                switch(accion)
                {
                    case 1:
                        utn_getTexto("\n-Ingrese nombre de la empresa nuevo: "," ERROR\n",1,TEXT_SIZE,1,array[posicion].nombreEmpresa);
                        break;
                    case 2:
                        utn_getTexto("\n-Ingrese direccion nueva: "," ERROR\n",1,TEXT_SIZE,1,array[posicion].direccion);
                        break;
                    case 3:
                        utn_getTexto("\n-Ingrese localidad nueva: "," ERROR\n",1,TEXT_SIZE,0,&array[posicion].localidad);
                        break;
                    case 4:
                        //utn_getUnsignedInt("\n-Ingrese cuit nuevo: "," ERROR\n",1,TEXT_SIZE,1,1000,2,&array[posicion].cuit);
                        utn_getTexto(" Ingrese cuit nuevo: "," ERROR - Cuit invalido (13 numeros y dos guiones)\n",1,13,1,&array[posicion].cuit);
                        break;
                    case 9:
                        break;
                    default:
                        printf("\n ERROR - Accion no valida (entre 1 y 3 o 9 para volver)\n\n");
                }
            }
            while(accion!=1&&accion!=2&&accion!=3&&accion!=4&&accion!=9);
            retorno=0;
        }
        else
        {
            msjCliente(-5);
        }
    }
    return retorno;
}

int bajaCliente(eCliente array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        int posicion;
        int id;

        utn_getUnsignedInt(" ID a dar de baja: "," ERROR\n",1,sizeof(int),1,tamanio,1,&id);

        if(buscarPorIdCliente(array,tamanio,id,&posicion)==0)
        {
            /** Realizamos una baja logica */

            strncpy(array[posicion].nombreEmpresa,"",TEXT_SIZE);
            strncpy(array[posicion].direccion,"",TEXT_SIZE);
            strncpy(array[posicion].localidad,"",TEXT_SIZE);

            strncpy(array[posicion].cuit,"",13);

            array[posicion].id=0;
            array[posicion].isEmpty=1;

            retorno=0;
        }
    }
    return retorno;
}

//////////////////////////////////////////////////////////////

int msjCliente(int idMensaje)
{
    if(idMensaje<0) //Si el idMensaje es negativo entonces se trata de un error
    {
        printf("\a");   // Por eso hacemos un ruidito
    }
    switch(idMensaje) /** Negativos para errores. 0 Adios*/
    {
        case 1:
            printf(" Hecho!\n");
            break;
        case -1: // Sin entes dados de alta
            printf("\n ERROR - No hay ningun %s dado de alta (opcion 1)\n",CLIENTE);
            break;
        case -2: // Acción no valida
            printf("\n ERROR - Opcion invalida (entre 1 y %d)\n",QTY_OPCIONES);
            break;
        case -5: // No existe id
            printf("\n No existe este ID\n");
            break;
        case -999: // Error desconocido o generico
            printf("\n ERROR - Algo salio mal!\n");
            break;
        default:   // Si se ingresa un idMensaje inexistente se da un salto de linea
            printf("\n");
    }
    printf("=========================================================\n");
    return 0;
}

int imprimirCliente(eCliente array[], int tamanio, int idCliente)
{
    int retorno=-1;
        if(array!=NULL && tamanio>=0 && idCliente>=0)
        {
            printf("\n  1) Nombre de la empresa: %s\n",array[idCliente].nombreEmpresa);
            printf("  2) Direccion: %s\n",array[idCliente].direccion);
            printf("  3) Localidad: %s\n",array[idCliente].localidad);
            printf("  4) Cuit: %s\n",array[idCliente].cuit);
            retorno=0;
        }
    return retorno;
}

int listarCliente(eCliente array[], int tamanio)//, ePedido arrayPedido[])
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int cantidadPedidosSinProcesar=0;
        for(int i=0;i<tamanio;i++)
        {
            //printf("array[%d].id: %d\n",i,array[i].id);
            if(array[i].isEmpty==0)
            {
                //calcularPedidosCliente(arrayPedido,tamanio,array[i].id,&cantidadPedidosSinProcesar,0);
                imprimirCliente(array,tamanio,i);
            }
        }
        printf("\n");
        retorno=0;
    }
    return retorno;
}

/** FUNCION GENÉRICA

            Esta funcion comentada la utilizo para realizar copy-paste y crear funciones nuevas
        ya con la validacion, el for y el retorno hechos.


int funcionGenerica(eEntidad array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {


            }
        }
        retorno=0;
    }
    return retorno;
}

*/

//////////////////////////////////////////////////////////////

