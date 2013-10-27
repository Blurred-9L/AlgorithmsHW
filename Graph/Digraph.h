#ifndef DIGRAPH_H
#define DIGRAPH_H

#include "GraphNode.h"
#include "GraphEdge.h"

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <stack>
using std::stack;

#include <set>
using std::set;

#include <iostream>
using std::cout;
using std::endl;

#include <climits>

template <class Node, class Edge>
class Digraph{
    protected:
        vector< GraphNode<Node>* > nodes;
        vector< vector< GraphEdge<Edge>* > > edges;
        
    public:
        Digraph(){
        }
        
        ~Digraph(){
            eraseNodes();
            eraseAllEdges();
            edges.clear();
        }
        
        int** getAdjMatrix() const{
            int** matrix;
            int i, j;
            int to;
            int size = nodes.size();
            int inSize;
            
            matrix = new int*[size];
            for( i = 0; i < size; i++ ){
                matrix[i] = new int[size];
                for( j = 0; j < size; j++ ){
                    if( i != j ){
                        matrix[i][j] = INT_MAX;
                    }
                    else{
                        matrix[i][j] = 0;
                    }
                }
                inSize = edges[i].size();
                for( j = 0; j < inSize; j++ ){
                    to = edges[i][j] -> to();
                    matrix[i][to] = edges[i][j] -> weight();
                }
            }
            
            return matrix;
        }
        
        int getNumNodes() const{
            return nodes.size();
        }
        
        bool addNode( const Node& data ){
            bool added = false;
            GraphNode<Node>* newNode;
            
            if( getNode( data ) == 0 ){
                newNode = new GraphNode<Node>( data );
                nodes.push_back( newNode );
                edges.resize( edges.size() + 1 );
                added = true;
            }
            
            return added;
        }
        
        int getIndex( const Node& data ) const{
            int index = -1;
            int i;
            int size = nodes.size();
            bool found = false;
            
            for( i = 0; i < size and not found; i++ ){
                if( data == nodes[i] -> tag() ){
                    found = true;
                    index = i;
                }
            }
            
            return index;
        }
        
        GraphNode<Node>* getNodeByIndex( int index ) const{
            GraphNode<Node>* node = 0;
            
            if( index >= 0 and index < nodes.size() ){
                node = nodes[index];
            }
            
            return node;
        }
        
        GraphNode<Node>* getNode( const Node& data ) const{
            GraphNode<Node>* node = 0;
            int i;
            int size = nodes.size();
            bool found = false;
            
            for( i = 0; i < size and not found; i++ ){
                if( data == nodes[i] -> tag() ){
                    found = true;
                    node = nodes[i];
                }
            }
            
            return node;
        }
        
        bool eraseNodeByIndex( int index ){
            GraphNode<Node>* node;
            bool erased = false;
            
            node = getNodeByIndex( index );
            if( node != 0 ){
                delete node;
                eraseRefs( index );
                nodes.erase( nodes.begin() + index );
                eraseEdges( index );
                edges.erase( edges.begin() + index );
                erased = true;
            }
            
            return erased;
        }
        
        bool eraseNode( const Node& data ){
            GraphNode<Node>* node;
            bool erased = false;
            int i;
            int size = nodes.size();
            
            for( i = 0; i < size and not erased; i++ ){
                if( data == nodes[i] -> tag() ){
                    node = nodes[i];
                    delete node;
                    eraseRefs( i );
                    nodes.erase( nodes.begin() + i );
                    eraseEdges( i );
                    edges.erase( edges.begin() + i );
                    erased = true;
                }
            }
            
            return erased;
        }
        
        void eraseRefs( int index ){
            int i, j;
            int size = nodes.size();
            int inSize;
            int from, to;
            queue<int> toErase;
            
            for( i = 0; i < size; i++ ){
                inSize = edges[i].size();
                for( j = 0; j < inSize; j++ ){
                    if( edges[i][j] -> to() == index ){
                        toErase.push( i );
                        toErase.push( j );
                        delete edges[i][j];
                    }
                }
            }
            
            while( not toErase.empty() ){
                from = toErase.front();
                toErase.pop();
                to = toErase.front();
                toErase.pop();
                edges[from].erase( edges[from].begin() + to );
            }
        }
        
