#include <stdio.h>
#include "../include/structs.h"
#include "../include/prato.h"
#include "../include/pedido.h"
#include "../include/lista.h"
#include "../include/fila.h"
#include "../include/cores.h"


/**
 * @brief Método responsável por verificar se o usuário
 * deseja utilizar outra funcionalidade.
 * 
 * @return
 */
int maisOpcoes() {
    int opcao = 0;
    printCiano("\nDeseja utilizar alguma outra funcionalidade?\n");
    printCiano("1 - Sim\t\t2 - Não\n");
    scanf("%i", &opcao);
    return opcao == 1 ? 0 : 8;
}


/**
 * @brief Método principal do programa contendo o menu 
 * com as funcionalidades disponíveis.
 * 
 * @return
 */
int main() {
    int opcao = 0;
    Fila fila;
    iniciarFila(&fila);
    No *cabeca = NULL;

    while(opcao < 1 || opcao > 8) {
        printCiano("\nInforme qual funcionalidade deseja utilizar:\n");
        printCiano("1 - Adicionar um pedido\t\t\t");
        printCiano("5 - Processar um pedido\n");
        printCiano("2 - Remover um pedido\t\t\t");
        printCiano("6 - Listar os pedidos pendentes\n");
        printCiano("3 - Adicionar prato(s) a um pedido\t");
        printCiano("7 - Listar os pedidos em processamento\n");
        printCiano("4 - Remover prato de um pedido\t\t");
        printCiano("8 - Sair\n");

        scanf("%i", &opcao);
        if(opcao >= 1 && opcao <= 8) {
            switch (opcao) {
                case 1:
                    printVerde("Você escolheu a opção: 1 - Adicionar um pedido\n");
                    adicionarPedido(&cabeca);
                    opcao = maisOpcoes();
                    break;
                case 2:
                    printVerde("Você escolheu a opção: 2 - Remover um pedido\n\n");
                    removerPedido(&cabeca);
                    opcao = maisOpcoes();
                    break;
                case 3:
                    printVerde("Você escolheu a opção: 3 - Adicionar prato a um pedido\n\n");
                    adicionarPratoNoPedido(&cabeca);
                    opcao = maisOpcoes();
                    break;
                case 4:
                    printVerde("Você escolheu a opção: 4 - Remover prato de um pedido\n\n");
                    removerPratoDoPedido(&cabeca);
                    opcao = maisOpcoes();
                    break;
                case 5:
                    printVerde("Você escolheu a opção: 5 - Processar um pedido\n\n");
                    processarPedido(&cabeca, &fila);
                    opcao = maisOpcoes();
                    break;
                case 6:
                    printVerde("Você escolheu a opção: 6 - Listar os pedidos pendentes\n\n");
                    listarPedidosLista(cabeca);
                    opcao = maisOpcoes();
                    break;
                case 7:
                    printVerde("Você escolheu a opção: 7 - Listar os pedidos em processamento\n\n");
                    listarPedidosFila(&fila);
                    opcao = maisOpcoes();
                    break;
                case 8:
                    printVerde("Você escolheu a opção: 8 - Sair\n");
                    break;
                default:
                    break;
            }
        } else {
            printVermelho("Escolha uma opção válida!\n");
        }
    }
    printMagenta("\nObrigado por utilizar nosso serviços!\n\n");

    return 0;
}
