//////////////////////////////////////////////////////////////
#ifndef CLIENTE
    #define CLIENTE         "cliente"         /** Reemplazamos 'entidad' por el nombre de nuestro ente (Recomiendo primer letra minus) */
    #define QTY_CLIENTES   100                /** Reemplazamos 1000 por la cantidad de entidades de nuestro array */
    //////////////////////////////////////////////////////////////
    #include "utn.h"
    //////////////////////////////////////////////////////////////
    #define QTY_OPCIONES    20                /** Reemplazamos 14 por la cantidad de opciones de nuestro ABM */
    //////////////////////////////////////////////////////////////

    typedef struct
    {
     int id;

     char nombreEmpresa[TEXT_SIZE];
     char direccion[TEXT_SIZE];
     char localidad[TEXT_SIZE];
     char cuit[13];

     int isEmpty;

    } eCliente;

    int inicializarCliente(eCliente array[], int tamanio);
    int hardcodeClientes(eCliente array[]);
    int buscarEmptyCliente(eCliente array[], int tamanio, int* posicion, int isEmptyBuscado);
    int buscarPorIdCliente(eCliente array[], int tamanio, int id, int* posicion);

    int altaCliente(eCliente array[], int tamanio, int* idRecibido);
    int modificarCliente(eCliente array[], int tamanio);
    int bajaCliente(eCliente array[], int tamanio);

    int imprimirCliente(eCliente array[], int tamanio, int idCliente);
    int listarCliente(eCliente array[], int tamanio);

#endif // ENTIDAD


