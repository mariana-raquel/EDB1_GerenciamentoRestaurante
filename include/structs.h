#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct itemCardapio {
    int id;
    char nomePrato[50];
    char tipo[16];
} ItemCardapio;

typedef struct cardapio {
    ItemCardapio pratos[15];
} Cardapio;

typedef struct pedido {
    ItemCardapio *pratos;
    int qtdPratos;
} Pedido; 

struct no {
    Pedido item;
    int idPedido;
    struct no *proximo;
};

typedef struct no No;

#endif