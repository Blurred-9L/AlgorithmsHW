/** \file
    Header file for the GraphNode class.
    
    Rodrigo Fuentes Hernandez
    aka Blurred-9L
*/

#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

/** The GraphNode class provides a template class for
    a graph's nodes. The GraphNode class's template
    parameter allows the user to define a tag for the
    corresponding GraphNode, allowing for an alternative
    identification of the node.
*/
template <class Tag>
class GraphNode{
    private:
        Tag tag_;           ///< The node's identifying tag.
    
    public:
        /// Class constructor.
        GraphNode( const Tag& t ) :
            tag_( t ){
        }
        
        /// Destructor
        ~GraphNode(){
        }
        
        /// Get method for 'tag' attribute.
        const Tag& tag() const{
            return tag_;
        }
        
        /// Set method fro 'tag' attribute.
        void setTag( const Tag& t ){
            tag_ = t;
        }
};

#endif //GRAPH_NODE_H
