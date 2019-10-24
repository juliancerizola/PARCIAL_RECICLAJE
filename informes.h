//////////////////////////////////////////////////////////////
#include "cliente.h"
#include "pedido.h"
//////////////////////////////////////////////////////////////

void msj(int idMensaje);

int clienteMasPedidosxEstado(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido, int estado);
int cantidadPedidosEstadoxIdCliente(int estado, int idCliente, ePedido array[], int length, int *contador);

int clienteMasPedidos(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido);
int cantidadPedidosxIdCliente(int idCliente, ePedido array[], int length, int *contador);

int clienteMasKgReciclados(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido);
int clienteMenosKgReciclados(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido);
int cantidadKgRecicladosxIdCliente(int idCliente, ePedido array[], int length, float *acumulador);

int porcentajePlasticoReciclado(ePedido array[], int length, int id);

int clientesMas1000kg(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido);
int clientesMenos100kg(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido);

int obtenerPedidoxLocalidad(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido);
int cantidadPPpromedioxCliente(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido);
int contarClientesPedidoCompletado(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido, int *cantidadPedidosProcesados);

int cantidadPlasticoRecicladoxCuit(ePedido arrayPedido[],eCliente arrayCliente[],int lengthCliente, int lengthPedido);

