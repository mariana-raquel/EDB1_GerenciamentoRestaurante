#include <stdio.h>
#include <errno.h>
#include <string.h>

void printVermelho(char valor[]) {
    printf("\033[0;31m");
    printf("%s", valor);
    printf("\033[0m");
}


void printVerde(char valor[]) {
    printf("\033[0;32m");
    printf("%s", valor);
    printf("\033[0m");
}

void printAmarelo(char valor[]) {
    printf("\033[0;33m");
    printf("%s", valor);
    printf("\033[0m");
}

void printAzul(char valor[]) {
    printf("\033[0;34m");
    printf("%s", valor);
    printf("\033[0m");
}

void printMagenta(char valor[]) {
    printf("\033[0;35m");
    printf("%s", valor);
    printf("\033[0m");
}

void printCiano(char valor[]) {
    printf("\033[0;36m");
    printf("%s", valor);
    printf("\033[0m");
}
