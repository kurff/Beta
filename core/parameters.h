#ifndef __PARAMETERS_HPP__
#define __PARAMETERS_HPP__

#include "proto/beta.pb.h"

namespace Beta{





static Parameters* global_parameters(){
    static Parameters* parameters = new Parameters();
    return parameters;
}

}


#endif