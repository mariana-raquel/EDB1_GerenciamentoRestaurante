#include <stdio.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/cores.h"

/**
 * @brief Método responsável por fazer a iniciação da Fila.
 * 
 * @param fila
 */
void iniciarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}


/**
 * @brief Método responsável por fazer a inserção
 * de um novo Pedido na Fila
 * 
 * @param fila
 * @param pedido
 * @return int
 */
int inserirPedidoFila(Fila *fila, No pedido) {
    No *novoPedido = (No *) malloc(sizeof(No));
    if(!novoPedido) {
        printVermelho("Falha ao alocar memória para novo nó!\n");
        printVermelho("Pedido não adicionado para processamento, tente novamente!\n");
        return 0;
    }

    novoPedido->pedido = pedido.pedido;
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


/**
 * @brief Método responsável por fazer a remoção
 * de um Pedido da Fila
 * 
 * @param fila
 */
void removerPedidoFila(Fila *fila) {
    if(fila->inicio == NULL){
        printAmarelo("Não existem pedidos para serem removidos!\n");
        return;
    }
    
    No *temp = fila->inicio;

    int idPedido = temp->idPedido;

    fila->inicio = fila->inicio->proximo;

    if(fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);

    printVerde("\nPedido [");
    printf("%i", idPedido);
    printVerde("] removido com sucesso!\n");

}


/**
 * @brief Método responsável por listar os Pedidos 
 * contidos na fila de processamento
 * 
 * @param fila
 */
void listarPedidosFila(Fila *fila) {
    if(fila->inicio == NULL) {
        printAmarelo("Não existem pedidos sendo processados!\n");
        return;
    }

    printAzul("Estes são os pedidos na fila de processamento:\n");
    No *atual = fila->inicio;
    while(atual != NULL) {    
        Pedido p = atual->pedido;
        printf("\nPedido: %i\n", atual->idPedido);
        for(int i = 0; i < p.qtdPratos; i++) {
            printf("%i. %s - %s\n", i+1, p.pratos[i].nomePrato, p.pratos[i].tipo);
        }
        atual = atual->proximo;
    }
}