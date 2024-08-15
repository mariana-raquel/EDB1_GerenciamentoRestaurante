#include <stdio.h>
#include <stdlib.h>
#include "../include/listarPedidosPendentes.h"

/*
    Funcionalidades:
    * Exibir todos os pedidos atualmente armazenados na lista ligada.
        
    Requisitos:
    * A função deve exibir todos os pedidos pendentes atualmente na lista ligada.
*/

void insercaoNoInicio(No **cabeca, ItemCardapio valor) {
    No *novoItem = malloc(sizeof(No));
    novoItem->item = valor;
    novoItem->proximo = *cabeca;
    *cabeca = novoItem;
}

void listarPedidosPendentes(No *cabeca) {
    if(cabeca == NULL) {
        printf("A LISTA ESTÁ VAZIA!\n");
        return;
    }

    int i = 1;
    No *atual = cabeca;
    while(atual != NULL) {
        printf("%i. %s\n", i, atual->item.nomePrato);
        atual = atual->proximo;
        i++;
    }
}