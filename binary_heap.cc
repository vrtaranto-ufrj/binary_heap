#include <vector>
#include <utility>
#include <iostream>

#include "binary_heap.hh"

using namespace std;

BinaryHeap::BinaryHeap( int tamanho ) : ultimo( -1 ), tamanho( tamanho ), array( tamanho ) {
}

void BinaryHeap::inserir( pair<float,int> node ) {
    int posicao = ++ultimo;
    
    
    if ( posicao > tamanho ) {
        cerr << "Erro! Heap já está cheio!" << endl;
        return;
    }

    array.at( posicao ) = node;

    int pai = calculaPai( posicao );

    while ( isMenor( posicao, pai ) && posicao != 0 ) {
        swap( posicao, pai );
        posicao = pai;
        pai = calculaPai( posicao );
    }
    
}

pair<float,int> BinaryHeap::getMin() {
    if ( ultimo == -1 ) {
        cerr << "Erro! Heap já está vazio!" << endl;
        return pair<float,int>( -1, -1 );
    }
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

bool BinaryHeap::isVazio() {
    return ultimo == -1;
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