#include <stdio.h>
#include "../include/cardapio.h"

int adicionarPedido() {
    /*
        Funcionalidades:
        * Permitir que o cliente adicione um novo pedido.
        * Armazenar o pedido na lista ligada de pedidos pendentes.

        Requisitos:
        * A função deve permitir que o cliente adicione um ou mais pratos ao pedido.
        * Cada pedido deve ser representado como um nó na lista ligada.
    */

    Cardapio cardapio = montarCardapio();
    listarCardapio(&cardapio);
    return 0;
}