#include <stdio.h>
#include "../include/structs.h"
#include "../include/adicionarPedido.h"
#include "../include/removerPedido.h"
#include "../include/processarPedido.h"
#include "../include/listarPedidosPendentes.h"
#include "../include/listarPedidosProcessamento.h"

/*
    Observações:
        1. Certifique-se de que a implementação da lista ligada e da fila esteja correta e eficiente.
        2. O sistema deve lidar adequadamente com tentativas de remoção de pratos que não existem na lista ligada.
        3. Inclua uma interface de usuário que permita a interação fácil com as funcionalidades do sistema.
        4. O código deve ser bem comentado e documentado para facilitar a compreensção e manutenção.
        5. Modularize o projeto (.c, .h e makefile).
 */

int maisOpcoes() {
    int opcao = 0;
    printf("\nDeseja utilizar alguma outra funcionalidade?\n");
    printf("1 - Sim\t\t7 - Não\n\n");
    scanf("%i", &opcao);
    return opcao-1;
}

int main() {
    No *cabecaLista = NULL;

    int opcao = 0;

    while(opcao < 1 || opcao > 6) {
        printf("\nInforme qual funcionalidade deseja utilizar:\n");
        printf("1 - Adicionar um pedido\t\t\t");
        printf("2 - Remover um pedido\n");
        printf("3 - Processar um pedido\t\t\t");
        printf("4 - Listar os pedidos pendentes\n");
        printf("5 - Listar os pedidos em processamento  ");
        printf("6 - Sair\n\n");

        scanf("%i", &opcao);
        if(opcao >= 1 && opcao <= 6) {
            switch (opcao) {
                case 1:
                    printf("Você escolheu a opção: 1 - Adicionar um pedido\n\n");
                    adicionarPedido(&cabecaLista);
                    opcao = maisOpcoes();
                    break;
                case 2:
                    printf("Você escolheu a opção: 2 - Remover um pedido\n\n");
                    removerPedido(&cabecaLista);
                    opcao = maisOpcoes();
                    break;
                case 3:
                    printf("Você escolheu a opção: 3 - Processar um pedido\n\n");
                    processarPedido();
                    opcao = maisOpcoes();
                    break;
                case 4:
                    printf("Você escolheu a opção: 4 - Listar os pedidos pendentes\n\n");
                    listarPedidosPendentes(cabecaLista);
                    opcao = maisOpcoes();
                    break;
                case 5:
                    printf("Você escolheu a opção: 5 - Listar os pedidos em processamento\n\n");
                    listarPedidosEmProcessamento();
                    opcao = maisOpcoes();
                    break;
                case 6:
                    printf("Você escolheu a opção: 6 - Sair\n\n");
                default:
                    break;
            }
        }
    }

    return 0;
}
