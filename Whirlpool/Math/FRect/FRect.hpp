#ifndef WHIRLPOOL_FRECT_HPP
#define WHIRLPOOL_FRECT_HPP

#include <Vector2.hpp>

namespace Whirlpool {
    struct FRect {
        Vector2 Min, Max;

        FRect(Vector2 Min = Vector2(), Vector2 Max = Vector2()):
            Min(Min),
            Max(Max)
        {}
    };
}

#endif