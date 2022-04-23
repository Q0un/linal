#pragma once

#include "fraction.h"

#include <initializer_list>
#include <iostream>
#include <vector>

class Poly {
public:
    explicit Poly(size_t deg = 0);
    explicit Poly(std::vector<Fraction> data);
    explicit Poly(std::vector<Fraction>&& data);
    Poly(std::initializer_list<Fraction> data);

    Poly operator+(const Poly& other) const;
    Poly operator-() const;
    Poly operator-(const Poly& other) const;
    Poly operator*(const Poly& other) const;

    Poly operator+(const Fraction& val) const;
    Poly operator-(const Fraction& val) const;
    Poly operator*(const Fraction& val) const;

    Poly& operator+=(const Poly& other);
    Poly& operator-=(const Poly& other);
    Poly& operator*=(const Poly& other);

    Poly& operator+=(const Fraction& val);
    Poly& operator-=(const Fraction& val);
    Poly& operator*=(const Fraction& val);

    size_t degree() const;

    Fraction& operator[](size_t i);
    Fraction operator[](size_t i) const;

    std::vector<Fraction>::iterator begin();
    std::vector<Fraction>::const_iterator begin() const;
    std::vector<Fraction>::iterator end();
    std::vector<Fraction>::const_iterator end() const;

    friend std::ostream& operator<<(std::ostream& stream, const Poly& poly);

private:
    std::vector<Fraction> data_;
};
