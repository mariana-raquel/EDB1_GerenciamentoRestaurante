#include <stdio.h>
#include <string.h>
#include "../include/adicionarPedido.h"
#include "../include/cardapio.h"
#include "../include/listarPedidosPendentes.h"


/*
    Funcionalidades:
    * Permitir que o cliente adicione um novo pedido.
    * Armazenar o pedido na lista ligada de pedidos pendentes.

    Requisitos:
    * A função deve permitir que o cliente adicione um ou mais pratos ao pedido.
    * Cada pedido deve ser representado como um nó na lista ligada.
*/

void adicionarPedido(No **cabeca) {
    Cardapio cardapio = montarCardapio();
    printf("Este é o nosso cardápio:\n\n");
    listarCardapio(&cardapio);
    
    printf("Por favor, nos informe o nome do prato que deseja pedir:\n");
    
    char prato[50];
    fgets(prato, 50, stdin);
    prato[strlen(prato)-1] = '\0';

    int index = buscarPrato(prato, &cardapio);
    while(index < 0) {
        printf("\nDesculpe, não encontramos o seu prato. Tente informá-lo novamente!\n");
        fgets(prato, 50, stdin);
        prato[strlen(prato)-1] = '\0';
        index = buscarPrato(prato, &cardapio);
    }
    printf("\nVocê escolheu o(a) %s %s. Iremos adicionar seu pedido!\n", cardapio.pratos[index].tipo, cardapio.pratos[index].nomePrato);
            
    insercaoNoInicio(cabeca, cardapio.pratos[index]);
    listarPedidosPendentes(*cabeca);

}