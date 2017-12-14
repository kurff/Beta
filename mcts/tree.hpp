#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <vector>
#include <map>
#include <string>
#include <queue>




#include "glog/logging.h"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include "core/network.hpp"
#include "core/context.hpp"


using namespace std;

namespace Beta{

template<typename State>
class Node{
    
    public:
        Node(string name):N_(0.0f),W_(0.0f),Q_(0.0f),P_(0.0f), index_(0), name_(name), flag_(true), parent_(nullptr){
            child_.clear();
            node_state_ = shared_ptr<State>(new State());
            
        }



        ~Node(){


        }

        // compute features using 
        void compute_feature(){

        }
    
        //float& sN(){return N_;}
        

        unsigned long & sindex(){
            lock_guard<mutex> lock(mutex_);
            return index_;
        }
        map<unsigned long, Node<State>* >& schild(){
            lock_guard<mutex> lock(mutex_);
            return child_;
        }
        Node<State>* & sparent(){
            lock_guard<mutex> lock(mutex_);
            return parent_;
        }
        bool & sflag(){
            lock_guard<mutex> lock(mutex_);
            return flag_;
        }

        State& sstate(){
            lock_guard<mutex> lock(mutex_);
            return *(node_state_.get());
        }

        void set_child(){
            lock_guard<mutex> lock(mutex_);
            
            
        }

        void set_index(int index){
             lock_guard<mutex> lock(mutex_);
             index_ = index;
        }
        void set_parent(Node<State>* parent){
            lock_guard<mutex> lock(mutex_);
            parent_ = parent;
        }
        void set_flag(int flag){
            lock_guard<mutex> lock(mutex_);
            flag_ = flag;
        }


        
        const float N(){lock_guard<mutex> lock(mutex_);return N_;}
        const float W(){lock_guard<mutex> lock(mutex_);return W_;}
        const float Q(){lock_guard<mutex> lock(mutex_);return Q_;}
        const float P(){lock_guard<mutex> lock(mutex_);return P_;}
        const float U(){lock_guard<mutex> lock(mutex_);return U_;}
        const string name(){lock_guard<mutex> lock(mutex_);return name_;}
        const unsigned long index(){lock_guard<mutex> lock(mutex_);return index_;}
        const map<unsigned long, Node<State> * > child(){lock_guard<mutex> lock(mutex_);return child_;}
        const Node<State>* parent(){lock_guard<mutex> lock(mutex_);return parent_;}
        const bool flag(){lock_guard<mutex> lock(mutex_);return flag_;}
        const State& state(){lock_guard<mutex> lock(mutex_);return *(state_.get());}

    

    protected:
        map<unsigned long, Node<State> * > child_;
        Node<State>* parent_;
        shared_ptr<State> node_state_;
        unsigned long index_;
        string name_;
        float N_;
        float W_;
        float Q_;
        float P_;
        float U_;
        bool flag_; // if flag == TRUE, keep else remove
        mutex mutex_;
        //static int index;
};


template<typename State, typename Action>
class Tree{
    typedef typename map<unsigned long, Node<State>* >::iterator Iterator;
    typedef typename queue<Node<State>* >::iterator QIterator;
    public:
        Tree(int L):L_(L), counter_(-1){

        }
        ~Tree(){

        }

        void add_node(Node<State>* leaf_node, Node<State>* node){
            //leaf_node->

            DLOG(INFO)<< "adding "<< counter_<<" node";
            node->sindex() = ++ counter_;
            nodes_[counter_] = node;
            leaf_node->schild().insert(std::pair<unsigned long, Node<State>* >(counter_,node));
            node->sparent()=leaf_node;

            
            
            //tree_.push_back(node);
            //leaf_node->child_ = node;
        }

