#include <vector>
#include <utility>
#include <iostream>

#include "binary_heap.hh"

using namespace std;

BinaryHeap::BinaryHeap( int tamanho ) : array( tamanho ), ultimo( -1 ) {
    this->tamanho = tamanho;
}

void BinaryHeap::inserir( pair<float,int> no ) {
    int posicao = ++ultimo;
    array.at( posicao ) = no;
    
    if ( posicao > tamanho ) {
        cerr << "Erro! Heap já está cheio!" << endl;
        return;
    }

    int pai = calculaPai( posicao );

    while ( isMenor( posicao, pai ) && posicao != 0 ) {
        swap( posicao, pai );
        posicao = pai;
        pai = calculaPai( posicao );
    }
    
}

pair<float,int> BinaryHeap::getMin() {
    int posicao = 0;
    pair<float,int> menor = array.at( 0 );
    pair<int,int> filhos;

    array.at( 0 ) = array.at( ultimo-- );

    filhos = calculaFilhos( posicao );

    while ( filhos.first < ultimo || filhos.second < ultimo ) {
        if ( isMenor( filhos.first, posicao ) ) {
            swap( filhos.first, posicao );
            posicao = filhos.first;
            filhos = calculaFilhos( posicao );
        } else if ( isMenor( filhos.second, posicao ) ) {
            swap( filhos.second, posicao );
            posicao = filhos.second;
            filhos = calculaFilhos( posicao );
        }
        else
            break;
    }

    return menor;
}

int BinaryHeap::calculaPai( int posicao ) {
    if ( posicao % 2 == 0 )
        return ( posicao - 1 ) / 2;
    else
        return posicao / 2;
}

pair<int,int> BinaryHeap::calculaFilhos( int posicao ) {
    pair<int, int> filhos;
    posicao++;
    filhos.second = posicao * 2;
    filhos.first = filhos.second - 1;

    return filhos;
}

bool BinaryHeap::isMenor( int posicao1, int posicao2 ) {
    return array.at( posicao1 ).first < array.at( posicao2 ).first;
}

void BinaryHeap::swap( int posicao1, int posicao2 ) {
    pair<float,int> auxiliar = array.at( posicao1 );
    array.at( posicao1 ) = array.at( posicao2 );
    array.at( posicao2 ) = auxiliar;
}