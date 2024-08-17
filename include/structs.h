#ifndef STRUCTS_H
#define STRUCTS_H


/**
 * Estrutura responsável por armazenar 
 * as informações de um prato
 */
typedef struct itemCardapio {
    int codigo;
    char nomePrato[50];
    char tipo[16];
} ItemCardapio;


/**
 * Estrutura responsável por agrupar 
 * os pratos disponíveis
 */
typedef struct cardapio {
    ItemCardapio pratos[15];
} Cardapio;


/**
 * Estrutura responsável por armazenar 
 * as informações de um pedido
 */
typedef struct pedido {
    ItemCardapio *pratos;
    int qtdPratos;;
} Pedido; 


/**
 * Estrutura responsável por representar 
 * os Nós que compõe a lista
 */
typedef struct no {
    Pedido pedido;
    int idPedido;
    struct no *proximo;
} No;


/**
 * Estrutura responsável por representar
 * a estrutura da Fila
 */
typedef struct Fila {
  No *inicio;
  No *fim;
} Fila;

#endif