#ifndef WHIRLPOOL_SIMPLE_WINDOW_HPP
#define WHIRLPOOL_SIMPLE_WINDOW_HPP

#include <string>
#include <SDL3/SDL.h>

namespace Whirlpool {
    struct SimpleWindow {
    private:
        bool WindowInit = false;
    public:
        int SizeX, SizeY;
        std::string WindowName;

        SDL_Window* Window;
        SDL_Renderer* Render;
        SDL_AudioStream* Audio;
        SDL_Event Event;

        SDL_AudioSpec AudioSpec;

        SimpleWindow(int WindowSizeX, int WindowSizeY, std::string WindowName):
            SizeX(WindowSizeX),
            SizeY(WindowSizeY),
            WindowName(WindowName)
        {}

        void Init(SDL_AudioSpec AudioSpec = {SDL_AUDIO_F32, 1, 44100}){
            this->AudioSpec = AudioSpec;

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
            
            WindowInit = true;
        }

        template <typename Function>

        void Input(Function CallBack){
            while(SDL_PollEvent(&Event)){
                CallBack(Event);
            }
        }

        ~SimpleWindow(){
            if (WindowInit){
                SDL_DestroyRenderer(Render);
                SDL_DestroyAudioStream(Audio);
                SDL_DestroyWindow(Window);
                SDL_Quit();
            }
        }
    };
}

#endif