        bool add_node(Node<State>* node){
            DLOG(INFO)<< "adding "<< counter_<<" node: "<< node->name();
            Iterator it = nodes_.find(node->index());
            if(it != nodes_.end()){
                LOG(INFO)<<" tree already has such node";
                return false;
            }
            node->sindex() = ++ counter_;
            nodes_[counter_] = node;
            return true;
        }

        Node<State>* find(int index){
            Iterator it = nodes_.find(index);
            if(it == nodes_.end()){
                LOG(INFO)<< "can not find " << index;
            }else{
                LOG(INFO)<<"find "<< index;
            }
            return it->second;
        }


        void travel(Node<State>* root){       
            queue<Node<State>* > cache;
            cache.push(root);
            while(cache.size()){
                Node<State>* ele = cache.front();
                DLOG(INFO)<<"visit "<< ele->name()<<" index: "<<ele->index()<<" child size: "<< ele->schild().size();
                for(Iterator it = ele->schild().begin(); it != ele->schild().end(); ++ it){
                    cache.push(it->second);
                }
                cache.pop();
            }
        }

        // remove given node and its descendant
        void clear_node(Node<State>*  node){
            Iterator it = nodes_.find(node->index());
            if(it == nodes_.end()){
                DLOG(INFO)<<"can not find node "<< node->name(); 
                return;
            }
            Iterator it_child = node->sparent()->schild().find(node->index());
            node->sparent()->schild().erase(it_child);
            queue<Node<State>* > cache;
            cache.push(node);

            // get all nodes in the sub-tree of node and remove these node
            // 
            while(cache.size()){
                Node<State>* ele = cache.front();
                for(Iterator it = ele->schild().begin(); it != ele->schild().end(); ++ it){
                    cache.push(it->second);
                } 
                nodes_.erase(nodes_.find(ele->index()));
                cache.pop();
            }
        }

        void reset_root(Node<State>*  node){
            nodes_.clear();
            add_node(node);
        }

        void select(Node<State>* root){
            queue<Node<State>* > cache;
            cache.push(root);
            Node<State>* best;
            while(cache.size()){
                Node<State>* ele = cache.front();
                DLOG(INFO)<<"visit "<< ele->name()<<" index: "<<ele->index()<<" child size: "<< ele->schild().size();
                float maxQ = 0;


                if(ele->schild().size() ==0){

                    // push leaf node
                    {
                        //lock_guard<mutex> lock(mutex_);
                        leafs_.push(ele);
                    }


                }

                for(Iterator it = ele->schild().begin(); it != ele->schild().end(); ++ it){
                    if(maxQ <= it->second->Q() + it->second->U()){
                        maxQ = it->second->Q() + it->second->U();
                        best = it->second;
                    }
                    
                    cache.push(best);
                }

                cache.pop();

            }

            
        }
        void expand_and_evaluate(){
            // add child node into leaf node
            
            for(QIterator it = leafs_.begin(); it != leafs_.end(); ++ it ){
                contex_->get_legal_action(it->state());
                for(int i = 0; i < context_->size_legal_action(); ++ i){
                    Node<State>* node = new Node<State> (std::to_string(counter_+1));
                    add_node(*it, node);
                }
            }







            // push leaf node into leafs_ for evaluation



        }
        void backup(){

        }

        void run(){


            select();
            expand_and_evaluate();
            backup();

        }



        const size_t size(){return nodes_.size();}
        const unsigned long counter(){return counter_;}
        const int L(){return L_;}
        const queue<Node<State>* > leafs(){return leafs_;}
        const std::map<unsigned long, Node<State>* > nodes(){return nodes_;}



    protected:
        std::map<unsigned long, Node<State>* > nodes_;
        vector<thread> thread_pool_;
        queue<function<void (Node<State>* ) > > tasks_;
        queue<Node<State>* > leafs_;
        shared_ptr<Network> network_;
        shared_ptr<Context<State, Action> > context_;
        unsigned long counter_;





        mutex mutex_;
        int L_;


};

} //end of namespace Beta

#endif