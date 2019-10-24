#ifndef PEDIDO

    //////////////////////////////////////////////////////////////
    #define PEDIDO       "pedido"         /** Reemplazamos 'entidad' por el nombre de nuestro ente (Recomiendo todo en minuscula) */
    #define QTY_PEDIDOS  1000             /** Reemplazamos 1000 por la cantidad de entidades de nuestro array */
    //////////////////////////////////////////////////////////////
    #include "utn.h"
    //////////////////////////////////////////////////////////////
    #define QTY_OPCIONES    20                /** Reemplazamos 14 por la cantidad de opciones de nuestro ABM */
    //////////////////////////////////////////////////////////////

    typedef struct
    {
         int id;

         int idCliente;

         int kilos;
         int kilosHDPE;
         int kilosLDPE;
         int kilosPP;
         int kilosBasura;

         int estado; //0 pendiente - 1 completado

         int isEmpty;
    } ePedido;

    int inicializarPedido(ePedido array[], int tamanio);
    int hardcodePedidos(ePedido array[]);
    int buscarEmptyPedido(ePedido array[], int tamanio, int* posicion, int isEmptyBuscado);
    int buscarPorIdPedido(ePedido array[], int tamanio, int id, int* posicion);

    int altaPedido(ePedido array[], int tamanio, int* idRecibido);
    int modificarPedido(ePedido array[], int tamanio);
    int bajaPedido(ePedido array[], int tamanio);
    int procesarPedido(ePedido array[], int tamanio);

    int listarPedido(ePedido array[], int tamanio, int estadoBuscado);
    int listarEncolumnadoPedido(ePedido array[], int tamanio);

    int calcularPedidosCliente(ePedido array[], int tamanio, int idCliente,int* cantidadPedidos, int estadoBuscado);

#endif //PEDIDO



