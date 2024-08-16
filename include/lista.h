#ifndef LISTA_H
#define LISTA_H

#include "structs.h"

void inserirPedidoLista(No **cabeca, Pedido valor);

void removerPedidoLista(No **cabeca, int numeroPedido);

void removerPrimeiroPedido(No **cabeca, Fila *fila);

void listarPedidosLista(No *cabeca);

#endif