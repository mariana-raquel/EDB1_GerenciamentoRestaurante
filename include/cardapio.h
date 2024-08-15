#ifndef CARDAPIO_H
#define CARDAPIO_H

#include "structs.h"

Cardapio montarCardapio();

void listarCardapio(Cardapio *cardapio);

int buscarPrato(char prato[50], Cardapio *cardapio);

#endif