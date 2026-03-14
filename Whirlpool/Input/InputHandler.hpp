#ifndef WHIRLPOOL_INPUTHANDLER_HPP
#define WHIRLPOOL_INPUTHANDLER_HPP

#include <SDL3/SDL.h>

namespace Whirlpool {
    struct InputHandler {
    private:
        SDL_Event Event;
    public:
        template <typename Function>

        void Input(Function CallBack){
            while(SDL_PollEvent(&Event)){
                CallBack(Event);
            }
        }
    };
}

#endif