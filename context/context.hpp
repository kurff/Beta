#ifndef __CONTEXT_HPP__
#define __CONTEXT_HPP__

#include "action/action.hpp"

// context of mcts.hpp
// go can be seen as a special case of context

namespace {
  

  
  class Context{
    public:
        Context(){

        }
        ~Context(){

        }

        // get current state
        virtual void get_state() = 0;
        virtual void get_features() = 0;
        virtual void get_next_state(Action& action) = 0;


    protected:
        
        

  };
 





}



#endif 