#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/cores.h"
#include "../include/structs.h"
#include "../include/lista.h"
#include "../include/pedido.h"
#include "../include/cardapio.h"


/**
 * @brief Método responsável por adicionar prato(s)
 * no pedido que será informado.
 * 
 * @param cabeca
 */
void adicionarPratoNoPedido(No **cabeca) {
    if(*cabeca == NULL) {
        printAmarelo("Não existem pedidos pendentes!\n");
        return;
    }
    listarPedidosLista(*cabeca);

    int numeroPedido = -1;
    int v = 0;
    No *atual = *cabeca;
    while(v == 0) {
        printCiano("\nEm qual pedido você deseja acrescentar o(s) prato(s)? ");
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

    Cardapio cardapio = montarCardapio();
    listarCardapio(&cardapio);

    Pedido p = atual->pedido;
    int qtdPratos = 0;
    printCiano("Quantos pratos você deseja acrescentar no pedido? ");
    scanf("%i", &qtdPratos);

    if(qtdPratos > 0) {
        int aux = p.qtdPratos;
        p.qtdPratos = p.qtdPratos + qtdPratos;
        p.pratos = realloc(p.pratos, sizeof(ItemCardapio) * p.qtdPratos);

        int index = -1;
        for(int i = aux; i < p.qtdPratos; i++) {
            printCiano("Por favor, nos informe o código do");
            printf(" %iº ", i+1);
            printCiano("prato que deseja acrescentar: ");
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

        atual->pedido = p;
        printVerde("\nPratos adicionados no pedido [");
        printf("%i", numeroPedido);
        printVerde("] com sucesso!\n");

    }
}


/**
 * @brief Método responsável por remover um prato
 * no pedido que será informado.
 * 
 * @param cabeca
 */
void removerPratoDoPedido(No **cabeca) {
    if(*cabeca == NULL) {
        printAmarelo("Não existem pedidos pendentes!\n");
        return;
    }

    listarPedidosLista(*cabeca);

    int idPedido = -1;
    int v = 0;
    No *atual = *cabeca;
    while(v == 0) {
        printCiano("\nEm qual pedido você deseja remover o(s) prato(s)? ");
        scanf("%i", &idPedido);

        while(atual != NULL && atual->idPedido != idPedido){
            atual = atual->proximo;
        }

        if(atual == NULL) {
            printVermelho("\nDesculpe, não encontramos esse pedido na lista! Verifique se informou o número corretamente!\n");
            atual = *cabeca;
        } else {
            v = 1;
        }
    }

    Pedido p = atual->pedido;

    mostrarPedido(p, atual->idPedido);

    int index = -1;
    printCiano("Por favor, nos informe o código do prato que deseja remover: ");
    scanf("%i", &index);
    int cont = 0;
    if(p.qtdPratos == 1) {
        while(index != 1) {
            printVermelho("\nDesculpe, não conhecemos o prato [");
            printf("%i", index);
            printVermelho("]. Digite novamente: ");
            scanf("%i", &index);
        }
        removerPedidoLista(cabeca, atual->idPedido);
        
        printAmarelo("\nO pedido [");
        printf("%i", atual->idPedido);
        printAmarelo("] só tinha um único prato, então também foi removido!\n");

    } else {
        if(index != p.qtdPratos) {
            while(cont == 0) {
                for(int j = 0; j < p.qtdPratos-1; j++) {
                    if(index-1 == j || cont > 0) {
                        cont++;
                        p.pratos[j].codigo = p.pratos[j+1].codigo;
                        strcpy(p.pratos[j].nomePrato, p.pratos[j+1].nomePrato);
                        strcpy(p.pratos[j].tipo, p.pratos[j+1].tipo);
                    }
                }
                if(cont == 0) {
                    printVermelho("\nDesculpe, não conhecemos o prato [");
                    printf("%i", index);
                    printVermelho("]. Digite novamente: ");
                    scanf("%i", &index);
                }
            }
        }

        p.qtdPratos = p.qtdPratos - 1;
        p.pratos = realloc(p.pratos, sizeof(ItemCardapio) * p.qtdPratos);

        atual->pedido = p;
        printVerde("\nPrato removido no pedido [");
        printf("%i", idPedido);
        printVerde("]!\n");

    }
    
}