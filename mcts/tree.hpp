#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <vector>
using namespace std;

#include "glog/logging.h"


namespace Beta{

template<typename Context>
class Node{
    
    public:
        Node():N_(0.0f),W_(0.0f),Q_(0.0f),P(0.0f){
            child_.clear();
            parent_.clear();
        }



        ~Node(){

        }

        // compute features using 
        void compute_feature(){

        }
    
    

    protected:
        vector<Node*> child_;
        vector<Node*> parent_;
        Context data_;
        float N_;
        float W_;
        float Q_;
        float P_;
        float U_;

};


template<typename Context>
class Tree{
    public:
        Tree(){

        }
        ~Tree(){

        }

        void add_node(Node<DType>* node){


        }

        void clear_node(){

        }

        void select(){

        }
        void expand_and_evaluate(){

        }
        void backup(){

        }

    protected:
        vector<Node<Context > > tree_;
        

};

} //end of namespace Beta

#endif