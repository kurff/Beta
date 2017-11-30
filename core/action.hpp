#ifndef __ACTION_HPP__
#define __ACTION_HPP__

#include <vector>

#include "caffe2/core/tensor.h"
using namespace caffe2;
namespace Beta{


class GoAction{
    public:
        GoAction():x_(0),y_(0){

        }
        ~GoAction(){

        }

        //template<>
        // choose action 

        void play(const Tensor<CPUContext>& probability){
            

            
        }
        
    protected:
        int x_;
        int y_;
        //std::vector<>
};


}

#endif 