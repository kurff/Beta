#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <vector>
using namespace std;
class Node{
    
    public:
        Node(){


        }

        ~Node(){

        }
    
    

    protected:
        vector<Node*> child_;
        vector<Node*> parent_;
    

};


class Tree{
    public:
        Tree(){

        }
        ~Tree(){

        }
    protected:
        

};


#endif