        bool addEdge( const Edge& data, int from, int to, int weight = 1 ){
            GraphEdge<Edge>* newEdge;
            int i;
            int size;
            bool added = false;
            bool found = false;
            
            if( from >= 0 and from < nodes.size() and to >= 0 and to < nodes.size() ){
                size = edges[from].size();
                for( i = 0; i < size and not found; i++ ){
                    if( to == edges[from][i] -> to() || data == edges[from][i] -> tag() ){
                        found = true;
                    }
                }
                if( not found ){
                        newEdge = new GraphEdge<Edge>( data, from, to, weight );
                        edges[from].push_back( newEdge );
                        added = true;
                    }
            }
            
            return added;
        }
        
        vector< GraphEdge<Edge>* >* getEdgesByIndex( int index ){
            vector< GraphEdge<Edge>* >* nodeEdges = 0;
            
            if( index >= 0 and index < nodes.size() ){
                nodeEdges = &edges[index];
            }
            
            return nodeEdges;
        }
        
        vector< GraphEdge<Edge>* >* getEdges( const Node& data ){
            vector< GraphEdge<Edge>* >* nodeEdges = 0;
            int i;
            int size = nodes.size();
            bool found = false;
            
            for( i = 0; i < size and not found; i++ ){
                if( data == nodes[i] -> tag() ){
                    found = true;
                    nodeEdges = &edges[i];
                }
            }
            
            return nodeEdges;
        }
        
        int getEdgeIndex( const Edge& data, int from ){
            int index = -1;
            int i;
            int size;
            bool found = false;
            
            if( from >= 0 and from < nodes.size() ){
                size = edges[from].size();
                for( i = 0; i < size and not found; i++ ){
                    if( data == edges[from][i] -> tag() ){
                        found = true;
                        index = i;
                    }
                }
            }
            
            return index;
        }
        
        GraphEdge<Edge>* getEdgeByIndex( int from, int to ){
            GraphEdge<Edge>* edge = 0;
            int i;
            int size;
            bool found = false;
            
            if( from >= 0 and from < nodes.size() and to >= 0 and to < nodes.size() ){
                size = edges[from].size();
                for( i = 0; i < size and not found; i++ ){
                    if( to == edges[from][i] -> to() ){
                        found = true;
                        edge = edges[from][i];
                    }
                }
            }
            
            return edge;
        }
        
        bool eraseEdgeByIndex( int from, int to ){
            GraphEdge<Edge>* edge;
            int i;
            int size;
            bool erased = false;
            
            if( from >= 0 and from < nodes.size() and to >= 0 and to < nodes.size() ){
                size = edges[from].size();
                for( i = 0; i < size and not erased; i++ ){
                    if( to == edges[from][i] -> to() ){
                        erased = true;
                        edge = edges[from][i];
                        delete edge;
                        edges[from].erase( edges[from].begin() + i );
                    }
                }
            }
            
            return erased;
        }
        
        bool eraseEdge( const Edge& data, int from ){
            GraphEdge<Edge>* edge;
            int i;
            int size;
            bool erased = false;
            
            if( from >= 0 and from < nodes.size() ){
                size = edges[from].size();
                for( i = 0; i < size and not erased; i++ ){
                    if( data == edges[from][i] -> tag() ){
                        erased = true;
                        edge = edges[from][i];
                        delete edge;
                        edges[from].erase( edges[from].begin() + i );
                    }
                }
            }
            
            return erased;
        }
        
        void eraseEdges( int index ){
            int i;
            int size = edges[index].size();
            
            for( i = 0; i < size; i++ ){
                delete edges[index][i];
            }
            edges[index].clear();
        }
        
