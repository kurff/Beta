#ifndef __NETWORK_HPP__
#define __NETWORK_HPP__

#include "caffe2/core/tensor.h"
namespace Beta{

    class Network{
        public:
            Network(){}
            ~Network(){}

        public:
            void forward(const Tensor<CPUContext>& inputs, 
                         Tensor<CPUContext>& outputs);
                         

        protected:
            


    };




}





#endif