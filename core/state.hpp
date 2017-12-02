#ifndef __STATE_HPP__
#define __STATE_HPP__

#include "caffe2/core/tensor.h"

namespace Beta{
    class GoState{
        public:
            GoState(){}
            ~GoState(){}
        protected:
        // 19 x 19
            Tensor<TensorCPU> go_state_;
            
            



    };




}





#endif