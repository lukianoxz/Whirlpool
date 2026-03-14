#include <SDL3/SDL.h>
#include <Whirlpool.hpp>

int main(){
    Whirlpool::SimpleWindow Window(900, 600, "First window :)");
    Window.Init();
    Whirlpool::SimpleRender2D Render(Window);

    Whirlpool::InputHandler InputHandler;

    bool Loop = true;

    while(Loop){
        InputHandler.Input([&Loop](SDL_Event Event){
            if (Event.type == SDL_EVENT_QUIT) Loop = false;
        });

        Window.Clear();
        
        Render.DrawRect({{200.0f, 100.0f}, {700.0f, 500.0f}}, {255, 0, 0, 255});

        Window.Present();
    }

    return 0;
}