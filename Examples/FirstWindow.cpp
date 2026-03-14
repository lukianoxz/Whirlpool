#include <SDL3/SDL.h>
#include <Whirlpool.hpp>

int main(){
    Whirlpool::SimpleWindow Window(900, 600, "First window :)");
    Window.Init();

    bool Loop = true;

    while(Loop){
        Window.Input([&Loop](SDL_Event Event){
            if (Event.type == SDL_EVENT_QUIT) Loop = false;
        });
    }

    return 0;
}