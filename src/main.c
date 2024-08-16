#include <stdio.h>
#include "../include/structs.h"
#include "../include/adicionarPedido.h"
#include "../include/pedido.h"
#include "../include/lista.h"
#include "../include/fila.h"
#include "../include/cores.h"


int maisOpcoes() {
    int opcao = 0;
    printCiano("\nDeseja utilizar alguma outra funcionalidade?\n");
    printCiano("1 - Sim\t\t2 - Não\n");
    scanf("%i", &opcao);
    return opcao == 1 ? 0 : 6;
}

int main() {
    int opcao = 0;
    Fila fila;
    iniciarFila(&fila);
    No *cabecaLista = NULL;

    while(opcao < 1 || opcao > 6) {
        printCiano("\nInforme qual funcionalidade deseja utilizar:\n");
        printCiano("1 - Adicionar um pedido\t\t\t");
        printCiano("5 - Processar um pedido\n");
        printCiano("2 - Remover um pedido\t\t\t");
        printCiano("6 - Listar os pedidos pendentes\n");
        printCiano("3 - Adicionar prato a um pedido\t\t");
        printCiano("7 - Listar os pedidos em processamento\n");
        printCiano("4 - Remover prato de um pedido\t\t");
        printCiano("8 - Sair\n");

        scanf("%i", &opcao);
        if(opcao >= 1 && opcao <= 7) {
            switch (opcao) {
                case 1:
                    printVerde("Você escolheu a opção: 1 - Adicionar um pedido\n\n");
                    adicionarPedido(&cabecaLista);
                    opcao = maisOpcoes();
                    break;
                case 2:
                    printVerde("Você escolheu a opção: 2 - Remover um pedido\n\n");
                    removerPedido(&cabecaLista);
                    opcao = maisOpcoes();
                    break;
                case 3:
                    printVerde("Você escolheu a opção: 3 - Adicionar prato a um pedido\n\n");
                    adicionarPratoNoPedido(&cabecaLista);
                    opcao = maisOpcoes();
                    break;
                case 4:
                    printVerde("Você escolheu a opção: 4 - Remover prato de um pedido\n\n");
                    removerPratoDoPedido(&cabecaLista);
                    opcao = maisOpcoes();
                    break;
                case 5:
                    printVerde("Você escolheu a opção: 5 - Processar um pedido\n\n");
                    processarPedido(&cabecaLista, &fila);
                    opcao = maisOpcoes();
                    break;
                case 6:
                    printVerde("Você escolheu a opção: 6 - Listar os pedidos pendentes\n\n");
                    listarPedidosLista(cabecaLista);
                    opcao = maisOpcoes();
                    break;
                case 7:
                    printVerde("Você escolheu a opção: 7 - Listar os pedidos em processamento\n");
                    listarPedidosFila(&fila);
                    opcao = maisOpcoes();
                    break;
                case 8:
                    printVerde("Você escolheu a opção: 8 - Sair\n");
                    printVerde("Obrigado por utilizar nosso serviços!\n\n");
                    break;
                default:
                    break;
            }
        } else {
            printVermelho("Escolha uma opção válida!\n");
        }
    }

    return 0;
}
