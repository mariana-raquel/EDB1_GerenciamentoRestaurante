#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/cores.h"
#include "../include/structs.h"
#include "../include/lista.h"
#include "../include/fila.h"
#include "../include/cardapio.h"
#include "../include/pedido.h"


void processarPedido(No **cabeca, Fila *fila) {
    removerPrimeiroPedido(cabeca, fila);
}

int removerPedido(No **cabeca) {
    int numeroPedido = -1;
    printAmarelo("Estes são os pedidos na lista.\n");
    listarPedidosLista(*cabeca);

    printCiano("\nQual o número do pedido que deseja remover? ");
    scanf("%i", &numeroPedido); 

    printCiano("\nVocê escolheu remover o pedido: [");
    printf("%i", numeroPedido);
    printCiano("]\n");

    removerPedidoLista(cabeca, numeroPedido);

    listarPedidosLista(*cabeca);

    return 0;
}


void adicionarPratoNoPedido(No **cabeca) {
    printAmarelo("Este são os pedidos feitos:\n");
    listarPedidosLista(*cabeca);

    int indPedido = -1;
    int v = 0;
    No *atual = *cabeca;
    while(v == 0) {
        printCiano("Em qual pedido você deseja acrescentar o(s) prato(s)? ");
        scanf("%i", &indPedido);

        while(atual != NULL && atual->idPedido != indPedido){
            printf("%i\n", atual->idPedido);
            atual = atual->proximo;
        }

        if(atual == NULL) {
            printVermelho("\nDesculpe, não encontramos esse pedido na lista! Verifique se informou o número corretamente\n\n");
            atual = *cabeca;
        } else {
            v = 1;
        }
    }

    Cardapio cardapio = montarCardapio();
    printAmarelo("\nEste é o nosso cardápio:\n\n");
    listarCardapio(&cardapio);

    Pedido p = atual->item;
    int qtdPratos = 0;
    printCiano("Quantos pratos você deseja acrescentar no pedido? ");
    scanf("%i", &qtdPratos);

    if(qtdPratos > 0) {
        int aux = p.qtdPratos;
        p.qtdPratos = p.qtdPratos + qtdPratos;
        p.pratos = realloc(p.pratos, sizeof(ItemCardapio) * p.qtdPratos);

        printCiano("\nPor favor, nos informe os ids do prato que deseja acrescentar (separados por espaço): ");
        int index = -1;
        for(int i = aux; i < p.qtdPratos; i++) {
            scanf("%i", &index);
            while(index < 1 || index > 15) {
                printVermelho("\nDesculpe, não conhecemos o prato [");
                printf("%i", index);
                printVermelho("]. Digite novamente: ");
                scanf("%i", &index);
            }
            p.pratos[i].id = cardapio.pratos[index-1].id;
            strcpy(p.pratos[i].nomePrato, cardapio.pratos[index-1].nomePrato);
            strcpy(p.pratos[i].tipo, cardapio.pratos[index-1].tipo);
        }

        atual->item = p;
        printVerde("Pratos adicionados no pedido [");
        printf("%i", indPedido);
        printVerde("]!\n");

        listarPedidosLista(*cabeca);
    }
}


void removerPratoDoPedido(No **cabeca) {
    printAmarelo("Este são os pedidos feitos:\n");
    listarPedidosLista(*cabeca);

    int idPedido = -1;
    int v = 0;
    No *atual = *cabeca;
    while(v == 0) {
        printCiano("\nEm qual pedido você deseja remover o(s) prato(s)? ");
        scanf("%i", &idPedido);

        while(atual != NULL && atual->idPedido != idPedido){
            printf("%i\n", atual->idPedido);
            atual = atual->proximo;
        }

        if(atual == NULL) {
            printVermelho("\nDesculpe, não encontramos esse pedido na lista! Verifique se informou o número corretamente\n\n");
            atual = *cabeca;
        } else {
            v = 1;
        }
    }

    Pedido p = atual->item;
    int index = -1;
    printCiano("Por favor, nos informe o id do prato que deseja remover: ");
    scanf("%i", &index);
    int cont = 0;
    if(index != p.qtdPratos) {
        for(int j = 0; j < p.qtdPratos-1; j++) {
            if(index-1 == j) {
                cont++;
                p.pratos[j].id = p.pratos[j+1].id;
                strcpy(p.pratos[j].nomePrato, p.pratos[j+1].nomePrato);
                strcpy(p.pratos[j].tipo, p.pratos[j+1].tipo);
            }
        }
        while(cont == 0) {
            printVermelho("\nDesculpe, não conhecemos o prato [");
            printf("%i", index);
            printVermelho("]. Digite novamente: ");
            scanf("%i", &index);
        }
    }
    p.qtdPratos = p.qtdPratos - 1;
    p.pratos = realloc(p.pratos, sizeof(ItemCardapio) * p.qtdPratos);

    atual->item = p;
    printVerde("\nPratos removidos no pedido [");
    printf("%i", idPedido);
    printVerde("]!\n");

    listarPedidosLista(*cabeca);

}