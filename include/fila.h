#ifndef FILA_H
#define FILA_H

#include "structs.h"

void iniciarFila(Fila *fila);

int inserirPedidoFila(Fila *fila, No pedido);

void removerPedidoFila(Fila *fila);

void listarPedidosFila(Fila *fila);

#endif