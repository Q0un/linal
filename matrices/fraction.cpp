#include "fraction.h"

#include <numeric>

Fraction::Fraction(int64_t n, int64_t m) {
    num_ = n;
    denom_ = m;
    Normalize();
}

Fraction Fraction::operator-() const {
    return {-num_, denom_};
}

Fraction Fraction::operator+(const Fraction& other) const {
    int64_t g = std::gcd(denom_, other.denom_);
    int64_t num = num_ * (other.denom_ / g) + other.num_ * (denom_ / g);
    int64_t denom = denom_ * other.denom_ / g;
    return {num, denom};
}

Fraction Fraction::operator+(int64_t other) const {
    return {num_ + other * denom_, denom_};
}

Fraction operator+(int64_t a, const Fraction& b) {
    return b + a;
}

Fraction Fraction::operator-(const Fraction& other) const {
    return operator+(-other);
}

Fraction Fraction::operator-(int64_t other) const {
    return operator+(-other);
}

Fraction operator-(int64_t a, const Fraction& b) {
    return -(b - a);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return {num_ * other.num_, denom_ * other.denom_};
}

Fraction Fraction::operator*(int64_t other) const {
    return {num_ * other, denom_};
}

Fraction operator*(int64_t a, const Fraction& b) {
    return b * a;
}

Fraction Fraction::operator/(const Fraction& other) const {
    return {num_ * other.denom_, denom_ * other.num_};
}

Fraction Fraction::operator/(int64_t other) const {
    return {num_, denom_ * other};
}

Fraction operator/(int64_t a, const Fraction& b) {
    return {a * b.denom_, b.num_};
}

Fraction& Fraction::operator+=(const Fraction& other) {
    return (*this) = operator+(other);
}

Fraction& Fraction::operator+=(int64_t other) {
    return (*this) = operator+(other);
}

Fraction& Fraction::operator-=(const Fraction& other) {
    return (*this) = operator-(other);
}

Fraction& Fraction::operator-=(int64_t other) {
    return (*this) = operator-(other);
}

Fraction& Fraction::operator*=(const Fraction& other) {
    return (*this) = operator*(other);
}

Fraction& Fraction::operator*=(int64_t other) {
    return (*this) = operator*(other);
}

Fraction& Fraction::operator/=(const Fraction& other) {
    return (*this) = operator/(other);
}

Fraction& Fraction::operator/=(int64_t other) {
    return (*this) = operator/(other);
}

std::ostream& operator<<(std::ostream& stream, const Fraction& fraction) {
    if (fraction.denom_ == 1) {
        return stream << fraction.num_;
    }
    return stream << fraction.num_ << '/' << fraction.denom_;
}

bool Fraction::operator<(const Fraction& other) const {
    int64_t g = std::gcd(denom_, other.denom_);
    return num_ * (other.denom_ / g) < other.num_ * (denom_ / g);
}

bool Fraction::operator<(int64_t other) const {
    return num_ < other * denom_;
}

bool operator<(int64_t a, const Fraction& b) {
    return a * b.denom_ < b.num_;
}

bool Fraction::operator==(const Fraction& other) const {
    return num_ == other.num_ && denom_ == other.denom_;
}

bool Fraction::operator==(int64_t other) const {
    return num_ == other && denom_ == 1;
}

bool operator==(int64_t a, const Fraction& b) {
    return a == b.num_ && b.denom_ == 1;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !operator==(other);
}

bool Fraction::operator!=(int64_t other) const {
    return !operator==(other);
}

bool operator!=(int64_t a, const Fraction& b) {
    return !(a == b);
}

bool Fraction::operator>(const Fraction& other) const {
    return !operator<(other) && !operator==(other);
}

bool Fraction::operator>(int64_t other) const {
    return !operator<(other) && !operator==(other);
}

bool operator>(int64_t a, const Fraction& b) {
    return !(a < b) && !(a == b);
}

bool Fraction::operator<=(const Fraction& other) const {
    return !operator>(other);
}

bool Fraction::operator<=(int64_t other) const {
    return !operator>(other);
}

bool operator<=(int64_t a, const Fraction& b) {
    return !(a > b);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !operator<(other);
}

bool Fraction::operator>=(int64_t other) const {
    return !operator<(other);
}

bool operator>=(int64_t a, const Fraction& b) {
    return !(a < b);
}

Fraction Fraction::GetAbs() const {
    if (num_ < 0) {
        return operator-();
    } else {
        return *this;
    }
}

void Fraction::Normalize() {
    if (denom_ < 0) {
        num_ *= -1;
        denom_ *= -1;
    }
    int64_t g = std::gcd(num_, denom_);
    num_ /= g;
    denom_ /= g;
}
