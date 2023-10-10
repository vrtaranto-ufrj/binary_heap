
# Implementação de Heap Binário em C++ para o algortimo de Dijkstra

Esse repositorio provê uma implementacão de um Heap binário em C++ visando seu uso para o algoritmo de Dijkstra.

## Visao Geral

Os pricipais componentes desse projeto são:
- `binary_heap.hh`: O arquivo Header que contêm a declaração da classe `BinaryHeap`.
- `binary_heap.cc`: O arquivo fonte da implementação da classe `BinaryHeap`.
- `main.cc`: Um simples programa que demonstra o uso da classe `BinaryHeap`.
- `Makefile`: Um makefile para compilar e rodar o programa.

## Classe BinaryHeap

A classe `BinaryHeap` oferece as seguintes funcionalidades:
- Inicializar o heap com um tamanho específico.
- Inserir um elemento no heap.
- Recuperar o elemento do topo do heap sem removê-lo.
- Remover o elemento do topo do heap.
- Checar se o heap está vazio.


## Compilação e Execução

Para compilar o programa, use:
```
make
```

Para rodar o programa compilado, use:
```
make run
```

Para limpar os arquivos compilados e executáveis, use
```
make clean
```
