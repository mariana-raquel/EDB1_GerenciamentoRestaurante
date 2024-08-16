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

typedef struct no {
    Pedido item;
    int idPedido;
    struct no *proximo;
} No;

typedef struct Fila {
  No *inicio;
  No *fim;
} Fila;

#endif