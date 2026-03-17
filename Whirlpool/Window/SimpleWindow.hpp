#ifndef WHIRLPOOL_SIMPLE_WINDOW_HPP
#define WHIRLPOOL_SIMPLE_WINDOW_HPP

#include <string>
#include <Rgba.hpp>
#include <SDL3/SDL.h>

namespace Whirlpool {
    struct SimpleWindow {
        friend struct SimpleRender2D;
        friend struct SimpleSound;
    private:
        void Init(){
            if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)){
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "[SimpleWindow]: Initialization failure :(", SDL_GetError(), NULL);
                exit(1);
            }

            Window = SDL_CreateWindow(WindowName.c_str(), SizeX, SizeY, 0);
            Render = SDL_CreateRenderer(Window, NULL);
            Audio = SDL_CreateAudioStream(&this->AudioSpec, &this->AudioSpec);
            SDL_AudioDeviceID DevId = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &this->AudioSpec);
            SDL_BindAudioStream(DevId, Audio);
            SDL_ResumeAudioDevice(DevId);
        }
    protected:
        SDL_Window* Window;
        SDL_Renderer* Render;
        SDL_AudioStream* Audio;
        SDL_AudioSpec AudioSpec;

        void SetDrawColor(Rgba Color = {0, 0, 0, 255}){
            Color.Clamp();
            SDL_SetRenderDrawColor(Render, (Uint8)Color.R, (Uint8)Color.G, (Uint8)Color.B, (Uint8)Color.A);
        }
    public:
        int SizeX, SizeY;
        std::string WindowName;

        SimpleWindow(int WindowSizeX, int WindowSizeY, std::string WindowName, SDL_AudioSpec AudioSpec = {SDL_AUDIO_F32, 1, 44100}):
            SizeX(WindowSizeX),
            SizeY(WindowSizeY),
            WindowName(WindowName),
            AudioSpec(AudioSpec)
        {Init();}

        void Clear(Rgba Color = {0, 0, 0, 255}){
            SetDrawColor(Color);
            SDL_RenderClear(Render);
        }

        void Present(){
            SDL_RenderPresent(Render);
        }

        ~SimpleWindow(){
            SDL_DestroyRenderer(Render);
            SDL_DestroyAudioStream(Audio);
            SDL_DestroyWindow(Window);
            SDL_Quit();
        }
    };
}

#endif