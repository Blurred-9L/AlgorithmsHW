#ifndef GRAPH_H
#define GRAPH_H

#include <climits>

#include "GraphNode.h"
#include "GraphEdge.h"
#include "Digraph.h"

template <class Node, class Edge>
class Graph : public Digraph<Node, Edge>{
    public:
        Graph() : Digraph<Node, Edge>(){
        }
        
        ~Graph(){
            this -> eraseNodes();
            this -> eraseAllEdges();
        }
        
        int addEdge( const Edge& data, int from, int to, int weight = 1 ){
            int added = 0;
            
            if( from != to ){
                added += Digraph<Node, Edge>::addEdge( data, from, to, weight );
                added += Digraph<Node, Edge>::addEdge( data, to, from, weight );
            }
            
            return added;
        }
        
        GraphEdge<Edge>** prim( int startIndex ){
            int size = this -> nodes.size();
            int i, j;
            int min, minIdx;
            int counter = 0;
            int** matrix = this -> getAdjMatrix();
            int* nearest = new int[size];
            int* minDist = new int[size];
            GraphEdge<Edge>** edges = new GraphEdge<Edge>*[size - 1];
            
            for( i = 0; i < size - 1; i++ ){
                edges[i] = 0;
            }
            
            for( i = 0; i < size; i++ ){
                if( i != startIndex ){
                    nearest[i] = startIndex;
                    minDist[i] = matrix[i][startIndex];
                }
                else{
                    minDist[i] = -1;
                    nearest[i] = -1;
                }
            }
            
            for( i = 0; i < size - 1; i++ ){
                min = INT_MAX;
                for( j = 0; j < size; j++ ){
                    if( j != startIndex ){
                        if( minDist[j] >= 0 and minDist[j] < min ){
                            min = minDist[j];
                            minIdx = j;
                        }
                    }
                }
                edges[counter++] = new GraphEdge<Edge>( *( this -> getEdgeByIndex( nearest[minIdx], minIdx ) ) );
                minDist[minIdx] = -1;
                for( j = 0; j < size; j++ ){
                    if( j != startIndex ){
                        if( matrix[j][minIdx] < minDist[j] ){
                            minDist[j] = matrix[j][minIdx];
                            nearest[j] = minIdx;
                        }
                    }
                }
            }
            
            for( i = 0; i < size; i++ ){
                delete[] matrix[i];
            }
            delete[] matrix;
            delete[] nearest;
            delete[] minDist;
            
            
            return edges;
        }
        
        //Programar Kruskal
};

#endif //GRAPH_H
