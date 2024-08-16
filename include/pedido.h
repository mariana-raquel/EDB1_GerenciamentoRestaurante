#ifndef PEDIDO_H
#define PEDIDO_H

#include "structs.h"

void processarPedido(No **cabeca, Fila *fila);

int removerPedido(No **cabeca);

void adicionarPratoNoPedido(No **cabeca);

void removerPratoDoPedido(No **cabeca);

#endif