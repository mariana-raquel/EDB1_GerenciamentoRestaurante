# Sistema de Gerenciamento de Pedidos de Restaurante

## Sumário:
* **[Descrição](#descrição)**
* **[Funcionalidades](#funcionalidades)**
* **[Como executar?](#como-executar)**
* **[Discente](#discente)**

## Descrição:
Desenvolver um sistema para gerenciar os pedidos de um restaurante, onde os pedidos são armazenados em uma lista ligada e, posteriormente, processados pela cozinha em ordem de chegada utilizando uma fila. A implementação deve ser feita na linguagem C.

O detalhamento do projeto encontra-se __*[aqui](./docs/projeto_1.pdf)*__.

## Funcionalidades:

### 1 - Adicionar um pedido:
Permite o usuário adicionar um novo pedido na lista, contendo a quantidade de pratos que ele desejar. Ao selecionar essa opção, o cardápio será exibido para exibir os pratos disponíveis para escolha.

### 2 - Remover um pedido:
Permite o usuário remover um pedido da lista. Ao selecionar essa opção, a lista dos pedidos pendentes será exibida, permitindo o usuário selecionar qual pedido irá remover.

### 3 - Adicionar prato(s) a um pedido:
Permite o usuário adicionarem outros pratos em algum pedido já existente. Ao selecionar essa opção, a lista dos pedidos pendentes será exibida, permitindo o usuário selecionar em qual pedido deseja acrescentar os pratos, e depois exibe o cardápio.

### 4 - Remover prato de um pedido:
Permite o usuário remover um prato de algum pedido já existente. Ao selecionar essa opção, a lista dos pedidos pendentes será exibida, permitindo o usuário selecionar de qual pedido deseja remover o prato. Depois disso, o pedido escolhido é mostrado, permitindo o usuário selecionar qual prato irá remover, se o pedido tiver apenas um prato, o pedido em si também será removido.

### 5 - Processar um pedido:
Permite o usuário processar um pedido. Ao fazer isso, o pedido mais antigo presente na lista de espera, será removido e adicionado na fila de processamento.

### 6 - Listar os pedidos pendentes:
Permite o usuário listar os pedidos pendentes.

### 7 - Listar os pedidos em processamento:
Permite o usuário listar os pedidos que estão na fila de processamento.


## Como executar?
Para compilar o projeto, no diretório base, execute:

``` 
$ make 
```
Para executar o projeto, utilize:
```
$ ./bin/gerenciador_restaurante
```
ou:
```
$ cd bin
$ ./gerenciador_restaurante
```
Obs.: Certifique-se de que possui o `gcc` e o `make` instalados.

> Para limpar os arquivos gerados durante a compilação (.o), juntamente com o executável:
> * make clean

## Discente:
Mariana Raquel de Morais (20230033690)