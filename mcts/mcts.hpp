#ifndef __MCTS_HPP__
#define __MCTS_HPP__

#include "core/context.hpp"
#include "tree.hpp"
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

        bool init(){
            tree_ = shared_ptr<Tree<State> >(new Tree<State>());
            context_ = shared_ptr<Context<State, Action> >(new Context<State, Action>());
            return true;
        }

        void run(){
            tree_->run();

        }
    protected:
        shared_ptr<Context<State, Action> > context_;
        shared_ptr<Tree<State> > tree_;
        




};
}
#endif