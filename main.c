//////////////////////////////////////////////////////////////
#include "informes.h"
//////////////////////////////////////////////////////////////
#define TITULO_PRUEBA   "Parcial Nro 1"     /** Reemplazamos 'Parcial de prueba' por el nombre que le queramos dar a nuestro parcial o TP */
#define ALUMNO          "Julian Cerizola"   /** Reemplazamos 'Julian Cerizola' por el nombre del alumno que esté entregando esta prueba */
#define DIVISION        "1ro E - UTN FRA"   /** Reemplazamos '1ro E - UTN FRA' por la division del alumno en cuestión */
//////////////////////////////////////////////////////////////
#define QTY_OPCIONES    20                  /** Reemplazamos 14 por la cantidad de opciones de nuestro ABM */
//////////////////////////////////////////////////////////////

int main(void)
{
    int opcion;
	int contadorId=1;

	eCliente arrayCliente[QTY_CLIENTES];
	ePedido arrayPedido[QTY_PEDIDOS];

	inicializarCliente(arrayCliente,QTY_CLIENTES);
	inicializarPedido(arrayPedido,QTY_PEDIDOS);

	hardcodePedidos(arrayPedido);
	hardcodeClientes(arrayCliente);

    // Notar que hay un \a          y un corazón <3
    printf("\a\t   Bienvenide!\n\n\t%s\n\t%s\n\t%s <3\n=========================================================\n",TITULO_PRUEBA,ALUMNO,DIVISION);

	do
    {
        printf("  1) Alta de cliente\n  2) Modificar cliente\n  3) Baja de cliente\n\n");
        printf("  4) Crear pedido de recoleccion\n  5) Procesar residuos\n\n");
        printf("  6) Imprimir clientes\n  7) Imprimir pedidos pendientes\n  8) Imprimir pedidos procesados\n\n");
        printf("  9) Imprimir cliente con mas pedidos pendientes\n  10) Imprimir cliente con mas pedidos procesados\n  11) Imprimir cliente con mas pedidos\n\n");
        printf("  12) Imprimir cliente que reciclo mas kilos\n  13) Imprimir cliente que reciclo menos kilos\n\n");
        printf("  14) Imprimir la cantidad de clientes que reciclaron mas de 1000 kilos\n  15) Imprimir la cantidad de clientes que reciclaron menos de 100 kilos\n\n");
        printf("  16) Imprimir pedidos completados junto con porcentaje de reciclado\n");
        printf("  17) Imprimir cantidad de kilos pendientes de una localidad\n");
        printf("  18) Imprimir cantidad de kilos de polipropileno (PP) reciclado promedio por cliente\n");
        printf("  19) Imprimir cantidad de kilos recicladas por tipo de plastico\n\n");

        printf("  %d) Salir\n",QTY_OPCIONES);

        utn_getUnsignedInt("-Ingrese el numero de la accion que desea realizar: "," ERROR - Opcion invalida (entre 1 y 21)\n",0,QTY_OPCIONES,1,100,1,&opcion);

        switch(opcion)
        {
            case 1: //  Alta
            printf("\n");
            if((altaCliente(arrayCliente,QTY_CLIENTES,&contadorId))==0)
            {
                msj(1);
            }
            else
            {
                msj(-999);
            }
            break;
        case 2: // Modificar
            if(buscarEmptyCliente(arrayCliente,QTY_CLIENTES,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
            {
                printf("\n");
                if((modificarCliente(arrayCliente,QTY_CLIENTES))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-999);
                }
            }
            else
            {
                msj(-1);
            }
            break;
        case 3: // Baja

            if((buscarEmptyCliente(arrayCliente,QTY_CLIENTES,&contadorId,0))==0)  /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
            {
                printf("\n");
                if((bajaCliente(arrayCliente,QTY_CLIENTES))==0)
                {
                    msj(1);
                }
                else
                {
                    printf(" ERROR - ID Inexistente\n");
                }
            }
            else
            {
                msj(-1);
            }
            break;

            //////////////////////////////////////////////////////////////
                        /** OPCIONES DE ENTIDAD 2*/
            //////////////////////////////////////////////////////////////

        case 4: // Pedido de recoleccion
            printf("\n");
            if((buscarEmptyCliente(arrayCliente,QTY_CLIENTES,&contadorId,0))==0)  /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
            {
                if((altaPedido(arrayPedido,QTY_PEDIDOS,&contadorId))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-999);
                }
            }
            else
            {
                msj(-1);
            }
            break;

        case 5: //  Procesar residuos

            if(buscarEmptyPedido(arrayPedido,QTY_PEDIDOS,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
            {
                if((listarPedido(arrayPedido,QTY_PEDIDOS,0))==0)
                {
                    if((procesarPedido(arrayPedido,QTY_PEDIDOS))==0)
                    {
                        msj(1);
                    }
                    else
                    {
                        msj(-999);
                    }
                }
                else
                {
                    msj(-999);
                }

            }
            else
            {
                msj(-1);
            }
            break;

            //////////////////////////////////////////////////////////////
            /** OPCIONES DE IMPRESIONES SIMPLES (DE UNA UNICA ENTIDAD)*/
            //////////////////////////////////////////////////////////////

        case 6: // Imprimir clientes

            if(buscarEmptyCliente(arrayCliente,QTY_CLIENTES,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
            {
                if((listarCliente(arrayCliente,QTY_CLIENTES))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-1);
                }
            }
            break;

        case 7: // Imprimir pedidos pendientes

            if(buscarEmptyPedido(arrayPedido,QTY_PEDIDOS,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
            {
                if((listarPedido(arrayPedido,QTY_PEDIDOS,0))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-2);
                }
            }
            break;

        case 8: // Imprimir pedidos procesados

            if(buscarEmptyPedido(arrayPedido,QTY_PEDIDOS,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
            {
                if((listarPedido(arrayPedido,QTY_PEDIDOS,1))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-2);
                }
            }

            break;

            //////////////////////////////////////////////////////////////
            /** OPCIONES DE IMPRESIONES COMPLEJAS (DE MAS DE UNA ENTIDAD)*/
            //////////////////////////////////////////////////////////////

        case 9:
            if((clienteMasPedidosxEstado(arrayPedido,arrayCliente,QTY_CLIENTES,QTY_PEDIDOS,0))==0)
            {
                msj(1);
            }
            break;
        case 10:
            if((clienteMasPedidosxEstado(arrayPedido,arrayCliente,QTY_CLIENTES,QTY_PEDIDOS,1))==0)
            {
                msj(1);
            }
            break;
        case 11:
            if((clienteMasPedidos(arrayPedido,arrayCliente,QTY_CLIENTES,QTY_PEDIDOS))==0)
            {
                msj(1);
            }
            else
            {
                msj(-999);
            }
            break;
        case 12:
            if((clienteMasKgReciclados(arrayPedido,arrayCliente,QTY_CLIENTES,QTY_PEDIDOS))==0)
            {
                msj(1);
            }
            else
            {
                msj(-999);
            }
            break;
        case 13:
            if((clienteMenosKgReciclados(arrayPedido,arrayCliente,QTY_CLIENTES,QTY_PEDIDOS))==0)
            {
                msj(1);
            }
            else
            {
                msj(-999);
            }
            break;
        case 14:
            if((clientesMas1000kg(arrayPedido,arrayCliente,QTY_CLIENTES,QTY_PEDIDOS))==0)
            {
                msj(1);
            }
            else
            {
                msj(-999);
            }
            break;
        case 15:
            if((clientesMenos100kg(arrayPedido,arrayCliente,QTY_CLIENTES,QTY_PEDIDOS))==0)
            {
                msj(1);
            }
            else
            {
                msj(-999);
            }
            break;
        case 16:
            if(buscarEmptyPedido(arrayPedido,QTY_PEDIDOS,&contadorId,1)==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
            {
                if((listarPedido(arrayPedido,QTY_PEDIDOS,1))==0)
                {
                    msj(1);
                }
                else
                {
                    msj(-2);
                }
            }
            break;
        case 17:
            if((obtenerPedidoxLocalidad(arrayPedido,arrayCliente,QTY_CLIENTES,QTY_PEDIDOS))==0)
            {
                msj(1);
            }
            else
            {
                msj(-999);
            }
            break;
        case 18:
            if((cantidadPPpromedioxCliente(arrayPedido,arrayCliente,QTY_CLIENTES,QTY_PEDIDOS))==0)
            {
                msj(1);
            }
            else
            {
                msj(-999);
            }
            break;
        case 19:
            if((cantidadPlasticoRecicladoxCuit(arrayPedido,arrayCliente,QTY_CLIENTES,QTY_PEDIDOS))==0)
            {
                msj(1);
            }
            else
            {
                msj(-999);
            }
            break;
        case QTY_OPCIONES: //Salir
            printf("\n\n\t   Adios!\n\n");
            return 0;
            break;
        default:
            msj(-3);
            break;
        }


    } while(opcion!=QTY_OPCIONES);

    return 0;
}
