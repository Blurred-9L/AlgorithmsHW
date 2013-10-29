/** \file
    Header file for the Graph class.
    
    Rodrigo Fuentes Hernandez
    aka Blurred-9L
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <climits>

#include <set>
using std::set;

#include "GraphNode.h"
#include "GraphEdge.h"
#include "Digraph.h"

/** The Graph class is the direct child of the Digraph
    class. As its parent, it allows the user to define
    an identifier for nodes and edges through the use
    of template parameters.
    The edges of an object of the Graph's class, do not
    have a specific direction. They can also be seen as
    bidirectional edges, so the operation for adding
    edges has been redefined. Aside from that, everything
    you could do with a Digraph is available for the
    Graph class, as well as Prim's and Kruskal's
    algorithms that find the minimum spanning tree of
    a graph.
*/
template <class Node, class Edge>
class Graph : public Digraph<Node, Edge>{
    private:
        /** Finds the root of the partition to which the
            node represented by the given index belongs.
            This function is used during Kruskal's algorithm.
        */
        int findPartition( int nodeIndex, int* partitions ){
            int parentIndex = partitions[nodeIndex];
            
            while( parentIndex != nodeIndex ){
                nodeIndex = parentIndex;
                parentIndex = partitions[nodeIndex];
            }
            
            return parentIndex;
        }
        
        /** Fuses two different partitions by making the
            root of one point to the other.
            This function is used during Kruskal's algorithm.
        */
        void mergePartitions( int from, int to, int* partitions ){
            if( from < to ){
                partitions[to] = from;
            }
            else{
                partitions[from] = to;
            }
        }
    public:
        /// Class constructor.
        Graph() : Digraph<Node, Edge>(){
        }
        
        /// Class destructor.
        ~Graph(){
        }
        
        /** Adds an edge to the graph. Since a Graph's edges
            no longer have a direction, the edge is added to
            both, the source and the destination nodes' list
            of edges.
        */
        int addEdge( const Edge& data, int from, int to, int weight = 1 ){
            int added = 0;
            
            if( from != to ){
                added += Digraph<Node, Edge>::addEdge( data, from, to, weight );
                added += Digraph<Node, Edge>::addEdge( data, to, from, weight );
            }
            
            return added;
        }
        
        /** Prim's algorithm to find the edges that form the
            graph's minimum spanning tree.
        */
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
        
        /** Kruskal's algorithm to find the edges that form
            the graph's minimum spanning tree.
        */
        GraphEdge<Edge>** kruskal(){
            int size = this -> nodes.size();
            int inSize;
            int i, j;
            int count = 0;
            int fromIdx, toIdx;
            int* partitions = new int[size];
            set< GraphEdge<Edge> > graphEdges;
            typename set< GraphEdge<Edge> >::iterator curEdge;
            GraphEdge<Edge>** edges = new GraphEdge<Edge>*[size - 1];
            
            for( i = 0; i < size; i++ ){
                inSize = this -> edges[i].size();
                for( j = 0; j < inSize; j++ ){
                    graphEdges.insert( *( this -> edges[i][j] ) );
                }
            }
            for( i = 0; i < size - 1; i++ ){
                edges[i] = 0;
            }
            for( i = 0; i < size; i++ ){
                partitions[i] = i;
            }
            
            curEdge = graphEdges.begin();
            while( count < size - 1 and curEdge != graphEdges.end() ){
                fromIdx = findPartition( (*curEdge).from(), partitions );
                toIdx = findPartition( (*curEdge).to(), partitions );
                if( fromIdx != toIdx ){
                    mergePartitions( fromIdx, toIdx, partitions );
                    edges[count++] = new GraphEdge<Edge>( *curEdge );
                }
                curEdge++;
            }
            
            delete[] partitions;
            
            return edges;
        }
};

#endif //GRAPH_H
