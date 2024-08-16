#include <stdio.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/cores.h"
#include "../include/cardapio.h"

Cardapio montarCardapio() {
    
    Cardapio cardapio;

    char entradas[5][20] = { "Sopa de Cebola", "Salada Caesar", "Bruschetta", "Carpaccio de Carne", "Camarão ao Alho" };
    char pratosPrincipais[5][30] = { "Lasanha à Bolonhesa", "Filé Mignon com Fritas", "Frango Grelhado com Legumes", "Bacalhau à Gomes de Sá", "Risoto de Cogumelos" };
    char sobremesas[5][50] = { "Tiramisu", "Cheesecake de Frutas Vermelhas", "Mousse de Chocolate", "Pudim de Leite", "Sorvete de Baunilha com Calda de Morango" };

    for(int i = 0; i < 5; i++) {
        cardapio.pratos[i].id = i + 1;
        strcpy(cardapio.pratos[i].tipo, "Entrada");
        strcpy(cardapio.pratos[i].nomePrato, entradas[i]);

        cardapio.pratos[i+5].id = i + 6;
        strcpy(cardapio.pratos[i+5].tipo, "Prato Principal");
        strcpy(cardapio.pratos[i+5].nomePrato, pratosPrincipais[i]);

        cardapio.pratos[i+10].id = i + 11;
        strcpy(cardapio.pratos[i+10].tipo, "Sobremesa");
        strcpy(cardapio.pratos[i+10].nomePrato, sobremesas[i]);
    }

    return cardapio;
}


void listarCardapio(Cardapio *cardapio)  { 

    printMagenta("ENTRADAS:\n");
    for(int i = 0; i < 5; i++) { 
        if(strcmp(cardapio->pratos[i].tipo, "Entrada") == 0) {
            printf("%i. %s\n", cardapio->pratos[i].id, cardapio->pratos[i].nomePrato);
        }
    }

    printMagenta("\nPRATOS PRINCIPAIS:\n");
    for(int i = 5; i < 10; i++) { 
        if(strcmp(cardapio->pratos[i].tipo, "Prato Principal") == 0) {
            printf("%i. %s\n", cardapio->pratos[i].id, cardapio->pratos[i].nomePrato);
        }
    }

    printMagenta("\nSOBREMESAS:\n");
    for(int i = 10; i < 15; i++) { 
        if(strcmp(cardapio->pratos[i].tipo, "Sobremesa") == 0) {
            printf("%i. %s\n", cardapio->pratos[i].id, cardapio->pratos[i].nomePrato);
        }
    }
    printf("\n");
}