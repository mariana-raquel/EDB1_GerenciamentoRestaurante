#include <stdio.h>
#include "../include/structs.h"
#include "../include/listarPedidosPendentes.h"
#include "../include/removerPedido.h"

/*
    Funcionalidades:
    * Permitir que o cliente remova um prato específico do pedido.
    * Atualizar a lista ligada de pedidos após a remoção.
        
    Requisitos:
    * A função deve permitir que o cliente remova um prato específico de um pedido.
    * A lista ligada deve ser atualizada para refletir a remoção.
*/
int removerPedido(No **cabeca) {
    int numeroPedido = -1;
    printf("Estes são os pedidos na lista.\n");
    listarPedidosPendentes(*cabeca);
    printf("\nQual o número do pedido que deseja remover?\n");
    scanf("%i", &numeroPedido); 

    printf("Você escolheu remover o pedido: [%i]\n", numeroPedido);

    removerPedidoLista(cabeca, numeroPedido);

    printf("Pedido removido!\n");
    listarPedidosPendentes(*cabeca);
    return 0;
}