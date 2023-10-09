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
        bool isVazio() const;

    private:
        int ultimo;
        int tamanho;

        vector<pair<float,int>> array;
        inline int calculaPai( int posicao ) const;
        inline pair<int,int> calculaFilhos( int posicao ) const;
        bool isMenor( int posicao1, int posicao2 );
        void swap( int posicao1, int posicao2 );
};

#endif