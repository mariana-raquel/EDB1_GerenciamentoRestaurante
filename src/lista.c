#include <stdio.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/cores.h"
#include "../include/fila.h"



void inserirPedidoLista(No **cabeca, Pedido pedido) {
    No *novoPedido = malloc(sizeof(No));
    if(!novoPedido) {
        printVermelho("Falha ao alocar memória para novo nó!\n");
        printVermelho("Pedido não registrado, tente novamente!\n");
        return;
    }

    novoPedido->pedido = pedido;
    novoPedido->proximo = NULL;

    if(*cabeca == NULL) {
        novoPedido->idPedido = 1;
        *cabeca = novoPedido;

        printVerde("\nPedido [");
        printf("%i", novoPedido->idPedido);
        printVerde("] registrado!\n");
        return;
    }

    No *atual = *cabeca;
    while(atual->proximo != NULL) {
        atual = atual->proximo;
    }
    
    novoPedido->idPedido = atual->idPedido + 1;
    atual->proximo = novoPedido;

    printVerde("\nPedido [");
    printf("%i", novoPedido->idPedido);
    printVerde("] registrado!\n");
}



void removerPedidoLista(No **cabeca, int numeroPedido) {
    if(*cabeca == NULL){
        printAmarelo("Não existem pedidos para serem removidos!\n");
        return;
    }

    No *anterior = NULL;
    No *atual = *cabeca;

    while(atual != NULL && atual->idPedido != numeroPedido){
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual == NULL){
        printVermelho("Desculpe, não encontramos esse pedido na lista! Verifique se informou o número corretamente\n");
        return;
    }

    if(anterior == NULL){
        *cabeca = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);

    printVerde("\nPedido [");
    printf("%i", numeroPedido);
    printVerde("] removido com sucesso!\n");
}



void removerPrimeiroPedido(No **cabeca, Fila *fila) {
    if(*cabeca == NULL){
        printAmarelo("Não existem pedidos para serem removidos!\n");
        return;
    }

    No *temp = *cabeca;
    int r = inserirPedidoFila(fila, *temp);
    if(r > 0) {
        *cabeca = (*cabeca)->proximo;
        free(temp);
    }
}


void listarPedidosLista(No *cabeca) {
    if(cabeca == NULL) {
        printAmarelo("Não existem pedidos pendentes!\n");
        return;
    }

    printAzul("Estes são os pedidos na lista de espera:\n");
    No *atual = cabeca;
    while(atual != NULL) {
        Pedido p = atual->pedido;
        printf("\nPedido: %i\n", atual->idPedido);
        for(int i = 0; i < p.qtdPratos; i++) {
            printf("%i. %s - %s\n", i+1, p.pratos[i].nomePrato, p.pratos[i].tipo);
        }
        atual = atual->proximo;       
    }
}