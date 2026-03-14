#ifndef WHIRLPOOL_POINT_HPP
#define WHIRLPOOL_POINT_HPP

#include <Vector2.hpp>

namespace Whirlpool {
    struct Point {
        int X, Y;

        Point(int X = 0, int Y = 0):
            X(X),
            Y(Y)
        {}
    };
}

#endif