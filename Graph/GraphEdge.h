#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

template <class Tag>
class GraphEdge{
    private:
        Tag tag_;
        int from_;
        int to_;
        int weight_;
    
    public:
        GraphEdge( const Tag& t, int from, int to, int weight = 1 ) :
            tag_( t ),
            from_( from ),
            to_( to ),
            weight_( weight ){
        }
        
        GraphEdge( GraphEdge<Tag>& e ) :
            tag_( e.tag() ),
            from_( e.from() ),
            to_( e.to() ),
            weight_( e.weight() ){}
        
        ~GraphEdge(){
        }
        
        bool operator<( GraphEdge<Tag>& e ){
            return weight_ < e.weight();
        }
        
        Tag& tag(){
            return tag_;
        }
        
        int from() const{
            return from_;
        }
        
        int to() const{
            return to_;
        }
        
        int weight() const{
            return weight_;
        }
        
        void setTag( const Tag& t ){
            tag_ = t;
        }
        
        void setFrom( int f ){
            from_ = f;
        }
        
        void setTo( int t ){
            to_ = t;
        }
        
        void setWeight( int w ){
            weight_ = w;
        }
};

#endif //GRAPH_EDGE_H
