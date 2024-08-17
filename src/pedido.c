#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/cores.h"
#include "../include/structs.h"
#include "../include/lista.h"
#include "../include/fila.h"
#include "../include/cardapio.h"


/**
 * @brief Método responsável por criar 
 * um pedido e adicioná-lo na lista
 * 
 * @param cabeca
 */
void adicionarPedido(No **cabeca) {
    int maisPedidos = 1;
    
    Cardapio cardapio = montarCardapio();
    listarCardapio(&cardapio);
    
    while(maisPedidos == 1) {
        Pedido p;
        
        int qtdPratos = 0;
        printCiano("Quantos pratos você deseja adicionar no pedido? ");
        scanf("%i", &qtdPratos);
        
        if(qtdPratos > 0) {

            p.qtdPratos = qtdPratos;
            p.pratos = malloc(sizeof(ItemCardapio) * qtdPratos);

            int index = -1;
            for(int i = 0; i < qtdPratos; i++) {
                printCiano("Por favor, nos informe o código do");
                printf(" %iº ", i+1);
                printCiano("prato que deseja pedir: ");
                scanf("%i", &index);
                while(index < 1 || index > 15) {
                    printVermelho("\nDesculpe, não conhecemos o prato [");
                    printf("%i", index);
                    printVermelho("]. Digite novamente: ");
                    scanf("%i", &index);
                    printf("\n");
                }
                p.pratos[i].codigo = cardapio.pratos[index-1].codigo;
                strcpy(p.pratos[i].nomePrato, cardapio.pratos[index-1].nomePrato);
                strcpy(p.pratos[i].tipo, cardapio.pratos[index-1].tipo);
            }
        
            inserirPedidoLista(cabeca, p);
        }

        printCiano("\nDeseja fazer mais algum pedido?\n");
        printCiano("1 - Sim\t\t2- Não\n");
        scanf("%i", &maisPedidos);
    }
}


/**
 * @brief Método responsável por remover um pedido da lista.
 * 
 * @param cabeca
 */
void removerPedido(No **cabeca) {
    if(*cabeca == NULL) {
        printAmarelo("Não existem pedidos pendentes!\n");
        return;
    } 
    int numeroPedido = -1;
    listarPedidosLista(*cabeca);

    int v = 0;
    No *atual = *cabeca;
    while(v == 0) {
        printCiano("\nQual o número do pedido que deseja remover? ");
        scanf("%i", &numeroPedido);

        while(atual != NULL && atual->idPedido != numeroPedido){
            atual = atual->proximo;
        }

        if(atual == NULL) {
            printVermelho("\nDesculpe, não encontramos esse pedido na lista! Verifique se informou o número corretamente!\n");
            atual = *cabeca;
        } else {
            v = 1;
        }
    }

    printAmarelo("\nVocê escolheu remover o pedido: [");
    printf("%i", numeroPedido);
    printAmarelo("]\n");

    removerPedidoLista(cabeca, numeroPedido);

}


/**
 * @brief Método responsável por gerenciar o processamento de
 * um pedido da lista, e adicioná-lo na fila de processamento
 * 
 * @param cabeca
 * @param fila
 */
void processarPedido(No **cabeca, Fila *fila) {
    if(*cabeca == NULL){
        printAmarelo("Não existem pedidos para serem processados!\n");
        return;
    }
    removerPrimeiroPedido(cabeca, fila);
}


/**
 * @brief Método responsável por exibir um pedido.
 * 
 * @param pedido
 * @param idPedido
 */
void mostrarPedido(Pedido pedido, int idPedido) {
    printf("\nPedido: %i\n", idPedido);
    for(int i = 0; i < pedido.qtdPratos; i++) {
        printf("%i. %s - %s\n", i+1, pedido.pratos[i].nomePrato, pedido.pratos[i].tipo);
    }
    printf("\n");
}