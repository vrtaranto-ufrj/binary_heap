#include <iostream>

#include "binary_heap.hh"

using namespace std;

int main() {
    BinaryHeap heap( 10 );

    
    pair<float,int> node( 10, 0 );
    heap.push( node );
    

    node.first = 7;
    node.second = 1;
    heap.push( node );

    node.first = 11;
    node.second = 2;
    heap.push( node );

    node.first = 5;
    node.second = 3;
    heap.push( node );

    node.first = 13;
    node.second = 4;
    heap.push( node );

    heap.decreaseKey( 0, 3 );
    heap.decreaseKey( 2, 4 );

    node.first = 2;
    node.second = 5;
    heap.push( node );

    heap.decreaseKey( 4, 1 );

    cout << heap.top().first << endl;
    heap.pop();
    cout << heap.top().first << endl;
    heap.pop();
    cout << heap.top().first << endl;
    heap.pop();
    cout << heap.top().first << endl;
    heap.pop();
    cout << heap.top().first << endl;
    heap.pop();
    cout << heap.empty() << endl;

    return 0;
}