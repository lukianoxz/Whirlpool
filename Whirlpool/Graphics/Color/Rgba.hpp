#ifndef WHIRLPOOL_RGBA_HPP
#define WHIRLPOOL_RGBA_HPP

#include <algorithm>

namespace Whirlpool {
    struct FRgba;

    struct Rgba {
        int R, G, B, A;

        Rgba(int R = 0, int G = 0, int B = 0, int A = 0):
            R(R),
            G(G),
            B(B),
            A(A)
        {}

        void Clamp(){
            R = std::clamp(R, 0, 255);
            G = std::clamp(G, 0, 255);
            B = std::clamp(B, 0, 255);
            A = std::clamp(A, 0, 255);
        }

        FRgba ToFRgba();
    };

    struct FRgba {
        float R, G, B, A;

        FRgba(int R = 0, int G = 0, int B = 0, int A = 0):
            R((R > 0) ? R / 255.0f : 0.0f),
            G((G > 0) ? G / 255.0f : 0.0f),
            B((B > 0) ? B / 255.0f : 0.0f),
            A((A > 0) ? A / 255.0f : 0.0f)
        {}
    };

    FRgba Rgba::ToFRgba(){
        return {R, G, B, A};
    }
}

#endif