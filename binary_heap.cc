#include "binary_heap.hh"

// Construtor: inicializa o heap com um tamanho definido e define 'ultimo' como -1.
BinaryHeap::BinaryHeap(int tamanho) : tamanho(tamanho), ultimo(-1), array(tamanho) {
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
        if (isMenor(filhos.first, posicao)) {
            swap(filhos.first, posicao);
            posicao = filhos.first;
            filhos = calculaFilhos(posicao);
        } else if (isMenor(filhos.second, posicao)) {
            swap(filhos.second, posicao);
            posicao = filhos.second;
            filhos = calculaFilhos(posicao);
        }
        else
            break;
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
}