        void eraseAllEdges(){
            int i;
            int size = edges.size();
            
            for( i = 0; i < size; i++ ){
                eraseEdges( i );
            }
        }
        
        void eraseNodes(){
            int i;
            int size = nodes.size();
            
            for( i = 0; i < size; i++ ){
                delete nodes[i];
            }
            nodes.clear();
        }
        
        void widthFirstSearch( int startIndex, vector<int>& order ) const{
            int size = nodes.size();
            int curNode;
            int i;
            bool* visited = new bool[size];
            queue<int> queue;
            
            if( startIndex >= 0 and startIndex < size ){
                for( i = 0; i < size; i++ ){
                    visited[i] = false;
                }
                queue.push( startIndex );
                while( not queue.empty() ){
                    curNode = queue.front();
                    queue.pop();
                    if( not visited[curNode] ){
                        order.push_back( curNode );
                        size = edges[curNode].size();
                        for( i = 0; i < size; i++ ){
                            queue.push( edges[curNode][i] -> to() );
                        }
                        visited[curNode] = true;
                    }
                }
            }
            
            delete[] visited;
        }
        
        void depthFirstSearch( int startIndex, vector<int>& order ) const{
            int size = nodes.size();
            int curNode;
            int i;
            bool* visited = new bool[size];
            stack<int> stack;
            
            if( startIndex >= 0 and startIndex < size ){
                for( i = 0; i < size; i++ ){
                    visited[i] = false;
                }
                stack.push( startIndex );
                while( not stack.empty() ){
                    curNode = stack.top();
                    stack.pop();
                    if( not visited[curNode] ){
                        order.push_back( curNode );
                        size = edges[curNode].size();
                        for( i = 0; i < size; i++ ){
                            stack.push( edges[curNode][i] -> to() );
                        }
                        visited[curNode] = true;
                    }
                }
            }
            
            delete[] visited;
        }
        
        unsigned* dijkstra( int startIndex ) const{
            int size = nodes.size();
            int i, min;
            int minIdx;
            int** matrix = getAdjMatrix();
            unsigned* distances = new unsigned[size];
            int* lastNode = new int[size];
            set<int> nodeSet;
            
            for( i = 0; i < size; i++ ){
                if( i != startIndex ){
                    distances[i] = matrix[startIndex][i];
                    lastNode[i] = startIndex;
                    nodeSet.insert( i );
                }
                else{
                    distances[i] = 0;
                    lastNode[i] = -1;
                }
            }
            
            for( i = 0; i < size - 1; i++ ){
                min = UINT_MAX;
                for( set<int>::iterator j = nodeSet.begin(); j != nodeSet.end(); j++ ){
                    if( distances[*j] < min ){
                        min = distances[*j];
                        minIdx = *j;
                    }
                }
                nodeSet.erase( nodeSet.find( minIdx ) );
                for( set<int>::iterator j = nodeSet.begin(); j != nodeSet.end(); j++ ){
                    if( distances[*j] > distances[minIdx] + matrix[minIdx][*j] ){
                        distances[*j] = distances[minIdx] + matrix[minIdx][*j];
                        lastNode[*j] = minIdx;
                    }
                }
            }
            
            for( i = 0; i < size; i++ ){
                delete[] matrix[i];
            }
            delete[] matrix;
            delete[] lastNode;
            
            return distances;
        }
        
        int** floyd(){
            int** matrix = getAdjMatrix();
            int size = nodes.size();
            int i, j, k;
            
            for( k = 0; k < size; k++ ){
                for( i = 0; i < size; i++ ){
                    for( j = 0; j < size; j++ ){
                        if( matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX ){
                            if( matrix[i][k] + matrix[k][j] < matrix[i][j] ){
                                matrix[i][j] = matrix[i][k] + matrix[k][j];
                            }
                        }
                    }
                }
            }
            
            return matrix;
        }
};

#endif //DIGRAPH_H
