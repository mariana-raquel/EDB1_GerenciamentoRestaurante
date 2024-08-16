#include <stdio.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/cores.h"
#include "../include/fila.h"


void iniciarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int inserirPedidoFila(Fila *fila, No pedido) {
    No *novoPedido = (No *) malloc(sizeof(No));
    if(!novoPedido) {
        printVermelho("Falha ao alocar memória para novo nó!\n");
        printVermelho("Pedido não adicionado para processamento, tente novamente!\n");
        return 0;
    }

    novoPedido->item = pedido.item;
    novoPedido->idPedido = pedido.idPedido;
    novoPedido->proximo = NULL;

    if(fila->inicio == NULL) {
        fila->inicio = novoPedido;
    } else {
        fila->fim->proximo = novoPedido;
    }

    fila->fim = novoPedido;

    printVerde("Pedido [");
    printf("%i", pedido.idPedido);
    printVerde("] colocado para processamento!\n");

    return 1;
}

void removerPedidoFila(Fila *fila);

void listarPedidosFila(Fila *fila) {
    if(fila->inicio == NULL) {
        printAmarelo("Não existem pedidos para serem processados!");
        return;
    }

    No *atual = fila->inicio;
    while(atual != NULL) {
        
        Pedido p = atual->item;
        printf("\nPedido: %i\n", atual->idPedido);
        for(int i = 0; i < p.qtdPratos; i++) {
            printf("%i. %s - %s\n", p.pratos[i].id, p.pratos[i].nomePrato, p.pratos[i].tipo);
        }
        atual = atual->proximo;
    }
    printf("\n");

}