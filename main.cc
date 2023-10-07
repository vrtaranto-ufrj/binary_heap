#include <iostream>

#include "binary_heap.hh"

using namespace std;

int main() {
    BinaryHeap heap( 5 );

    pair<float,int> node( 10, 0 );
    heap.inserir( node );

    node.first = 7;
    heap.inserir( node );

    node.first = 11;
    heap.inserir( node );

    node.first = 5;
    heap.inserir( node );

    node.first = 13;
    heap.inserir( node );

    cout << heap.getMin().first << endl;
    cout << heap.getMin().first << endl;
    cout << heap.getMin().first << endl;
    cout << heap.getMin().first << endl;

    return 0;
}