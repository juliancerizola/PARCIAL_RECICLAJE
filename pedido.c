//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "pedido.h"
//////////////////////////////////////////////////////////////

int inicializarPedido(ePedido array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        for(;tamanio>0;tamanio--)
        {
            array[tamanio-1].isEmpty=1;
            array[tamanio-1].id=tamanio;
            array[tamanio-1].idCliente=0;
        }
        retorno=0;
    }

    return retorno;
}

int buscarEmptyPedido(ePedido array[], int tamanio, int* posicion, int isEmptyBuscado) /** Si isEmptyBuscado==1 busca isEmpty==1, si isEmptyBuscado==0 busca isEmpty==0 */
{
    int retorno=-1;


    if(array!=NULL && tamanio>=0 && posicion!=NULL)
    {

        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==isEmptyBuscado)
            {
                //printf("i=%d",i);
                //printf("pos %d",i);
                *posicion=i;
                //printf("pos %d",i);
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

int buscarPorIdPedido(ePedido array[], int tamanio, int id, int* posicion)
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
}

int altaPedido(ePedido array[], int tamanio, int* idRecibido)
{

    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        if(buscarEmptyPedido(array,tamanio,idRecibido,1)==-1)
        {
            printf("No hay lugares vacios\n");
        }
        else
        {
            array[*idRecibido].isEmpty=0;

            /** Ingresamos las funciones correspondientes a nuestro caso en particular */

            /*utn_getName(" Ingrese string1: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].string1);
            utn_getTexto(" Ingrese string2: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].string2);
            utn_getFloat(" Ingrese float1: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].float1);
            utn_getFloat(" Ingrese float2: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].float2);*/
            utn_getUnsignedInt(" Ingrese id del cliente: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].idCliente);
            //printf("id cliente: %d",array[*idRecibido].idCliente);
            utn_getUnsignedInt(" Ingrese kilos: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].kilos);
            array[*idRecibido].estado=0;
            //utn_getUnsignedInt(" Ingrese idEntidad: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].idEntidad);


            array[*idRecibido].id=*idRecibido+1;
            retorno=0;
        }
    }
    return retorno;
}

int procesarPedido(ePedido array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        int idProcesado=1;
        utn_getUnsignedInt("\n-Ingrese id del pedido a procesar: "," ERROR\n",0,TEXT_SIZE,0,QTY_PEDIDOS,0,&idProcesado);

        idProcesado--; //Menos uno porque el id siempre es +1 que el indice del array

        utn_getUnsignedInt("-Ingrese la cantidad de kilos de polietileno de alta densidad: "," ERROR\n",0,TEXT_SIZE,0,QTY_PEDIDOS,0,&array[idProcesado].kilosHDPE);
        utn_getUnsignedInt("-Ingrese la cantidad de kilos de polietileno de baja densidad: "," ERROR\n",0,TEXT_SIZE,0,QTY_PEDIDOS,0,&array[idProcesado].kilosLDPE);
        utn_getUnsignedInt("-Ingrese la cantidad de kilos de polipropileno: "," ERROR\n",0,TEXT_SIZE,0,QTY_PEDIDOS,0,&array[idProcesado].kilosPP);

        array[idProcesado].estado=1;
        array[idProcesado].isEmpty=0;


        array[idProcesado].kilosBasura = (array[idProcesado].kilos) - (array[idProcesado].kilosHDPE) - (array[idProcesado].kilosLDPE) - (array[idProcesado].kilosPP);

        printf("\n");

        retorno=0;

    }
    return retorno;

}

int hardcodePedidos(ePedido array[])
{
//////////////////////////////////////////////////////////////

		array[0].id = 1;
		array[0].idCliente = 1;
		array[0].estado = 1;
		array[0].kilos = 1000;
		array[0].kilosLDPE = 200;
		array[0].kilosHDPE = 145;
		array[0].kilosPP = 230;
		array[0].kilosBasura = (array[0].kilos) - (array[0].kilosHDPE) - (array[0].kilosLDPE) - (array[0].kilosPP);

		array[0].isEmpty = 0;

//////////////////////////////////////////////////////////////

		array[1].id = 2;
		array[1].idCliente = 1;
		array[1].estado = 1;
		array[1].kilos = 800;
		array[1].kilosLDPE = 210;
		array[1].kilosHDPE = 45;
		array[1].kilosPP = 30;
		array[1].kilosBasura = (array[1].kilos) - (array[1].kilosHDPE) - (array[1].kilosLDPE) - (array[1].kilosPP);

		array[1].isEmpty = 0;

//////////////////////////////////////////////////////////////

		array[2].id = 3;
		array[2].idCliente = 2;
		array[2].estado = 0;
		array[2].kilos = 100;
		array[2].kilosHDPE = 0;
		array[2].kilosLDPE = 0;
		array[2].kilosPP = 0;

		array[2].isEmpty = 0;

//////////////////////////////////////////////////////////////

		array[3].id = 4;
		array[3].idCliente = 2;
		array[3].estado = 0;
		array[3].kilos = 300;
		array[3].isEmpty = 0;

//////////////////////////////////////////////////////////////

		array[4].id = 5;
		array[4].idCliente = 3;
		array[4].estado = 1;
		array[4].kilos = 1500;
		array[4].kilosLDPE = 500;
		array[4].kilosHDPE = 150;
		array[4].kilosPP = 270;
		array[4].kilosBasura = (array[4].kilos) - (array[4].kilosHDPE) - (array[4].kilosLDPE) - (array[4].kilosPP);

		array[4].isEmpty = 0;

//////////////////////////////////////////////////////////////

		array[5].id = 6;
		array[5].idCliente = 4;
		array[5].estado = 1;
		array[5].kilos = 750;
		array[5].kilosLDPE = 100;
		array[5].kilosHDPE = 50;
		array[5].kilosPP = 70;
		array[5].kilosBasura = (array[5].kilos) - (array[5].kilosHDPE) - (array[5].kilosLDPE) - (array[5].kilosPP);

		array[5].isEmpty = 0;

//////////////////////////////////////////////////////////////

		array[6].id = 7;
		array[6].idCliente = 1;
		array[6].estado = 0;
		array[6].kilos = 200;
		array[6].isEmpty = 0;

//////////////////////////////////////////////////////////////

		array[7].id = 8;
		array[7].idCliente = 5;
		array[7].estado = 1;
		array[7].kilos = 30;
		array[7].kilosLDPE = 10;
		array[7].kilosHDPE = 5;
		array[7].kilosPP = 3;
		array[7].kilosBasura = (array[7].kilos) - (array[7].kilosHDPE) - (array[7].kilosLDPE) - (array[7].kilosPP);

		array[7].isEmpty = 0;

//////////////////////////////////////////////////////////////

		array[8].id = 9;
		array[8].idCliente = 6;
		array[8].estado = 0;
		array[8].kilos = 456;
		array[8].isEmpty = 0;

//////////////////////////////////////////////////////////////

	return 0;
}

//////////////////////////////////////////////////////////////

int msjPedido(int idMensaje)
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
            printf("\n ERROR - No hay ningun %s dado de alta (opcion 1)\n",PEDIDO);
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

int imprimirPedido(ePedido array[], int tamanio, int idCliente)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0 && idCliente >=1)
    {
        if(array[idCliente].estado==0 && array[idCliente].isEmpty==0)
        {
            printf("\n  ID: %d\n  ID Cliente: %d\n  Kilos: %d\n  Estado: %d\n",
            array[idCliente].id, array[idCliente].idCliente, array[idCliente].kilos, array[idCliente].estado);
        }
        else if(array[idCliente].estado==1)
        {
            printf("\n  ID: %d\n  ID Cliente: %d\n  Kilos HDPE: %d\n  Kilos LDPE: %d\n  Kilos PP: %d\n  Kilos de basura: %d\n",
                array[idCliente].id, array[idCliente].idCliente, array[idCliente].kilosHDPE, array[idCliente].kilosLDPE, array[idCliente].kilosPP, array[idCliente].kilosBasura);
        }
    }
    return retorno;
}

