#include <iostream>

#include "binary_heap.hh"

using namespace std;

int main() {
    BinaryHeap heap( 5 );

    
    pair<float,int> node( 10, 0 );
    heap.push( node );
    

    node.first = 7;
    heap.push( node );

    node.first = 11;
    heap.push( node );

    node.first = 5;
    heap.push( node );

    node.first = 13;
    heap.push( node );

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