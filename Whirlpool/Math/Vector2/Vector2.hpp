#ifndef WHIRLPOOL_VECTOR2_HPP
#define WHIRLPOOL_VECTOR2_HPP

namespace Whirlpool {
    struct FRect;

    struct Vector2 {
        float X, Y;

        Vector2(float X = 0, float Y = 0):
            X(X),
            Y(Y)
        {}

        bool InRange(const Vector2& Limit) const;
        bool InRect(const FRect& R) const;

        Vector2 operator+(const Vector2& V) const {
            return {this->X + V.X, this->Y + V.Y};
        }
        Vector2 operator-(const Vector2& V) const {
            return {this->X - V.X, this->Y - V.Y};
        }
        Vector2 operator*(const float F) const {
            return {this->X * F, this->Y * F};
        }
        Vector2 operator/(const float F) const {
            return {this->X / F, this->Y / F};
        }
    };
}

#endif