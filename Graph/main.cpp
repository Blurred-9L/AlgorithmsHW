#include <iostream>
#include <vector>

#include "Digraph.h"

using namespace std;

int main(){
    Digraph<int, int> d;
    vector<int> order;
    
    d.addNode( 1 );
    d.addNode( 2 );
    d.addNode( 3 );
    d.addNode( 4 );
    
    cout << boolalpha;
    cout << "Node 1 is on index: " << d.getIndex( 1 ) << endl;
    cout << "Node 2 is on index: " << d.getIndex( 2 ) << endl;
    cout << "Node 3 is on index: " << d.getIndex( 3 ) << endl;
    cout << "Node 4 is on index: " << d.getIndex( 4 ) << endl;
    
    cout << "Erasing node 1... " << d.eraseNode( 1 ) << endl;
    
    cout << "What is on index 1? " << d.getNodeByIndex( 1 ) -> tag() << endl;
    cout << "Erasing node at index 1... " << d.eraseNodeByIndex( 1 ) << endl;
    cout << "What is on index 1? " << d.getNodeByIndex( 1 ) -> tag() << endl;
    cout << "Erasing node at index 0... " << d.eraseNodeByIndex( 0 ) << endl;
    
    d.eraseNodes();
    d.eraseAllEdges();
    
    cout << d.addNode( 1 ) << endl;
    cout << d.addNode( 2 ) << endl;
    cout << d.addNode( 3 ) << endl;
    cout << d.addNode( 4 ) << endl;
    
    cout << d.getIndex( 1 ) << endl;
    cout << d.getIndex( 2 ) << endl;
    cout << d.getIndex( 3 ) << endl;
    cout << d.getIndex( 4 ) << endl;
    
    cout << d.addEdge( 12, d.getIndex( 1 ), d.getIndex( 2 ) ) << endl;
    cout << d.addEdge( 14, d.getIndex( 1 ), d.getIndex( 4 ) ) << endl;
    cout << d.addEdge( 23, d.getIndex( 2 ), d.getIndex( 3 ) ) << endl;
    cout << d.addEdge( 31, d.getIndex( 3 ), d.getIndex( 1 ) ) << endl;
    cout << d.addEdge( 42, d.getIndex( 4 ), d.getIndex( 2 ) ) << endl;
    
    cout << "Amplitud: " << endl;
    d.widthFirstSearch( d.getIndex( 1 ), order );
    for( int i = 0; i < order.size(); i++ ){
        cout << order[i] << " ";
    }
    cout << endl << endl;
    
    order.clear();
    cout << "Profundidad: " << endl;
    d.depthFirstSearch( d.getIndex( 1 ), order );
    for( int i = 0; i < order.size(); i++ ){
        cout << order[i] << " ";
    }
    cout << endl;
    
    return 0;
}
