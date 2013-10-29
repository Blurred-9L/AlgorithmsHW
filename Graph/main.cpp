#include <iostream>
#include <vector>
#include <climits>

#include "Digraph.h"
#include "Graph.h"
#include "GraphEdge.h"

using namespace std;

void testDigraph(){
    Digraph<int, int> d;
    vector<int> order;
    int i, j, size;
    int** matrix;
    unsigned* distances;
    
    cout << "Testing Digraph:" << endl;
    
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
    order.clear();
    
    size = d.getNumNodes();
    matrix = d.getAdjMatrix();
    for( i = 0; i < size; i++ ){
        for( j = 0; j < size; j++ ){
            cout.width( 3 );
            if( matrix[i][j] != INT_MAX ){
                cout << matrix[i][j];
            }
            else{
                cout << 'x';
            }
        }
        delete[] matrix[i];
        cout << endl;
    }
    delete[] matrix;
    
    cout << "Erasing all nodes and edges..." << endl;
    d.eraseAllEdges();
    d.eraseNodes();
    
    cout << d.addNode( 1 ) << endl;
    cout << d.addNode( 2 ) << endl;
    cout << d.addNode( 3 ) << endl;
    cout << d.addNode( 4 ) << endl;
    cout << d.addNode( 5 ) << endl;
    
    cout << d.addEdge( 12, d.getIndex( 1 ), d.getIndex( 2 ), 4 ) << endl;
    cout << d.addEdge( 13, d.getIndex( 1 ), d.getIndex( 3 ), 11 ) << endl;
    cout << d.addEdge( 24, d.getIndex( 2 ), d.getIndex( 4 ), 6 ) << endl;
    cout << d.addEdge( 25, d.getIndex( 2 ), d.getIndex( 5 ), 2 ) << endl;
    cout << d.addEdge( 32, d.getIndex( 3 ), d.getIndex( 2 ), 3 ) << endl;
    cout << d.addEdge( 34, d.getIndex( 3 ), d.getIndex( 4 ), 6 ) << endl;
    cout << d.addEdge( 53, d.getIndex( 5 ), d.getIndex( 3 ), 5 ) << endl;
    cout << d.addEdge( 54, d.getIndex( 5 ), d.getIndex( 4 ), 3 ) << endl;
    
    size = d.getNumNodes();
    matrix = d.getAdjMatrix();
    for( i = 0; i < size; i++ ){
        for( j = 0; j < size; j++ ){
            cout.width( 3 );
            if( matrix[i][j] != INT_MAX ){
                cout << matrix[i][j];
            }
            else{
                cout << 'x';
            }
        }
        delete[] matrix[i];
        cout << endl;
    }
    delete[] matrix;
    
    cout << "Dijkstra start on 1:" << endl;
    distances = d.dijkstra( d.getIndex( 1 ) );
    for( i = 0; i < size; i++ ){
        cout.width( 3 );
        cout << distances[i];
    }
    cout << endl;
    delete[] distances;
    
    cout << "Floyd:" << endl;
    matrix = d.floyd();
    for( i = 0; i < size; i++ ){
        for( j = 0; j < size; j++ ){
            cout.width( 3 );
            if( matrix[i][j] != INT_MAX ){
                cout << matrix[i][j];
            }
            else{
                cout << 'x';
            }
        }
        delete[] matrix[i];
        cout << endl;
    }
    delete[] matrix;
    
    cout << "Erasing node at index 1... " << d.eraseNodeByIndex( 1 ) << endl;
    cout << "New matrix:" << endl;
    size = d.getNumNodes();
    matrix = d.getAdjMatrix();
    for( i = 0; i < size; i++ ){
        for( j = 0; j < size; j++ ){
            cout.width( 3 );
            if( matrix[i][j] != INT_MAX ){
                cout << matrix[i][j];
            }
            else{
                cout << 'x';
            }
        }
        delete[] matrix[i];
        cout << endl;
    }
    delete[] matrix;
}

