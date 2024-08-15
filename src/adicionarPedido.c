#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/cardapio.h"
#include "../include/listarPedidosPendentes.h"

#include "../include/adicionarPedido.h"

/*
    Funcionalidades:
    * Permitir que o cliente adicione um novo pedido.
    * Armazenar o pedido na lista ligada de pedidos pendentes.

    Requisitos:
    * A função deve permitir que o cliente adicione um ou mais pratos ao pedido.
    * Cada pedido deve ser representado como um nó na lista ligada.
*/

void adicionarPedido(No **cabeca) {
    int maisPedidos = 1;
    
    Cardapio cardapio = montarCardapio();
    printf("Este é o nosso cardápio:\n\n");
    listarCardapio(&cardapio);
    
    while(maisPedidos == 1) {
        Pedido p;
        
        int qtdPratos = 0;
        printf("Quantos pratos você deseja acrescentar no pedido? ");
        scanf("%i", &qtdPratos);
        p.qtdPratos = qtdPratos;
        p.pratos = malloc(sizeof(ItemCardapio) * qtdPratos);

        printf("\nPor favor, nos informe os ids do prato que deseja pedir (separados por espaço): ");
        int index = -1;
        for(int i = 0; i < qtdPratos; i++) {
            scanf("%i", &index);
            while(index < 1 || index > 15) {
                printf("\nDesculpe, não conhecemos o prato [%i]. Digite novamente:\n", index);
                scanf("%i", &index);
            }
            p.pratos[i].id = cardapio.pratos[index-1].id;
            strcpy(p.pratos[i].nomePrato, cardapio.pratos[index-1].nomePrato);
            strcpy(p.pratos[i].tipo, cardapio.pratos[index-1].tipo);
        }
        
        insercaoNoInicio(cabeca, p);
        listarPedidosPendentes(*cabeca);

        printf("\nDeseja fazer mais algum pedido?\n");
        printf("1 - Sim\t\t2- Não\n");
        scanf("%i", &maisPedidos);
    }

}