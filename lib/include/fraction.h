#pragma once

#include <cstdint>
#include <iostream>
#include <string>

class Fraction {
public:
    Fraction(int64_t n = 0, int64_t m = 1);

    Fraction operator-() const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator+(int64_t other) const;
    friend Fraction operator+(int64_t a, const Fraction& b);
    Fraction operator-(const Fraction& other) const;
    Fraction operator-(int64_t other) const;
    friend Fraction operator-(int64_t a, const Fraction& b);
    Fraction operator*(const Fraction& other) const;
    Fraction operator*(int64_t other) const;
    friend Fraction operator*(int64_t a, const Fraction& b);
    Fraction operator/(const Fraction& other) const;
    Fraction operator/(int64_t other) const;
    friend Fraction operator/(int64_t a, const Fraction& b);

    Fraction& operator+=(const Fraction& other);
    Fraction& operator+=(int64_t other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator-=(int64_t other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator*=(int64_t other);
    Fraction& operator/=(const Fraction& other);
    Fraction& operator/=(int64_t other);

    friend std::ostream& operator<<(std::ostream& stream, const Fraction& fraction);

    bool operator<(const Fraction& other) const;
    bool operator<(int64_t other) const;
    friend bool operator<(int64_t a, const Fraction& b);
    bool operator==(const Fraction& other) const;
    bool operator==(int64_t other) const;
    friend bool operator==(int64_t a, const Fraction& b);
    bool operator!=(const Fraction& other) const;
    bool operator!=(int64_t other) const;
    friend bool operator!=(int64_t a, const Fraction& b);
    bool operator>(const Fraction& other) const;
    bool operator>(int64_t other) const;
    friend bool operator>(int64_t a, const Fraction& b);
    bool operator<=(const Fraction& other) const;
    bool operator<=(int64_t other) const;
    friend bool operator<=(int64_t a, const Fraction& b);
    bool operator>=(const Fraction& other) const;
    bool operator>=(int64_t other) const;
    friend bool operator>=(int64_t a, const Fraction& b);

    Fraction abs() const;
    std::string toString() const;
    size_t length() const;

private:
    int64_t num_;
    int64_t denom_;

    void normalize();
};
