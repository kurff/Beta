#ifndef __CONTEXT_HPP__
#define __CONTEXT_HPP__


#include <vector>
#include "caffe2/core/tensor.h"
#include "glog/logging.h"
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



        State& get_next_state(int index){
          if(index<0 || index >= current_legal_states_.size()){
            LOG(INFO)<<"out of range";
          }
          return current_legal_states_[index];
        }

        virtual void calc_next_state() = 0;

        virtual void get_legal_action(const Tensor<CPUContext>& current) = 0;

        size_t size_legal_action(){
          return current_legal_action_.size(); 
        }
        const Action& legal_action(int index){
          return current_legal_action_[index];
        }





    protected:
        std::vector<State> states_;
        std::vector<Action> actions_;
        std::vector<Action> current_legal_action_;
        std::vector<State> current_legal_states_;

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


      void calc_next_state(){
        current_legal_states_.resize(current_legal_action_.size());
        for(int i = 0; i < current_legal_action_.size(); ++ i){


        }

      }

      void get_legal_action(const Tensor<CPUContext>& current){
        //



      }



    protected:
      
      

  };

  template<typename State, typename Action>
  class ChessContext: public Context<State, Action>{
    public:
      ChessContext(){}
      ~ChessContext(){}
      void get_current_state() {

      }
      void get_current_features(){

      }


      void calc_next_state(){


      }


      void get_legal_action(const Tensor<CPUContext>& current){
        //




      }



    protected:
      

  };




}



#endif 