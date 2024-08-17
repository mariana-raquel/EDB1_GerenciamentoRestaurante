#include <stdio.h>

/**
 * Método responsável por personalizar
 * os prints com a cor Vermelha.
 */
void printVermelho(char valor[]) {
    printf("\033[0;31m");
    printf("%s", valor);
    printf("\033[0m");
}


/**
 * Método responsável por personalizar
 * os prints com a cor Verde.
 */
void printVerde(char valor[]) {
    printf("\033[0;32m");
    printf("%s", valor);
    printf("\033[0m");
}


/**
 * Método responsável por personalizar
 * os prints com a cor Amarela.
 */
void printAmarelo(char valor[]) {
    printf("\033[0;33m");
    printf("%s", valor);
    printf("\033[0m");
}


/**
 * Método responsável por personalizar
 * os prints com a cor Azul.
 */
void printAzul(char valor[]) {
    printf("\033[0;34m");
    printf("%s", valor);
    printf("\033[0m");
}


/**
 * Método responsável por personalizar
 * os prints com a cor Magenta.
 */
void printMagenta(char valor[]) {
    printf("\033[0;35m");
    printf("%s", valor);
    printf("\033[0m");
}


/**
 * Método responsável por personalizar
 * os prints com a cor Ciano.
 */
void printCiano(char valor[]) {
    printf("\033[0;36m");
    printf("%s", valor);
    printf("\033[0m");
}
