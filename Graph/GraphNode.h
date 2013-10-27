#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

template <class Tag>
class GraphNode{
    private:
        Tag tag_;
    
    public:
        GraphNode( const Tag& t ) :
            tag_( t ){
        }
        
        ~GraphNode(){
        }
        
        Tag& tag(){
            return tag_;
        }
        
        void setTag( const Tag& t ){
            tag_ = t;
        }
};

#endif //GRAPH_NODE_H