void testGraph(){
    Graph<int, int> g;
    vector<int> order;
    int i, j;
    int size;
    int** matrix;
    unsigned* distances;
    GraphEdge<int>** prims;
    GraphEdge<int>** kruskals;
    
    g.addNode( 1 );
    g.addNode( 2 );
    g.addNode( 3 );
    g.addNode( 4 );
    
    cout << boolalpha;
    cout << "Node 1 is on index: " << g.getIndex( 1 ) << endl;
    cout << "Node 2 is on index: " << g.getIndex( 2 ) << endl;
    cout << "Node 3 is on index: " << g.getIndex( 3 ) << endl;
    cout << "Node 4 is on index: " << g.getIndex( 4 ) << endl;
    
    cout << "Erasing node 1... " << g.eraseNode( 1 ) << endl;
    
    cout << "What is on index 1? " << g.getNodeByIndex( 1 ) -> tag() << endl;
    cout << "Erasing node at index 1... " << g.eraseNodeByIndex( 1 ) << endl;
    cout << "What is on index 1? " << g.getNodeByIndex( 1 ) -> tag() << endl;
    cout << "Erasing node at index 0... " << g.eraseNodeByIndex( 0 ) << endl;
    
    g.eraseNodes();
    g.eraseAllEdges();
    
    cout << g.addNode( 1 ) << endl;
    cout << g.addNode( 2 ) << endl;
    cout << g.addNode( 3 ) << endl;
    cout << g.addNode( 4 ) << endl;
    
    cout << g.getIndex( 1 ) << endl;
    cout << g.getIndex( 2 ) << endl;
    cout << g.getIndex( 3 ) << endl;
    cout << g.getIndex( 4 ) << endl;
    
    cout << g.addEdge( 12, g.getIndex( 1 ), g.getIndex( 2 ) ) << endl;
    cout << g.addEdge( 14, g.getIndex( 1 ), g.getIndex( 4 ) ) << endl;
    cout << g.addEdge( 23, g.getIndex( 2 ), g.getIndex( 3 ) ) << endl;
    cout << g.addEdge( 31, g.getIndex( 3 ), g.getIndex( 1 ) ) << endl;
    cout << g.addEdge( 42, g.getIndex( 4 ), g.getIndex( 2 ) ) << endl;
    
    cout << "Amplitud: " << endl;
    g.widthFirstSearch( g.getIndex( 1 ), order );
    for( int i = 0; i < order.size(); i++ ){
        cout << order[i] << " ";
    }
    cout << endl << endl;
    
    order.clear();
    cout << "Profundidad: " << endl;
    g.depthFirstSearch( g.getIndex( 1 ), order );
    for( int i = 0; i < order.size(); i++ ){
        cout << order[i] << " ";
    }
    cout << endl;
    order.clear();
    
    size = g.getNumNodes();
    matrix = g.getAdjMatrix();
    for( i = 0; i < size; i++ ){
        for( j = 0; j < size; j++ ){
            cout.width( 3 );
            if( matrix[i][j] != INT_MAX ){
                cout << matrix[i][j];
            }
            else{
                cout << 'x';
            }
        }
        delete[] matrix[i];
        cout << endl;
    }
    delete[] matrix;
    
    cout << "Erasing all nodes and edges..." << endl;
    g.eraseAllEdges();
    g.eraseNodes();
    
    cout << g.addNode( 1 ) << endl;
    cout << g.addNode( 2 ) << endl;
    cout << g.addNode( 3 ) << endl;
    cout << g.addNode( 4 ) << endl;
    cout << g.addNode( 5 ) << endl;
    
    cout << g.addEdge( 12, g.getIndex( 1 ), g.getIndex( 2 ), 50 ) << endl;
    cout << g.addEdge( 13, g.getIndex( 1 ), g.getIndex( 3 ), 30 ) << endl;
    cout << g.addEdge( 14, g.getIndex( 1 ), g.getIndex( 4 ), 100 ) << endl;
    cout << g.addEdge( 15, g.getIndex( 1 ), g.getIndex( 5 ), 10 ) << endl;
    cout << g.addEdge( 23, g.getIndex( 2 ), g.getIndex( 3 ), 5 ) << endl;
    cout << g.addEdge( 24, g.getIndex( 2 ), g.getIndex( 4 ), 20 ) << endl;
    cout << g.addEdge( 34, g.getIndex( 3 ), g.getIndex( 4 ), 50 ) << endl;
    cout << g.addEdge( 45, g.getIndex( 4 ), g.getIndex( 5 ), 10 ) << endl;

    
    size = g.getNumNodes();
    matrix = g.getAdjMatrix();
    for( i = 0; i < size; i++ ){
        for( j = 0; j < size; j++ ){
            cout.width( 5 );
            if( matrix[i][j] != INT_MAX ){
                cout << matrix[i][j];
            }
            else{
                cout << 'x';
            }
        }
        delete[] matrix[i];
        cout << endl;
    }
    delete[] matrix;
    
    cout << "Dijkstra start on 1:" << endl;
    distances = g.dijkstra( g.getIndex( 1 ) );
    for( i = 0; i < size; i++ ){
        cout.width( 3 );
        cout << distances[i];
    }
    cout << endl;
    delete[] distances;
    
    g.eraseAllEdges();
    
    cout << g.addEdge( 12, g.getIndex( 1 ), g.getIndex( 2 ), 20 ) << endl;
    cout << g.addEdge( 15, g.getIndex( 1 ), g.getIndex( 5 ), 10 ) << endl;
    cout << g.addEdge( 23, g.getIndex( 2 ), g.getIndex( 3 ), 20 ) << endl;
    cout << g.addEdge( 25, g.getIndex( 2 ), g.getIndex( 5 ), 15 ) << endl;
    cout << g.addEdge( 34, g.getIndex( 3 ), g.getIndex( 4 ), 5 ) << endl;
    cout << g.addEdge( 35, g.getIndex( 3 ), g.getIndex( 5 ), 10 ) << endl;
    cout << g.addEdge( 54, g.getIndex( 5 ), g.getIndex( 4 ), 15 ) << endl;
    
    cout << "Prim starts on 1" << endl;
    prims = g.prim( g.getIndex( 1 ) );
    
    g.eraseAllEdges();
    cout << "Changing graph to Prim's result..." << endl;
    for( i = 0; i < size - 1; i++ ){
        g.addEdge( prims[i] -> tag(), prims[i] -> from(), prims[i] -> to(), prims[i] -> weight() );
        cout << prims[i] -> from() << ", " << prims[i] -> to() << endl;
        delete prims[i];
    }
    delete[] prims;
    
    cout << "Prim matrix:" << endl;
    size = g.getNumNodes();
    matrix = g.getAdjMatrix();
    for( i = 0; i < size; i++ ){
        for( j = 0; j < size; j++ ){
            cout.width( 5 );
            if( matrix[i][j] != INT_MAX ){
                cout << matrix[i][j];
            }
            else{
                cout << 'x';
            }
        }
        delete[] matrix[i];
        cout << endl;
    }
    delete[] matrix;
    
    g.eraseAllEdges();
    
    cout << g.addEdge( 12, g.getIndex( 1 ), g.getIndex( 2 ), 20 ) << endl;
    cout << g.addEdge( 15, g.getIndex( 1 ), g.getIndex( 5 ), 10 ) << endl;
    cout << g.addEdge( 23, g.getIndex( 2 ), g.getIndex( 3 ), 20 ) << endl;
    cout << g.addEdge( 25, g.getIndex( 2 ), g.getIndex( 5 ), 15 ) << endl;
    cout << g.addEdge( 34, g.getIndex( 3 ), g.getIndex( 4 ), 5 ) << endl;
    cout << g.addEdge( 35, g.getIndex( 3 ), g.getIndex( 5 ), 10 ) << endl;
    cout << g.addEdge( 54, g.getIndex( 5 ), g.getIndex( 4 ), 15 ) << endl;
    
    cout << "Kruskal..." << endl;
    kruskals = g.kruskal();
    
    g.eraseAllEdges();
    cout << "Changing graph to Kruskal's result..." << endl;
    for( i = 0; i < size - 1; i++ ){
        g.addEdge( kruskals[i] -> tag(), kruskals[i] -> from(), kruskals[i] -> to(), kruskals[i] -> weight() );
        cout << kruskals[i] -> from() << ", " << kruskals[i] -> to() << endl;
        delete kruskals[i];
    }
    delete[] kruskals;
    
    cout << "Kruskal matrix:" << endl;
    size = g.getNumNodes();
    matrix = g.getAdjMatrix();
    for( i = 0; i < size; i++ ){
        for( j = 0; j < size; j++ ){
            cout.width( 5 );
            if( matrix[i][j] != INT_MAX ){
                cout << matrix[i][j];
            }
            else{
                cout << 'x';
            }
        }
        delete[] matrix[i];
        cout << endl;
    }
    delete[] matrix;
}

int main(){
    //testDigraph();
    testGraph();
    
    return 0;
}
