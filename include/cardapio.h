typedef struct itemCardapio {
    int id;
    char nomePrato[50];
} ItemCardapio;

typedef struct cardapio {
    ItemCardapio entradas[5];
    ItemCardapio pratosPrincipais[5];
    ItemCardapio sobremesas[5];
} Cardapio;

Cardapio montarCardapio();

void listarCardapio(Cardapio *cardapio);