int listarPedido(ePedido array[], int tamanio, int estadoBuscado)
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

                if(array[i].estado!=estadoBuscado)
                {
                    continue;
                }
                else
                {
                    if(estadoBuscado==0)
                    {
                        printf("\n  ID: %d\n  ID Cliente: %d\n  Kilos: %d\n  Estado: %d\n",
                        array[i].id, array[i].idCliente, array[i].kilos, array[i].estado);
                    }
                    else if(estadoBuscado==1)
                    {
                        printf("\n  ID: %d\n  ID Cliente: %d\n  Kilos HDPE: %d\n  Kilos LDPE: %d\n  Kilos PP: %d\n  Kilos de basura: %d\n  Porcentaje de kilos reciclados: %d%%\n",
                        array[i].id, array[i].idCliente, array[i].kilosHDPE, array[i].kilosLDPE, array[i].kilosPP, array[i].kilosBasura, porcentajePlasticoReciclado(array,tamanio,i));
                    }
                    retorno=0;
                }
            }
        }
        printf("\n");
    }
    return retorno;
}

int listarEncolumnadoPedido(ePedido array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int columnaMostrada=0;

        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                if(columnaMostrada==0)
                {
                    printf("  ID\t\tString1\t\tString2\t\tFloat1\t\tFloat2\t\tInt1\t\tInt2\n");
                    columnaMostrada=1;
                }

                /**     Podemos hacerlo en un solo printf, pero me gusta más con varios, además si hay variables que no se usan
                puedo simplemente comentar la línea en lugar de tener que modificar TODO el unico printf

                OPCION 1
                //printf("  %d\t\t%s\t\t%s\t\t%d\t\t%d\t\t%f\t\t%f\n",array[i].id, array[i].string1, array[i].string2, array[i].int1, array[i].int2, array[i].float1, array[i].float2);

                OPCION 2 AGUANTE ESTA :)
                printf("  %d\t\t",array[i].id);
                printf("  %s\t\t",array[i].string1);
                printf("  %s\t\t",array[i].string2);
                printf("  %f\t\t",array[i].float1);
                printf("  %f\t\t",array[i].float2);
                printf("  %d\t\t",array[i].int1);
                printf("  %d\t\t",array[i].int2);
                printf("\n");
                */

                printf("  %d\t\t",array[i].id);
                printf("  %d\t\t",array[i].idCliente);
                printf("  %d\t\t",array[i].kilos);
                printf("  %d\t\t",array[i].estado);
                /*printf("  %f\t\t",array[i].float2);
                printf("  %d\t\t",array[i].int1);
                printf("  %d\t\t",array[i].int2);*/
                printf("\n");

            }
        }
        retorno=0;
    }
    return retorno;
}

int calcularPedidosCliente(ePedido array[], int tamanio, int idCliente,int* cantidadPedidos, int estadoBuscado)
{
    int retorno=-1;
    *cantidadPedidos=0;

    if(array!=NULL && tamanio>=0)
    {
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==0)
            {
                if(array[i].estado==estadoBuscado)
                {
                    if(array[i].idCliente==idCliente)
                    {
                        *cantidadPedidos+=1;
                    }
                }

            }
        }
        printf("\n");
    }
    return retorno;
}

/** FUNCION GENÉRICA

            Estaba harto de escribir siempre lo mismo en las funciones asi que
        esta funcion comentada la utilizo para realizar copy-paste y crear funciones nuevas
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

