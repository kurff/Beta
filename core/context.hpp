#ifndef __CONTEXT_HPP__
#define __CONTEXT_HPP__


#include <vector>

// context of mcts.hpp
// go can be seen as a special case of context
// get features 

namespace Beta{
  

  template<typename State, typename Action>
  class Context{
    public:
        Context(){

        }
        ~Context(){

        }

        // get current state
        virtual void get_current_state() = 0;
        virtual void get_current_features() = 0;
        //virtual void self_play() = 0;
        virtual void get_next_state(Action& action) = 0;


    protected:
        std::vector<State> states_;
        std::vector<Action> actions_;
  };
 
  template<typename State, typename Action>
  class GoContext: public Context<State, Action>{
    public:
      GoContext(){}
      ~GoContext(){}
      void get_current_state() {

      }
      void get_current_features(){

      }
      void get_next_state(){
        
      }


    protected:
      

  };



}



#endif 