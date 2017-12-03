#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;


#include "glog/logging.h"

#include <mutex>

namespace Beta{

template<typename State>
class Node{
    
    public:
        Node(string name):N_(0.0f),W_(0.0f),Q_(0.0f),P_(0.0f), index_(0), name_(name){
            child_.clear();
            parent_.clear();
            
        }



        ~Node(){

        }

        // compute features using 
        void compute_feature(){

        }
    
        //float& sN(){return N_;}
        

        unsigned long & sindex(){return index_;}
        vector<Node<State>* >& schild(){return child_;}
        vector<Node<State>* >& sparent(){return parent_;}

        
        const float N(){return N_;}
        const float W(){return W_;}
        const float Q(){return Q_;}
        const float P(){return P_;}
        const float U(){return U_;}
        const string name(){return name_;}
        const unsigned long index(){return index_;}
        const vector<Node<State> * > child(){return child_;}
        const vector<Node<State> * > parent(){return parent_;} 
    

    protected:
        vector<Node<State> * > child_;
        vector<Node<State>* > parent_;
        State state_;
        unsigned long index_;
        string name_;
        float N_;
        float W_;
        float Q_;
        float P_;
        float U_;
        //static int index;
};


template<typename State>
class Tree{
    public:
        Tree(int L):L_(L), counter_(0){

        }
        ~Tree(){

        }

        void add_node(Node<State>* leaf_node, Node<State>* node){
            //leaf_node->

            DLOG(INFO)<< "adding "<< counter_<<" node";
            node->sindex() = ++ counter_;
            nodes_[counter_] = node;
            leaf_node->schild().push_back(node);
            node->sparent().push_back(leaf_node);

            
            
            //tree_.push_back(node);
            //leaf_node->child_ = node;
        }

        void add_node(Node<State>* node){
            DLOG(INFO)<< "adding "<< counter_<<" node";
            node->sindex() = ++ counter_;
            nodes_[counter_] = node;
        }


        void travel(Node<State>* root){
            
            queue<Node<State>* > cache;
            cache.push(root);
            while(cache.size()){
                Node<State>* ele = cache.front();
                DLOG(INFO)<<"visit "<< ele->name();
                for(unsigned int i =0; i < ele->child().size(); ++ i){
                    cache.push(ele->child()[i]);
                }
                cache.pop();
            }


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
        map<int, Node<State>* > nodes_;
        queue<Node<State>* > leafs_;
        unsigned long counter_;
        int L_;

};

} //end of namespace Beta

#endif