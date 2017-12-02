#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;


#include "glog/logging.h"


namespace Beta{

template<typename State>
class Node{
    
    public:
        Node(string name):N_(0.0f),W_(0.0f),Q_(0.0f),P(0.0f), index_(0), name_(name){
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
        int index_;
        string name_;
        float N_;
        float W_;
        float Q_;
        float P_;
        float U_;

};


template<typename State>
class Tree{
    public:
        Tree(int L):L_(L){

        }
        ~Tree(){

        }

        void add_node(Node<State>* leaf_node, Node<State>* node){
            //tree_.push_back(node);
            //leaf_node->child_ = node;



        }

        void clear_node(){

        }

        void reset_root(){

        }

        void select(){

        }
        void expand_and_evaluate(){


            // push leaf node into leafs_ for evaluation

        }
        void backup(){

        }

        void run(){
            select();
            expand_and_evaluate();
            backup();

        }




    protected:
        map< string,Node<State > > tree_;
        queue<Node<State>* > leafs_;
        int L_;

};

} //end of namespace Beta

#endif