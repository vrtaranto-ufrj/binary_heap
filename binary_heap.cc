#include "binary_heap.hh"
#include <iostream>

// Construtor: inicializa o heap com um tamanho definido e define 'ultimo' como -1.
BinaryHeap::BinaryHeap(int tamanho) : tamanho(tamanho), ultimo(-1), array(tamanho), mapPosicao(tamanho) {
}

// Insere um elemento no heap e ajusta o heap para manter sua propriedade.
void BinaryHeap::push(std::pair<float, int> no) {
    if (ultimo == tamanho - 1) {
        throw std::runtime_error("Erro! Heap já está cheio!");
    }
    
    array[++ultimo] = no;

    int posicao = ultimo;
    int pai = calculaPai(posicao);

    while (posicao != 0 && isMenor(posicao, pai)) {
        swap(posicao, pai);
        posicao = pai;
        pai = calculaPai(posicao);
    }
    mapPosicao[no.second] = posicao;
}

// Retorna o elemento no topo do heap.
std::pair<float, int> BinaryHeap::top() const {
    return array[0];
}

// Remove o elemento do topo e ajusta o heap.
void BinaryHeap::pop() {
    if (ultimo == -1) {
        throw std::runtime_error("Erro! Heap já está vazio!");
        return;
    }
    int posicao = 0;
    std::pair<int, int> filhos;

    array[0] = array[ultimo--];

    filhos = calculaFilhos(posicao);

    while (filhos.first <= ultimo || filhos.second <= ultimo) {
        int menorFilho;
        
        // Verifica se apenas o filho esquerdo existe ou se o filho esquerdo é menor que o filho direito
        if (filhos.second > ultimo || isMenor(filhos.first, filhos.second)) {
            menorFilho = filhos.first;
        } else {
            menorFilho = filhos.second;
        }
        
        if (isMenor(menorFilho, posicao)) {
            swap(menorFilho, posicao);
            posicao = menorFilho;
            filhos = calculaFilhos(posicao);
        } else {
            break;
        }
    }

}

void BinaryHeap::decreaseKey( int elemento, float novaChave ) {
    if ( mapPosicao.find( elemento ) == mapPosicao.end() ) {
        throw std::runtime_error("Erro! Elemento não está no heap!");
        return;
    }
    
    int posicao = mapPosicao[elemento];
    if ( array[posicao].first <= novaChave ) {
        throw std::runtime_error("Erro! Nova chave não é menor que a chave atual!");
        return;
    }
    array[posicao].first = novaChave;
    int pai = calculaPai(posicao);

    while ( posicao != 0 && isMenor(posicao, pai) ) {
        swap(posicao, pai);
        posicao = pai;
        pai = calculaPai(posicao);
    }
}


// Verifica se o heap está vazio.
bool BinaryHeap::empty() const {
    return ultimo == -1;
}

// Calcula o índice do pai de um elemento específico no heap.
int BinaryHeap::calculaPai(int posicao) const {
    return (posicao - 1) / 2;
}

// Calcula os índices dos filhos de um elemento específico no heap.
std::pair<int, int> BinaryHeap::calculaFilhos(int posicao) const {
    return std::make_pair(2 * posicao + 1, 2 * posicao + 2);
}

// Compara dois elementos no heap e retorna 'true' se o elemento na 'posicao1' for menor.
bool BinaryHeap::isMenor(int posicao1, int posicao2) const {
    return array[posicao1].first < array[posicao2].first;
}

// Troca a posição de dois elementos no heap.
void BinaryHeap::swap(int posicao1, int posicao2) {
    std::pair<float, int> temp = array[posicao1];
    array[posicao1] = array[posicao2];
    array[posicao2] = temp;
    mapPosicao[array[posicao1].second] = posicao1;
    mapPosicao[array[posicao2].second] = posicao2;
}
