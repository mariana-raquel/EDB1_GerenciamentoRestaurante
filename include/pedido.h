#ifndef PEDIDO_H
#define PEDIDO_H

#include "structs.h"

void adicionarPedido(No **cabeca);

void processarPedido(No **cabeca, Fila *fila);

void removerPedido(No **cabeca);

#endif