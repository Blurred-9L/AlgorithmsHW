/** \file
    Header file for the GraphEdge class.
    
    Rodrigo Fuentes Hernandez
    aka Blurred-9L
*/

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

/** The GraphEdge class provides a template class for
    a graph's edge. The template parameter allows the
    the user to select a tag with which to identify
    the corresponding edge.
*/
template <class Tag>
class GraphEdge{
    private:
        Tag tag_;           ///< The edge's identifying tag.
        int from_;          ///< Index of the source node on which this edge starts.
        int to_;            ///< Index of the destinatino node of this edge.
        int weight_;        ///< Weigth of the edge.
    
    public:
        /// Class constructor.
        GraphEdge( const Tag& t, int from, int to, int weight = 1 ) :
            tag_( t ),
            from_( from ),
            to_( to ),
            weight_( weight ){
        }
        
        /// Copy constructor.
        GraphEdge( const GraphEdge<Tag>& e ) :
            tag_( e.tag() ),
            from_( e.from() ),
            to_( e.to() ),
            weight_( e.weight() ){
        }
        
        /// Destructor.
        ~GraphEdge(){
        }
        
        /// Overload of the 'less-than' operator.
        bool operator<( const GraphEdge<Tag>& e ) const{
            bool result;
            
            if( weight_ > e.weight() ){
                result = false;
            }
            else if( weight_ < e.weight() ){
                result = true;
            }
            else if( from_ < e.from() ){
                result = true;
            }
            else if( from_ > e.from() ){
                result = false;
            }
            else if( to_ > e.to() ){
                result = false;
            }
            else if( to_ < e.to() ){
                result = true;
            }
            else{
                result = false;
            }
            
            return result;
        }
        
        /// Get method for 'tag' attribute.
        const Tag& tag() const{
            return tag_;
        }
        
        /// Get method for 'from' attribute.
        int from() const{
            return from_;
        }
        
        /// Get method for 'to' attribute.
        int to() const{
            return to_;
        }
        
        /// Get method for 'weight' attribute.
        int weight() const{
            return weight_;
        }
        
        /// Set method for 'tag' attribute.
        void setTag( const Tag& t ){
            tag_ = t;
        }
        
        /// Set method for 'from' attribute.
        void setFrom( int f ){
            from_ = f;
        }
        
        /// Set method for 'to' attribute.
        void setTo( int t ){
            to_ = t;
        }
        
        /// Set method for 'weight' attribute.
        void setWeight( int w ){
            weight_ = w;
        }
};

#endif //GRAPH_EDGE_H
