#include <SDL3/SDL.h>
#include <Whirlpool.hpp>

int main() {
    Whirlpool::SimpleWindow Window(900, 600, "Whirlpool music");
    Whirlpool::SimpleSound Sound(Window);
    Whirlpool::InputHandler InputHandler;

    Whirlpool::Audio MySong;
    
    MySong.Notes = {
        {261.63f, 0.5f, 500},
        {329.63f, 0.5f, 500},
        {392.00f, 0.5f, 500},
        {523.25f, 0.5f, 1000},
        {392.00f, 0.5f, 500},
        {329.63f, 0.5f, 500},
        {261.63f, 0.8f, 1500}
    };

    bool Loop = true;

    while (Loop) {
        InputHandler.Input([&Loop](SDL_Event Event) {
            if (Event.type == SDL_EVENT_QUIT) Loop = false;
        });

        Sound.Play(MySong);

        Window.Clear();
        Window.Present();
    }

    return 0;
}