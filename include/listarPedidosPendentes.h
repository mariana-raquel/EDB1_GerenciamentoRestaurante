#ifndef LISTAR_PEDIDOS_PENDENTES_H
#define LISTAR_PEDIDOS_PENDENTES_H


#include "cardapio.h"

struct no {
    ItemCardapio item;
    struct no *proximo;
};

typedef struct no No;

void insercaoNoInicio(No **cabeca, ItemCardapio valor);

void listarPedidosPendentes(No *cabeca);

#endif