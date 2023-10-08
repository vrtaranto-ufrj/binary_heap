#ifndef BINARY_HEAP_HH
#define BINARY_HEAP_HH

#include <vector>
#include <utility>


using namespace std;


class BinaryHeap {
    public:
        BinaryHeap( int tamanho );

        void inserir( pair<float,int> );
        pair<float,int> getMin();
        bool isVazio();

    private:
        int ultimo;
        int tamanho;

        vector<pair<float,int>> array;
        int calculaPai( int posicao );
        pair<int,int> calculaFilhos( int posicao );
        bool isMenor( int posicao1, int posicao2 );
        void swap( int posicao1, int posicao2 );
};

#endif