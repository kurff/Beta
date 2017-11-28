#ifndef __ACTION_HPP__
#define __ACTION_HPP__

#include <vector>

namespace Beta{




class Action{
    public:
        Action(){

        }
        
        ~Action(){

        }


        virtual void play() = 0;

    protected:
};

class GoAction{
    public:
        GoAction(){

        }
        ~GoAction(){

        }

        void play(){
            
        }
        
    protected:
        int x_;
        int y_;
        //std::vector<>
};


}

#endif 