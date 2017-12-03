#ifndef __MCTS_HPP__
#define __MCTS_HPP__

#include "core/context.hpp"
#include "tree.hpp"
#include "proto/beta.pb.h"
#include <queue>

namespace Beta{
template <typename State, typename Action>
//multiple thread run
class MCTS{
    public:
        MCTS(){

        }
        ~MCTS(){

        }

        bool init(int L){
            tree_ = shared_ptr<Tree<State> >(new Tree<State>(L));
            context_ = shared_ptr<Context<State, Action> >(new Context<State, Action>());
            return true;
        }

        void run(State root){
            tree_->run();

        }
    protected:
        shared_ptr<Context<State, Action> > context_;
        shared_ptr<Tree<State> > tree_;
        




};
}
#endif