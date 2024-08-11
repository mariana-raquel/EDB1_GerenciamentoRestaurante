PROG = main
CC = gcc
FLAGS = -I. -W -o
OBJSDIR = bin/main.o bin/adicionarPedido.o bin/removerPedido.o bin/processarPedido.o bin/listarPedidosPendentes.o bin/listarPedidosProcessamento.o bin/cardapio.o
OBJS = main.o adicionarPedido.o removerPedido.o processarPedido.o listarPedidosPendentes.o listarPedidosProcessamento.o cardapio.o

$(PROG) : $(OBJS)
	$(CC) $(FLAGS) bin/$(PROG) $(OBJSDIR)

main.o: src/main.c
	$(CC) $(FLAGS) bin/main.o -c src/main.c

adicionarPedido.o: src/adicionarPedido.c
	$(CC) $(FLAGS) bin/adicionarPedido.o -c src/adicionarPedido.c

removerPedido.o: src/removerPedido.c
	$(CC) $(FLAGS) bin/removerPedido.o -c src/removerPedido.c

processarPedido.o: src/processarPedido.c
	$(CC) $(FLAGS) bin/processarPedido.o -c src/processarPedido.c

listarPedidosPendentes.o: src/listarPedidosPendentes.c
	$(CC) $(FLAGS) bin/listarPedidosPendentes.o -c src/listarPedidosPendentes.c

listarPedidosProcessamento.o: src/listarPedidosProcessamento.c
	$(CC) $(FLAGS) bin/listarPedidosProcessamento.o -c src/listarPedidosProcessamento.c

cardapio.o: src/cardapio.c
	$(CC) $(FLAGS) bin/cardapio.o -c src/cardapio.c

clean:
	rm -rf bin/*.o bin/main 