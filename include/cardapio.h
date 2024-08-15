#ifndef CARDAPIO_H
#define CARDAPIO_H

typedef struct itemCardapio {
    int id;
    char nomePrato[50];
    char tipo[16];
} ItemCardapio;

typedef struct cardapio {
    ItemCardapio pratos[15];
} Cardapio;

Cardapio montarCardapio();

void listarCardapio(Cardapio *cardapio);

int buscarPrato(char prato[50], Cardapio *cardapio);

#endif