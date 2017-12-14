#ifndef __ACTION_HPP__
#define __ACTION_HPP__

#include <vector>

#include "caffe2/core/tensor.h"
using namespace caffe2;
namespace Beta{


class Action{
    public:
        Action(){

        }

        ~Action(){

        }

        virtual void play(Tensor<CPUContext>& probability) = 0;
        

    protected: 



}




class GoAction: public Action{
    public:
        GoAction():x_(0),y_(0){

        }
        ~GoAction(){

        }

        //template<>
        // choose action 

        void play(Tensor<CPUContext>& probability){
            

            
        }



        int x(){return x_;}
        int y(){return y_;}
        
    protected:
        int x_;
        int y_;
        //std::vector<>
};


class ChessAction: public Action{
    public:
        ChessAction(){

        }
        ~ChessAction(){

        }

        void play(Tensor<CPUContext>& probability){

        }

        

};


}

#endif 