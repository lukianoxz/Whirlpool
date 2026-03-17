#ifndef WHIRLPOOL_SIMPLE_SOUND_HPP
#define WHIRLPOOL_SIMPLE_SOUND_HPP

#include <SDL3/SDL.h>
#include <SimpleWindow.hpp>
#include <memory>
#include <vector>
#include <math.h>

namespace Whirlpool {
    struct Note {
        float Frequency;
        float Amplitude;
        Uint32 Duration;
    };

    struct Audio {
        friend struct SimpleSound;
    private:
        bool Playing = false;
        Uint32 NotePlayTime;
        std::size_t CurrentNote;
    public:
        std::vector <Note> Notes;
        
    };

    struct SimpleSound {
    private:
        SimpleWindow& Window;

        void PlayNote(Note& NoteToPlay){
            int SampleRate = Window.AudioSpec.freq;
            std::size_t NoteSize = (std::size_t)(SampleRate * NoteToPlay.Duration / 1000.0f);
            float* Samples = new float[NoteSize];

            for (std::size_t i = 0; i < NoteSize; i++){
                float Time = (float)i / (float)SampleRate;
                float Sample = NoteToPlay.Amplitude * sinf(2.0f * M_PI * NoteToPlay.Frequency * Time);

                float Filter = 1000.0f;
                if (NoteSize - i < Filter){
                    Sample = Sample * ((float)(NoteSize - i) / Filter);
                }

                if (i < Filter){
                    Sample = Sample * ((float)(i) / Filter);
                }
                
                Samples[i] = Sample;
            }

            SDL_PutAudioStreamData(Window.Audio, Samples, (int)NoteSize * sizeof(float));
            delete[] Samples;
        }
    public:

        void Play(Audio& AudioToPlay){
            if (SDL_GetAudioStreamQueued(Window.Audio) > 16000) return;
            
            if (!AudioToPlay.Playing){
                AudioToPlay.CurrentNote = 0;
                AudioToPlay.Playing = true;
                AudioToPlay.NotePlayTime = SDL_GetTicks();
                PlayNote(AudioToPlay.Notes[AudioToPlay.CurrentNote]);
            }
            
            Uint32 CurrentTime = SDL_GetTicks();

            if (CurrentTime - AudioToPlay.NotePlayTime >= AudioToPlay.Notes[AudioToPlay.CurrentNote].Duration){
                AudioToPlay.CurrentNote++;
                if (AudioToPlay.CurrentNote >= AudioToPlay.Notes.size()){
                    AudioToPlay.Playing = false;
                } else {
                    AudioToPlay.NotePlayTime = CurrentTime;
                    PlayNote(AudioToPlay.Notes[AudioToPlay.CurrentNote]);
                }
            }
        }
        
        SimpleSound(SimpleWindow& Window):
            Window(Window)
        {}

    };
}

#endif