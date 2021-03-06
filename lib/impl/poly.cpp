#include "poly.h"

Poly::Poly(size_t deg) : data_(deg + 1) {
}

Poly::Poly(std::vector<Fraction> data) : data_(data) {
}

Poly::Poly(std::vector<Fraction>&& data) : data_(data) {
}

Poly::Poly(std::initializer_list<Fraction> data) : data_(data) {
}

Poly Poly::operator+(const Poly& other) const {
    Poly res(std::max(degree(), other.degree()));
    for (size_t i = 0; i <= res.degree(); ++i) {
        res[i] = operator[](i) + other[i];
    }
    return res;
}

Poly Poly::operator-() const {
    Poly res;
    std::transform(begin(), end(), std::back_inserter(res.data_), [](const Fraction& x) { return -x; });
    return res;
}

Poly Poly::operator-(const Poly& other) const {
    return operator+(-other);
}

Poly Poly::operator*(const Poly& other) const {
    Poly res(degree() + other.degree());
    for (size_t i = 0; i <= degree(); ++i) {
        for (size_t j = 0; j <= other.degree(); ++j) {
            res[i + j] += operator[](i) * other[j];
        }
    }
    return res;
}

Poly Poly::operator+(const Fraction& val) const {
    return operator+(Poly({val}));
}

Poly Poly::operator-(const Fraction& val) const {
    return operator-(Poly({val}));
}

Poly Poly::operator*(const Fraction& val) const {
    return operator*(Poly({val}));
}

Poly& Poly::operator+=(const Poly& other) {
    return (*this) = operator+(other);
}

Poly& Poly::operator-=(const Poly& other) {
    return (*this) = operator-(other);
}

Poly& Poly::operator*=(const Poly& other) {
    return (*this) = operator*(other);
}

Poly& Poly::operator+=(const Fraction& val) {
    return operator+=(Poly({val}));
}

Poly& Poly::operator-=(const Fraction& val) {
    return operator-=(Poly({val}));
}

Poly& Poly::operator*=(const Fraction& val) {
    return operator*=(Poly({val}));
}

size_t Poly::degree() const {
    return data_.size() - 1;
}

Fraction Poly::operator[](size_t i) const {
    if (i > degree()) {
        return 0;
    } else {
        return data_[i];
    }
}

Fraction& Poly::operator[](size_t i) {
    return data_[i];
}

std::vector<Fraction>::iterator Poly::begin() {
    return data_.begin();
}

std::vector<Fraction>::const_iterator Poly::begin() const {
    return data_.begin();
}

std::vector<Fraction>::iterator Poly::end() {
    return data_.end();
}

std::vector<Fraction>::const_iterator Poly::end() const {
    return data_.end();
}

std::ostream& operator<<(std::ostream& stream, const Poly& poly) {
    for (size_t i = 0; i <= poly.degree(); ++i) {
        stream << poly[i];
        stream << "x^" << i;
        if (i + 1 <= poly.degree()) {
            stream << " + ";
        }
    }
    return stream;
}
