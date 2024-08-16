#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/cores.h"
#include "../include/cardapio.h"
#include "../include/lista.h"
#include "../include/adicionarPedido.h"


void adicionarPedido(No **cabeca) {
    int maisPedidos = 1;
    
    Cardapio cardapio = montarCardapio();
    printAmarelo("Este é o nosso cardápio:\n\n");
    listarCardapio(&cardapio);
    
    while(maisPedidos == 1) {
        Pedido p;
        
        int qtdPratos = 0;
        printCiano("Quantos pratos você deseja adicionar no pedido? ");
        scanf("%i", &qtdPratos);
        
        if(qtdPratos > 0) {

            p.qtdPratos = qtdPratos;
            p.pratos = malloc(sizeof(ItemCardapio) * qtdPratos);

            printCiano("\nPor favor, nos informe os ids do prato que deseja pedir (separados por espaço): ");
            int index = -1;
            for(int i = 0; i < qtdPratos; i++) {
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
        
            inserirPedidoLista(cabeca, p);
            listarPedidosLista(*cabeca);
        }

        printCiano("\nDeseja fazer mais algum pedido?\n");
        printCiano("1 - Sim\t\t2- Não\n");
        scanf("%i", &maisPedidos);
        printf("\n");
    }

}