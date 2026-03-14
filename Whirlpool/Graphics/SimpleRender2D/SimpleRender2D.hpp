#ifndef WHIRLPOOL_SIMPLERENDER2D_HPP
#define WHIRLPOOL_SIMPLERENDER2D_HPP

#include <Rgba.hpp>
#include <FRect.hpp>
#include <SimpleWindow.hpp>

namespace Whirlpool {
    struct SimpleRender2D {
    private:
        SimpleWindow& Window;
    public:
        SimpleRender2D(SimpleWindow& Window):
            Window(Window)
        {}

        void DrawRect(FRect Rect, Rgba Color = {0, 0, 0, 255}){
            Window.SetDrawColor(Color);
            SDL_FRect SDLRect = {Rect.Min.X, Rect.Min.Y, Rect.Max.X - Rect.Min.X, Rect.Max.Y - Rect.Min.Y};
            SDL_RenderFillRect(Window.Render, &SDLRect);
        }
    };
}

#endif