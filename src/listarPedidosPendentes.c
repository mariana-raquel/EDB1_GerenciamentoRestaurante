#include <stdio.h>
#include <stdlib.h>
#include "../include/listarPedidosPendentes.h"
#include "../include/structs.h"
/*
    Funcionalidades:
    * Exibir todos os pedidos atualmente armazenados na lista ligada.
        
    Requisitos:
    * A função deve exibir todos os pedidos pendentes atualmente na lista ligada.
*/

void insercaoNoInicio(No **cabeca, Pedido valor) {
    No *novoItem = malloc(sizeof(No));
    novoItem->item = valor;
    novoItem->proximo = *cabeca;
    if(*cabeca == NULL) {
        novoItem->idPedido = 1;
    } else {
        No c = **cabeca;
        novoItem->idPedido = c.idPedido + 1;
    }
    *cabeca = novoItem;
}

void listarPedidosPendentes(No *cabeca) {
    if(cabeca == NULL) {
        printf("A LISTA ESTÁ VAZIA!\n");
        return;
    }

    No *atual = cabeca;
    while(atual != NULL) {
        printf("\nPedido: %i\n", atual->idPedido);
        Pedido p = atual->item;
        for(int i = 0; i < p.qtdPratos; i++) {
            printf("%i. %s - %s\n", p.pratos[i].id, p.pratos[i].nomePrato, p.pratos[i].tipo);
        }
        atual = atual->proximo;       
    }
}