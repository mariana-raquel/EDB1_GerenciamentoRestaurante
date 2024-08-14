#include <stdio.h>
#include <string.h>
#include "../include/cardapio.h"

Cardapio montarCardapio() {
    
    Cardapio cardapio;

    char entradas[5][20] = { "Sopa de Cebola", "Salada Caesar", "Bruschetta", "Carpaccio de Carne", "Camarão ao Alho" };
    char pratosPrincipais[5][30] = { "Lasanha à Bolonhesa", "Filé Mignon com Fritas", "Frango Grelhado com Legumes", "Bacalhau à Gomes de Sá", "Risoto de Cogumelos" };
    char sobremesas[5][50] = { "Tiramisu", "Cheesecake de Frutas Vermelhas", "Mousse de Chocolate", "Pudim de Leite", "Sorvete de Baunilha com Calda de Morango" };

    for(int i = 0; i < 5; i++) {
        cardapio.entradas[i].id = i + 1;
        strcpy(cardapio.entradas[i].nomePrato, entradas[i]);

        cardapio.pratosPrincipais[i].id = i + 1;
        strcpy(cardapio.pratosPrincipais[i].nomePrato, pratosPrincipais[i]);

        cardapio.sobremesas[i].id = i + 1;
        strcpy(cardapio.sobremesas[i].nomePrato, sobremesas[i]);
    }

    return cardapio;
}


void listarCardapio(Cardapio *cardapio)  { 

    printf("ENTRADAS:\n");
    for(int i = 0; i < 5; i++) { 
        printf("%i. %s\n", cardapio->entradas[i].id, cardapio->entradas[i].nomePrato);
    }

    printf("\nPRATOS PRINCIPAIS:\n");
    for(int i = 0; i < 5; i++) { 
        printf("%i. %s\n", cardapio->pratosPrincipais[i].id, cardapio->pratosPrincipais[i].nomePrato);
    }

    printf("\nSOBREMESAS:\n");
    for(int i = 0; i < 5; i++) { 
        printf("%i. %s\n", cardapio->sobremesas[i].id, cardapio->sobremesas[i].nomePrato);
    }
    printf("\n");
    
}