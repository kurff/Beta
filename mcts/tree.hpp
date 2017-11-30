#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <vector>
using namespace std;

#include "glog/logging.h"


namespace Beta{

template<typename State>
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
        State state_;
        float N_;
        float W_;
        float Q_;
        float P_;
        float U_;

};


template<typename State>
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

        void reset_root(){

        }

        void select(){

        }
        void expand_and_evaluate(){

        }
        void backup(){

        }

        void run(){
            select();
            expand_and_evaluate();
            backup();

        }




    protected:
        vector<Node<State > > tree_;
        

};

} //end of namespace Beta

#endif