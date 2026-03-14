#include <FRect.hpp>

bool Whirlpool::Vector2::InRange(const Vector2& Limit) const {
        return (this->X <= Limit.X && this->Y <= Limit.Y);
}

bool Whirlpool::Vector2::InRect(const FRect& R) const {
    return (R.Min.InRange(*this) && this->InRange(R.Max));
}