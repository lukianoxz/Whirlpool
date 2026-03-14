#include <SDL3/SDL.h>
#include <Whirlpool.hpp>

int main(){
    Whirlpool::SimpleWindow Window(900, 600, "First window :)");
    Whirlpool::SimpleRender2D Render(Window);
    Whirlpool::InputHandler InputHandler;

    Window.Init();
    bool Loop = true;

    while(Loop){
        InputHandler.Input([&Loop](SDL_Event Event){
            if (Event.type == SDL_EVENT_QUIT) Loop = false;
        });

        Window.Clear();
        Window.SetDrawColor({255, 0, 0, 255});

        Render.DrawRect({{200.0f, 100.0f}, {700.0f, 500.0f}});

        Window.Present();
    }

    return 0;
}